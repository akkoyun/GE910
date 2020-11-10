/* *******************************************************************************
 *  Copyright (C) 2014-2020 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *	Revision			: 01.08.00
 *
 *********************************************************************************/

#include "Arduino.h"
#include "GE910.h"

// Power Functions
bool GE910::Module_ON(void) {

	// IoT Signal Pins
	// ---------------------------------------------------------------
	// Power EN			- Output [Active HIGH] (Pull-up) 	- PB1
	// Comm EN			- Output [Active LOW] (Pull-up) 	- PC0
	// On/Off			- Output [Active HIGH] (Pull-down) 	- PC1
	// SDown			- Output [Active HIGH] (Pull-down) 	- PC2
	// PwrMon			- Input [Active HIGH] (Pull-down) 	- PC3
	// ---------------------------------------------------------------
	DDRB	|= 0b00000010;	PORTB	&= 0b11111101;
	DDRC	|= 0b00000001;	PORTC	|= 0b00000001;
	DDRC	|= 0b00000010;	PORTC	&= 0b11111101;
	DDRC	|= 0b00000100;	PORTC	&= 0b11111011;
	DDRC	&= 0b11110111;	PORTC	&= 0b11110111;
	DDRD	|= 0b00100000;	PORTD	&= 0b11011111;

	// Reset Variables
	PwrMon = false;
	Device_Error = false;

	// Boot Delay
	delay(200);

	// Begin UART Communication
	UART_IoT.begin(115200);

	// Set Communication Signal LOW
	PORTC &= 0b11111110;

	// Set GSM Power Signal EN HIGH
	PORTB |= 0b00000010;

	// Control for PWMon (PC3)
	if ((PINC & 0b00001000) == 0b00001000) {
		
		// Delay
		delay(300);
		
		// Init AT Command
		if (AT() == true) {
			
			// Set Variable
			PwrMon = true;

			// End Function
			return(true);

		}
		
	} else {

		// Set On/Off Signal High [PC1]
		PORTC |= 0b00000010;

		// Command Delay
		delay(5000);
		
		// Set On/Off Signal Low [PC1]
		PORTC &= 0b11111101;

		// Control for PWMon (PC3)
		if ((PINC & 0b00001000) == 0b00001000) {

			// Delay
			delay(300);
			
			// Init AT Command
			if (AT() == true) {
				
				// Set Variable
				PwrMon = true;

				// End Function
				return(true);

			}

		}
		
	}

	// HW unconditional ShutDown Delay
	delay(20);

	// Set ShutDown Signal High [PC2]
	PORTC |= 0b00000100;

	// Command Delay
	delay(300);

	// Set ShutDown Signal Low [PC2]
	PORTC &= 0b11111011;

	// Control for PWMon (PC3)
	if ((PINC & 0b00001000) == 0b00001000) {
	
		// Set Error Variable
		Device_Error = true;
		
	} else {
	
		// Reset Device
		asm volatile ("  jmp 0");

	}
	
}

