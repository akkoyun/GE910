// Define Ovoo Libraries
#include "GE910.h"

// Define Object
GE910 GSM;

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
    
    
  }
  
}
