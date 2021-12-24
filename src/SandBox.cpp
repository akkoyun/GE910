// AT command function
bool GE910::ATE(const bool _State) {

    //**************************************************
	//  Function	: ATE0 Command
    //  Descriotion : Command Echo Enable/Disable
	//  Revision	: 03.00.00
	//  Command		: ATE0\r\n (6 byte)
	//  Response	: OK\r\n (4 byte)
    //**************************************************

	// Clear UART Buffer
	while (UART_IoT.available() > 0) UART_IoT.read(); delay(3);

	// Send UART Command
	UART_IoT.print(F("ATE"));
	if (_State) UART_IoT.print(F("1"));
	if (!_State) UART_IoT.print(F("0"));
	UART_IoT.print(F("\r\n"));
    
    
    
    


}