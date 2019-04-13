/* *******************************************************************************
 *  Copyright (C) 2014-2019 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *	Revision			: 1.0.2
 *
 *********************************************************************************/

#include "Arduino.h"
#include "GE910.h"

// AT Command Set
bool GE910::AT(void) {
	
	/******************************************************************************
	 *	Function	: Telit GE910 - AT Command
	 *	Revision	: 01.00.00
	 ******************************************************************************/

	// Declare Command
	char _Command[] = "AT";
	
	// Declare Response
	char _Response[] = "OK";
	int _Response_Length = 10;
	int _Response_TimeOut = 1000;
	
	// Begin UART Communication
	UART_IoT.begin(UART_BAUD);
	
	// Clear UART Buffer
	UART_Flush();
	
	// Send UART Command
	UART_IoT.println(_Command);

	// Read Current Time
	unsigned int _Time = millis();

	// Wait for UART Available
	while (UART_IoT.available() <= _Response_Length) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= _Response_TimeOut) {
			
			// End UART Communication
			UART_IoT.end();

			// End Function Failed
			return(false);
			
		}
		
	}

	// Read UART Buffer
	char _Buffer[] = UART_IoT.read();
	
	// End UART Communication
	UART_IoT.end();

	// Analyse Respose
	if (strstr(_Buffer, _Response)) {
		
		// End Function Success
		return(true);

	}
	else {
		
		// End Function Failed
		return(false);
		
	}
	
}
bool GE910::AT_CMEE(int _Parameter) {
	
	/******************************************************************************
	 *	Function	: Telit GE910 - AT+CMEE Command
	 *	Revision	: 01.00.00
	 ******************************************************************************/
	
	// Declare Command
	char _Command[] = "AT+CMEE=";
	
	// Declare Response
	char _Response[] = "OK";
	int _Response_Length = 10;
	int _Response_TimeOut = 1000;
	
	// Handle Parameter
	if (_Parameter < 0 or _Parameter > 2) _Parameter = 1;
	
	// Begin UART Communication
	UART_IoT.begin(UART_BAUD);
	
	// Clear UART Buffer
	UART_Flush();
	
	// Send UART Command
	UART_IoT.print(_Command); UART_IoT.println(_Parameter);

	// Read Current Time
	unsigned int _Time = millis();
	
	// Wait for UART Available
	while (UART_IoT.available() <= _Response_Length) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= _Response_TimeOut) {
			
			// End UART Communication
			UART_IoT.end();
			
			// End Function Failed
			return(false);
			
		}
		
	}
	
	// Read UART Buffer
	char _Buffer[] = UART_IoT.read();
	
	// End UART Communication
	UART_IoT.end();
	
	// Analyse Respose
	if (strstr(_Buffer, _Response)) {
		
		// End Function Success
		return(true);
		
	}
	else {
		
		// End Function Failed
		return(false);
		
	}
	
	/******************************************************************************
	 * +CMEE Command
	 *
	 * Parameters
	 * 0 - Disable report and use only ERROR report. (default)
	 * 1 - Enable report for numeric format
	 * 2 - Enable report for description format
	 *
	 * (Telit AT Commands Refferance Guide (r22) page 181
	 *
	 ******************************************************************************/

}
bool GE910::AT_FCLASS(int _Parameter) {
	
	/******************************************************************************
	 *	Function	: Telit GE910 - AT+FCLASS Command
	 *	Revision	: 01.00.00
	 ******************************************************************************/
	
	// Declare Command
	char _Command[] = "AT+FCLASS=";
	
	// Declare Response
	char _Response[] = "OK";
	int _Response_Length = 10;
	int _Response_TimeOut = 1000;
	
	// Handle Parameter
	if (_Parameter != 0 or _Parameter != 1 or _Parameter != 8) _Parameter = 0;
	
	// Begin UART Communication
	UART_IoT.begin(UART_BAUD);
	
	// Clear UART Buffer
	UART_Flush();
	
	// Send UART Command
	UART_IoT.print(_Command); UART_IoT.println(_Parameter);
	
	// Read Current Time
	unsigned int _Time = millis();
	
	// Wait for UART Available
	while (UART_IoT.available() <= _Response_Length) {
		
		// Wait delay
		delay(1);
		
		// Handle for timeout
		if (millis() - _Time >= _Response_TimeOut) {
			
			// End UART Communication
			UART_IoT.end();
			
			// End Function Failed
			return(false);
			
		}
		
	}
	
	// Read UART Buffer
	char _Buffer[] = UART_IoT.read();
	
	// End UART Communication
	UART_IoT.end();
	
	// Analyse Respose
	if (strstr(_Buffer, _Response)) {
		
		// End Function Success
		return(true);
		
	}
	else {
		
		// End Function Failed
		return(false);
		
	}
	
	/******************************************************************************
	 * +FCLASS Command
	 *
	 * Parameters
	 * 0 - Data
	 * 1 - Fax
	 * 8 - Voice
	 *
	 * (Telit AT Commands Refferance Guide (r22) page 55
	 *
	 ******************************************************************************/

}

// Utility Functions
bool GE910::UART_Flush(void) {
	
	// Flush UART
	UART_IoT.flush();
	
	// Read UART Buffer
	while(UART_IoT.available() > 0) UART_IoT.read();
	
	// Flush Delay
	delay(5);

}
