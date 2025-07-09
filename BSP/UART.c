#include "MyHFile.h"

////////////////////////////////一定不要忘记打开魔术棒里的"Use MicroLIB"///////////////////
#define Length 17

// AC5编译器使用这段代码
#pragma import(__use_no_semihosting)  
int _ttywrch(int ch)    
{
    ch=ch;
	return ch;
}         
struct __FILE 
{ 
	int handle; 

}; 
FILE __stdout;       

void _sys_exit(int x) 
{ 
	x = x; 
} 


int fputc(int ch,FILE *f)
{
	HAL_UART_Transmit(&huart1,(uint8_t *)&ch,1,HAL_MAX_DELAY);
	return ch;
}

char RxBuffer[DataLength]={'\0'};
char Buffer[DataLength]={'\0'};
uint8_t RxFlag=0;

char GPSRxBuffer[DataLength]={'\0'};
uint8_t GPSRxFlag=0;

char AIR780EX_rx_buf[200];
uint8_t AIR780EXRxFlag=0;

char IMURxBuffer[DataLength]={'\0'};


void UART_Init(void)
{
    HAL_UARTEx_ReceiveToIdle_IT(&huart4,(uint8_t *)GPSRxBuffer,DataLength);
	HAL_UART_Receive_IT(&huart7,(uint8_t*)RxBuffer,5);
	HAL_UART_Receive_IT(&huart6,(uint8_t *)IMURxBuffer,UART6_RX_BUFFER_SIZE);
	HAL_UARTEx_ReceiveToIdle_IT(&huart3,(uint8_t *)AIR780EX_rx_buf,200);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart)
{
	if(huart->Instance==UART7)//蓝牙手环数据
	{
        RxFlag=1;
		HAL_UART_Receive_IT(&huart7,(uint8_t*)RxBuffer,5); 
	}
	if(huart->Instance==USART6)
	{
		IMURxBufferHandle();
	}
}

void HAL_UARTEx_RxEventCallback(UART_HandleTypeDef *huart, uint16_t Size)
{
    if(huart->Instance==UART4)//GPS数据
    {
        GPSRxFlag=1;
        HAL_UARTEx_ReceiveToIdle_IT(&huart4,(uint8_t *)GPSRxBuffer,DataLength);
        GPSRxBufferHandle(&GPSRxFlag);
    }
	if(huart->Instance==USART3)//GPS数据
    {
        AIR780EXRxFlag=1;
		AIR780EXRxBufferHandle(&AIR780EXRxFlag);
    }
}


