/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *
 *********************************************************************************/

#include "Arduino.h"
#include <GE910.h>
#include <avr/pgmspace.h>

// Modem AT Command Functions
bool GE910::AT(void) {
		
	/******************************************************************************
	 *	Function	: AT Command
	 *	Revision	: 02.00.03
	 *	Command		: AT\r\n (4 byte)
	 *	Response	: AT\r\n\r\nOK\r\n (10 byte)
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(10, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);
			
		}

		// Control for Command
		if(strstr(_Response, "AT") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, NOT_OK);

				// Set Control Variable
				Control.AT = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, NOT_COMMAND);

			// Set Control Variable
			Control.AT = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_CMEE(uint8_t _CMEE) {
	
	/******************************************************************************
	 *	Function	: AT CMEE Command
	 *	Revision	: 02.00.03
	 *	Command		: AT+CMEE=1\r\n (11 byte)
	 *	Response	: AT+CMEE=1\r\n\r\nOK\r\n (17 byte)
	 ******************************************************************************
	 *	Parameter	: 0 Disable, 1 Numeric Format, 2 Verbose Format
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT+CMEE=")); UART_IoT.print(String(_CMEE)); UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(17, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT+CMEE=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_CMEE = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_CMEE = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_CMEE = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_CMEE = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_FCLASS(uint8_t _FCLASS) {
	
	/******************************************************************************
	 *	Function	: AT FCLASS Command
	 *	Revision	: 02.00.02
	 *	Command		: AT+FCLASS=0\r\n (13 byte)
	 *	Response	: AT+FCLASS=0\r\n\r\nOK\r\n (19 byte)
	 ******************************************************************************
	 *	Parameter	: 0 Data, 1 Fax, 8 Voice
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT+FCLASS=")); UART_IoT.print(String(_FCLASS)); UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(19, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT+FCLASS=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_FCLASS = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_FCLASS = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_FCLASS = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_FCLASS = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_K(uint8_t _K) {

	/******************************************************************************
	 *	Function	: AT K Command
	 *	Revision	: 02.00.03
	 *	Command		: AT&K0\r\n (7 byte)
	 *	Response	: AT&K0\r\n\r\nOK\r\n (13 byte)
	 ******************************************************************************
	 *	Parameter	: 0 No Flow Control, 1, 2, 3, 4, 5, 6
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT&K")); UART_IoT.print(String(_K)); UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(13, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT&K") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_K = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_K = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_K = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_K = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_CPIN(void) {
	
	/******************************************************************************
	 *	Function	: AT CPIN Command
	 *	Revision	: 02.00.03
	 *	Command		: AT+CPIN?\r\n (10 byte)
	 *	Response	: AT+CPIN?\r\n\r\n+CPIN: READY\r\n\r\nOK\r\n (32 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT+CPIN?\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(32, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
		
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT+CPIN?") != NULL) {

			// Control for Response
			if(strstr(_Response, "READY") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_CPIN = true;
				
				// End Function
				return (true);

			} else if (strstr(_Response, "+CME ERROR: 10") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, "NoSIM");

				// Set Control Variable
				Control.AT_CPIN = false;

				// End Function
				return (false);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_CPIN = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_CPIN = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_CPIN = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_CCID(void) {
	
	/******************************************************************************
	 *	Function	: AT CCID Command
	 *	Revision	: 02.00.02
	 *	Command		: AT#CCID\r\n (9 byte)
	 *	Response	: AT#CCID\r\n\r\n#CCID: 0000000000000000000\r\n\r\nOK\r\n (45 byte)
	 ******************************************************************************/

	// Control for SIM
	if (Control.AT_CPIN) {
		
		// Command Chain Delay (Advice by Telit)
		delay(10);

		// Clear Response Variable
		memset(Command_Response, 0, sizeof(Command_Response));

		// Clear UART Buffer
		while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

		// Send UART Command
		UART_IoT.print(F("AT#CCID\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Handle Response
		if (Response_Wait(45, 1000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Data Order Variable
			uint8_t _Data_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];
			
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
				
				// Stream Delay
				delay(1);

			}

			// Control for Command
			if(strstr(_Response, "AT#CCID") != NULL) {

				// Control for Response
				if(strstr(_Response, "OK") != NULL) {

					// Set Response Variable
					strcpy(Command_Response, _Response);

					// Set Control Variable
					Control.AT_CCID = true;
					
					// End Function
					return (true);

				} else {

					// Set Response Variable
					strcpy(Command_Response, (char*)NOT_OK);

					// Set Control Variable
					Control.AT_CCID = false;

					// End Function
					return (false);

				}

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_COMMAND);

				// Set Control Variable
				Control.AT_CCID = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)TIME_OUT);

			// Set Control Variable
			Control.AT_CCID = false;

			// End Function
			return (false);

		}

		// End Function
		return (false);
		
	} else {

		// Set Control Variable
		Control.AT_CCID = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_CGSN(void) {
	
	/******************************************************************************
	 *	Function	: AT CGSN Command
	 *	Revision	: 02.00.02
	 *	Command		: AT+CGSN\r\n (9 byte)
	 *	Response	: AT+CGSN\r\n\r\n000000000000000\r\n\r\nOK\r\n (34 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT+CGSN\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(34, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Data Order Variable
		uint8_t _Data_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
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
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT+CGSN") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_CGSN = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_CGSN = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_CGSN = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_CGSN = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_GSN(void) {
	
	/******************************************************************************
	 *	Function	: AT GSN Command
	 *	Revision	: 02.00.02
	 *	Command		: AT+GSN\r\n (8 byte)
	 *	Response	: AT+GSN\r\n\r\n0000000000\r\n\r\nOK\r\n (28 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT+GSN\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(28, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Data Order Variable
		uint8_t _Data_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
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
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT+GSN") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_GSN = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_GSN = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_GSN = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_GSN = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_SLED(uint8_t _SLED) {

	/******************************************************************************
	 *	Function	: AT SLED Command
	 *	Revision	: 02.00.02
	 *	Command		: AT#SLED=2\r\n (11 byte)
	 *	Response	: AT#SLED=2\r\n\r\nOK\r\n (17 byte)
	 ******************************************************************************
	 *	Parameter	: 0 LOW, 1 HIGH, 2 Blink, 3 Blink (Manuel)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SLED=")); UART_IoT.print(String(_SLED)); UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(17, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#SLED=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_SLED = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_SLED = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SLED = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SLED = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_TXMONMODE(uint8_t _TXMONMODE) {

	/******************************************************************************
	 *	Function	: AT TXMONMODE Command
	 *	Revision	: 02.00.02
	 *	Command		: AT#TXMONMODE=1\r\n (16 byte)
	 *	Response	: AT#TXMONMODE=1\r\n\r\nOK\r\n (22 byte)
	 ******************************************************************************
	 *	Parameter	: 0, 1
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#TXMONMODE=")); UART_IoT.print(String(_TXMONMODE)); UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(22, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#TXMONMODE=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_TXMONMODE = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_TXMONMODE = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_TXMONMODE = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_TXMONMODE = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_REGMODE(uint8_t _REGMODE) {

	/******************************************************************************
	 *	Function	: AT REGMODE Command
	 *	Revision	: 02.00.02
	 *	Command		: AT#REGMODE=1\r\n (14 byte)
	 *	Response	: AT#REGMODE=1\r\n\r\nOK\r\n (20 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#REGMODE=")); UART_IoT.print(String(_REGMODE)); UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(20, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#REGMODE=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_REGMODE = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_REGMODE = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_REGMODE = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_REGMODE = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_CREG(void) {

	/******************************************************************************
	 *	Function	: AT CREG Command
	 *	Revision	: 02.00.02
	 ******************************************************************************/
	
	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Declare Control Variable
	bool _Control = false;
	
	// Declare WD Variable
	uint8_t _Error_WD = 0;

	// Declare Stat Variable
	uint8_t _Stat = 0;

	// ****************************************************************************
	// Set Registration Mode : (AT+CREG=2)
	// ****************************************************************************
	// Command		: AT+CREG=1\r\n (11 byte)
	// Response		: AT+CREG=1\r\n\r\nOK\r\n (17 byte)
	// ****************************************************************************

	// Send AT+CREG=1 Connection Command
	while (!_Control) {
	
		// Clear UART Buffer
		while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

		// Send UART Command
		UART_IoT.print(F("AT+CREG=1\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Handle Response
		if (Response_Wait(17, 1000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
				// Stream Delay
				delay(1);

			}

			// Control for Command
			if(strstr(_Response, "AT+CREG=") != NULL) {

				// Control for Response
				if(strstr(_Response, "OK") != NULL) {

					// Set Control Variable
					_Control = true;

				} else {

					// Set Control Variable
					_Control = false;

				}

			} else {

				// Set Control Variable
				_Control = false;

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}

	// Reset Control Variable
	_Control = false;
	
	// Reset WD Variable
	_Error_WD = 0;

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// ****************************************************************************
	// CREG:
	// ****************************************************************************
	// Response		: \r\n+CREG: 1\r\n (12 byte)
	// ****************************************************************************

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Control for Connection
	while (!_Control) {
	
		// Handle Response
		if (Response_Wait(12, 300000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];

			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;

				// Stream Delay
				delay(1);

			}

			// Set Response Variable
			strcpy(Command_Response, _Response);

			// Control for Response
			if(strstr(_Response, "+CREG:") != NULL) {
			
				// Read Stat
				_Stat = _Response[9];
				
				// Handle Stat Variable
				if (_Stat == 48) {
					
					// Network Not Registered
					
					// Set Variable
					CREG = NOT_REGISTERED;
					
					// Set Control Variable
					Control.AT_CREG = false;

					// Set Control Variable
					_Control = false;

				} // Not Registered [0]
				if (_Stat == 49) {
					
					// Network Registered Home Network

					// Set Variable
					CREG = HOME_REGISTERED;
					
					// Set Control Variable
					Control.AT_CREG = true;

					// Set Control Variable
					_Control = true;
					
				} // Registered to Home Network [1]
				if (_Stat == 50) {
					
					// Still Searching Network
					
					// Set Variable
					CREG = SEARCHING;
					
					// Set Control Variable
					Control.AT_CREG = false;

					// Set Control Variable
					_Control = false;

				} // Searching Network [2]
				if (_Stat == 51) {
					
					// Network Registration Denied
					
					// Set Variable
					CREG = DENIED;
					
					// Set Control Variable
					Control.AT_CREG = false;

					// Set Control Variable
					_Control = false;

				} // Registration Denied [3]
				if (_Stat == 52) {
					
					// Unknown Error
					
					// Set Variable
					CREG = UNKNOWN;
					
					// Set Control Variable
					Control.AT_CREG = false;

					// End Function
					return(false);
					
				} // Unknown Error [4]
				if (_Stat == 53) {
					
					// Network Registered Rooming

					// Set Variable
					CREG = ROAMING_REGISTERED;
					
					// Set Control Variable
					Control.AT_CREG = true;

					// Set Control Variable
					_Control = true;

				} // Registered to Rooming Network [5]

			}
			
		}
	
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 3) return(false);

	}

	// Control for Response
	if (CREG == HOME_REGISTERED or CREG == ROAMING_REGISTERED) return(true);

	// End Function
	return(false);
	
}
bool GE910::AT_CGREG(void) {

	/******************************************************************************
	 *	Function	: AT CGREG Command
	 *	Revision	: 02.00.01
	 ******************************************************************************/

	// Control for CREG
	if (CREG == HOME_REGISTERED or CREG == ROAMING_REGISTERED) {

		// Command Chain Delay (Advice by Telit)
		delay(10);

		// Declare Control Variable
		bool _Control = false;
		
		// Declare WD Variable
		uint8_t _Error_WD = 0;

		// Declare Stat Variable
		uint8_t _Stat = 0;

		// ****************************************************************************
		// Set Registration Mode : (AT+CGREG=1)
		// ****************************************************************************
		// Command		: AT+CGREG=1\r\n (12 byte)
		// Response		: AT+CGREG=1\r\n\r\nOK\r\n (18 byte)
		// ****************************************************************************

		// Send AT+CGREG=1 Connection Command
		while (!_Control) {
		
			// Clear UART Buffer
			while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

			// Send UART Command
			UART_IoT.print(F("AT+CGREG=1\r\n"));

			// Wait for UART Data Send
			UART_IoT.flush();

			// Handle Response
			if (Response_Wait(18, 1000)) {

				// Declare Read Order Variable
				uint8_t _Read_Order = 0;

				// Declare Response Variable
				char _Response[UART_IoT.available()];
				
				// Read UART Response
				while(UART_IoT.available() > 0) {

					// Read Serial Char
					_Response[_Read_Order] = UART_IoT.read();
					
					// Increase Read Order
					_Read_Order++;
					
					// Stream Delay
					delay(1);

				}

				// Control for Command
				if(strstr(_Response, "AT+CGREG=") != NULL) {

					// Control for Response
					if(strstr(_Response, "OK") != NULL) {

						// Set Control Variable
						_Control = true;

					} else {

						// Set Control Variable
						_Control = false;

					}

				} else {

					// Set Control Variable
					_Control = false;

				}

			}
			
			// Count for Error
			_Error_WD++;

			// Handle for Error
			if (_Error_WD >= 10) return(false);

		}

		// Reset Control Variable
		_Control = false;
		
		// Reset WD Variable
		_Error_WD = 0;

		// Command Chain Delay (Advice by Telit)
		delay(10);

		// ****************************************************************************
		// CGREG:
		// ****************************************************************************
		// Response		: \r\n+CGREG: 2\r\n (13 byte)
		// ****************************************************************************

		// Clear Response Variable
		memset(Command_Response, 0, sizeof(Command_Response));

		// Control for Connection
		while (!_Control) {
		
			// Handle Response
			if (Response_Wait(13, 300000)) {

				// Declare Read Order Variable
				uint8_t _Read_Order = 0;

				// Declare Response Variable
				char _Response[UART_IoT.available()];

				// Read UART Response
				while(UART_IoT.available() > 0) {

					// Read Serial Char
					_Response[_Read_Order] = UART_IoT.read();
					
					// Increase Read Order
					_Read_Order++;

					// Stream Delay
					delay(1);

				}

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Control for Response
				if(strstr(_Response, "+CGREG:") != NULL) {
				
					// Read Stat
					_Stat = _Response[10];
					
					// Handle Stat Variable
					if (_Stat == 48) {
						
						// Network Not Registered
						
						// Set Variable
						CGREG = NOT_REGISTERED;
						
						// Set Control Variable
						Control.AT_CGREG = false;

						// Set Control Variable
						_Control = false;

					} // Not Registered [0]
					if (_Stat == 49) {
						
						// Network Registered Home Network

						// Set Variable
						CGREG = HOME_REGISTERED;
						
						// Set Control Variable
						Control.AT_CGREG = true;

						// Set Control Variable
						_Control = true;
						
					} // Registered to Home Network [1]
					if (_Stat == 50) {
						
						// Still Searching Network
						
						// Set Variable
						CGREG = SEARCHING;
						
						// Set Control Variable
						Control.AT_CGREG = false;

						// Set Control Variable
						_Control = false;

					} // Searching Network [2]
					if (_Stat == 51) {
						
						// Network Registration Denied
						
						// Set Variable
						CGREG = DENIED;
						
						// Set Control Variable
						Control.AT_CGREG = false;

						// Set Control Variable
						_Control = false;

					} // Registration Denied [3]
					if (_Stat == 52) {
						
						// Unknown Error
						
						// Set Variable
						CGREG = UNKNOWN;
						
						// Set Control Variable
						Control.AT_CGREG = false;

						// Set Control Variable
						_Control = false;

					} // Unknown Error [4]
					if (_Stat == 53) {
						
						// Network Registered Rooming

						// Set Variable
						CGREG = ROAMING_REGISTERED;
						
						// Set Control Variable
						Control.AT_CGREG = true;

						// Set Control Variable
						_Control = true;

					} // Registered to Rooming Network [5]

				}

			}
		
			// Count for Error
			_Error_WD++;

			// Handle for Error
			if (_Error_WD >= 3) return(false);

		}

		// Control for Response
		if (CGREG == HOME_REGISTERED or CGREG == ROAMING_REGISTERED) return(true);
		
	}
	
	// End Function
	return(false);
	
}
bool GE910::AT_CGDCONT(char *_PDP, char *_APN) {
	
	/******************************************************************************
	 *	Function	: AT CGDCONT Command
	 *	Revision	: 02.00.01
	 *	Command		: AT+CGDCONT=1,"IP","internet"\r\n (30 byte)
	 *	Response	: AT+CGDCONT=1,"IP","internet"\r\n\r\nOK\r\n (36 byte)
	 ******************************************************************************/

	// Control for CREG and CGREG
	if ((CREG == HOME_REGISTERED or CREG == ROAMING_REGISTERED) and (CGREG == HOME_REGISTERED or CGREG == ROAMING_REGISTERED)) {

		// Command Chain Delay (Advice by Telit)
		delay(10);

		// Clear Response Variable
		memset(Command_Response, 0, sizeof(Command_Response));

		// Clear UART Buffer
		while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

		// Send UART Command
		UART_IoT.print(F("AT+CGDCONT=1,\""));
		UART_IoT.print(String(_PDP));
		UART_IoT.print(F("\",\""));
		UART_IoT.print(String(_APN));
		UART_IoT.print(F("\""));
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Handle Response
		if (Response_Wait(32, 1000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
				// Stream Delay
				delay(1);

			}

			// Control for Command
			if(strstr(_Response, "AT+CGDCONT=") != NULL) {

				// Control for Response
				if(strstr(_Response, "OK") != NULL) {

					// Set Response Variable
					strcpy(Command_Response, _Response);

					// Set Control Variable
					Control.AT_CGDCONT = true;
					
					// End Function
					return (true);

				} else {

					// Set Response Variable
					strcpy(Command_Response, (char*)NOT_OK);

					// Set Control Variable
					Control.AT_CGDCONT = false;

					// End Function
					return (false);

				}

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_COMMAND);

				// Set Control Variable
				Control.AT_CGDCONT = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)TIME_OUT);

			// Set Control Variable
			Control.AT_CGDCONT = false;

			// End Function
			return (false);

		}

	}
	
	// End Function
	return (false);

}
bool GE910::AT_SCFG(uint8_t _ConnID, uint8_t _PktSz, uint8_t _MaxTo, uint8_t _ConnTo, uint8_t _TxTo) {
	
	/******************************************************************************
	 *	Function	: AT SCFG Command
	 *	Revision	: 02.00.01
	 *	Command		: AT#SCFG=1,1,0,0,150,1\r\n (23 byte)
	 *	Response	: AT#SCFG=1,1,0,0,150,1\r\n\r\nOK\r\n (29 byte)
	 ******************************************************************************/

	// Control for CREG and CGREG
	if ((CREG == HOME_REGISTERED or CREG == ROAMING_REGISTERED) and (CGREG == HOME_REGISTERED or CGREG == ROAMING_REGISTERED)) {

		// Command Chain Delay (Advice by Telit)
		delay(10);

		// Clear Response Variable
		memset(Command_Response, 0, sizeof(Command_Response));

		// Clear UART Buffer
		while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

		// Send UART Command
		UART_IoT.print(F("AT#SCFG="));
		UART_IoT.print(String(_ConnID));
		UART_IoT.print(F(",1,"));
		UART_IoT.print(String(_PktSz));
		UART_IoT.print(F(","));
		UART_IoT.print(String(_MaxTo));
		UART_IoT.print(F(","));
		UART_IoT.print(String(_ConnTo));
		UART_IoT.print(F(","));
		UART_IoT.print(String(_TxTo));
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Handle Response
		if (Response_Wait(29, 1000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
				// Stream Delay
				delay(1);

			}

			// Control for Command
			if(strstr(_Response, "AT#SCFG=") != NULL) {

				// Control for Response
				if(strstr(_Response, "OK") != NULL) {

					// Set Response Variable
					strcpy(Command_Response, _Response);

					// Set Control Variable
					Control.AT_SCFG1 = true;
					Control.AT_SCFG2 = true;

					// End Function
					return (true);

				} else {

					// Set Response Variable
					strcpy(Command_Response, (char*)NOT_OK);

					// Set Control Variable
					Control.AT_SCFG1 = false;
					Control.AT_SCFG2 = false;

					// End Function
					return (false);

				}

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_COMMAND);

				// Set Control Variable
				Control.AT_SCFG1 = false;
				Control.AT_SCFG2 = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)TIME_OUT);

			// Set Control Variable
			Control.AT_SCFG1 = false;
			Control.AT_SCFG2 = false;

			// End Function
			return (false);

		}

	}

}
bool GE910::AT_SGACT(void) {
	
	/******************************************************************************
	 *	Function	: AT SGACT Command
	 *	Revision	: 02.00.01
	 ******************************************************************************/

	// Control for CREG and CGREG
	if ((CREG == HOME_REGISTERED or CREG == ROAMING_REGISTERED) and (CGREG == HOME_REGISTERED or CGREG == ROAMING_REGISTERED)) {

		// Command Chain Delay (Advice by Telit)
		delay(10);

		// Reset Variables
		uint8_t _Error_WD = 0;
		bool _Control = false;

		// Clear Response Variable
		memset(Command_Response, 0, sizeof(Command_Response));

		// ****************************************************************************
		// Relase IP : (AT#SGACT=1,0)
		// ****************************************************************************
		// Command 		: AT#SGACT=1,0\r\n (14 byte)
		// Response 	: AT#SGACT=1,0\r\n\r\nOK\r\n (20 byte)
		// ****************************************************************************

		// Send AT#SGACT=1,0 Release IP Command
		while (_Control == false) {

			// Clear UART Buffer
			while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

			// Send UART Command
			UART_IoT.print(F("AT#SGACT=1,0"));
			UART_IoT.print(F("\r\n"));

			// Wait for UART Data Send
			UART_IoT.flush();

			// Handle Response
			if (Response_Wait(20, 2000)) {

				// Declare Read Order Variable
				uint8_t _Read_Order = 0;

				// Declare Response Variable
				char _Response[UART_IoT.available()];
				
				// Read UART Response
				while(UART_IoT.available() > 0) {

					// Read Serial Char
					_Response[_Read_Order] = UART_IoT.read();
					
					// Increase Read Order
					_Read_Order++;
					
					// Stream Delay
					delay(1);

				}

				// Control for Command
				if(strstr(_Response, "AT#SGACT=1,0") != NULL) {

					// Control for Response
					if(strstr(_Response, "OK") != NULL) _Control = true;

				} else {

					// Set Response Variable
					strcpy(Command_Response, (char*)NOT_COMMAND);

				}

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)TIME_OUT);

			}
			
			// Count for Error
			_Error_WD++;

			// Handle for Error
			if (_Error_WD >= 10) return(false);

		}
		
		// Reset Variables
		_Error_WD = 0;
		_Control = false;

		// Command Chain Delay (Advice by Telit)
		delay(50);

		// ****************************************************************************
		// Relase IP : (AT#SGACT=1,1)
		// ****************************************************************************
		// Command		: AT#SGACT=1,1\r\n (14 byte)
		// Response		: AT#SGACT?\r\n\r\n#SGACT: 1,1\r\n\r\nOK\r\n (32 byte)
		// ****************************************************************************

		// Send AT#SGACT=1,1 Get IP Command
		while (_Control == false) {
		
			// Clear UART Buffer
			while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

			// Send UART Command
			UART_IoT.print(F("AT#SGACT=1,1"));
			UART_IoT.print(F("\r\n"));

			// Wait for UART Data Send
			UART_IoT.flush();

			// Handle Response
			if (Response_Wait(14, 2000)) {

				// Declare Read Order Variable
				uint8_t _Read_Order = 0;

				// Declare Response Variable
				char _Response[UART_IoT.available()];
				
				// Read UART Response
				while(UART_IoT.available() > 0) {

					// Read Serial Char
					_Response[_Read_Order] = UART_IoT.read();
					
					// Increase Read Order
					_Read_Order++;
					
					// Stream Delay
					delay(1);

				}

				// Control for Command
				if(strstr(_Response, "AT#SGACT=1,1") != NULL) {

					// Control for Response
					_Control = true;

				} else {

					// Set Response Variable
					strcpy(Command_Response, (char*)NOT_COMMAND);

				}

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)TIME_OUT);

			}

			// Count for Error
			_Error_WD++;

			// Handle for Error
			if (_Error_WD >= 10) return(false);

		}

		// Reset Variables
		_Error_WD = 0;
		_Control = false;

		// Command Chain Delay (Advice by Telit)
		delay(50);

		// ****************************************************************************
		// SGACT
		// ****************************************************************************
		// Response		: \r\n#SGACT: x.x.x.x\r\n\r\nOK\r\n (25 byte)
		// ****************************************************************************

		// Control for Connection
		while (_Control == false) {
			
			// Handle Response
			if (Response_Wait(25, 2000)) {

				// Declare Read Order Variable
				uint8_t _Read_Order = 0;

				// Declare Data Order Variable
				uint8_t _Data_Order = 0;

				// Declare Response Variable
				char _Response[UART_IoT.available()];
				
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
					
					// Stream Delay
					delay(1);

				}

				// Control for Command
				if(strstr(_Response, "#SGACT:") != NULL) {

					// Set Variable
					SGACT = 1;
					_Control = true;
					
					// Set Response Variable
					strcpy(Command_Response, _Response);

					// Set Control Variable
					Control.AT_SGACT = true;

					// End Function
					return(true);

				} else if (strstr(_Response, "+CME ERROR: 553") != NULL) {

					// Set Variable
					SGACT = 1;
					_Control = true;
					
					// Set Response Variable
					strcpy(Command_Response, _Response);

					// Set Control Variable
					Control.AT_SGACT = true;

					// End Function
					return(true);

				} else {

					// Set Response Variable
					strcpy(Command_Response, (char*)NOT_COMMAND);

					// Set Control Variable
					Control.AT_SGACT = false;

					// Set Variable
					SGACT = 0;

					// End Function
					return(false);

				}

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)TIME_OUT);

				// Set Control Variable
				Control.AT_SGACT = false;

			}
			
			// Count for Error
			_Error_WD++;

			// Handle for Error
			if (_Error_WD >= 10) return(false);

		}
		
	}

	// End Function
	return(false);
	
}
bool GE910::AT_CSQ(void) {
	
	/******************************************************************************
	 *	Function	: AT CSQ Command
	 *	Revision	: 02.00.01
	 *	Command		: AT+CSQ\r\n (9 byte)
	 *	Response	: AT+CSQ\r\n\r\n+CSQ: 9,0\r\n\r\nOK\r\n (27 byte)
	 ******************************************************************************/

	
	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT+CSQ\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(27, 1000)) {

		// Declare Buffer Variables
		char _RSSI[2];

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		uint8_t _Data_Order = 0;
		bool _Comma = false;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();

			// Handle ,
			if (_Response[_Read_Order] == 44 ) _Comma = true;

			// Handle Comma
			if (_Comma == false) {
				
				// Handle Data
				if (_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) {
					
					// Get Data
					_RSSI[_Data_Order] = _Response[_Read_Order];

					// Increase Data Order
					_Data_Order++;

				}

			}

			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "+CSQ:") != NULL) {

			// Set Response Variable
			strcpy(Command_Response, _Response);

			// Convert Variable
			RSSI = atoi(_RSSI);

			// Set Control Variable
			Control.AT_CSQ = true;
			
			// End Function
			return (true);

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_CSQ = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_CSQ = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_SERVINFO(void) {
	
	/******************************************************************************
	 *	Function	: AT SERVINFO Command
	 *	Revision	: 02.00.01
	 *	Command 	: AT#SERVINFO\r\n (13 byte)
	 *	Response	: AT#SERVINFO\r\n\r\n#SERVINFO: 42,-93,"Turkcell","28601",63,855E,03,1,,"II",01,6\r\n (77 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SERVINFO\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(60, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[100];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "#SERVINFO:") != NULL) {

			// Control for Response
			if(strstr(_Response, "28601") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Operator Code
				Operator = 28601;
				
				// Set Control Variable
				Control.AT_SERVINFO = true;
				
				// End Function
				return (true);

			}
			else if (strstr(_Response, "28602") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Operator Code
				Operator = 28602;
				
				// Set Control Variable
				Control.AT_SERVINFO = true;
				
				// End Function
				return (true);

			}
			else if (strstr(_Response, "28603") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Operator Code
				Operator = 28603;
				
				// Set Control Variable
				Control.AT_SERVINFO = true;
				
				// End Function
				return (true);

			}
			else if (strstr(_Response, "28604") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Operator Code
				Operator = 28604;
				
				// Set Control Variable
				Control.AT_SERVINFO = true;
				
				// End Function
				return (true);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SERVINFO = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SERVINFO = false;

		// End Function
		return (false);

	}
	
}
bool GE910::AT_CTZU(uint8_t _Ctzu) {

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT+CTZU=")); UART_IoT.print(String(_Ctzu)); UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(17, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT+CTZU=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_CTZU = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_CTZU = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_CTZU = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_CTZU = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_NTP(char *_NTP_Server) {
	
	/******************************************************************************
	 *	Function	: AT NTP Command
	 *	Revision	: 01.00.01
	 *	Command 	: AT#NTP="129.6.15.28",123,1,10\r\n (31 byte)
	 *	Response-1 	: AT#NTP="129.6.15.28",123,1,10\r\n (31 byte)
	 *	Response-2	: \r\n#NTP: 20/10/16,08:55:58\r\nOK\r\n (31 byte)
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#NTP=\""));
	UART_IoT.print(String(_NTP_Server));
	UART_IoT.print(F("\",123,1,3\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();
	
	// Declare Variables
	uint16_t _Response_Length = 50 + String(Parameter.NTP_Server).length();
	
	// Handle Response
	if (Response_Wait(19, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Request Delay
		delay(3000);
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "#NTP:") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_NTP = true;

				// Declare Buffer
				char _Buffer[2];
				
				// Parse Year
				_Buffer[0] = _Response[27 + String(Parameter.NTP_Server).length()];
				_Buffer[1] = _Response[28 + String(Parameter.NTP_Server).length()];
				Year = 2000 + (uint8_t)atoi(_Buffer);
				
				// Parse Month
				_Buffer[0] = _Response[30 + String(Parameter.NTP_Server).length()];
				_Buffer[1] = _Response[31 + String(Parameter.NTP_Server).length()];
				Month = (uint8_t)atoi(_Buffer);
				if (Month < 1 or Month > 12) Month = 1;

				// Parse Day
				_Buffer[0] = _Response[33 + String(Parameter.NTP_Server).length()];
				_Buffer[1] = _Response[34 + String(Parameter.NTP_Server).length()];
				Day = (uint8_t)atoi(_Buffer);
				if (Day < 1 or Day > 31) Day = 1;

				// Parse Hour
				_Buffer[0] = _Response[36 + String(Parameter.NTP_Server).length()];
				_Buffer[1] = _Response[37 + String(Parameter.NTP_Server).length()];
				Hour = (uint8_t)atoi(_Buffer);
				if (Hour < 0 or Hour > 24) Hour = 1;

				// Parse Minute
				_Buffer[0] = _Response[39 + String(Parameter.NTP_Server).length()];
				_Buffer[1] = _Response[40 + String(Parameter.NTP_Server).length()];
				Minute = (uint8_t)atoi(_Buffer);
				if (Minute < 0 or Minute > 60) Minute = 1;

				// Parse Second
				_Buffer[0] = _Response[42 + String(Parameter.NTP_Server).length()];
				_Buffer[1] = _Response[43 + String(Parameter.NTP_Server).length()];
				Second = (uint8_t)atoi(_Buffer);
				if (Second < 0 or Second > 60) Second = 1;
				
				// End Function
				return (true);

			}

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_OK);

			// Set Control Variable
			Control.AT_NTP = false;

			// End Function
			return (false);

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_NTP = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_NTP = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_CCLK(void) {
	
	/******************************************************************************
	 *	Function	: AT CCLK Command
	 *	Revision	: 02.00.01
	 *	Command 	: AT#CCLK?\r\n (10 byte)
	 *	Response	: AT#CCLK?\r\n\r\n#CCLK: "20/10/16,08:55:58+00.0"\r\n\r\nOK\r\n (51 byte)
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#CCLK?\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();
		
	// Handle Response
	if (Response_Wait(51, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#CCLK") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_CCLK = true;

				// Declare Buffer
				char _Buffer[2];
				
				// Parse Year
				_Buffer[0] = _Response[20];
				_Buffer[1] = _Response[21];
				Year = 2000 + (uint8_t)atoi(_Buffer);
				
				// Parse Month
				_Buffer[0] = _Response[23];
				_Buffer[1] = _Response[24];
				Month = (uint8_t)atoi(_Buffer);
				if (Month < 1 or Month > 12) Month = 1;

				// Parse Day
				_Buffer[0] = _Response[26];
				_Buffer[1] = _Response[27];
				Day = (uint8_t)atoi(_Buffer);
				if (Day < 1 or Day > 31) Day = 1;

				// Parse Hour
				_Buffer[0] = _Response[29];
				_Buffer[1] = _Response[30];
				Hour = (uint8_t)atoi(_Buffer);
				if (Hour < 0 or Hour > 24) Hour = 1;

				// Parse Minute
				_Buffer[0] = _Response[32];
				_Buffer[1] = _Response[33];
				Minute = (uint8_t)atoi(_Buffer);
				if (Minute < 0 or Minute > 60) Minute = 1;

				// Parse Second
				_Buffer[0] = _Response[35];
				_Buffer[1] = _Response[36];
				Second = (uint8_t)atoi(_Buffer);
				if (Second < 0 or Second > 60) Second = 1;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_CCLK = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_CCLK = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_CCLK = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_HTTPCFG(char *_HTTP_Server, uint8_t _Port) {
	
	/******************************************************************************
	 *	Function	: AT HTTPCFG Command
	 *	Revision	: 02.00.01
	 *	Command 	: AT#HTTPCFG=1,"xxx.xxx.xxx.xxx",80,0,"","",0,60,1\r\n (49 byte)
	 *	Response	: AT#CCLK?\r\n\r\n#CCLK: "20/10/16,08:55:58+00.0"\r\n\r\nOK\r\n (51 byte)
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#HTTPCFG=1,\""));
	UART_IoT.print(String(_HTTP_Server));
	UART_IoT.print(F("\","));
	UART_IoT.print(String(_Port));
	UART_IoT.print(F(",0,\"\",\"\",0,60,1"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();
	
	// Declare Variables
	uint8_t _Response_Length = 37 + String(_HTTP_Server).length() + String(_Port).length();

	// Handle Response
	if (Response_Wait(_Response_Length, 60000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#HTTPCFG=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_HTTPCFG = true;
				
				// Set HTTP Configuration
				HTTP_CFG = true;

				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_HTTPCFG = false;

				// Set HTTP Configuration
				HTTP_CFG = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_HTTPCFG = false;

			// Set HTTP Configuration
			HTTP_CFG = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_HTTPCFG = false;

		// Set HTTP Configuration
		HTTP_CFG = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_HTTPSND(char *_URL, const String &Data) {
	
	/******************************************************************************
	 *	Function	: AT HTTPSND Command
	 *	Revision	: 02.00.01
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Declare Control Variable
	bool _Control = false;
	uint8_t _Error_WD = 0;

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// ****************************************************************************
	// Command		: AT#HTTPSND=1,0,"/api/v1.0/p511ba",427,"application/json"\r\n (39 byte)
	// Response		: \r\n (17 byte)
	// ****************************************************************************

	// Send AT#HTTPSND Command
	while (_Control == false) {
	
		// Clear UART Buffer
		while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

		// Send UART Command
		UART_IoT.print(F("AT#HTTPSND=1,0,\"")); // 16
		UART_IoT.print(String(_URL));
		UART_IoT.print(F("\",")); // 2
		UART_IoT.print(Data.length());
		UART_IoT.print(F(",\"application/json\"")); // 19
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 39 + String(_URL).length() + String(Data.length()).length();

		// Handle Response
		if (Response_Wait(_Response_Length, 5000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
				// Stream Delay
				delay(1);

			}

			// Control for Command
			if(strstr(_Response, "AT#HTTPSND=") != NULL) {

				// Set Control Variable
				_Control = true;

			} else {

				// Set Control Variable
				_Control = false;

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}
	
	// Reset Control Variable
	_Control = false;
	_Error_WD = 0;

	// Send AT#HTTPSND Command
	while (_Control == false) {
	
		// Handle Response
		if (Response_Wait(5, 60000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
				// Stream Delay
				delay(1);

			}

			// Control for Command
			if(strstr(_Response, ">>>") != NULL) {
				
				// Send Delay
				delay(50);
				
				// Print Data
				UART_IoT.print(Data);

				// Send Delay
				delay(50);

				// Handle Response
				if (Response_Wait(6, 5000)) {
				
					// Declare Read Order Variable
					uint8_t _Read_Order = 0;

					// Declare Response Variable
					char _Response[UART_IoT.available()];
					
					// Read UART Response
					while(UART_IoT.available() > 0) {

						// Read Serial Char
						_Response[_Read_Order] = UART_IoT.read();
						
						// Increase Read Order
						_Read_Order++;
						
						// Stream Delay
						delay(1);

					}

					// Control for Command
					if(strstr(_Response, "\r\nOK\r\n") != NULL) {

						// Set Control Variable
						_Control = true;

					}

				}

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}

	// Reset Control Variable
	_Control = false;
	_Error_WD = 0;

	// Control for RING Command
	while (_Control == false) {
	
		// Handle Response
		if (Response_Wait(40, 6000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[45];

			// UART Delay
			delay(100);

			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
				// Stream Delay
				delay(1);

			}

			// Control for Command
			if(strstr(_Response, "200") != NULL) {

				// Set Control Variable
				_Control = true;
				
				// Send Delay
				delay(50);
				
			} else {

				// Set Control Variable
				_Control = false;

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 3) return(false);

	}

	// Reset Control Variable
	_Control = false;
	_Error_WD = 0;

	// Send AT#HTTPSND Command
	while (_Control == false) {
	
		// Clear UART Buffer
		while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

		// Send UART Command
		UART_IoT.print(F("AT#HTTPRCV=1\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Handle Variable Defination
		bool _Handle = false;
		
		// Response Delay
		delay(500);
		
		// Reset Response Variable
		Response = "";

		// Handle Response
		if (Response_Wait(38, 5000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[UART_IoT.available()];
			
			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Handle Response
				if (_Response[_Read_Order] == 123) _Handle = true;
				if (_Response[_Read_Order] == 125) _Handle = false;

				// Response String
				if (_Handle) Response += _Response[_Read_Order];

				// Increase Read Order
				_Read_Order++;
				
				// Stream Delay
				delay(1);

			}

			// Handle Update
			Response += "}";

			// Clear Response
			Server_Response = 0;

			// Set Response Variable
			Response.toCharArray(Command_Response, Response.length() + 1);

			// Control for Command
			if(strstr(_Response, "500") != NULL) {

				// Set Control Variable
				_Control = true;

				// Set Variable
				Server_Response = 500;

				// Set Control Variable
				Control.AT_HTTPSND = true;

				// End Function
				return(true);

			} else {

				// Set Control Variable
				_Control = false;

				// Set Variable
				Server_Response = 0;

				// Set Control Variable
				Control.AT_HTTPSND = false;

				// End Function
				return(false);

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}

	// Set Control Variable
	Control.AT_HTTPSND = false;

	// End Function
	return(false);

}
bool GE910::AT_SHDN(void) {
	
	/******************************************************************************
	 *	Function	: AT#SHDN Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#SHDN\r\n (9 byte)
	 *	Response	: AT#SHDN\r\n\r\nOK\r\n (15 byte)
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SHDN\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(15, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#SHDN") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Clear Variables
				PwrMon = NOT_POWERED;
				CREG = NOT_REGISTERED;
				CGREG = NOT_REGISTERED;
				Connected = NOT_CONNECTED;

				// Set Control Variable
				Control.AT_SHDN = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_SHDN = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SHDN = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SHDN = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_SL(uint8_t _ConnID, bool _State, uint8_t _Port) {
	
	/******************************************************************************
	 *	Function	: AT SL Command
	 *	Revision	: 01.00.01
	 *	Command		: AT#SL=1,1,80\r\n (14 byte)
	 *	Response	: AT#SL=1,1,80\r\n\r\nOK\r\n (20 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SL="));
	UART_IoT.print(_ConnID);
	UART_IoT.print(F(","));
	UART_IoT.print(_State);
	UART_IoT.print(F(","));
	UART_IoT.print(_Port);
	UART_IoT.print(F(",255\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(24, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#SL=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_SL = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_SL = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SL = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SL = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_FRWL(const String &_IP) {
	
	/******************************************************************************
	 *	Function	: AT FRWL Command
	 *	Revision	: 01.00.01
	 *	Command		: AT#FRWL=1,"213.14.250.214","255.255.255.0"\r\n (44 byte)
	 *	Response	: AT#FRWL=1,"213.14.250.214","255.255.255.0"\r\n\r\nOK\r\n (50 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#FRWL=1,\""));
	UART_IoT.print(_IP);
	UART_IoT.print(F("\",\"255.255.255.0\"\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 36 + String(_IP).length();

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#FRWL=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_FRWL = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_FRWL = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_FRWL = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_FRWL = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_SA(void) {
	
	/******************************************************************************
	 *	Function	: AT SA Command
	 *	Revision	: 01.00.01
	 *	Command		:
	 *	Response	:
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SA=2,1\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(33, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		uint8_t _Data_Order = 0;
		bool _Comma = false;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Declare Incomming Message Length Variable
		char _Incomming_Length[4];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Data
			if (_Read_Order > 20) {

				if (_Comma == true and _Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) {
					
					// Get Data
					_Incomming_Length[_Data_Order] = _Response[_Read_Order];

					// Increase Data Order
					_Data_Order++;

				}

				// Handle ,
				if (_Response[_Read_Order] == 44 ) _Comma = true;

			}
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "SRING:") != NULL) {

			// Reset Variable
			Socket_Incomming_Length = 0;

			// Convert Variable
			Socket_Incomming_Length = atoi(_Incomming_Length);

			// Set Response Variable
			strcpy(Command_Response, _Response);

			// Set Control Variable
			Control.AT_SA = true;
			
			// End Function
			return (true);

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_OK);

			// Set Control Variable
			Control.AT_SA = false;

			// End Function
			return (false);

		}
		
	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SA = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_SRECV(void) {
	
	/******************************************************************************
	 *	Function	: AT SRECV Command
	 *	Revision	: 01.00.01
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SRECV=2,"));
	UART_IoT.print(String(Socket_Incomming_Length));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Response Length Variable
	uint16_t _Length = Socket_Incomming_Length + 41;
	
	// Command Delay
	delay(30);
	
	// Handle Response
	if (Response_Wait(_Length, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Declare Handle Variable
		bool _Handle = false;
		
		// Reset Response Variable
		Response = "";

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Response
			if (_Response[_Read_Order] == 123) _Handle = true;

			// Response String
			if (_Handle) Response += _Response[_Read_Order];

			// Handle Response
			if (_Response[_Read_Order] == 125) _Handle = false;

			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);
			
		}

		// Handle Update
		Response += "}";

		// Set Response Variable
		Response.toCharArray(Command_Response, Response.length() + 1);

		// Control for Command
		if(strstr(_Response, "#SRECV:") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Control Variable
				Control.AT_SRECV = true;

				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_SRECV = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SRECV = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SRECV = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_SCFGEXT(uint8_t _srMode, uint8_t _recvDataMode, uint8_t _keepalive) {
	
	/******************************************************************************
	 *	Function	: AT SCFGEXT Command
	 *	Revision	: 01.00.01
	 *	Command		: AT#SCFGEXT=2,1,0,1\r\n (20 byte)
	 *	Response	: AT#SCFGEXT=2,1,0,1\r\n\r\nOK\r\n (26 byte)
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SCFGEXT=2,"));
	UART_IoT.print(String(_srMode));
	UART_IoT.print(F(","));
	UART_IoT.print(String(_recvDataMode));
	UART_IoT.print(F(","));
	UART_IoT.print(String(_keepalive));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(25, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#SCFGEXT=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_SCFGEXT = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_SCFGEXT = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SCFGEXT = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SCFGEXT = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_SH(void) {
	
	/******************************************************************************
	 *	Function	: AT SH Command
	 *	Revision	: 01.00.01
	 *	Command		:
	 *	Response	:
	 ******************************************************************************/

	// Command Chain Delay (Advice by Telit)
	delay(10);

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SH=2\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(15, 4000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#SH") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_SH = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_SH = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SH = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SH = false;

		// End Function
		return (false);

	}

}
bool GE910::AT_E2SLRI(void) {
		
	/******************************************************************************
	 *	Function	: AT E2SLRI Command
	 *	Revision	: 01.00.01
	 *	Command		:
	 *	Response	:
	 ******************************************************************************/

	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#E2SLRI=1150\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(21, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);
			
		}

		// Control for Command
		if(strstr(_Response, "#E2SLRI=") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Set Control Variable
				Control.AT_E2SLRI = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_E2SLRI = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_E2SLRI = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_E2SLRI = false;

		// End Function
		return (false);

	}

}