// Modem Set Functions
bool GE910::AT(void) {
	
	/******************************************************************************
	 *	Function	: AT Command
	 *	Revision	: 01.00.01
	 *	Command		: AT\r\n (4 byte)
	 *	Response	: AT\r\n\r\nOK\r\n (10 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 10;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 7ms
		
		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];
		
		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);
	
}
bool GE910::AT_CMEE(void) {
	
	/******************************************************************************
	 *	Function	: AT CMEE Command
	 *	Revision	: 01.00.01
	 *	Command		: AT+CMEE=1\r\n (11 byte)
	 *	Response	: AT+CMEE=1\r\n\r\nOK\r\n (17 byte)
	 ******************************************************************************
	 *	Parameter	: 0 Disable, 1 Numeric Format, 2 Verbose Format
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit
	
	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+CMEE="));
	UART_IoT.print(_CMEE);
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 17;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 7ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_FCLASS(void) {
	
	/******************************************************************************
	 *	Function	: AT FCLASS Command
	 *	Revision	: 01.00.01
	 *	Command		: AT+FCLASS=0\r\n (13 byte)
	 *	Response	: AT+FCLASS=0\r\n\r\nOK\r\n (19 byte)
	 ******************************************************************************
	 *	Parameter	: 0 Data, 1 Fax, 8 Voice
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit
	
	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+FCLASS="));
	UART_IoT.print(_FCLASS);
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 19;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 10ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_K(void) {

	/******************************************************************************
	 *	Function	: AT K Command
	 *	Revision	: 01.00.01
	 *	Command		: AT&K0\r\n (7 byte)
	 *	Response	: AT&K0\r\n\r\nOK\r\n (13 byte)
	 ******************************************************************************
	 *	Parameter	: 0 No Flow Control, 1, 2, 3, 4, 5, 6
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT&K"));
	UART_IoT.print(_K);
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 13;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 10ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}

// SIM Functions
bool GE910::AT_CPIN(void) {
	
	/******************************************************************************
	 *	Function	: AT CPIN Command
	 *	Revision	: 01.00.01
	 *	Command		: AT+CPIN?\r\n (10 byte)
	 *	Response	: AT+CPIN?\r\n\r\n+CPIN: READY\r\n\r\nOK\r\n (32 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+CPIN?"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 32;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 8ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "READY") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_CCID(void) {
	
	/******************************************************************************
	 *	Function	: AT CCID Command
	 *	Revision	: 01.00.01
	 *	Command		: AT#CCID\r\n (9 byte)
	 *	Response	: AT#CCID\r\n\r\n#CCID: 0000000000000000000\r\n\r\nOK\r\n (45 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT#CCID"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 45;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 12ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Data Order Variable
		uint8_t _Data_Order = 0;

		// Declare Response Variable
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
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_CNUM(void) {
	
	/******************************************************************************
	 *	Function	: AT CNUM Command
	 *	Revision	: 01.00.00
	 *	Command		: AT+CNUM\r\n (9 byte)
	 *	Response	:
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+CNUM"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 15;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Data Order Variable
		uint8_t _Data_Order = 0;

		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Data
			if (_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) {
				
				// Get Data
				PHONE[_Data_Order] = _Response[_Read_Order];

				// Increase Data Order
				_Data_Order++;

			}
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}

// Modem ID Functions
bool GE910::AT_CGSN(void) {
	
	/******************************************************************************
	 *	Function	: AT CGSN Command
	 *	Revision	: 01.00.01
	 *	Command		: AT+CGSN\r\n (9 byte)
	 *	Response	: AT+CGSN\r\n\r\n000000000000000\r\n\r\nOK\r\n (34 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+CGSN"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 34;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 12ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Data Order Variable
		uint8_t _Data_Order = 0;

		// Declare Response Variable
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
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);
	
}
bool GE910::AT_GSN(void) {
	
	/******************************************************************************
	 *	Function	: AT GSN Command
	 *	Revision	: 01.00.01
	 *	Command		: AT+GSN\r\n (8 byte)
	 *	Response	: AT+GSN\r\n\r\n0000000000\r\n\r\nOK\r\n (28 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+GSN"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 28;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 10ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Data Order Variable
		uint8_t _Data_Order = 0;

		// Declare Response Variable
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
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}

// GPIO Functions
bool GE910::AT_SLED(void) {

	/******************************************************************************
	 *	Function	: AT SLED Command
	 *	Revision	: 01.00.01
	 *	Command		: AT#SLED=2\r\n (11 byte)
	 *	Response	: AT#SLED=2\r\n\r\nOK\r\n (17 byte)
	 ******************************************************************************
	 *	Parameter	: 0 LOW, 1 HIGH, 2 Blink, 3 Blink (Manuel)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT#SLED="));
	UART_IoT.print(_SLED);
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 17;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 8ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_TXMONMODE(void) {

	/******************************************************************************
	 *	Function	: AT TXMONMODE Command
	 *	Revision	: 01.00.01
	 *	Command		: AT#TXMONMODE=1\r\n (16 byte)
	 *	Response	: AT#TXMONMODE=1\r\n\r\nOK\r\n (22 byte)
	 ******************************************************************************
	 *	Parameter	: 0, 1
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT#TXMONMODE="));
	UART_IoT.print(_TXMONMODE);
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 22;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 12ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}

// GSM Connection Functions
bool GE910::AT_REGMODE(void) {

	/******************************************************************************
	 *	Function	: AT REGMODE Command
	 *	Revision	: 01.00.00
	 *	Command		: AT#REGMODE=1\r\n (14 byte)
	 *	Response	: AT#REGMODE=1\r\n\r\nOK\r\n (20 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT#REGMODE=1"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 20;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {	// Wait for 50ms, Measured 10ms

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_CREG(void) {

	/******************************************************************************
	 *	Function	: AT CREG Command
	 *	Revision	: 01.01.00
	 ******************************************************************************/

	// Declare Control Variable
	bool _Control = false;
	
	// Declare WD Variable
	uint8_t _Error_WD = 0;

	// Declare Stat Variable
	uint8_t _Stat = 0;

	// ****************************************************************************
	// Set Registration Mode : (AT+CREG=1)
	// ****************************************************************************
	// Command		: AT+CREG=1\r\n (11 byte)
	// Response		: AT+CREG=1\r\n\r\nOK\r\n (17 byte)
	// ****************************************************************************

	// Send AT+CREG=1 Connection Command
	while (_Control == false) {
	
		// Command Chain Delay
		delay(_Command_Delay);	// Advice by Telit

		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(F("AT+CREG=1"));
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 17;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) { // Measured 10
			
			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[_Response_Length];

			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Control Variable
				_Control = true;

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}
	
	// ****************************************************************************
	// AT+CREG?
	// ****************************************************************************
	// Command		: AT+CREG?\r\n (10 byte)
	// Response		: AT+CREG?\r\n\r\n+CREG: 1,2\r\n\r\nOK\r\n (30 byte)
	// ****************************************************************************

	// Reset Variables
	_Stat = 0;
	_Error_WD = 0;
	_Control = false;

	// Send AT+CREG? Status Read Command
	while (_Control == false) {
		
		// Command Chain Delay
		delay(_Command_Delay);	// Advice by Telit

		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(F("AT+CREG?"));
		UART_IoT.print(F("\r\n"));

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
			if(strstr(_Response, "OK") != NULL) {

				// Set Control Variable
				_Control = true;

				// Read Stat
				_Stat = _Response[21];

				// Handle Stat Variable
				if (_Stat == 49) {
					
					// Network Registered Home Network

					// Set Variable
					CREG = 1;
					
					// End Function
					return(true);
					
				} // Registered to Home Network [1]
				if (_Stat == 53) {
					
					// Network Registered Rooming

					// Set Variable
					CREG = 5;
					
					// End Function
					return(true);

				} // Registered to Rooming Network [5]

			}
				
		} // Measured 12ms

		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}

	// ****************************************************************************
	// CREG:
	// ****************************************************************************
	// Response		: \r\n+CREG: 2\r\n (12 byte)
	// ****************************************************************************

	// Reset Variables
	_Stat = 0;
	_Error_WD = 0;
	_Control = false;

	// Control for Connection
	while (_Control == false) {

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
				if (_Stat == 48) {
					
					// Network Not Registered
					
					// Set Variable
					CREG = 0;
					
					// End Function
					return(false);
					
				} // Not Registered [0]
				if (_Stat == 49) {
					
					// Network Registered Home Network

					// Set Variable
					CREG = 1;
					
					// Set Control Variable
					_Control = true;
					
				} // Registered to Home Network [1]
				if (_Stat == 50) {
					
					// Still Searching Network
					
					// Set Variable
					CREG = 2;
					
					// Wait Delay
					delay(10);
					
				} // Searching Network [2]
				if (_Stat == 51) {
					
					// Network Registration Denied
					
					// Set Variable
					CREG = 3;
					
					// End Function
					return(false);
					
				} // Registration Denied [3]
				if (_Stat == 52) {
					
					// Unknown Error
					
					// Set Variable
					CREG = 4;
					
					// End Function
					return(false);
					
				} // Unknown Error [4]
				if (_Stat == 53) {
					
					// Network Registered Rooming

					// Set Variable
					CREG = 5;
					
					// Set Control Variable
					_Control = true;

				} // Registered to Rooming Network [5]

			}
				
		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);
		
	}

	// ****************************************************************************
	// End Function
	// ****************************************************************************

	// End Function
	return(true);

}
bool GE910::AT_CGREG(void) {

	/******************************************************************************
	 *	Function	: AT CGREG Command
	 *	Revision	: 01.01.00
	 ******************************************************************************/

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
	while (_Control == false) {
	
		// Command Chain Delay
		delay(_Command_Delay);	// Advice by Telit

		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(F("AT+CGREG=1"));
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 18;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) { // Measured 10
			
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
			if(strstr(_Response, "OK") != NULL) {

				// Set Control Variable
				_Control = true;

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}

	// ****************************************************************************
	// AT+CGREG?
	// ****************************************************************************
	// Command		: AT+CGREG?\r\n (11 byte)
	// Response		: AT+CGREG?\r\n\r\n+CGREG: 1,2\r\n\r\nOK\r\n (31 byte)
	// ****************************************************************************

	// Reset Variables
	_Stat = 0;
	_Error_WD = 0;
	_Control = false;

	// Send AT+CGREG? Status Read Command
	while (_Control == false) {
		
		// Command Chain Delay
		delay(_Command_Delay);	// Advice by Telit

		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(F("AT+CGREG?"));
		UART_IoT.print(F("\r\n"));

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
			if(strstr(_Response, "OK") != NULL) {

				// Set Control Variable
				_Control = true;

				// Read Stat
				_Stat = _Response[23];

				// Handle Stat Variable
				if (_Stat == 49) {
					
					// Network Registered Home Network

					// Set Variable
					CGREG = 1;
					
					// End Function
					return(true);
					
				} // Registered to Home Network [1]
				if (_Stat == 53) {
					
					// Network Registered Rooming

					// Set Variable
					CGREG = 5;
					
					// End Function
					return(true);

				} // Registered to Rooming Network [5]

			}
				
		} // Measured 12ms

		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}
	
	// ****************************************************************************
	// CGREG:
	// ****************************************************************************
	// Response		: \r\n+CGREG: 2\r\n (13 byte)
	// ****************************************************************************

	// Reset Variables
	_Stat = 0;
	_Error_WD = 0;
	_Control = false;

	// Control for Connection
	while (_Control == false) {

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
				if (_Stat == 48) {
					
					// Network Not Registered
					
					// Set Variable
					CGREG = 0;
					
					// End Function
					return(false);
					
				} // Not Registered [0]
				if (_Stat == 49) {
					
					// Network Registered Home Network

					// Set Variable
					CGREG = 1;
					
					// Set Control Variable
					_Control = true;
					
				} // Registered to Home Network [1]
				if (_Stat == 50) {
					
					// Still Searching Network
					
					// Set Variable
					CGREG = 2;
					
					// Wait Delay
					delay(10);
					
				} // Searching Network [2]
				if (_Stat == 51) {
					
					// Network Registration Denied
					
					// Set Variable
					CGREG = 3;
					
					// End Function
					return(false);
					
				} // Registration Denied [3]
				if (_Stat == 52) {
					
					// Unknown Error
					
					// Set Variable
					CGREG = 4;
					
					// End Function
					return(false);
					
				} // Unknown Error [4]
				if (_Stat == 53) {
					
					// Network Registered Rooming

					// Set Variable
					CGREG = 5;
					
					// Set Control Variable
					_Control = true;

				} // Registered to Rooming Network [5]

			}
				
		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);
		
	}

	// ****************************************************************************
	// End Function
	// ****************************************************************************

	// End Function
	return(true);

}
bool GE910::AT_CGDCONT(void) {
	
	/******************************************************************************
	 *	Function	: AT CGDCONT Command
	 *	Revision	: 01.00.01
	 *	Command		: AT+CGDCONT=1,"IP","internet"\r\n (30 byte)
	 *	Response	: AT+CGDCONT=1,"IP","internet"\r\n\r\nOK\r\n (36 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+CGDCONT=1,\""));
	UART_IoT.print(_PDP);
	UART_IoT.print(F("\",\""));
	UART_IoT.print(_APN);
	UART_IoT.print(F("\""));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 36;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_SCFG(void) {
	
	/******************************************************************************
	 *	Function	: AT SCFG Command
	 *	Revision	: 01.00.01
	 *	Command		: AT#SCFG=1,1,0,0,150,1\r\n (23 byte)
	 *	Response	: AT#SCFG=1,1,0,0,150,1\r\n\r\nOK\r\n (29 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT#SCFG=1,1,"));
	UART_IoT.print(_PktSz);
	UART_IoT.print(F(","));
	UART_IoT.print(_MaxTo);
	UART_IoT.print(F(","));
	UART_IoT.print(_ConnTo);
	UART_IoT.print(F(","));
	UART_IoT.print(_TxTo);
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 29;
	
	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);

}
bool GE910::AT_SGACT(void) {
	
	/******************************************************************************
	 *	Function	: AT SGACT Command
	 *	Revision	: 01.01.00
	 ******************************************************************************/

	// Declare Control Variable
	bool _Control = false;
	
	// Declare WD Variable
	uint8_t _Error_WD = 0;

	// ****************************************************************************
	// Relase IP : (AT#SGACT=1,0)
	// ****************************************************************************
	// Command 		: AT#SGACT=1,0\r\n (14 byte)
	// Response 	: AT#SGACT=1,0\r\n\r\nOK\r\n (20 byte)
	// ****************************************************************************

	// Send AT#SGACT=1,0 Release IP Command
	while (_Control == false) {
	
		// Command Chain Delay
		delay(_Command_Delay);	// Advice by Telit

		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(F("AT#SGACT=1,0"));
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 20;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) { // Measured 10
			
			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[_Response_Length];

			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "OK") != NULL) {

				// Set Control Variable
				_Control = true;

			}
			if(strstr(_Response, "ERROR:") != NULL) {
			
				// End Function
				return(false);

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}

	// ****************************************************************************
	// Relase IP : (AT#SGACT=1,1)
	// ****************************************************************************
	// Command		: AT#SGACT=1,1\r\n (14 byte)
	// Response		: AT#SGACT?\r\n\r\n#SGACT: 1,1\r\n\r\nOK\r\n (32 byte)
	// ****************************************************************************

	// Reset Variables
	_Error_WD = 0;
	_Control = false;

	// Send AT#SGACT=1,1 Get IP Command
	while (_Control == false) {
		
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(F("AT#SGACT=1,1"));
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 14;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 1000)) {
			
			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Response Variable
			char _Response[_Response_Length];

			// Read UART Response
			while(UART_IoT.available() > 0) {

				// Read Serial Char
				_Response[_Read_Order] = UART_IoT.read();
				
				// Increase Read Order
				_Read_Order++;
				
			}

			// Control for Response
			if(strstr(_Response, "#SGACT") != NULL) {

				// Set Control Variable
				_Control = true;

			}
			if(strstr(_Response, "ERROR:") != NULL) {
			
				// End Function
				return(false);

			}

				
		} // Measured 12ms

		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);

	}

	// ****************************************************************************
	// SGACT
	// ****************************************************************************
	// Response		: \r\n#SGACT: x.x.x.x\r\n\r\nOK\r\n (25 byte)
	// ****************************************************************************

	// Reset Variables
	_Error_WD = 0;
	_Control = false;
	
	// Control for Connection
	while (_Control == false) {

		// Handle Response
		if (Response_Wait(25, 150000)) {

			// Declare Read Order Variable
			uint8_t _Read_Order = 0;

			// Declare Data Order Variable
			uint8_t _Data_Order = 0;

			// Declare Response Variable
			char _Response[35];

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
				_Control = true;

			}
			if(strstr(_Response, "ERROR:") != NULL) {
			
				// End Function
				return(false);

			}

		}
		
		// Count for Error
		_Error_WD++;

		// Handle for Error
		if (_Error_WD >= 10) return(false);
		
	}
	
	// End Function
	return(true);
	
}

