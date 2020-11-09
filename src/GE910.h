/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *	Revision			: 01.08.00
 *
 *********************************************************************************/

#ifndef __GE910__
#define __GE910__

#include <Arduino.h>

// Software Definations
#define 	UART_IoT			Serial
#define 	UART_BAUD			115200
	
class GE910 {

public:
	
	// ************************************************************
	// Public Variables
	// ************************************************************

	// Function Variables
	const PROGMEM char 		Version[9] = "01.08.04";

	// IoT Variables
	char 					ID[11];
	char 					IMEI[17];
	char 					ICCID[21];
	char 					IP[15];
	char 					PHONE[15];
	int 					Operator;
	int		 				RSSI;

	// Time Variables
	uint8_t 				Day;
	uint8_t 				Month;
	uint8_t 				Year;
	uint8_t 				Hour;
	uint8_t 				Minute;
	uint8_t 				Second;
	
	// Control Variables
	bool					Device_Error;
	bool					PwrMon;
	uint8_t					CREG;
	uint8_t					CGREG;
	bool 					Connected;
	bool					Time_Updated;
	bool					Recorded;
	
	// Measure Variables
	uint8_t					Connection_Time;

	// ************************************************************
	// Public Functions
	// ************************************************************
	
	// Power Functions
	bool Module_ON(void);
	
	// GSM Connection Functions
	bool Connect(void);
	
	// GSM RTC Functions
	bool Time_Update(void);
	
	// Phone Number Function
	bool Phone_Number(void);
	
	// Data Functions
	bool AT_HTTPCFG(void);
	bool AT_HTTPSND(const String& _Data);
	
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
	bool AT_CNUM(void);
	
	// Modem ID Functions
	bool AT_CGSN(void);
	bool AT_GSN(void);

	// LED Functions
	bool AT_SLED(void);
	bool AT_TXMONMODE(void);

	// GSM Connection Functions
	bool AT_REGMODE(void);
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
	bool Response_Wait(uint16_t _Length, uint16_t _TimeOut);
		
	// ************************************************************
	// Private GSM Setting Variables
	// ************************************************************
		
	// Module Variables
	const PROGMEM uint8_t	_Command_Delay		= 10;				// Command Chain Delay
	
	// CMEE Variables
	const PROGMEM uint8_t 	_CMEE 				= 1;				// Set Numeric Error Format (1)

	// FCLASS Variables
	const PROGMEM uint8_t	_FCLASS 			= 0;				// Set Data Connection (0)

	// K Variables
	const PROGMEM uint8_t 	_K 					= 0;				// Set Flow Control (0)

	// SLED Variables
	const PROGMEM uint8_t 	_SLED 				= 2;				// Set Status LED Software Control (2)

	// TXMONMODE Variables
	const PROGMEM uint8_t 	_TXMONMODE 			= 1;				// Set Tx LED Software Control (1)

	// CGDCONT Variables
	const PROGMEM char 		_PDP[3] 			= "IP";				// Set PDP Variable (IP)
	const PROGMEM char 		_APN[15] 			= "internet";		// Set APN Variable (internet/statikip)

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
