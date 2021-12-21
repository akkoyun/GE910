/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *
 *********************************************************************************/

#ifndef __GE910__
#define __GE910__

// Define Arduino Library
#ifndef __Arduino__
#include <Arduino.h>
#endif

// Define PGMspace Function
#include <avr/pgmspace.h>

// Define Library Structures
#ifndef __GE910_Structures__
#include "GE910_Structures.h"
#endif

class GE910 {

public:

	// ************************************************************
	// Public Variables
	// ************************************************************

	// Function Variables
	char 					Version[9] 				= "01.18.00";		// Version Variable

	// IoT Variables
	char 					ID[11]					= "";				// ID Variable
	char 					IMEI[17]				= "";				// IMEI Variable
	char 					ICCID[21]				= "";				// ICCID Variable
	char 					IP[15]					= "";				// IP Variable
	int 					Operator				= 0;				// Operator Variable
	uint8_t					RSSI					= 0;				// RSSI Variable
	uint8_t					GMI						= 0;				// GMI Variable

	// Time Variables
	uint8_t 				Day						= 29;				// Day Variable
	uint8_t 				Month					= 10;				// Month Variable
	uint16_t 				Year					= 1923;				// Year Variable
	uint8_t 				Hour					= 0;				// Hour Variable
	uint8_t 				Minute					= 0;				// Minute Variable
	uint8_t 				Second					= 0;				// Second Variable
	
	// Control Variables
	bool					PwrMon					= false;			// Power Monitor Test Variable
	uint8_t					CREG					= NOT_REGISTERED;	// CREG Test Variable
	uint8_t					CGREG					= NOT_REGISTERED;	// CGREG Test Variable
	uint8_t					SGACT					= 0;				// SGACT Test Variable
	bool 					Connected				= NOT_CONNECTED;	// Connected Test Variable
	bool					HTTP_CFG				= false;			// HTTPCFG Variable
	int						Server_Response 		= 0;				// Server Response Variable
	String					Response				= "";
	uint8_t					Connection_Time			= 0;				// CREG and CGREG time Variable
	bool					RTC_Update				= false;
	
	// New Versipn Variables
	char					Command_Response[255]	= "";				// Full Command Response
	bool					Message					= false;			// Incomming Message Variable
	int						Request					= 0;				// Server Request Variable
	int						Socket_Incomming_Length = 0;

	// JSON Variables
	String					JSON_P01				= "";				// P01 JSON Pack
	String					JSON_P02				= "";				// P02 JSON Pack
	String					JSON_P03				= "";				// P03 JSON Pack

	// ************************************************************
	// Public GSM Setting Variables
	// ************************************************************

	// Parameter Variable Structure
	Parameter_Struct Parameter {
		1,										// (CMEE) Set Numeric Error Format (1)
		0,										// (FCLASS) Set Data Connection (0)
		0,										// (K) Set Flow Control (0)
		2,										// (SLED) Set Status LED Software Control (2)
		0,										// (TXMONMODE) Set Tx LED Software Control (1)
		0,										// (REGMODE)
		"IP",									// (PDP) Set PDP Variable (IP)
		"mgbs",									// (APN) Set APN Variable (internet/statikip/mgbs)
		0,										// (PktSz) Set PktSz Variable (0-Auto)
		0,										// (MaxTo) Set MaxTo Variable (0-No Timeout)
		150,									// (ConnTo) Set ConnTo Variable (150 nS)
		0,										// (TxTo) Set TxTo Variable (0-No Timeout)
		1,										// (CTZU)
		"85.199.214.98",						// (NTP_Server) Set NTP Server Variable (NASA)
		"54.216.226.171",						// (HTTP_Server) Cloud Server IP
		"/api/v1.1/p402",						// (HTTP_URL) Cloud Server URL
		80,										// (HTTP_Port) Cloud Server Port
		1,
		0,
		1,
		50										// (Pulse_Duration) E2SLRI Pulse Duration
	};

	// Control Variable Structure
	Control_Struct Control { 
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false,
		false
	};

	// Interrupt Structure
	Interrupt_Struct Socket {
		false
	};

	// ************************************************************
	// Public Functions
	// ************************************************************
	
	// Hardware Functions

	void Communication(bool State);
	bool PowerMonitor(void);
	void OnOff(int Time_);
	void ShutDown(int Time_);
	void Power(bool State);
	void LED(bool State);
	bool Activate(bool Status);

	// Batch Functions

	void Connect(void);
	bool Connection_AT_Batch(void);
	bool Time_Update(void);
	bool Recieve_AT_Batch(void);
	bool RSSI_Refresh(void);
	bool Connection_Control(void);
	bool Send(const String &_Data);
	void Listen(void);

private:
	
	// ************************************************************
	// Private Functions
	// ************************************************************
	
	// Modem AT Command Functions

	bool AT(void);
	bool AT_CMEE(uint8_t _CMEE);
	bool AT_FCLASS(const uint8_t _FCLASS);
	bool AT_K(const uint8_t _K);
	bool AT_CPIN(void);
	bool AT_CCID(void);
	bool AT_CGSN(void);
	bool AT_GSN(void);
	bool AT_GMI(void);
	bool AT_SLED(const uint8_t _SLED);
	bool AT_TXMONMODE(const uint8_t _TXMONMODE);
	bool AT_REGMODE(const uint8_t _REGMODE);
	bool AT_CREG(void);
	bool AT_CGREG(void);
	bool AT_CGDCONT(const char *_PDP, const char *_APN);
	bool AT_SCFG(const uint8_t _ConnID, const uint8_t _CID, const uint8_t _PktSz, const uint8_t _MaxTo, const uint16_t _ConnTo, const uint8_t _TxTo);
	bool AT_SGACT(void);
	bool AT_CSQ(void);
	bool AT_SERVINFO(void);
	bool AT_CCLK(void);
	bool AT_NTP(const char *_NTP_Server, const uint16_t _NTP_Port, bool _Update, const uint8_t _TimeOut, const uint8_t _TimeZone);
	bool AT_CTZU(const uint8_t _Ctzu);
	bool AT_HTTPCFG(const uint8_t _ProfID, const char *_HTTP_Server, const uint8_t _Port, const uint8_t _AuthType, const char *_Username, const char *_Password, const uint8_t _SSL, const uint8_t _TimeOut, const uint8_t _Cid);
	bool AT_HTTPSND(const uint8_t _ProfID, const uint8_t _Command, const char *_URL, const String &Data);
	bool AT_SL(const uint8_t _ConnID, const bool _State, const uint8_t _Port);
	bool AT_FRWL(const uint8_t _Action, const char *_IP);
	bool AT_SA(const uint8_t _ConnID, const uint8_t _ConnMode);
	bool AT_SH(const uint8_t _ConnID);
	bool AT_SHDN(void);
	bool AT_SRECV(const uint8_t _ConnID);
	bool AT_SCFGEXT(const uint8_t _ConnID, const uint8_t _srMode, const uint8_t _recvDataMode, const uint8_t _keepalive);
	bool AT_E2SLRI(const uint8_t _Pulse_Duration);
	
	// Utility Functions

	bool Response_Wait(uint16_t _Length, uint32_t _TimeOut);

};

extern GE910 GSM;

#endif /* defined(__GE910__) */
