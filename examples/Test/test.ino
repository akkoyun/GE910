// Define Ovoo Libraries
#include "GE910.h"

// Define Object
GE910 GSM;

// Define UART Names
#define UART_IoT    Serial1

void setup() {
 
 
  // Boot Delay
  delay(1000);
  
  // Activate IoT Modem
  GSM.Connect();

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
