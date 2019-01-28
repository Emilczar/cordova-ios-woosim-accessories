//
//  WSParser.h
//  SDK212
//
//  Created by woosimsystems on 2016. 7. 04..
//  Copyright © 2016년 woosimsystems. All rights reserved.
//

#import <Foundation/Foundation.h>
#define PRINTER_VER     0x2000
#define PRINTER_NAME    0X2001
#define PRINTER_BATTERY 0x2002


typedef enum{
    WSDATA_MSR,
    WSDATA_MSRFAIL,
    WSDATA_SPECIAL,
    WSDATA_UNKNOWN
}WSDATATYPE;

@interface WSParser : NSObject


#pragma mark decode receive data
-(WSDATATYPE)decode:(NSData *)srcData;

#pragma mark MSR data
@property (nonatomic, readonly) NSData *track1;
@property (nonatomic, readonly) NSData *track2;
@property (nonatomic, readonly) NSData *track3;

#pragma mark printer infomations
//specialDataTypes are PRINTER_NAME, PRINTER_BATTERY, PRINTER_VER.
@property (nonatomic, readonly) int specialDataType;
//printer version string
@property (nonatomic, readonly) NSString *printerVersion;
//name of printer
@property (nonatomic, readonly) NSString *printerName;
//printer's paper width inch 1: 1inch, 2: 2inch, 3: 3inchs, 4: 4inch
@property (nonatomic, readonly) int paperWidthInch;
//printer battery charge status 1: 0~25%, 2: 25~50%, 3: 50~75%, 4: 75~100%
@property (nonatomic, readonly) int batteryStatus;


@end