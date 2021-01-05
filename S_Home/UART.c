#include "Dio_Int.h"
#include "util/delay.h"
#include "Utilities.h"
#include "Dio_Reg.h"
#include "UART.h"
void UART_Init(void)
{
	SET_BIT(UCSRB,4);
	SET_BIT(UCSRB,3);
	SET_BIT(UCSRC,1);
	SET_BIT(UCSRC,2);
	UBRRL=103;
}
void UART_SendByte(u8 Byte)
{
	UDR = Byte;
	while(GET_BIT(UCSRA,6)==0);


}
u8 UART_RecieveByte(void)
{
	while(GET_BIT(UCSRA,7)==0);
	return UDR;
}

