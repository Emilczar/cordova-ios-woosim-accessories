//
//  WSEncoder.h
//  SDK212
//
//  Created by woosimsystems on 2016. 7. 04..
//  Copyright © 2016년 woosimsystems. All rights reserved.

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

typedef enum {
    BARCODE_UPCA = 65,
    BARCODE_UPCE,
    BARCODE_EAN13,
    BARCODE_EAN8,
    BARCODE_CODE39,
    BARCODE_ITF,
    BARCODE_CODABAR,
    BARCODE_CODE93,
    BARCODE_CODE128
} BARCODE;

typedef enum {
    TEXTWIDTH_1 = 0x00,
    TEXTWIDTH_2,
    TEXTWIDTH_3,
    TEXTWIDTH_4,
    TEXTWIDTH_5,
    TEXTWIDTH_6,
    TEXTWIDTH_7,
    TEXTWIDTH_8
} TEXTWIDTH;

typedef enum {
    TEXTHEIGHT_1 = 0x00,
    TEXTHEIGHT_2 = 0x10,
    TEXTHEIGHT_3 = 0x20,
    TEXTHEIGHT_4 = 0x30,
    TEXTHEIGHT_5 = 0x40,
    TEXTHEIGHT_6 = 0x50,
    TEXTHEIGHT_7 = 0x60,
    TEXTHEIGHT_8 = 0x70
} TEXTHEIGHT;

typedef enum {
    FONTSIZE_A = 0x00,
    FONTSIZE_B,
    FONTSIZE_C
} FONTSIZE;

typedef enum{
    DIRECTION_LEFTTORIGHT = 0x00,
    DIRECTION_BOTTOMTOTOP,
    DIRECTION_RIGHTTOLEFT,
    DIRECTION_TOPTOBOTTOM
    
}DIRECTION;

typedef enum{
    ALIGN_LEFT = 0x00,
    ALIGN_CENTER,
    ALIGN_RIGHT
    
}ALIGN;

typedef enum {
    CUT_FULL = 0x00,
    CUT_PARTIAL
}CUT;

typedef enum {
    LANGUAGE_CP437      = 0,
    LANGUAGE_CP850      = 2,
    LANGUAGE_CP860      = 3,
    LANGUAGE_CP852      = 6,
    LANGUAGE_CP857      = 7,
    LANGUAGE_CP737      = 8,
    LANGUAGE_CP866      = 9,
    LANGUAGE_CP775      = 11,
    LANGUAGE_ISO8859_15 = 13,
    LANGUAGE_WIN1252    = 14,
    LANGUAGE_CP858      = 15,
    LANGUAGE_WIN1251    = 17,
    LANGUAGE_WIN1250    = 18,
    LANGUAGE_WIN1253    = 19,
    LANGUAGE_WIN1254    = 20,
    LANGUAGE_WIN1255    = 21,
    LANGUAGE_WIN1258    = 22,
    LANGUAGE_WIN1257    = 23,
    LANGUAGE_CP874      = 30,
    LANGUAGE_EUC_KR     = 255,
    LANGUAGE_SHIFT_JIS  = 255,
    LANGUAGE_GB18030    = 255,
    LANGUAGE_BIG5       = 255
}LANGUAGE;


@interface WSEncoder : NSObject
@property (nonatomic, readonly) NSMutableData *printableData;

