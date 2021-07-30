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

#include <Arduino.h>

// Software Definations
#define 	UART_IoT			Serial3
#define 	UART_BAUD			115200
	
class GE910 {

public:

	// ************************************************************
	// Public Variables
	// ************************************************************

	// Function Variables
	char 					Version[9] 				= "01.17.01";		// Version Variable

	// IoT Variables
	char 					ID[11]					= "";				// ID Variable
	char 					IMEI[17]					= "";				// IMEI Variable
	char 					ICCID[21]				= "";				// ICCID Variable
	char 					IP[15]					= "";				// IP Variable
	int 						Operator				= 0;				// Operator Variable
	uint8_t					RSSI					= 0;				// RSSI Variable

	// Time Variables
	uint8_t 				Day						= 29;				// Day Variable
	uint8_t 				Month					= 10;				// Month Variable
	uint16_t 				Year					= 1923;				// Year Variable
	uint8_t 				Hour					= 0;				// Hour Variable
	uint8_t 				Minute					= 0;				// Minute Variable
	uint8_t 				Second					= 0;				// Second Variable
	
	// Control Variables
	bool						PwrMon					= false;			// Power Monitor Test Variable
	uint8_t					CREG					= NOT_REGISTERED;	// CREG Test Variable
	uint8_t					CGREG					= NOT_REGISTERED;	// CGREG Test Variable
	uint8_t					SGACT					= 0;				// SGACT Test Variable
	bool 					Connected				= NOT_CONNECTED;	// Connected Test Variable
	bool						HTTP_CFG				= false;			// HTTPCFG Variable
	int						Server_Response 		= 0;				// Server Response Variable
	String					Response				= "";
	uint8_t					Connection_Time			= 0;				// CREG and CGREG time Variable
	bool						RTC_Update				= false;
	
	// New Versipn Variables
	char						Command_Response[255]	= "";				// Full Command Response
	bool						Message					= false;			// Incomming Message Variable
	int						Request					= 0;				// Server Request Variable
	int						Socket_Incomming_Length = 0;

	// ************************************************************
	// Public Enum Definations
	// ************************************************************

	enum GSM_Stat {
		NOT_REGISTERED,		// 0
		HOME_REGISTERED,	// 1
		SEARCHING,			// 2
		DENIED,				// 3
		UNKNOWN,			// 4
		ROAMING_REGISTERED	// 5
	};
	enum GSM_Status {
		NOT_CONNECTED,		// 0
		CONNECTED			// 1
	};
	enum GSM_Power {
		NOT_POWERED,		// 0
		POWERED				// 1
	};
	enum GSM_CommandStatus {
		NOT_OK,				// 0
		NOT_COMMAND,		// 1
		TIME_OUT			// 2
	};

	// ************************************************************************************************************************
	// Public GSM Setting Variables
	// ************************************************************************************************************************
	struct Parameter_Struct {
		//------------------------------------------------------------------
		const uint8_t 		CMEE;				// Set Numeric Error Format (1)
		const uint8_t		FCLASS;				// Set Data Connection (0)
		const uint8_t 		K;					// Set Flow Control (0)
		const uint8_t 		SLED;				// Set Status LED Software Control (2)
		const uint8_t 		TXMONMODE;			// Set Tx LED Software Control (1)
		const uint8_t 		REGMODE;			//
		const char 			PDP[3];				// Set PDP Variable (IP)
		const char 			APN[15];			// Set APN Variable (internet/statikip)
		const uint8_t 		PktSz;				// Set PktSz Variable (0-Auto)
		const uint8_t 		MaxTo;				// Set MaxTo Variable (0-No Timeout)
		const uint8_t 		ConnTo;				// Set ConnTo Variable (150 nS)
		const uint8_t 		TxTo;				// Set TxTo Variable (0-No Timeout)
		const uint8_t 		Ctzu;				//
		const char 			NTP_Server[16];		// Set NTP Server Variable (NASA)
		const char 			HTTP_Server[16];	// Cloud Server IP
		const char 			HTTP_URL[20];		// Cloud Server URL
		const uint8_t 		HTTP_Port;			// Cloud Server Port
		const uint8_t		srMode;
		const uint8_t		recvDataMode;
		const uint8_t		keepalive;
		//------------------------------------------------------------------

	}; Parameter_Struct Parameter {
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
		150,										// (ConnTo) Set ConnTo Variable (150 nS)
		0,										// (TxTo) Set TxTo Variable (0-No Timeout)
		1,										// (CTZU)
		"85.199.214.98",							// (NTP_Server) Set NTP Server Variable (NASA)
		"54.216.226.171",							// (HTTP_Server) Cloud Server IP
		"/api/v1.1/p401",							// (HTTP_URL) Cloud Server URL
		80,										// (HTTP_Port) Cloud Server Port
		1,
		0,
		1
	};
	struct Control_Struct {

