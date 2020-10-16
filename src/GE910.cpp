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

// AT Command Set
bool GE910::AT(void) {
	
	/******************************************************************************
	 *	Function	: AT Command
	 *	Revision	: 01.00.00
	 *	Command		: AT\r\n (4 byte)
	 *	Response	: AT\r\n\r\nOK\r\n (10 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();
	
	// Send UART Command
	UART_IoT.println(String(F("AT")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 10) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}
	
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
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT+CMEE=")) + String(_CMEE));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 17) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}

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
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT+CMEE=")) + String(_FCLASS));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 19) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}

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
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT&K")) + String(_K));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 13) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}

}
bool GE910::AT_CPIN(void) {
	
	/******************************************************************************
	 *	Function	: AT CPIN Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CPIN?\r\n (10 byte)
	 *	Response	: AT+CPIN?\r\n\r\n+CPIN: READY\r\n\r\nOK\r\n (32 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT+CPIN?")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 32) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("READY")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}

}
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
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT#SLED=")) + String(_SLED));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 17) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}

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
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT#TXMONMODE=")) + String(_TXMONMODE));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 22) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}
}
bool GE910::AT_CGSN(void) {
	
	/******************************************************************************
	 *	Function	: AT CGSN Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CGSN\r\n (9 byte)
	 *	Response	: AT+CGSN\r\n\r\n000000000000000\r\n\r\nOK\r\n (34 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT+CGSN")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 34) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Read UART Buffer
	String _Buffer = UART_IoT.readString();

	// Parse ICCID Number
	IMEI = _Buffer.substring(11, 26);

	// End Function
	return (true);
	
}
bool GE910::AT_GSN(void) {
	
	/******************************************************************************
	 *	Function	: AT GSN Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+GSN\r\n (8 byte)
	 *	Response	: AT+GSN\r\n\r\n0000000000\r\n\r\nOK\r\n (28 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT+GSN")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 28) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Read UART Buffer
	String _Buffer = UART_IoT.readString();

	// Parse Serial Number
	IMEI = _Buffer.substring(10, 20);
	
	// End Function
	return (true);

}
bool GE910::AT_CCID(void) {
	
	/******************************************************************************
	 *	Function	: AT CCID Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#CCID\r\n (9 byte)
	 *	Response	: AT#CCID\r\n\r\n000000000000000000\r\n\r\nOK\r\n (37 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT#CCID")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 37) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Read UART Buffer
	String _Buffer = UART_IoT.readString();

	// Parse ICCID Number
	ICCID = _Buffer.substring(11, 29);
	
	// End Function
	return (true);

}
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
		UART_Flush();

		// Send UART Command
		UART_IoT.println(String(F("AT+CREG=1")));

		// Read Current Time
		long _Time = millis();

		// Wait for UART Available
		while (UART_IoT.available() < 17) {
			
			// Wait delay
			delay(1);
			
			// Handle for timeout
			if (millis() - _Time >= 1000) {
				
				// Clear UART Buffer
				UART_Flush();

				// End Function Failed
				return(false);
				
			}
			
		}

		// Analyse Respose
		if (UART_IoT.find("OK")) {

			// Set Control Variable
			_CREG_Set = true;
			
		}
		else {

			// Set Control Variable
			_CREG_Set = false;

		}

		// Handle for Error
		if (_Error_WD >= 5) return(false);

		// Count for Error
		_Error_WD++;

		// Wait on Error
		if (_CREG_Set == false) delay(500);
		
	}
	
	// Reset Error WD
	_Error_WD = 0;
	
	// Send CREG Status Read Command
	while (_CREG_Status == false) {
		
		// Clear UART Buffer
		UART_Flush();

		// Send UART Command
		UART_IoT.println(String(F("AT+CREG?")));

		// Read Current Time
		long _Time = millis();

		// Wait for UART Available
		while (UART_IoT.available() < 30) {
			
			// Wait delay
			delay(1);
			
			// Handle for timeout
			if (millis() - _Time >= 1000) {
				
				// Clear UART Buffer
				UART_Flush();

				// End Function Failed
				return(false);
				
			}
			
		}
		
		// Analyse Response
		if (UART_IoT.find("+CREG") == true) {
			
			/******************************************************************************
			 [Stat]
			 0 - Not Registered to Network
			 1 - Registered to Home Network
			 2 - Searching Network
			 3 - Registration to Network Denied
			 4 - Unknown
			 5 - Registered & Rooming
			 ******************************************************************************/
			
			// Get Response Parameters
			_Mode  = UART_IoT.parseInt();
			_Stat  = UART_IoT.parseInt();
			
			// Set Control Variable
			_CREG_Status = true;
			
			// Control for Stat
			if (_Stat == 1 or _Stat == 5) return(true);

		}
		
		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Count for Error
		_Error_WD++;

		// Wait on Error
		if (_CREG_Status == false) delay(500);

	}

	// Wait for CREG process
	if (_Stat != 1 or _Stat != 5) {
		
		// Control for Connection
		while (_CREG_Connection != true) {
			
			// Read Current Time
			long _Time = millis();

			// Wait for UART Available
			while (UART_IoT.available() < 12) {
				
				// Wait delay
				delay(1);
				
				// Handle for timeout
				if (millis() - _Time >= 1000) {
					
					// Clear UART Buffer
					UART_Flush();

					// End Function Failed
					return(false);
					
				}
				
			}

			// Wait for Response
			if (UART_IoT.find("+CREG") == true) {
				
				// Get Response Parameters
				_Stat = UART_IoT.parseInt();
				
				// Handle Stat Variable
				if (_Stat == 0) return (false);				// Not Registered
				if (_Stat == 1) _CREG_Connection = true;	// Registered to Home Network
				if (_Stat == 2) delay(10);					// Searching Network
				if (_Stat == 3) return (false);				// Registration to Network Denied
				if (_Stat == 4) return (false);				// Unknown
				if (_Stat == 5) _CREG_Connection = true;	// Registered & Rooming
				
			}
			
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
		UART_Flush();

		// Send UART Command
		UART_IoT.println(String(F("AT+CGREG=1")));

		// Read Current Time
		long _Time = millis();

		// Wait for UART Available
		while (UART_IoT.available() < 18) {
			
			// Wait delay
			delay(1);
			
			// Handle for timeout
			if (millis() - _Time >= 1000) {
				
				// Clear UART Buffer
				UART_Flush();

				// End Function Failed
				return(false);
				
			}
			
		}

		// Analyse Respose
		if (UART_IoT.find("OK")) {

			// Set Control Variable
			_CGREG_Set = true;
			
		}
		else {

			// Set Control Variable
			_CGREG_Set = false;

		}

		// Handle for Error
		if (_Error_WD >= 5) return(false);

		// Count for Error
		_Error_WD++;

		// Wait on Error
		if (_CGREG_Set == false) delay(500);
		
	}

	// Reset Error WD
	_Error_WD = 0;

	// Send CGREG Status Read Command
	while (_CGREG_Status == false) {
		
		// Clear UART Buffer
		UART_Flush();

		// Send UART Command
		UART_IoT.println(String(F("AT+CGREG?")));

		// Read Current Time
		long _Time = millis();

		// Wait for UART Available
		while (UART_IoT.available() < 32) {
			
			// Wait delay
			delay(1);
			
			// Handle for timeout
			if (millis() - _Time >= 1000) {
				
				// Clear UART Buffer
				UART_Flush();

				// End Function Failed
				return(false);
				
			}
			
		}
		
		// Analyse Response
		if (UART_IoT.find("+CGREG") == true) {
			
			/******************************************************************************
			 [Stat]
			 0 - Not Registered to Network
			 1 - Registered to Home Network
			 2 - Searching Network
			 3 - Registration to Network Denied
			 4 - Unknown
			 5 - Registered & Rooming
			 ******************************************************************************/

			// Get Response Parameters
			_Mode  = UART_IoT.parseInt();
			_Stat  = UART_IoT.parseInt();
			
			// Set Control Variable
			_CGREG_Status = true;
			
			// Control for Stat
			if (_Stat == 1 or _Stat == 5) return(true);

		}
		
		// Handle for Error
		if (_Error_WD >= 10) return(false);

		// Count for Error
		_Error_WD++;

		// Wait on Error
		if (_CGREG_Status == false) delay(500);

	}

	// Wait for CGREG process
	if (_Stat != 1 or _Stat != 5) {
		
		// Control for Connection
		while (_CGREG_Connection != true) {
			
			// Read Current Time
			long _Time = millis();

			// Wait for UART Available
			while (UART_IoT.available() < 13) {
				
				// Wait delay
				delay(1);
				
				// Handle for timeout
				if (millis() - _Time >= 1000) {
					
					// Clear UART Buffer
					UART_Flush();

					// End Function Failed
					return(false);
					
				}
				
			}

			// Wait for Response
			if (UART_IoT.find("+CGREG") == true) {
				
				// Get Response Parameters
				_Stat = UART_IoT.parseInt();
				
				// Handle Stat Variable
				if (_Stat == 0) delay(10);					// Not Registered
				if (_Stat == 1) _CGREG_Connection = true;	// Registered to Home Network
				if (_Stat == 2) delay(10);					// Searching Network
				if (_Stat == 3) return (false);				// Registration to Network Denied
				if (_Stat == 4) return (false);				// Unknown
				if (_Stat == 5) _CGREG_Connection = true;	// Registered & Rooming
				
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
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT+CGDCONT=")) + String(_Cid) + String(F(",\"")) + String(_PDP) + String(F("\",\"")) + String(_APN) + String(F("\"")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 36) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}

}
bool GE910::AT_SCFG(void) {
	
	/******************************************************************************
	 *	Function	: AT SCFG Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#SCFG=1,1,0,0,150,1\r\n (23 byte)
	 *	Response	: AT#SCFG=1,1,0,0,150,1\r\n\r\nOK\r\n (29 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT#SCFG=")) + String(_ConnID) + String(F(",")) + String(_Cid) + String(F(",")) + String(_PktSz) + String(F(",")) + String(_MaxTo) + String(F(",")) + String(_ConnTo) + String(F(",")) + String(_TxTo) + String(F(",")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 29) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// End Function Success
		return (true);
		
	}
	else {

		// Clear UART Buffer
		UART_Flush();

		// End Function Failed
		return (false);
		
	}

}
bool GE910::AT_SGACT(void) {
	
	/******************************************************************************
	 *	Function	: AT SGACT Command
	 *	Revision	: 01.00.00
	 *	Command-1	: AT#SGACT=1,0\r\n (14 byte)
	 *	Response-1	: AT#SGACT=1,0\r\n\r\nOK\r\n (20 byte)
	 *	Command-2	: AT#SGACT?\r\n (11 byte)
	 *	Response-2	: AT#SGACT?\r\n\r\n#SGACT: 1,0\r\n\r\nOK\r\n (32 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT#SGACT=")) + String(_Cid) + String(F(",0")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 20) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("OK")) {

		// Clear UART Buffer
		UART_Flush();

		// Send UART Command
		UART_IoT.println(String(F("AT#SGACT?")));

		// Read Current Time
		_Time = millis();

		// Wait for UART Available
		while (UART_IoT.available() < 32) {
			
			// Wait delay
			delay(1);
			
			// Handle for timeout
			if (millis() - _Time >= 1000) {
				
				// Clear UART Buffer
				UART_Flush();

				// End Function Failed
				return(false);
				
			}
			
		}

		// Analyse Respose
		if (UART_IoT.find("OK")) {

			// Clear UART Buffer
			UART_Flush();

			// Send UART Command
			UART_IoT.println(String(F("AT#SGACT=")) + String(_Cid) + String(F(",1")));

			// Read Current Time
			_Time = millis();

			// Wait for UART Available
			while (UART_IoT.available() < 14) {
				
				// Wait delay
				delay(1);
				
				// Handle for timeout
				if (millis() - _Time >= 1000) {
					
					// Clear UART Buffer
					UART_Flush();

					// End Function Failed
					return(false);
					
				}
				
			}

			// Analyse Respose
			if (UART_IoT.find("AT#SGACT=1,1")) {
				
				// Control for Connection
				while (_SGACT_Connection != true) {
					
					// Read Current Time
					long _Time = millis();

					// Wait for UART Available
					while (UART_IoT.available() < 25) {
						
						// Wait delay
						delay(1);
						
						// Handle for timeout
						if (millis() - _Time >= 1000) {
							
							// Clear UART Buffer
							UART_Flush();

							// End Function Failed
							return(false);
							
						}
						
					}

					// Wait for Response
					if (UART_IoT.find("SGACT:") == true) {
												
						// GET IP values
						uint8_t _IP1  = UART_IoT.parseInt();
						uint8_t _IP2  = UART_IoT.parseInt();
						uint8_t _IP3  = UART_IoT.parseInt();
						uint8_t _IP4  = UART_IoT.parseInt();
						
						// Parse IP
						IP = _IP1 + "." + _IP2 + "." + _IP3 + "." + _IP4;

						// End Function
						return (true);

					}
					
				}

			}
		}
		
	}

}
bool GE910::AT_SERVINFO(void) {
	
	/******************************************************************************
	 *	Function	: AT SERVINFO Command
	 *	Revision	: 01.00.00
	 *	Command 	: AT#SERVINFO\r\n (13 byte)
	 *	Response	: AT#SERVINFO\r\n\r\n#SERVINFO: 42,-93,"Turkcell","28601",63,855E,03,1,,"II",01,6\r\n (83 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT#SERVINFO")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 75) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("SERVINFO:")) {

		// Parse Data
		int _Band = UART_IoT.parseInt();
		Signal = UART_IoT.parseInt();
		Operator = UART_IoT.parseInt();

		// Define Band
		if ((_Band >= 259 and _Band <= 293) or (_Band >= 306 and _Band <= 340)) Band = 500;
		if (_Band >= 438 and _Band <= 511) Band = 700;
		if (_Band >= 128 and _Band <= 251) Band = 850;
		if ((_Band >= 0 and _Band <= 124) or (_Band >= 955 and _Band <= 1023)) Band = 900;
		if (_Band >= 512 and _Band <= 810) Band = 1900;
		if (_Band >= 512 and _Band <= 885) Band = 1800;

	}

	// End Function
	return (true);

}
bool GE910::AT_NTP(void) {
	
	/******************************************************************************
	 *	Function	: AT NTP Command
	 *	Revision	: 01.00.00
	 *	Command 	: AT#NTP="129.6.15.28",123,1,10\r\n (31 byte)
	 *	Response-1 	: AT#NTP="129.6.15.28",123,1,10\r\n (31 byte)
	 *	Response-2	: \r\n#NTP: 20/10/16,08:55:58\r\nOK\r\n (31 byte)
	 ******************************************************************************/

	// Define Control Variables
	bool _NTP_Set = false;
	bool _NTP_Ready = false;
	uint8_t _Error_WD = 0;

	// NTP Time Update Command
	while (_NTP_Set == false) {
	
		// Clear UART Buffer
		UART_Flush();

		// Send UART Command
		UART_IoT.println(String(F("AT#NTP=\"")) + String(_NTP_Server) + String("\",") + String(_NTP_Port) + String(",1,10"));

		// Read Current Time
		long _Time = millis();

		// Wait for UART Available
		while (UART_IoT.available() < 31) {
			
			// Wait delay
			delay(1);
			
			// Handle for timeout
			if (millis() - _Time >= 11000) {
				
				// End Function Failed
				return (false);
				
			}
			
		}

		// Analyse Response
		if (UART_IoT.find("AT#NTP=") == true) _NTP_Set = true;

		// Handle for Error
		if (_Error_WD == 10) return(false);
		
		// Count for Error
		_Error_WD++;
		
		// Wait on Error
		if (_NTP_Set == false) delay(500);

	}
	
	// Reset Error Variable
	_Error_WD = 0;

	// Wait NTP Time Set
	while (_NTP_Ready == false) {
		
		// Read Current Time
		long _Time = millis();

		// Wait for UART Available
		while (UART_IoT.available() < 31) {
			
			// Wait delay
			delay(1);
			
			// Handle for timeout
			if (millis() - _Time >= 11000) {
				
				// End Function Failed
				return (false);
				
			}
			
		}

		// Analyse Response
		if (UART_IoT.find("NTP:") == true) {
		
			// End Delay
			delay(10);

			// End Function Success
			return (true);

		}
		
		// Handle for Error
		if (_Error_WD == 10) return(false);
		
		// Count for Error
		_Error_WD++;
		
		// Wait on Error
		if (_NTP_Ready == false) delay(500);

	}
		
}
bool GE910::AT_CCLK(void) {
	
	/******************************************************************************
	 *	Function	: AT CCLK Command
	 *	Revision	: 01.00.00
	 *	Command 	: AT#CCLK?\r\n (10 byte)
	 *	Response	: AT#CCLK?\r\n\r\n#CCLK: "20/10/16,08:55:58+00.0"\r\n\r\nOK\r\n (51 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Flush();

	// Send UART Command
	UART_IoT.println(String(F("AT#CCLK?")));

	// Read Current Time
	long _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() < 51) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= 1000) {
			
			// Clear UART Buffer
			UART_Flush();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Analyse Respose
	if (UART_IoT.find("CCLK:")) {

		// Parse Data
		Year = UART_IoT.parseInt();
		Month = UART_IoT.parseInt();
		Day = UART_IoT.parseInt();
		Hour = UART_IoT.parseInt();
		Minute = UART_IoT.parseInt();
		Second = UART_IoT.parseInt();

	}

	// End Function Success
	return (true);

}

// Utility Functions
bool GE910::UART_Flush(void) {
	
	// Flush UART
	UART_IoT.flush();
	
	// Controll for UART Buffer
	while(UART_IoT.available() > 0) {
	
		// Read Buffer
		UART_IoT.read();
	
	}
	
	// Flush Delay
	delay(2);

}
