/********* woosimPrint.m Cordova Plugin Implementation *******/

#import <Cordova/CDV.h>
#import <Foundation/Foundation.h>
#import <ExternalAccessory/ExternalAccessory.h>
#import "WSEncoder.h"
@interface woosimPrint : CDVPlugin {
    // Member variables go here.
}
@property (nonatomic, retain) EASession* session;
@property (nonatomic, retain) NSMutableArray*  accessoryList;
@property (nonatomic, retain) NSMutableData *outData;
@property (nonatomic, retain) NSMutableData *_nData;

- (void)connect:(CDVInvokedUrlCommand*)command;
- (void)printString:(CDVInvokedUrlCommand*)command;
@end

@implementation woosimPrint


- (void)connect:(CDVInvokedUrlCommand*)command
{
    NSString *protocol = @"com.woosim.wspr240";
    NSString *modelNumber = @"WSP-i450i";
    self.accessoryList = [[NSMutableArray alloc] initWithArray:[[EAAccessoryManager sharedAccessoryManager] connectedAccessories]];
    BOOL statusSession = FALSE;
    for(EAAccessory* accessory in self.accessoryList)
    {
        if ([accessory.modelNumber isEqual:(modelNumber) ]) {
            
            if(self.session == nil) {
                [accessory setDelegate: self];
                self.session = [[EASession alloc] initWithAccessory: accessory forProtocol: protocol];
                
                [[self.session inputStream] setDelegate: self];
                [[self.session inputStream] scheduleInRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
                [[self.session inputStream] open];
                
                [[self.session outputStream ] setDelegate: self];
                [self.session.outputStream scheduleInRunLoop:[NSRunLoop mainRunLoop] forMode:NSDefaultRunLoopMode];
                [self.session.outputStream open];
                statusSession = TRUE;
            }
            statusSession = TRUE;
            NSLog(@" tak  %@", accessory.modelNumber);
        }else {
            NSLog(@" nie ");
        }
    }
    CDVPluginResult*  pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsBool : statusSession];
    [self.commandDelegate sendPluginResult: pluginResult callbackId:command.callbackId];
}

- (void)printString:(CDVInvokedUrlCommand*)command
{
    WSEncoder *_wsSM;
    NSMutableData *_printDataSM;
    NSString* stringData = nil;
    stringData = [command.arguments objectAtIndex: 0];
    
    _printDataSM = [[NSMutableData alloc]init];
    _wsSM = [[WSEncoder alloc]init];
    
    [_printDataSM appendData:[_wsSM clearPrinterBuffer]];
    [_printDataSM appendData:[_wsSM addString: stringData encoding:NSASCIIStringEncoding]];
    [_printDataSM appendData:[_wsSM printDataInStandardMode]];
    [_printDataSM appendData:[_wsSM printDataInStandardMode]];
    [_printDataSM appendData:[_wsSM printDataInStandardMode]];
    
    [[self.session outputStream] write:[_printDataSM bytes] maxLength:[_printDataSM length]];
}


@end
