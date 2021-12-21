#ifndef __GE910_Structures__
#define __GE910_Structures__

// Software Definations
#define 	UART_IoT 		Serial3
#define 	UART_BAUD 		115200

enum GSM_Stat {
	NOT_REGISTERED,			// 0
	HOME_REGISTERED,		// 1
	SEARCHING,				// 2
	DENIED,					// 3
	UNKNOWN,				// 4
	ROAMING_REGISTERED		// 5
};
enum GSM_Status {
	NOT_CONNECTED,			// 0
	CONNECTED				// 1
};
enum GSM_Power {
	NOT_POWERED,			// 0
	POWERED					// 1
};
enum GSM_CommandStatus {
	NOT_OK,					// 0
	NOT_COMMAND,			// 1
	TIME_OUT				// 2
};

// Parameter Variable Structure
struct Parameter_Struct {
	const uint8_t 			CMEE;				// Set Numeric Error Format 		(1)
	const uint8_t 			FCLASS;				// Set Data Connection 				(0)
	const uint8_t 			K;					// Set Flow Control 				(0)
	const uint8_t 			SLED;				// Set Status LED Software Control 	(2)
	const uint8_t 			TXMONMODE;			// Set Tx LED Software Control 		(1)
	const uint8_t 			REGMODE;			//
	const char 				PDP[3];				// Set PDP Variable 				(IP)
	const char 				APN[15];			// Set APN Variable 				(internet/statikip)
	const uint8_t 			PktSz;				// Set PktSz Variable 				(0-Auto)
	const uint8_t 			MaxTo;				// Set MaxTo Variable 				(0-No Timeout)
	const uint8_t 			ConnTo;				// Set ConnTo Variable 				(150 nS)
	const uint8_t 			TxTo;				// Set TxTo Variable 				(0-No Timeout)
	const uint8_t 			Ctzu;				//
	const char 				NTP_Server[16];		// Set NTP Server Variable 			(NASA)
	const char 				HTTP_Server[16];	// Cloud Server IP
	const char 				HTTP_URL[20];		// Cloud Server URL
	const uint8_t 			HTTP_Port;			// Cloud Server Port
	const uint8_t 			srMode;
	const uint8_t 			recvDataMode;
	const uint8_t 			keepalive;
	const uint8_t			Pulse_Duration;		// E2SLRI Pulse Duration (Ring)		[50]
};

// Control Variable Structure
struct Control_Struct {
	bool 					AT;					// AT Command Control Variable
	bool 					AT_CMEE;			// AT+CMEE Command Control Variable
	bool 					AT_FCLASS;			// AT+FCLASS Command Control Variable
	bool 					AT_K;				// AT&K Command Control Variable
	bool 					AT_CPIN;			// AT+CPIN Command Control Variable
	bool 					AT_CCID;			// AT+CCID Command Control Variable
	bool 					AT_CGSN;			// AT+CGSN Command Control Variable
	bool 					AT_GSN;				// AT+GSN Command Control Variable
	bool 					AT_SLED;			// AT#SLED Command Control Variable
	bool 					AT_TXMONMODE;		// AT#MONMODE Command Control Variable
	bool 					AT_REGMODE;			// AT#REGMODE Command Control Variable
	bool 					AT_CREG;			// AT+CREG Command Control Variable
	bool 					AT_CGREG;			// AT+CGREG Command Control Variable
	bool 					AT_CGDCONT;			// AT+CGDCONT Command Control Variable
	bool 					AT_SCFG1;			// AT+SCFG Command Control Variable
	bool 					AT_SCFG2;			// AT+SCFG Command Control Variable
	bool 					AT_SGACT;			// AT+SGACT Command Control Variable
	bool 					AT_SERVINFO;		// AT+SERVINFO Command Control Variable
	bool 					AT_CSQ;				// AT+CSQ Command Control Variable
	bool 					AT_CTZU;			// AT+CTZU Command Control Variable
	bool 					AT_NTP;				// AT+NTP Command Control Variable
	bool 					AT_CCLK;			// AT+CCLK Command Control Variable
	bool 					AT_HTTPCFG;			// AT+HTTPCFG Command Control Variable
	bool 					AT_HTTPSND;			// AT+HTTPSND Command Control Variable
	bool 					AT_SL;				// AT#SL Command Control Variable
	bool 					AT_FRWL;			// AT#FRWL Command Control Variable
	bool 					AT_SA;				// AT#SA Command Control Variable
	bool 					AT_SH;				// AT#SH Command Control Variable
	bool 					AT_SRECV;			// AT#RECV Command Control Variable
	bool 					AT_SCFGEXT;
	bool 					AT_SHDN;
	bool 					AT_E2SLRI;
	bool					AT_GMI;
};

// Parameter Variable Structure
struct Interrupt_Struct {
	bool					Interrupt;			// GSM Interrupt
};

#endif