#pragma mark Barcode
- (NSData *)createBarcode:(NSString *)data barcodeType:(BARCODE)type;
- (NSData *)createGS1Databar:(NSString *)data type:(uint8_t)type rowSegment:(uint8_t)segment;
- (NSData *)createBarcodeMaxicode:(NSString *)data mode:(uint8_t)mode;
- (NSData *)createBarcodePDF417:(NSString *)data dataEncoding:(NSStringEncoding)encoding column:(uint8_t)column securityLevel:(uint8_t)level HVRatio:(uint8_t)ratio;
- (NSData *)createBarcodeDataMatrix:(NSString *)data dataEncoding:(NSStringEncoding)encoding symbolHeight:(uint8_t)height symbolWidth:(uint8_t)width moduleSize:(uint8_t)size;
- (NSData *)createBarcodeQRCode:(NSString *)data dataEncoding:(NSStringEncoding)encoding symbolVersion:(uint8_t)version ECLevel:(char)level moduleSize:(uint8_t)size;
- (NSData *)createBarcodeMicroPDF417:(NSString *)data dataEncoding:(NSStringEncoding)encoding column:(uint8_t)column row:(uint8_t)row HVRatio:(uint8_t)ratio;
- (NSData *)createBarcodeTruncPDF417:(NSString *)data dataEncoding:(NSStringEncoding)encoding column:(uint8_t)column securityLevel:(uint8_t)level HVRatio:(uint8_t)ratio;
- (NSData *)enableHRI:(Boolean)HRI;
- (NSData *)setBarcodeHeight:(uint8_t)height;
- (NSData *)setBarcodeWidth:(uint8_t)width;

#pragma mark Page mode
- (NSData *)clearDataInPageMode;
- (NSData *)createDrawingAreaWithStartPositionX:(uint16_t)positionX withStartPositionY:(uint16_t)positionY withAreaWidth:(uint16_t)width withAreaHeight:(uint16_t)height;
- (NSData *)createImageInPageMode:(CGImageRef)cgImage withStartPositionX:(uint16_t)positionX withStartPositionY:(uint16_t)positionY withDithering:(BOOL)dithering;
- (NSData *)drawBoxWithWidth:(uint16_t)width withHeight:(uint16_t)height withLineThickness:(uint8_t)thickness;
- (NSData *)drawHorizontalLineWithLength:(uint16_t)length withLineThickness:(uint8_t)thickness;
- (NSData *)drawVerticalLineWithLength:(uint16_t)length withLineThickness:(uint8_t)thickness;
- (NSData *)enterPageMode;
- (NSData *)exitPageMode;
- (NSData *)feedLineInPageMode;
- (NSData *)feedNDotInPageMode:(uint8_t)n;
- (NSData *)feedNLineInPageMode:(uint8_t)n;
- (NSData *)movePositionToX:(uint16_t)pointX toY:(uint16_t)pointY;
- (NSData *)printDataInPageMode;
- (NSData *)setPrintingDirectionInPageMode:(DIRECTION)direction;
- (NSData *)drawDiagonalLineWithStartPositionX:(uint16_t)startX withStartPositionY:(uint16_t)startY withEndPositionX:(uint16_t)endX withEndPositionY:(uint16_t)endY withThickness:(uint8_t)thickness;
- (NSData *)drawEllipseWithCenterPositionX:(uint16_t)x withCenterPositionY:(uint16_t)y withRadiusX:(uint16_t)radiusX withRadiusY:(uint16_t)radiusY withThickness:(uint8_t)thickness;

#pragma mark Standard mode
- (NSData *)createImageInStandardMode:(CGImageRef)cgImage withShiftPosition:(uint16_t)position withDithering:(BOOL)dithering;
- (NSData *)printAndFeedNDotInStandardMode:(uint8_t)dot;
- (NSData *)printAndFeedNLineInStandardMode:(uint8_t)line;
- (NSData *)printDataInStandardMode;
- (NSData *)printImageInStandardMode;
- (NSData *)setLeftMarginInStandardMode:(uint16_t)margin;
- (NSData *)setPrintableAreaWidthInStandardMode:(uint16_t)width;
- (NSData *)setPrintingUpsideDownInStandardMode:(Boolean)upsideDown;
- (NSData *)setTextAlignInStandardMode:(ALIGN)align;

