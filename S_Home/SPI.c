#include "Dio_Int.h"
#include "Utilities.h"
#include "Dio_Reg.h"
#include "SPI.h"
extern u8 flag;
void SPI_InitMaster(void)
{

	Dio_SetPinDirection(GroupB,PIN4,OUTPUT);
	Dio_SetPinDirection(GroupB,PIN5,OUTPUT);
	Dio_SetPinDirection(GroupB,PIN6,INPUT);
	Dio_SetPinDirection(GroupB,PIN7,OUTPUT);
	SET_BIT(SPCR,4);
	SET_BIT(SPCR,6);



}
void SPI_InitSlave(void)
{
	Dio_SetPinDirection(GroupB,PIN4,INPUT);
	Dio_SetPinDirection(GroupB,PIN5,INPUT);
	Dio_SetPinDirection(GroupB,PIN6,OUTPUT);
	Dio_SetPinDirection(GroupB,PIN7,INPUT);

	SET_BIT(SPCR,6);
}
void SPI_SendByte(u8 data)
{
	SPDR =data;
	if(flag == 1)
	Dio_SetPinDirection(GroupB,PIN4,HIGH);
	while(GET_BIT(SPSR,7)==0);
}
u8 SPI_RecieveByte(void)
{
	while(GET_BIT(SPSR,7)==0);
	return SPDR;
}

