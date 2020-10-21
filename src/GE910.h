/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *	Revision			: 01.04.00
 *
 *********************************************************************************/

#ifndef __GE910__
#define __GE910__

#include <Arduino.h>

// Software Definations
#define 	UART_IoT			Serial
#define 	UART_BAUD			115200

// Power Variables
#define 	Power_EN_DDR 		DDRB
#define 	Power_EN_PORT 		PORTB
#define 	Power_EN_PIN 		2
#define 	Comm_EN_DDR 		DDRC
#define 	Comm_EN_PORT 		PORTC
#define 	Comm_EN_PIN 		0
#define 	OnOff_DDR 			DDRC
#define 	OnOff_PORT 			PORTC
#define 	OnOff_PIN 			1
#define 	SDown_DDR 			DDRC
#define 	SDown_PORT 			PORTC
#define 	SDown_PIN 			2
#define 	PwrMon_DDR 			DDRC
#define 	PwrMon_PORT 		PORTC
#define 	PwrMon_PINS 		PINC
#define 	PwrMon_PIN 			3
	
class GE910 {

public:
	
	// ************************************************************
	// Public Variables
	// ************************************************************

	// Function Variables
	const PROGMEM char 		Version[9] = "01.04.00";		// Library Firmware

	// IoT Variables
	char 					ID[11];				// 10 digit number
	char 					IMEI[17];			// 17 digit number
	char 					ICCID[20];			// 20 digit number
	char 					IP[15];				// 15 digit string
	int 					Operator;			// 5 digit number
	uint8_t 				RSSI;				// 2 digit number
	uint8_t 				dBM;				// 2 digit number

	// CCLK Variables
	uint8_t 				Day;				// 2 digit Day Variable
	uint8_t 				Month;				// 2 digit Month Variable
	uint8_t 				Year;				// 2 digit Year Variable
	uint8_t 				Hour;				// 2 digit Hour Variable
	uint8_t 				Minute;				// 2 digit Minute Variable
	uint8_t 				Second;				// 2 digit Second Variable
	
	// Control Variables
	bool					GE910_Power;		// GSM Power Variable
	bool 					Connected;			// GSM Connected Variable
	bool					Time_Updated;		// Time Updated Variable
	bool					Recorded;			// Data Recorded Variable

	// ************************************************************
	// Public Functions
	// ************************************************************
	
	// Power Functions
	bool GSM_Module_ON(void);
	
	// GSM Connection Functions
	bool Connect(void);
	
	// GSM RTC Functions
	bool Time_Update(void);
	
	// Data Functions
	bool AT_HTTPCFG(void);
	bool AT_HTTPSND(String _Data);
	
private:
	
	// ************************************************************
	// Private Functions
	// ************************************************************

	// Modem Set Functions
	bool AT(void);
	bool AT_CMEE(void);
	bool AT_FCLASS(void);
	bool AT_K(void);

	// SIM Functions
	bool AT_CPIN(void);
	bool AT_CCID(void);

	// Modem ID Functions
	bool AT_CGSN(void);
	bool AT_GSN(void);

	// LED Functions
	bool AT_SLED(void);
	bool AT_TXMONMODE(void);

	// GSM Connection Functions
	bool AT_CREG(void);
	bool AT_CGREG(void);
	bool AT_CGDCONT(void);
	bool AT_SCFG(void);
	bool AT_SGACT(void);

	// Operotor Functions
	bool AT_SERVINFO(void);
	bool AT_CSQ(void);

	// RTC Functions
	bool AT_CCLK(void);
	bool AT_NTP(void);
	bool AT_CTZU(void);

	// Utility Functions
	void UART_Clear(void);
	bool Response_Wait(uint8_t _Length, uint16_t _TimeOut);
		
	// ************************************************************
	// Private GSM Setting Variables
	// ************************************************************
		
	// CMEE Variables
	const PROGMEM uint8_t 	_CMEE 				= 1;				// Set Numeric Error Format (1)

	// FCLASS Variables
	const PROGMEM uint8_t 	_FCLASS 			= 0;				// Set Data Connection (0)

	// K Variables
	const PROGMEM uint8_t 	_K 					= 0;				// Set Flow Control (0)

	// SLED Variables
	const PROGMEM uint8_t 	_SLED 				= 2;				// Set Status LED Software Control (2)

	// TXMONMODE Variables
	const PROGMEM uint8_t 	_TXMONMODE 			= 1;				// Set Tx LED Software Control (1)

	// CGDCONT Variables
	const PROGMEM char 		_PDP[3] 			= "IP";				// Set PDP Variable (IP)
	const PROGMEM char 		_APN[9] 			= "internet";		// Set APN Variable (internet)

	// SCFG Variables
	const PROGMEM uint8_t 	_PktSz	 			= 0;				// Set PktSz Variable (0-Auto)
	const PROGMEM uint8_t 	_MaxTo 				= 0;				// Set MaxTo Variable (0-No Timeout)
	const PROGMEM uint8_t 	_ConnTo 			= 150;				// Set ConnTo Variable (150 nS)
	const PROGMEM uint8_t 	_TxTo 				= 2;				// Set TxTo Variable (0-No Timeout)
	
	// NTP Variables
	const PROGMEM char 		_NTP_Server[15] 	= "85.199.214.98";	// Set NTP Server Variable (NASA)
	
	// HTTP Variables
	const PROGMEM char 		_HTTP_Server[23] 	= "agristat.aeyazilim.com";
	const PROGMEM char 		_HTTP_URL[20] 		= "/api/airstatservice";
	const PROGMEM uint8_t 	_HTTP_Port 			= 80;
};

#endif /* defined(__GE910__) */