#pragma mark Text style
- (NSData *)addString:(NSString *)string encoding:(NSStringEncoding)encoding;
- (NSData *)addString:(NSString *)string encoding:(NSStringEncoding)encoding withTextWidth:(TEXTWIDTH)width withTextHeight:(TEXTHEIGHT)height withTextBold:(Boolean)bold;
- (NSData *)resetLineSpacing;
- (NSData *)reverseTextColor:(Boolean)reverseMode;
- (NSData *)selectTextCodeTable:(LANGUAGE)codetable;
- (NSData *)setFontSize:(FONTSIZE)size;
- (NSData *)setLetterSpacing: (uint8_t)spacing;
- (NSData *)setLineSpacing:(uint8_t)spacing;
- (NSData *)setTextBold:(Boolean)bold;
- (NSData *)setTextSizeWithWidth:(TEXTWIDTH)width withHeight:(TEXTHEIGHT)height;
- (NSData *)setTextUnderline:(Boolean)underline withLineThickness:(int)thickness;
- (NSData *)shiftAbsolutePosition:(uint16_t)position;
- (NSData *)shiftRelativePosition:(uint16_t)position;

#pragma mark TTF
- (NSData *)addStringWithTrueTypeFont:(NSString*)data withStringWidth:(uint8_t)width withStringHeight:(uint8_t)height;
- (NSData *)selectTrueTypeFontFile:(NSString*)fileName;

#pragma mark MSR
- (NSData *)enterMSR1stTrackMode;
- (NSData *)enterMSR2ndTrackMode;
- (NSData *)enterMSR3rdTrackMode;
- (NSData *)enterMSRDoubleTrackMode;
- (NSData *)enterMSRTripleTrackMode;
- (NSData *)exitMSRMode;

#pragma mark Label paper
- (NSData *)feedToBlackMarkPosition;
- (NSData *)setBlackMarkPosition:(uint16_t)position;

#pragma mark Miscellaneous
- (NSData *)clearPrinterBuffer;
- (uint16_t)changeDotFromCentimeter:(float)cm;
- (NSData *)cutPaper:(CUT)type;
- (NSData *)selectLogoImage:(uint8_t)index;
- (NSData *)verifyPrinterVer;
- (NSData *)requestPrinterName;
- (NSData *)requestPrinterBatteryStatus;

#pragma mark EMV command: Operation in specific firmware.
-(NSData *) SCR_enterPaymentMode;
-(NSData *) SCR_checkIntegrity;
-(NSData *) SCR_enterKeyDownloadMode;
-(NSData *) SCR_checkReaderStatus;
-(NSData *) SCR_checkKeyValidation;

#pragma mark 
-(NSData*)startPrintOutStatus;
-(NSData*)stopPrintOutStatus;

#pragma mark Deprecated
- (void)createPrintableDataFromImage:(CGImageRef)image coordinateX:(int)x coordinateY:(int)y width:(NSUInteger)width height:(NSUInteger)height;//SDK 210
- (NSData *)createBarcodeDataMatrix:(NSString *)data symbolHeight:(uint8_t)height symbolWidth:(uint8_t)width moduleSize:(uint8_t)size;
- (NSData *)createBarcodeMicroPDF417:(NSString *)data column:(uint8_t)column row:(uint8_t)row HVRatio:(uint8_t)ratio;
- (NSData *)createBarcodePDF417:(NSString *)data column:(uint8_t)column securityLevel:(uint8_t)level HVRatio:(uint8_t)ratio;
- (NSData *)createBarcodeQRCode:(NSString *)data symbolVersion:(uint8_t)version ECLevel:(char)level moduleSize:(uint8_t)size;
- (NSData *)createBarcodeTruncPDF417:(NSString *)data column:(uint8_t)column securityLevel:(uint8_t)level HVRatio:(uint8_t)ratio;
- (NSData *)createImageInPageMode:(CGImageRef)cgImage withStartPositionX:(uint16_t)positionX withStartPositionY:(uint16_t)positionY;//SDK 212
- (NSData *)createImageInStandardMode:(CGImageRef)cgImage withShiftPosition:(uint16_t)position;//SDK 212



@end
