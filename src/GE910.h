/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *	Revision			: 01.00.00
 *
 *********************************************************************************/

#ifndef __GE910__
#define __GE910__

#include <Arduino.h>

// Software Definations
#define UART_IoT		Serial
#define UART_BAUD		115200

class GE910 {

public:
	
	// ************************************************************
	// GE910 IoT Functions
	// ************************************************************

	// Modem Set Functions
	bool AT(void);
	bool AT_CMEE(void);
	bool AT_FCLASS(void);
	bool AT_K(void);

	// Modem ID Functions
	bool AT_CGSN(void);
	bool AT_GSN(void);

	// SIM Functions
	bool AT_CPIN(void);
	bool AT_CCID(void);

	// GSM Connection Functions
	bool AT_CREG(void);
	bool AT_CGREG(void);
	bool AT_CGDCONT(void);
	bool AT_SCFG(void);
	bool AT_SGACT(void);

	// Operotor Functions
	bool AT_SERVINFO(void);

	// LED Functions
	bool AT_SLED(void);
	bool AT_TXMONMODE(void);

	// Time Functions
	bool AT_CCLK(void)
	bool AT_NTP(void);

	// ************************************************************
	// Public Variables
	// ************************************************************

	// Function Variables
	char 		Firmware[9] = "01.00.00";		// Library Firmware

	// IoT Variables
	char 		ID[11];							// 10 digit number
	char 		IMEI[16];						// 15 digit number
	char 		ICCID[19];						// 18 digit number
	char 		IP[16];							// 15 digit string
	int 		Operator;						// 5 digit number
	int 		Signal;							// 2 digit number
	int			Band;							// 4 digit number
		
	// Date & Time Variables
	uint8_t 	Day;							// 2 digit Day Variable
	uint8_t 	Month;							// 2 digit Month Variable
	uint8_t 	Year;							// 2 digit Year Variable
	uint8_t 	Hour;							// 2 digit Hour Variable
	uint8_t 	Minute;							// 2 digit Minute Variable
	uint8_t 	Second;							// 2 digit Second Variable

private:

	// ************************************************************
	// Private Functions
	// ************************************************************

	// Utility Functions
	void UART_Flush(void);
	
	// ************************************************************
	// Private Variables
	// ************************************************************

	// IoT Variables
	uint8_t _CMEE 			= 1;				// Set Numeric Error Format (1)
	uint8_t _FCLASS 		= 0;				// Set Data Connection (0)
	uint8_t _K 				= 0;				// Set Flow Control (0)
	uint8_t _SLED 			= 2;				// Set Status LED Software Control (2)
	uint8_t _TXMONMODE 		= 1;				// Set Tx LED Software Control (1)
	uint8_t _Cid 			= 1;				// Set Cid Variable (1)
	char 	_PDP[3] 		= "IP";				// Set PDP Variable (IP)
	char 	_APN[8] 		= "internet";		// Set APN Variable (internet)
	uint8_t _ConnID 		= 1;				// Set ConnID Variable (1)
	uint8_t _PktSz	 		= 0;				// Set PktSz Variable (0-Auto)
	uint8_t _MaxTo 			= 0;				// Set MaxTo Variable (0-No Timeout)
	uint8_t _ConnTo 		= 150;				// Set ConnTo Variable (150 nS)
	uint8_t _TxTo 			= 0;				// Set TxTo Variable (0-No Timeout)
	char 	_NTP_Server[] 	= "129.6.15.28";	// Set NTP Server Variable (NASA)
	uint8_t _NTP_Port 		= 123;				// Set NTP Port Variable (123)
	
};

#endif /* defined(__GE910__) */
