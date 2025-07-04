#ifndef __PRINT_H__
#define __PRINT_H__

#include "MyHFile.h"

//extern uint8_t RxFlag;
//int fputc(int ch,FILE *f);									//打印函数
//int fgetc(FILE *f);											//读取函数
//void UART_Test(void);
//void UART_Init(void);										//串口接收必须初始化
//void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);	//串口接收中断

//我的日志信息
#ifdef MYLOG
		#define MyLog(format,...)	printf(format,##__VA_ARGS__)
#else
		#define MyLog(format,...)
#endif

// 自定义的 BluetoothSend 函数

extern uint8_t RxFlag;

#define DataLength 600

extern char RxBuffer[DataLength];
extern char Buffer[DataLength];

//GPS数据缓冲区
extern char GPSRxBuffer[DataLength];


extern uint8_t RxFlag;

void UART_Init(void);
void BluetoothSend(const char *format, ...);


#endif