// Operotor Functions
bool GE910::AT_CSQ(void) {
	
	/******************************************************************************
	 *	Function	: AT CSQ Command
	 *	Revision	: 01.01.01
	 *	Command		: AT+CSQ\r\n (9 byte)
	 *	Response	: AT+CSQ\r\n\r\n000000000000000\r\n\r\nOK\r\n (34 byte)
	 ******************************************************************************/

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT+CSQ"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 27;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Variables
		uint8_t _Read_Order = 0;
		uint8_t _Data_Order = 0;
		char _Response[_Response_Length];

		// Declare Buffer Variables
		char _RSSI[2];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Handle Data
			if (_Response[_Read_Order] < 58 and _Response[_Read_Order] > 47) {
				
				// Get Data
				_RSSI[_Data_Order] = _Response[_Read_Order];

				// Increase Data Order
				_Data_Order++;

			}

			// Handle ,
			if (_Response[_Read_Order] == 44 ) break;

			// Increase Read Order
			_Read_Order++;
			
		}

		// Convert Variable
		RSSI = atoi(_RSSI);

		// Control for Response
		if(strstr(_Response, "CSQ") != NULL) return (true);

	}

	// End Function
	return (false);
	
}
bool GE910::AT_SERVINFO(void) {
	
	/******************************************************************************
	 *	Function	: AT SERVINFO Command
	 *	Revision	: 01.02.00
	 *	Command 	: AT#SERVINFO\r\n (13 byte)
	 *	Response	: AT#SERVINFO\r\n\r\n#SERVINFO: 42,-93,"Turkcell","28601",63,855E,03,1,,"II",01,6\r\n (83 byte)
	 ******************************************************************************/

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT#SERVINFO"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 60;

	// Handle Response
	if (Response_Wait(_Response_Length, 1000)) {
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Declare Read Order Variable
		uint8_t _Read_Order = 0;

		// Declare DBM Variable
		bool _Control_DBM = false;
		char _Response_DBM[3];
		uint8_t _Data_Order_DBM = 0;

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

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
	UART_IoT.print(F("AT#CCLK?"));
	UART_IoT.print(F("\r\n"));

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
	UART_IoT.print(F("AT#NTP=\""));
	UART_IoT.print(_NTP_Server);
	UART_IoT.print(F("\",123,1,3"));
	UART_IoT.print(F("\r\n"));

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
	UART_IoT.print(F("AT+CTZU=1"));
	UART_IoT.print(F("\r\n"));

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

	// Command Chain Delay
	delay(_Command_Delay);	// Advice by Telit

	// Clear UART Buffer
	UART_Clear();
	
	// Send UART Command
	UART_IoT.print(F("AT#HTTPCFG=1,\""));
	UART_IoT.print(_HTTP_Server);
	UART_IoT.print(F("\","));
	UART_IoT.print(_HTTP_Port);
	UART_IoT.print(F(",0,\"\",\"\",0,60,1"));
	UART_IoT.print(F("\r\n"));

	// Wait for UART Data Send
	UART_IoT.flush();

	// Declare Variables
	uint8_t _Response_Length = 41 + String(_HTTP_Server).length();
	
	// Handle Response
	if (Response_Wait(_Response_Length, 60000)) {
		
		// Declare Read Order Variable
		uint8_t _Read_Order = 0;
		
		// Declare Response Variable
		char _Response[_Response_Length];

		// Read UART Response
		while(UART_IoT.available() > 0) {

			// Read Serial Char
			_Response[_Read_Order] = UART_IoT.read();
			
			// Increase Read Order
			_Read_Order++;
			
		}

		// Control for Response
		if(strstr(_Response, "OK") != NULL) {

			// End Function
			return (true);

		}

	}

	// End Function
	return (false);
}
bool GE910::AT_HTTPSND(const String &_Data) {
	
	/******************************************************************************
	 *	Function	: AT HTTPSND Command
	 *	Revision	: 01.00.01
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
		UART_IoT.print(F("AT#HTTPSND=1,0,\"")); // 16
		UART_IoT.print(_HTTP_URL);
		UART_IoT.print(F("\",")); // 2
		UART_IoT.print(_Data.length());
		UART_IoT.print(F(",\"application/json\"")); // 19
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 37 + String(_HTTP_URL).length() + String(_Data.length()).length();
		
		// Handle Response
		if (Response_Wait(_Response_Length, 5000)) {
			
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
		uint8_t _Response_Length = 5;

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

	// Define Watchdog Variable
	uint8_t _WD = 0;
	
	
	// Control for Ring
	while (_HTTP_Ring == false) {

		// Control For WD
		if (_WD > 1) return(false);
		
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
			if(strstr(_Response, "200") != NULL) {
				
				// Handle Variable
				_HTTP_Ring = true;
				
			} else {
				
				// End Function
				return(false);
				
			}

		}
		
		// Increase WD
		_WD++;
		
	}
	
	// Send HTTPSND Command
	while (_HTTP_Rcv == false) {
	
		// Clear UART Buffer
		UART_Clear();
		
		// Send UART Command
		UART_IoT.print(F("AT#HTTPRCV=1"));
		UART_IoT.print(F("\r\n"));

		// Wait for UART Data Send
		UART_IoT.flush();

		// Declare Variables
		uint8_t _Response_Length = 46;
		
		// Handle Response
		if (Response_Wait(_Response_Length, 3000)) {
			
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
				
				// End Function
				return(true);

			}
			if(strstr(_Response, "\"result\":\"2\"") != NULL) return(false);

		} else {
			
			// End Function
			return(false);
		
		}
		
	}

	// Set Variable
	Recorded = true;

	// End Function
	return(true);

}

// Utility Functions
void GE910::UART_Clear(void) {
	
	// Control for UART Buffer
	while(UART_IoT.available() > 0) {
	
		// Read Buffer
		char i = UART_IoT.read();
	
		// Clear Delay
		delay(1);

	}
	
}
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

// Public Functions
bool GE910::Connect(void) {
	
	// Control for Power Monitor
	if (PwrMon == true and Device_Error == false) {

		// Control for Connection
		if (Connected == false) {
			
			// Declare Variable
			bool _Process_Control = false;
			bool AT_Command_Confirmation[17] = {false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false, false};
			
			// ************************************************************
			// 1- IoT AT Command
			// ************************************************************
			
			// Declare Variable
			uint8_t _Error_WD = 0;
			
			// Process Command
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

					// Set WD Variable
					_Error_WD++;
					
				}
				
				// Control for WD
				if (_Error_WD > 5) return(false);

			}
			
			// ************************************************************
			// 2- IoT CMEE Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 3- IoT FCLASS Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 4- IoT K Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 5- IoT CPIN Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 6- IoT CGSN Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 7- IoT GSN Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 8- IoT CCID Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 9- IoT SLED Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 10- IoT TXMONMODE Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

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

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}
			
			// ************************************************************
			// 11- IoT REGMODE Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			while (_Process_Control == false) {
				
				// Process Command
				if (AT_REGMODE() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
					// Set Confirmation
					AT_Command_Confirmation[10] = true;
					
				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// Read Current Time
			uint32_t _CTime = millis();
			
			// ************************************************************
			// 12- IoT CREG Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			while (_Process_Control == false and CREG != 1) {
				
				// Process Command
				if (AT_CREG() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
					// Set Confirmation
					AT_Command_Confirmation[11] = true;
					
				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 13- IoT CGREG Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			// Read Current Time
			uint32_t _CRTime = millis() - _CTime;
			Connection_Time = uint8_t(_CRTime / 1000);
			
			while (_Process_Control == false and CGREG != 1) {
				
				// Process Command
				if (AT_CGREG() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
					// Set Confirmation
					AT_Command_Confirmation[12] = true;

				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}
			
			// ************************************************************
			// 14- IoT CGDCONT Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			while (_Process_Control == false) {
				
				// Process Command
				if (AT_CGDCONT() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
					// Set Confirmation
					AT_Command_Confirmation[13] = true;

				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 15- IoT SCFG Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			while (_Process_Control == false) {
				
				// Process Command
				if (AT_SCFG() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
					// Set Confirmation
					AT_Command_Confirmation[14] = true;

				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 16- IoT SGACT Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			while (_Process_Control == false) {
				
				// Process Command
				if (AT_SGACT() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
					// Set Confirmation
					AT_Command_Confirmation[15] = true;

				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}

			// ************************************************************
			// 17- IoT SERVINFO Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			while (_Process_Control == false) {
				
				// Process Command
				if (AT_SERVINFO() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
					// Set Confirmation
					AT_Command_Confirmation[16] = true;

				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}
			
			// ************************************************************
			// 18- IoT CSQ Command
			// ************************************************************

			// Set Control Variable
			_Process_Control = false;
			_Error_WD = 0;

			while (_Process_Control == false) {
				
				// Process Command
				if (AT_CSQ() == true) {
					
					// Set Command Response
					_Process_Control = true;
					
				} else {
					
					// Set Command Response
					_Process_Control = false;

					// Set WD Variable
					_Error_WD++;

				}

				// Control for WD
				if (_Error_WD > 5) return(false);

			}
			
			
			
			
			

			
			// Control for IoT AT Confirmation
			if (AT_Command_Confirmation[0] and AT_Command_Confirmation[1] and AT_Command_Confirmation[2] and AT_Command_Confirmation[3] and AT_Command_Confirmation[4] and AT_Command_Confirmation[5] and AT_Command_Confirmation[6] and AT_Command_Confirmation[7] and AT_Command_Confirmation[8] and AT_Command_Confirmation[9] and AT_Command_Confirmation[10] and AT_Command_Confirmation[11] and AT_Command_Confirmation[12] and AT_Command_Confirmation[13] and AT_Command_Confirmation[14] and AT_Command_Confirmation[15] and AT_Command_Confirmation[16]) {
				
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
bool GE910::Phone_Number(void) {

	// Time Zone Update
	AT_CNUM();
	
}