// Utility Functions
bool GE910::Response_Wait(uint16_t _Length, uint16_t _TimeOut) {
	
	// Read Current Time
	uint32_t _Time = millis();

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

// Batch Functions
bool GE910::Time_Update(void) {
	
	// ************************************************************
	// 1- IoT CTZU Command
	// ************************************************************

	// Declare Variable
	uint8_t _Error_WD = 0;

	// Process Command
	while (!Control.AT_CTZU) {

		// Process Command
		AT_CTZU(1);
		
		// Set WD Variable
		_Error_WD++;

		// Control for WD
		if (_Error_WD > 2) break;

	}

	// ************************************************************
	// 1- IoT NTP Command
	// ************************************************************

	// Reset WD Error Variable
	_Error_WD = 0;

	while (!Control.AT_NTP) {
		
		// Process Command
		AT_NTP(Parameter.NTP_Server);
		
		// Set WD Variable
		_Error_WD++;

		// Control for WD
		if (_Error_WD > 2) break;

	}

	// ************************************************************
	// End Function
	// ************************************************************

	if (Year == 1923) {
		
		// End Function
		return(false);

	} else {
		
		// End Function
		return(true);

	}

}
bool GE910::Connection_Control(void) {
	
	// ****************************************************************************
	// Function	: AT SGACT Command
	// Revision	: 01.03.00
	// ****************************************************************************
	// Command		: AT#SGACT=?\r\n (14 byte)
	// Response		: AT#SGACT?\r\n\r\n#SGACT: x,y\r\n\r\nOK\r\n (32 byte)
	// ****************************************************************************
	
	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Clear UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();delay(3);

	// Send UART Command
	UART_IoT.print(F("AT#SGACT?\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Handle Response
	if (Response_Wait(30, 1000)) {

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
			// Stream Delay
			delay(1);

		}

		// Control for Command
		if(strstr(_Response, "AT#SGACT?") != NULL) {

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Response Variable
				strcpy(Command_Response, _Response);

				// Read Stat
				SGACT = _Response[23];

				// Handle SGACT Variable
				if (SGACT == 48) {
					
					// Set Variable
					Connected = NOT_CONNECTED;
					
					// End Function
					return(false);
					
				}
				if (SGACT == 49) {
					
					// Set Variable
					Connected = CONNECTED;

					// End Function
					return(true);
					
				}
				
				// Set Control Variable
				Control.AT_SGACT = true;
				
				// End Function
				return (true);

			} else {

				// Set Response Variable
				strcpy(Command_Response, (char*)NOT_OK);

				// Set Control Variable
				Control.AT_SGACT = false;

				// End Function
				return (false);

			}

		} else {

			// Set Response Variable
			strcpy(Command_Response, (char*)NOT_COMMAND);

			// Set Control Variable
			Control.AT_SGACT = false;

			// End Function
			return (false);

		}

	} else {

		// Set Response Variable
		strcpy(Command_Response, (char*)TIME_OUT);

		// Set Control Variable
		Control.AT_SGACT = false;

		// End Function
		return (false);

	}

	// Set Variable
	Connected = NOT_CONNECTED;

	// End Function
	return (false);
	
}
bool GE910::Connection_AT_Batch(void) {
	
	// Control Power Monitor
	PowerMonitor();
	
	// Control for Power Monitor
	if (PwrMon) {

		// Control for Connection
		if (!Connected) {
			
			// ************************************************************
			// IoT AT Command
			// ************************************************************
			
			// Declare Variable
			uint8_t _Error_WD = 0;

			// Process Command
			while (!Control.AT) {

				// Process Command
				AT();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}
			
			// End Function
			if (!Control.AT) return(false);

			// ************************************************************
			// IoT CMEE Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_CMEE) {
				
				// Process Command
				AT_CMEE(Parameter.CMEE);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}

			// End Function
			if (!Control.AT_CMEE) return(false);

			// ************************************************************
			// IoT FCLASS Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_FCLASS) {
				
				// Process Command
				AT_FCLASS(Parameter.FCLASS);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}

			// End Function
			if (!Control.AT_FCLASS) return(false);

			// ************************************************************
			// IoT K Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_K) {
				
				// Process Command
				AT_K(Parameter.K);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;


			}

			// End Function
			if (!Control.AT_K) return(false);

			// ************************************************************
			// IoT CPIN Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_CPIN) {
				
				// Process Command
				AT_CPIN();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}

			// End Function
			if (!Control.AT_CPIN) return(false);

			// ************************************************************
			// IoT CGSN Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_CGSN) {
				
				// Process Command
				AT_CGSN();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}

			// End Function
			if (!Control.AT_CGSN) return(false);

			// ************************************************************
			// IoT GSN Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_GSN) {
				
				// Process Command
				AT_GSN();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}
		
			// End Function
			if (!Control.AT_GSN) return(false);

			// ************************************************************
			// IoT CCID Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_CCID) {
				
				// Process Command
				AT_CCID();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}

			// End Function
			if (!Control.AT_CCID) return(false);

			// ************************************************************
			// IoT SLED Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_SLED) {
				
				// Process Command
				AT_SLED(Parameter.SLED);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}

			// End Function
			if (!Control.AT_SLED) return(false);

			// ************************************************************
			// IoT TXMONMODE Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_TXMONMODE) {
				
				// Process Command
				AT_TXMONMODE(Parameter.TXMONMODE);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}
			
			// End Function
			if (!Control.AT_TXMONMODE) return(false);

			// ************************************************************
			// IoT CREG Command
			// ************************************************************

			// Read Current Time
			uint32_t _CTime = millis();

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_CREG) {
				
				// Process Command
				AT_CREG();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 3) break;

			}

			// End Function
			if (!Control.AT_CREG) return(false);

			// ************************************************************
			// IoT CGREG Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_CGREG) {
				
				// Process Command
				AT_CGREG();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 3) break;

			}
						
			// End Function
			if (!Control.AT_CGREG) return(false);

			// Read Current Time
			uint32_t _CRTime = millis() - _CTime;
			Connection_Time = uint8_t(_CRTime / 1000);

			// ************************************************************
			// IoT CGDCONT Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_CGDCONT) {
				
				// Process Command
				AT_CGDCONT(Parameter.PDP, Parameter.APN);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 3) break;

			}

			// End Function
			if (!Control.AT_CGDCONT) return(false);

			// ************************************************************
			// IoT SCFG Command 1
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;
			Control.AT_SCFG1 = false;

			while (!Control.AT_SCFG1) {
				
				// Process Command
				AT_SCFG(1, Parameter.PktSz, Parameter.MaxTo, Parameter.ConnTo, Parameter.TxTo);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 3) break;

			}

			// End Function
			if (!Control.AT_SCFG1) return(false);

			// ************************************************************
			// IoT SCFG Command 2
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;
			Control.AT_SCFG2 = false;

			while (!Control.AT_SCFG2) {
				
				// Process Command
				AT_SCFG(2, 0, 0, 400, 0);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 3) break;

			}

			// End Function
			if (!Control.AT_SCFG2) return(false);

			// ************************************************************
			// IoT SCFGEXT Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_SCFGEXT) {
				
				// Process Command
				AT_SCFGEXT(Parameter.srMode, Parameter.recvDataMode, Parameter.keepalive);
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 5) break;

			}

			// End Function
			if (!Control.AT_SCFGEXT) return(false);

			// ************************************************************
			// IoT SGACT Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_SGACT) {
				
				// Process Command
				AT_SGACT();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 3) break;

			}

			// End Function
			if (!Control.AT_SGACT) return(false);

			// ************************************************************
			// IoT SERVINFO Command
			// ************************************************************

			// Reset WD Error Variable
			_Error_WD = 0;

			while (!Control.AT_SERVINFO) {
				
				// Process Command
				AT_SERVINFO();
				
				// Set WD Variable
				_Error_WD++;

				// Control for WD
				if (_Error_WD > 3) break;

			}

			// End Function
			if (!Control.AT_SERVINFO) return(false);

			// ************************************************************
			// End Function
			// ************************************************************

			if (sizeof(IP) >= 7) {
				
				// Set Variable
				Connected = CONNECTED;
				
				// End Function
				return(true);
				
			} else {

				// Set Variable
				Connected = NOT_CONNECTED;

				// End Function
				return(false);
				
			}
			
		}

	}
	
}
bool GE910::Recieve_AT_Batch(void) {
	
	// ************************************************************
	// Socket Listen Command
	// ************************************************************

	// Declare WD Error Variable
	uint8_t _Error_WD = 0;

	while (!Control.AT_SL) {
		
		// Process Command
		AT_SL(2, true, 80);
		
		// Set WD Variable
		_Error_WD++;

		// Control for WD
		if (_Error_WD > 3) break;

	}

	// ************************************************************
	// Firewall Config Command
	// ************************************************************

	// Declare WD Error Variable
	_Error_WD = 0;

	while (!Control.AT_FRWL) {
		
		// Process Command
		AT_FRWL("213.14.250.214");
		
		// Set WD Variable
		_Error_WD++;

		// Control for WD
		if (_Error_WD > 3) break;

	}

	// ************************************************************
	// SL Ring Config Command
	// ************************************************************

	// Declare WD Error Variable
	_Error_WD = 0;

	while (!Control.AT_E2SLRI) {
		
		// Process Command
		AT_E2SLRI();
		
		// Set WD Variable
		_Error_WD++;

		// Control for WD
		if (_Error_WD > 3) break;

	}

	// ************************************************************
	// End Function
	// ************************************************************

	// End Function
	return(true);

}
void GE910::Connect(void) {
	
	// Activate IoT Modem
	if (Activate(true) and !Connected) {
		
		// Activate IoT Modem
		if (Connection_AT_Batch()) {
			
			// Update GE910 RTC
			Time_Update();
			
			// Set Socket Status
			Recieve_AT_Batch();
			
			// Set HTTP Configuration
			if (HTTP_CFG == false) if (AT_HTTPCFG(Parameter.HTTP_Server, Parameter.HTTP_Port) == true) HTTP_CFG = true;

		} else {

			// GSM Connect Sound

		}
		
	}

}
bool GE910::Send(const String &_Data) {

	// Control Power Mon
	if (!PowerMonitor()) Connect();
	
	// Control Connection
	if (Connection_Control() == true) {

		// Control HTTP Configuration
		if (!HTTP_CFG) AT_HTTPCFG(Parameter.HTTP_Server, Parameter.HTTP_Port);

		// Check For UART
		Listen();
		
		// Send Data
		AT_HTTPSND(Parameter.HTTP_URL, _Data);
		
		// End Function
		return(true);
		
	}

	// End Function
	return(false);

}
bool GE910::RSSI_Refresh(void) {
	
	// Reset Control Variable
	Control.AT_CSQ = false;
	uint8_t _Error_WD = 0;

	while (!Control.AT_CSQ) {
		
		// Process Command
		if (AT_CSQ() == true) {
			
			// Set Command Response
			Control.AT_CSQ = true;
			
			// End Function
			return(true);

		} else {
			
			// Set Command Response
			Control.AT_CSQ = false;

			// Set WD Variable
			_Error_WD++;

		}

		// Control for WD
		if (_Error_WD > 2) break;

	}
	
	// Handle RSSI
	if (!Control.AT_CSQ) RSSI = 0;
	
	// End Function
	return(false);
	
}
void GE910::Listen(void) {

	/******************************************************************************
	 *	Function	: GSM UART Listen Function
	 *	Revision	: 01.00.00
	 ******************************************************************************/

	// Control for Incoming Message
	if (UART_IoT.available() > 0) {

		// Clear Response Variable
		memset(Command_Response, 0, sizeof(Command_Response));

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[UART_IoT.available()];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;

			// Stream Delay
			delay(1);

		}

		// Set Response Variable
		strcpy(Command_Response, _Response);

		// Control for Response
		if(strstr(_Response, "SRING: 2") != NULL) {

			// Reset Variable
			Request = 0;

			// Socket Answer Command
			AT_SA();

			// Socket Recieve Command
			AT_SRECV();
			
			// Start Pump Command
			if (strstr(Command_Response, "{\"Event\":256}") != NULL) Request = 256;
			
			// Stop Pump Command
			if (strstr(Command_Response, "{\"Event\":257}") != NULL) Request = 257;
			
			// Update Data
			if (strstr(Command_Response, "{\"Event\":262}") != NULL) Request = 262;

			// Close Socket Command
			AT_SH();

			// ReOpen Socket Command
			AT_SL(2, true, 80);

		} else {

			// Set Request Variable
			Request = 0;

		}
				
	}

}
void GE910::Socket_Get_Command(void) {
	
	// Clear Response Variable
	memset(Command_Response, 0, sizeof(Command_Response));

	// Declare Read Order Variable
	uint8_t _Read_Order = 0;

	// Declare Response Variable
	char _Response[UART_IoT.available()];

	// Read UART Response
	while(UART_IoT.available() > 0) {

		// Read Serial Char
		_Response[_Read_Order] = UART_IoT.read();
		
		// Increase Read Order
		_Read_Order++;

		// Stream Delay
		delay(1);

	}

	// Set Response Variable
	strcpy(Command_Response, _Response);

	// Control for Response
	if(strstr(_Response, "SRING: 2") != NULL) {

		// Reset Variable
		Request = 0;

		// Socket Answer Command
		AT_SA();

		// Socket Recieve Command
		AT_SRECV();
		
		// Start Pump Command
		if (strstr(Command_Response, "{\"Event\":256}") != NULL) Request = 256;
		
		// Stop Pump Command
		if (strstr(Command_Response, "{\"Event\":257}") != NULL) Request = 257;
		
		// Update Data
		if (strstr(Command_Response, "{\"Event\":262}") != NULL) Request = 262;

		// Close Socket Command
		AT_SH();

		// ReOpen Socket Command
		AT_SL(2, true, 80);

	} else {

		// Set Request Variable
		Request = 0;

	}
	
}

