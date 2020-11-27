// Define Ovoo Libraries
#include "GE910.h"			// IoT Library

// Define Object
GE910 GSM;

void setup() {
 
 	// Activate IoT Modem
	GSM.Module_ON();

}

void loop() {

	// Control for Connection
	if (GSM.Connected == true and GSM.CREG == 1 and GSM.CGREG == 1) {
		
		// Update GSM RTC
		GSM.Time_Update();
		
		// Control for HTTPConfig
		if (GSM.AT_HTTPCFG() == true) {


		}
		
	}
	
}