		//------------------------------------------------------------------
		bool AT;				// AT Command Control Variable
		bool AT_CMEE;			// AT+CMEE Command Control Variable
		bool AT_FCLASS;			// AT+FCLASS Command Control Variable
		bool AT_K;				// AT&K Command Control Variable
		bool AT_CPIN;			// AT+CPIN Command Control Variable
		bool AT_CCID;			// AT+CCID Command Control Variable
		bool AT_CGSN;			// AT+CGSN Command Control Variable
		bool AT_GSN;			// AT+GSN Command Control Variable
		bool AT_SLED;			// AT#SLED Command Control Variable
		bool AT_TXMONMODE;		// AT#MONMODE Command Control Variable
		bool AT_REGMODE;		// AT#REGMODE Command Control Variable
		bool AT_CREG;			// AT+CREG Command Control Variable
		bool AT_CGREG;			// AT+CGREG Command Control Variable
		bool AT_CGDCONT;		// AT+CGDCONT Command Control Variable
		bool AT_SCFG1;			// AT+SCFG Command Control Variable
		bool AT_SCFG2;			// AT+SCFG Command Control Variable
		bool AT_SGACT;			// AT+SGACT Command Control Variable
		bool AT_SERVINFO;		// AT+SERVINFO Command Control Variable
		bool AT_CSQ;			// AT+CSQ Command Control Variable
		bool AT_CTZU;			// AT+CTZU Command Control Variable
		bool AT_NTP;			// AT+NTP Command Control Variable
		bool AT_CCLK;			// AT+CCLK Command Control Variable
		bool AT_HTTPCFG;		// AT+HTTPCFG Command Control Variable
		bool AT_HTTPSND;		// AT+HTTPSND Command Control Variable
		bool AT_SL;				// AT#SL Command Control Variable
		bool AT_FRWL;			// AT#FRWL Command Control Variable
		bool AT_SA;				// AT#SA Command Control Variable
		bool AT_SH;				// AT#SH Command Control Variable
		bool AT_SRECV;			// AT#RECV Command Control Variable
		bool AT_SCFGEXT;
		bool AT_SHDN;
		bool AT_E2SLRI;
		//------------------------------------------------------------------

	}; Control_Struct Control {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	// ************************************************************
	// Public Functions
	// ************************************************************
	
	// Hardware Functions
	void LED(bool State);
	void Communication(bool State);
	void Power(bool State);
	void OnOff(int Time_);
	void ShutDown(int Time_);
	bool PowerMonitor(void);

	// Modem AT Command Functions
	bool AT(void);
	bool AT_CMEE(const uint8_t _CMEE);
	bool AT_FCLASS(const uint8_t _FCLASS);
	bool AT_K(const uint8_t _K);
	bool AT_CPIN(void);
	bool AT_CCID(void);
	bool AT_CGSN(void);
	bool AT_GSN(void);
	bool AT_SLED(const uint8_t _SLED);
	bool AT_TXMONMODE(const uint8_t _TXMONMODE);
	bool AT_REGMODE(const uint8_t _REGMODE);
	bool AT_CREG(void);
	bool AT_CGREG(void);
	bool AT_CGDCONT(const char *_PDP, const char *_APN);
	bool AT_SCFG(const uint8_t _ConnID, const uint8_t _PktSz, const uint8_t _MaxTo, const uint16_t _ConnTo, const uint8_t _TxTo);
	bool AT_SGACT(void);
	bool AT_CSQ(void);
	bool AT_SERVINFO(void);
	bool AT_CCLK(void);
	bool AT_NTP(const char *_NTP_Server);
	bool AT_CTZU(const uint8_t _Ctzu);
	bool AT_HTTPCFG(const char *_HTTP_Server, const uint8_t _Port);
	bool AT_HTTPSND(const char *_URL, const String &Data);
	bool AT_SL(const uint8_t _ConnID, const bool _State, const uint8_t _Port);
	bool AT_FRWL(const char *_IP);
	bool AT_SA(void);
	bool AT_SH(void);
	bool AT_SHDN(void);
	bool AT_SRECV(void);
	bool AT_SCFGEXT(const uint8_t _srMode, const uint8_t _recvDataMode, const uint8_t _keepalive);
	bool AT_E2SLRI(void);
	
	// Batch Functions
	bool Time_Update(void);												// GSM Embedded RTC Time Update Function
	bool Connection_Control(void);										// Connection Control Function
	void Connect(void);													// Connection Function
	bool Send(const String &_Data);										// Data Send Function
	bool RSSI_Refresh(void);											// RSSI Refresh Function
	void Listen(void);													// Listen UART
	void Socket_Get_Command(void);
	bool Activate(bool Status);

private:
	
	// ************************************************************
	// Private Functions
	// ************************************************************
	
	// Batch Functions
	bool Connection_AT_Batch(void);
	bool Recieve_AT_Batch(void);
		
	// Utility Functions
	bool Response_Wait(uint16_t _Length, uint32_t _TimeOut);

};

extern GE910 GSM;

#endif /* defined(__GE910__) */
