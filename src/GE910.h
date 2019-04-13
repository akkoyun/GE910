/* *******************************************************************************
 *  Copyright (C) 2014-2019 Mehmet Gunce Akkoyun Can not be copied and/or
 *	distributed without the express permission of Mehmet Gunce Akkoyun.
 *
 *	Library				: Telit GE910 Library.
 *	Code Developer		: Mehmet Gunce Akkoyun (akkoyun@me.com)
 *	Revision			: 1.0.0
 *
 *********************************************************************************/

#ifndef __GE910__
#define __GE910__

#include <Arduino.h>

// Hardware Definations

// Software Definations
#define UART_IoT		Serial
#define UART_BAUD		115200

class GE910 {

public:
	
	// Public Commands
	
	// Public Variables
	
private:

	// Modem Hardware Functions

	// AT Command Set
	bool AT(void);
	
	// Utility Functions
	bool UART_Flush(void);

};

#endif /* defined(__GE910__) */