// Hardware Functions
void GE910::LED(bool State) {
	
	// Set GSM LED Power EN
	if (State == true) PORTH &= 0b11101111;

	// Set GSM LED Power EN
	if (State == false) PORTH |= 0b00010000;

}
void GE910::Communication(bool State) {
	
	// Set GSM Comm EN
	if (State == true) PORTH &= 0b11110111;

	// Set GSM Comm EN
	if (State == false) PORTH |= 0b00001000;

}
void GE910::Power(bool State) {
	
	// Set GSM Comm EN
	if (State == true) PORTH |= 0b00000100;

	// Set GSM Comm EN
	if (State == false) PORTH &= 0b11111011;

}
bool GE910::PowerMonitor(void) {
	
	// Control for PWMon (PH7)
	if ((PINH & (1 << PINH7)) == (1 << PINH7)) {
		
		// Set Variable
		PwrMon = POWERED;
		
		// Power Monitor 3V3 HIGH
		return(true);

	} else {
		
		// Set Variable
		PwrMon = NOT_POWERED;

		// Power Monitor 3V3 LOW
		return(false);
	
	}

}
void GE910::OnOff(int Time_) {
	
	// Set On/Off Signal HIGH [PH5]
	PORTH |= 0b00100000;

	// Command Delay
	delay(Time_);
	
	// Set On/Off Signal LOW [PH5]
	PORTH &= 0b11011111;

}
void GE910::ShutDown(int Time_) {
	
	// Set Shut Down Signal HIGH [PH6]
	PORTH |= 0b01000000;

	// Command Delay
	delay(Time_);
	
	// Set Shut Down Signal LOW [PH6]
	PORTH &= 0b10111111;
	
}
bool GE910::Activate(bool Status) {

	// IoT Signal Pins
	// ---------------------------------------------------------------
	// GSM Power EN		- Output [Active HIGH] (Pull-Down) 	- PH2
	// GSM Comm EN 		- Output [Active LOW] (Pull-Up)		- PH3
	// GSM LED EN		- Output [Active LOW] (Pull-Up)		- PH4
	// On/Off			- Output [Active HIGH] (Pull-down) 	- PH5
	// SDown			- Output [Active HIGH] (Pull-down) 	- PH6
	// PwrMon			- Input [Active HIGH] (Pull-down) 	- PH7
	// ---------------------------------------------------------------

	// Turn ON Modem
	if (Status == true) {
		
		UART_IoT.begin(UART_BAUD);
		
		// Set GSM Power Signal EN HIGH
		Power(true);

		// Set GSM LED Power EN
		LED(true);
		
		// Set Communication Signal LOW
		Communication(true);

		// GSM Boot Delay
		delay(2000);

		// Turn On Modem
		if (PowerMonitor()) {
			
			// Power Monitor 3V3 HIGH

			// Set Variable
			PwrMon = POWERED;

			// End Function
			return(true);

		} else {
			
			// Power Monitor 3V3 LOW
			
			// Send On Off Signal
			OnOff(5000);
			
			// Control for PWMon (PH7)
			if (PowerMonitor()) {
				
				// Power Monitor 3V3 HIGH

				// Set Variable
				PwrMon = POWERED;

				// End Function
				return(true);

			} else {
				
				// Power Monitor 3V3 LOW
				
				// Send Shut Down Signal
				ShutDown(200);

			}
			
		}

		// Set Variable
		PwrMon = NOT_POWERED;
		Connected = NOT_CONNECTED;
		
		// End Function
		return(false);
	}
	
	// Turn OFF Modem
	if (Status == false) {
		
		// Turn Off Modem
		if (PowerMonitor()) {
			
			// Power Monitor 3V3 HIGH

			// Send On Off Signal
			AT_SHDN();
			
			// Set GSM LED Power EN
			LED(false);
			
			// Set Communication Signal LOW
			Communication(false);

			// Set GSM Power Signal EN HIGH
			Power(false);

			// Command Delay
			delay(5000);

			// Set Variable
			PwrMon = NOT_POWERED;
			Connected = NOT_CONNECTED;

			// Set Control Variables
			Control.AT	= false;
			Control.AT_CMEE = false;
			Control.AT_FCLASS = false;
			Control.AT_K = false;
			Control.AT_CPIN = false;
			Control.AT_CCID = false;
			Control.AT_CGSN = false;
			Control.AT_GSN = false;
			Control.AT_SLED = false;
			Control.AT_TXMONMODE = false;
			Control.AT_REGMODE = false;
			Control.AT_CREG = false;
			Control.AT_CGREG = false;
			Control.AT_CGDCONT = false;
			Control.AT_SCFG1 = false;
			Control.AT_SCFG2 = false;
			Control.AT_SGACT = false;
			Control.AT_SERVINFO = false;
			Control.AT_CSQ = false;
			Control.AT_CTZU = false;
			Control.AT_NTP = false;
			Control.AT_CCLK = false;
			Control.AT_HTTPCFG = false;
			Control.AT_HTTPSND = false;
			Control.AT_SL = false;
			Control.AT_FRWL = false;
			Control.AT_SA = false;

			// End Function
			return(true);

		} else {
			
			// Power Monitor 3V3 LOW
			
			// Set Variable
			PwrMon = NOT_POWERED;
			Connected = NOT_CONNECTED;

			// End Function
			return(true);
			
		}
		
	}
	
}

GE910 GSM;

// 1903
