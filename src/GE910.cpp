/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *	Revision			: 1.0.0
 *
 *********************************************************************************/

#include "Arduino.h"
#include "GE910.h"

// Modem Set Functions
bool GE910::AT(void) {
	
	/******************************************************************************
	 *	Function	: AT Command
	 *	Revision	: 01.00.00
	 *	Command		: AT\r\n (4 byte)
	 *	Response	: AT\r\n\r\nOK\r\n (10 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(F("AT"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 10;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);
	
}
bool GE910::AT_CMEE(void) {
	
	/******************************************************************************
	 *	Function	: AT CMEE Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CMEE=1\r\n (11 byte)
	 *	Response	: AT+CMEE=1\r\n\r\nOK\r\n (17 byte)
	 ******************************************************************************
	 *	Parameter	: 0 Disable, 1 Numeric Format, 2 Verbose Format
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT+CMEE=")) + String(_CMEE));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 17;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}
bool GE910::AT_FCLASS(void) {
	
	/******************************************************************************
	 *	Function	: AT FCLASS Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+FCLASS=0\r\n (13 byte)
	 *	Response	: AT+FCLASS=0\r\n\r\nOK\r\n (19 byte)
	 ******************************************************************************
	 *	Parameter	: 0 Data, 1 Fax, 8 Voice
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT+FCLASS=")) + String(_FCLASS));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 19;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}
bool GE910::AT_K(void) {

	/******************************************************************************
	 *	Function	: AT K Command
	 *	Revision	: 01.00.00
	 *	Command		: AT&K0\r\n (7 byte)
	 *	Response	: AT&K0\r\n\r\nOK\r\n (13 byte)
	 ******************************************************************************
	 *	Parameter	: 0 No Flow Control, 1, 2, 3, 4, 5, 6
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT&K")) + String(_K));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 13;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}

// SIM Functions
bool GE910::AT_CPIN(void) {
	
	/******************************************************************************
	 *	Function	: AT CPIN Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CPIN?\r\n (10 byte)
	 *	Response	: AT+CPIN?\r\n\r\n+CPIN: READY\r\n\r\nOK\r\n (32 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT+CPIN?")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 32;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "READY") != NULL) return (true);

	}

	// End Function
	return (false);

}
bool GE910::AT_CCID(void) {
	
	/******************************************************************************
	 *	Function	: AT CCID Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#CCID\r\n (9 byte)
	 *	Response	: AT#CCID\r\n\r\n#CCID: 0000000000000000000\r\n\r\nOK\r\n (45 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT#CCID")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 45;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		uint8_t _Data_Order = 0;
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Data
			if (_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) {
				
				// Get Data
				ICCID[_Data_Order] = _Response[_Read_Order];

				// Increase Data Order
				_Data_Order++;

			}
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}

// Modem ID Functions
bool GE910::AT_CGSN(void) {
	
	/******************************************************************************
	 *	Function	: AT CGSN Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CGSN\r\n (9 byte)
	 *	Response	: AT+CGSN\r\n\r\n000000000000000\r\n\r\nOK\r\n (34 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT+CGSN")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 34;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		uint8_t _Data_Order = 0;
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Data
			if (_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) {
				
				// Get Data
				IMEI[_Data_Order] = _Response[_Read_Order];

				// Increase Data Order
				_Data_Order++;

			}
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);
	
}
bool GE910::AT_GSN(void) {
	
	/******************************************************************************
	 *	Function	: AT GSN Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+GSN\r\n (8 byte)
	 *	Response	: AT+GSN\r\n\r\n0000000000\r\n\r\nOK\r\n (28 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT+GSN")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 28;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		uint8_t _Data_Order = 0;
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Data
			if (_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) {
				
				// Get Data
				ID[_Data_Order] = _Response[_Read_Order];

				// Increase Data Order
				_Data_Order++;

			}
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}

// GPIO Functions
bool GE910::AT_SLED(void) {

	/******************************************************************************
	 *	Function	: AT SLED Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#SLED=2\r\n (11 byte)
	 *	Response	: AT#SLED=2\r\n\r\nOK\r\n (17 byte)
	 ******************************************************************************
	 *	Parameter	: 0 LOW, 1 HIGH, 2 Blink, 3 Blink (Manuel)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT#SLED=")) + String(_SLED));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 17;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}
bool GE910::AT_TXMONMODE(void) {

	/******************************************************************************
	 *	Function	: AT TXMONMODE Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#TXMONMODE=1\r\n (16 byte)
	 *	Response	: AT#TXMONMODE=1\r\n\r\nOK\r\n (22 byte)
	 ******************************************************************************
	 *	Parameter	: 0, 1
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT#TXMONMODE=")) + String(_TXMONMODE));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 22;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}

// GSM Connection Functions
bool GE910::AT_CREG(void) {

	/******************************************************************************
	 *	Function	: AT CREG Command
	 *	Revision	: 01.00.00
	 *	Command-1	: AT+CREG=1\r\n (11 byte)
	 *	Response-1	: AT+CREG=1\r\n\r\nOK\r\n (17 byte)
	 *	Command-2	: AT+CREG?\r\n (10 byte)
	 *	Response-2	: AT+CREG?\r\n\r\n+CREG: 1,2\r\n\r\nOK\r\n (30 byte)
	 *	Response-3	: \r\n+CREG: 2\r\n (12 byte)
	 ******************************************************************************/

	// Define Variables
	bool _CREG_Set = false;
	bool _CREG_Status = false;
	bool _CREG_Connection = false;
	uint8_t _Error_WD = 0;
	uint8_t _Mode = 0;
	uint8_t _Stat = 0;

	// Send CREG Connection Command
	while (_CREG_Set == false) {
	
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.println(String(F("AT+CREG=1")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 17;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "OK") != NULL) _CREG_Set = true;

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Wait on Error
		if (_CREG_Set == false) delay(500);

	}
	
	// Reset Error WD
	_Error_WD = 0;

	// Send CREG Status Read Command
	while (_CREG_Status == false) {
		
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.println(String(F("AT+CREG?")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 30;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "+CREG:") != NULL) {
			
				// Set Control Variable
				_CREG_Status = true;
				
				// Read Mode
				_Mode = _Response[19];
				
				// Read Stat
				_Stat = _Response[21];
				
				// Control for Stat
				if (_Stat == 49 or _Stat == 53) return(true);

			}
				
		}

		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Wait on Error
		if (_CREG_Status == false) delay(500);

	}
	
	// Control for Connection
	while (_CREG_Connection == false) {

		// Declare Variables
		uint8_t _Response_Length = 12;

		// Handle Response
		if (Response_Wait(_Response_Length, 150000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "+CREG:") != NULL) {
			
				// Read Stat
				_Stat = _Response[9];
				
				// Handle Stat Variable
				if (_Stat == 48) return (false);				// Not Registered
				if (_Stat == 49) _CREG_Connection = true;	// Registered to Home Network
				if (_Stat == 50) delay(10);					// Searching Network
				if (_Stat == 51) return (false);				// Registration to Network Denied
				if (_Stat == 52) return (false);				// Unknown
				if (_Stat == 53) _CREG_Connection = true;	// Registered & Rooming

			}
				
		} else {

			// End Function
			return(false);

		}
		
	}

	// End Function
	return(true);

}
bool GE910::AT_CGREG(void) {

	/******************************************************************************
	 *	Function	: AT CGREG Command
	 *	Revision	: 01.00.00
	 *	Command-1	: AT+CGREG=1\r\n (12 byte)
	 *	Response-1	: AT+CGREG=1\r\n\r\nOK\r\n (18 byte)
	 *	Command-2	: AT+CGREG?\r\n (11 byte)
	 *	Response-2	: AT+CGREG?\r\n\r\n+CGREG: 1,2\r\n\r\nOK\r\n (32 byte)
	 *	Response-3	: \r\n+CGREG: 1\r\n (13 byte)
	 ******************************************************************************/

	// Define Variables
	bool _CGREG_Set = false;
	bool _CGREG_Status = false;
	bool _CGREG_Connection = false;
	uint8_t _Error_WD = 0;
	uint8_t _Mode = 0;
	uint8_t _Stat = 0;

	// Send CGREG Connection Command
	while (_CGREG_Set == false) {
		
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.println(String(F("AT+CGREG=1")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 18;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "OK") != NULL) _CGREG_Set = true;

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Wait on Error
		if (_CGREG_Set == false) delay(500);
		
	}

	// Reset Error WD
	_Error_WD = 0;

	// Send CGREG Status Read Command
	while (_CGREG_Status == false) {
		
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.println(String(F("AT+CGREG?")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 32;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "+CGREG:") != NULL) {
			
				// Set Control Variable
				_CGREG_Status = true;
				
				// Read Mode
				_Mode = _Response[21];
				
				// Read Stat
				_Stat = _Response[23];
				
				// Control for Stat
				if (_Stat == 49 or _Stat == 53) return(true);

			}
				
		}

		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Wait on Error
		if (_CGREG_Status == false) delay(500);

	}
	
	// Control for Connection
	while (_CGREG_Connection == false) {

		// Declare Variables
		uint8_t _Response_Length = 13;

		// Handle Response
		if (Response_Wait(_Response_Length, 150000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "+CGREG:") != NULL) {
			
				// Read Stat
				_Stat = _Response[10];
				
				// Handle Stat Variable
				if (_Stat == 48) return (false);				// Not Registered
				if (_Stat == 49) _CGREG_Connection = true;	// Registered to Home Network
				if (_Stat == 50) delay(10);					// Searching Network
				if (_Stat == 51) return (false);				// Registration to Network Denied
				if (_Stat == 52) return (false);				// Unknown
				if (_Stat == 53) _CGREG_Connection = true;	// Registered & Rooming

			}
				
		}
		
	}

	// End Function
	return(true);

}
bool GE910::AT_CGDCONT(void) {
	
	/******************************************************************************
	 *	Function	: AT CGDCONT Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CGDCONT=1,"IP","internet"\r\n (30 byte)
	 *	Response	: AT+CGDCONT=1,"IP","internet"\r\n\r\nOK\r\n (36 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT+CGDCONT=1,\"")) + String(_PDP) + String(F("\",\"")) + String(_APN) + String(F("\"")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 36;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}
bool GE910::AT_SCFG(void) {
	
	/******************************************************************************
	 *	Function	: AT SCFG Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#SCFG=1,1,0,0,150,1\r\n (23 byte)
	 *	Response	: AT#SCFG=1,1,0,0,150,1\r\n\r\nOK\r\n (29 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT#SCFG=1,1,")) + String(_PktSz) + String(F(",")) + String(_MaxTo) + String(F(",")) + String(_ConnTo) + String(F(",")) + String(_TxTo));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 29;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}
bool GE910::AT_SGACT(void) {
	
	/******************************************************************************
	 *	Function	: AT SGACT Command
	 *	Revision	: 01.00.00
	 *	Command-1	: AT#SGACT=1,0\r\n (14 byte)
	 *	Response-1	: AT#SGACT=1,0\r\n\r\nOK\r\n (20 byte)
	 *	Command-2	: AT#SGACT=1,1\r\n (14 byte)
	 *	Response-2	: AT#SGACT?\r\n\r\n#SGACT: 1,1\r\n\r\nOK\r\n (32 byte)
	 ******************************************************************************/

	// Define Variables
	bool _SGACT_Release_IP = false;
	bool _SGACT_Get_IP = false;
	bool _SGACT_Parse_IP = false;
	uint8_t _Error_WD = 0;
	uint8_t _Cid = 0;
	uint8_t _Stat = 0;

	// Send Release IP Command
	while (_SGACT_Release_IP == false) {
	
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.println(String(F("AT#SGACT=1,0")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 20;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "OK") != NULL) _SGACT_Release_IP = true;
			if(strstr(_Response, "ERROR:") != NULL) {
			
				// End Function
				return(false);

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Wait on Error
		if (_SGACT_Release_IP == false) delay(500);

	}

	// Reset Error WD
	_Error_WD = 0;

	// Send GET IP Command
	while (_SGACT_Get_IP == false) {
	
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.println(String(F("AT#SGACT=1,1")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 14;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "SGACT") != NULL) _SGACT_Get_IP = true;
			if(strstr(_Response, "ERROR:") != NULL) {
			
				// End Function
				return(false);

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Wait on Error
		if (_SGACT_Get_IP == false) delay(500);

	}

	// Control for Connection
	while (_SGACT_Parse_IP == false) {

		// Declare Variables
		uint8_t _Response_Length = 29;

		// Handle Response
		if (Response_Wait(_Response_Length, 150000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			uint8_t _Data_Order = 0;
			char _Response[_Response_Length];

			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Handle Data
				if ((_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) or _Response[_Read_Order] == 46) {
					
					// Get Data
					IP[_Data_Order] = _Response[_Read_Order];

					// Increase Data Order
					_Data_Order++;

				}
				
				// Increase Read Order
				_Read_Order++;

			}

			// Control for Response
			if(strstr(_Response, "SGACT:") != NULL) {
			
				// Set Control Variable
				_SGACT_Parse_IP = true;

			}
			if(strstr(_Response, "ERROR:") != NULL) {
			
				// End Function
				return(false);

			}

		} else {

			// End Function
			return(false);

		}
		
	}
	
	// End Function
	return(true);
	
}

// Operotor Functions
bool GE910::AT_CSQ(void) {
	
	/******************************************************************************
	 *	Function	: AT CSQ Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CSQ\r\n (9 byte)
	 *	Response	: AT+CSQ\r\n\r\n000000000000000\r\n\r\nOK\r\n (34 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT+CSQ")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 28;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		uint8_t _Data_Order = 0;
		char _Response[_Response_Length];

		// Declare Buffer Variables
		char _RSSI[3];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Data
			if ((_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) or _Response[_Read_Order] == 45) {
				
				// Get Data
				_RSSI[_Data_Order] = _Response[_Read_Order];

				// Increase Data Order
				_Data_Order++;

			}
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Convert Variable
		RSSI = (uint8_t)atoi(_RSSI);

		// Control for Response
		if(strstr(_Response, "CSQ") != NULL) return (true);

	}

	// End Function
	return (false);
	
}
bool GE910::AT_SERVINFO(void) {
	
	/******************************************************************************
	 *	Function	: AT SERVINFO Command
	 *	Revision	: 01.00.00
	 *	Command 	: AT#SERVINFO\r\n (13 byte)
	 *	Response	: AT#SERVINFO\r\n\r\n#SERVINFO: 42,-93,"Turkcell","28601",63,855E,03,1,,"II",01,6\r\n (83 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT#SERVINFO")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 60;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Parse DBM
		char _Buffer[2];
		_Buffer[0] = _Response[30];
		_Buffer[1] = _Response[31];
		dBM = (uint8_t)atoi(_Buffer);

		// Parse Operator
		if(strstr(_Response, "28601") != NULL) Operator = 28601;
		if(strstr(_Response, "28602") != NULL) Operator = 28602;
		if(strstr(_Response, "28603") != NULL) Operator = 28603;
		if(strstr(_Response, "28604") != NULL) Operator = 28604;

		// Control for Response
		if(strstr(_Response, "#SERVINFO:") != NULL) return (true);

	}

	// End Function
	return (false);

}

// RTC Functions
bool GE910::AT_CCLK(void) {
	
	/******************************************************************************
	 *	Function	: AT CCLK Command
	 *	Revision	: 01.00.00
	 *	Command 	: AT#CCLK?\r\n (10 byte)
	 *	Response	: AT#CCLK?\r\n\r\n#CCLK: "20/10/16,08:55:58+00.0"\r\n\r\nOK\r\n (51 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT#CCLK?")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 51;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Declare Buffer
		char _Buffer[2];

		// Parse Year
		_Buffer[0] = _Response[20];
		_Buffer[1] = _Response[21];
		Year = (uint8_t)atoi(_Buffer);

		// Parse Month
		_Buffer[0] = _Response[23];
		_Buffer[1] = _Response[24];
		Month = (uint8_t)atoi(_Buffer);

		// Parse Day
		_Buffer[0] = _Response[26];
		_Buffer[1] = _Response[27];
		Day = (uint8_t)atoi(_Buffer);

		// Parse Hour
		_Buffer[0] = _Response[29];
		_Buffer[1] = _Response[30];
		Hour = (uint8_t)atoi(_Buffer);

		// Parse Minute
		_Buffer[0] = _Response[32];
		_Buffer[1] = _Response[33];
		Minute = (uint8_t)atoi(_Buffer);

		// Parse Second
		_Buffer[0] = _Response[35];
		_Buffer[1] = _Response[36];
		Second = (uint8_t)atoi(_Buffer);

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}
bool GE910::AT_NTP(void) {
	
	/******************************************************************************
	 *	Function	: AT NTP Command
	 *	Revision	: 01.00.00
	 *	Command 	: AT#NTP="129.6.15.28",123,1,10\r\n (31 byte)
	 *	Response-1 	: AT#NTP="129.6.15.28",123,1,10\r\n (31 byte)
	 *	Response-2	: \r\n#NTP: 20/10/16,08:55:58\r\nOK\r\n (31 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(String(F("AT#NTP=\"")) + String(_NTP_Server) + String(F("\",123,1,3")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 50 + String(_NTP_Server).length();
	
	// Handle Response
	if (Response_Wait(_Response_Length, 4000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);
		if(strstr(_Response, "ERROR") != NULL) return (false);

	}

	// End Function
	return (false);
		
}
bool GE910::AT_CTZU(void) {
	
	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.println(F("AT+CTZU=1"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 17;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);

}

// Data Functions
bool GE910::AT_HTTPCFG(void) {
	
	/******************************************************************************
	 *	Function	: AT HTTPCFG Command
	 *	Revision	: 01.00.00
	 *	Command 	: AT#HTTPCFG=1,"xxx.xxx.xxx.xxx",80,0,"","",0,60,1\r\n ( byte)
	 *	Response	: AT#CCLK?\r\n\r\n#CCLK: "20/10/16,08:55:58+00.0"\r\n\r\nOK\r\n (51 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(String(F("AT#HTTPCFG=1,\"")));
	UART_IoT.print(String(_HTTP_Server));
	UART_IoT.print(String(F("\",")));
	UART_IoT.print(String(_HTTP_Port));
	UART_IoT.println(String(F(",0,\"\",\"\",0,60,1")));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 41 + String(_HTTP_Server).length();
	
	// Handle Response
	if (Response_Wait(_Response_Length, 60000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) return (true);

	}

	// End Function
	return (false);
}
bool GE910::AT_HTTPSND(String _Data) {
	
	/******************************************************************************
	 *	Function	: AT HTTPSND Command
	 *	Revision	: 01.00.00
	 *	Command		:  (4 byte)
	 *	Response	:  (10 byte)
	 ******************************************************************************/

	// Declare Variable
	bool _HTTP_Command = false;
	bool _HTTP_Prompt = false;
	bool _HTTP_Ring = false;
	bool _HTTP_Rcv = false;
	uint8_t _Error_WD = 0;
	
	// Send HTTPSND Command
	while (_HTTP_Command == false) {
	
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(String(F("AT#HTTPSND=1,0,\"")));
		UART_IoT.print(String(_HTTP_URL));
		UART_IoT.print(String(F("\",")));
		UART_IoT.print(String(_Data.length()));
		UART_IoT.println(String(F(",\"application/json\"")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 60;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "HTTPSND") != NULL) _HTTP_Command = true;

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}
	
	// Reset Error WD
	_Error_WD = 0;

	// Control for Prompt
	while (_HTTP_Prompt == false) {

		// Declare Variables
		uint8_t _Response_Length = 3;

		// Handle Response
		if (Response_Wait(_Response_Length, 150000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, ">>>") != NULL) {
			
				// Set Control Variable
				_HTTP_Prompt = true;

				// Send Delay
				delay(20);
				
				// Print Data
				UART_IoT.print(_Data);
				
			}
				
		}
		
	}

	// Control for Ring
	while (_HTTP_Ring == false) {

		// Declare Variables
		uint8_t _Response_Length = 56;

		// Handle Response
		if (Response_Wait(_Response_Length, 60000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "200") != NULL) _HTTP_Ring = true;

		}
		
	}
	
	// Send HTTPSND Command
	while (_HTTP_Rcv == false) {
	
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.println(String(F("AT#HTTPRCV=1")));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 52;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Variables
			uint8_t _Read_Order = 0;
			char _Response[_Response_Length];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "\"result\":\"0\"") != NULL) return(false);
			if(strstr(_Response, "\"result\":\"1\"") != NULL) {

				// Set Control Variable
				_HTTP_Rcv = true;

				// Set Variable
				Recorded = true;
				
			}
			if(strstr(_Response, "\"result\":\"2\"") != NULL) return(false);

		} else {
			
			// End Function
			return(false);
		
		}
		
	}

	// End Function
	return(true);

}

// Utility Functions
void GE910::UART_Clear(void) {
	
	// Control for UART Buffer
	while(UART_IoT.available() > 0) {
	
		// Read Buffer
		UART_IoT.read();
	
	}
	
	// Clear Delay
	delay(1);

}
bool GE910::Response_Wait(uint8_t _Length, uint16_t _TimeOut) {
	
	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < _Length) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= _TimeOut) return(false);
		
	}
	
	// End Function
	return(true);

}

// Public Functions
bool GE910::Connect(void) {
	
	// Start AT Command Sequence
	if (Connected == false) {
		
		// Declare Variable
		bool _Process_Control = false;
		bool AT_Command_Confirmation[16] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
		
		// ************************************************************
		// 1- IoT AT Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[0] = true;
				
			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}
		
		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 2- IoT CMEE Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_CMEE() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[1] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 3- IoT FCLASS Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_FCLASS() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[2] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 4- IoT K Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_K() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[3] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 5- IoT CPIN Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_CPIN() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[4] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;

		// ************************************************************
		// 6- IoT CGSN Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_CGSN() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[5] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;

		// ************************************************************
		// 7- IoT GSN Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_GSN() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[6] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;

		// ************************************************************
		// 8- IoT CCID Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_CCID() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[7] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;

		// ************************************************************
		// 9- IoT SLED Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_SLED() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[8] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 10- IoT TXMONMODE Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_TXMONMODE() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[9] = true;
				
			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 11- IoT CREG Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_CREG() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[10] = true;
				
			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 12- IoT CGREG Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_CGREG() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[11] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 13- IoT CGDCONT Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_CGDCONT() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[12] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 14- IoT SCFG Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_SCFG() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[13] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 15- IoT SGACT Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_SGACT() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[14] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// ************************************************************
		// 16- IoT SERVINFO Command
		// ************************************************************
		while (_Process_Control == false) {
			
			// Process Command
			if (AT_SERVINFO() == true) {
				
				// Set Command Response
				_Process_Control = true;
				
				// Set Confirmation
				AT_Command_Confirmation[15] = true;

			} else {
				
				// Set Command Response
				_Process_Control = false;

			}

		}

		// Set Control Variable
		_Process_Control = false;
		
		// GSM Delay
		delay(100);
		
		// Control for IoT AT Confirmation
		if (AT_Command_Confirmation[0] and AT_Command_Confirmation[1] and AT_Command_Confirmation[2] and AT_Command_Confirmation[3] and AT_Command_Confirmation[4] and AT_Command_Confirmation[5] and AT_Command_Confirmation[6] and AT_Command_Confirmation[7] and AT_Command_Confirmation[8] and AT_Command_Confirmation[9] and AT_Command_Confirmation[10] and AT_Command_Confirmation[11] and AT_Command_Confirmation[12] and AT_Command_Confirmation[13]) {
			
			// Set Global Variable
			Connected = true;
			
			// End Function
			return(true);

		}
		
	} else {

		// Set Global Variable
		Connected = true;

		// End Function
		return(true);

	}
	
}
bool GE910::Time_Update(void) {

	// Time Zone Update
	AT_CTZU();
	
	// Update RTC
	AT_NTP();

	// Get Time
	AT_CCLK();

	Time_Updated = true;
	
}
