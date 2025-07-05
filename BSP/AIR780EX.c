#include "MyHFile.h"


extern char AIR780EX_rx_buf[200];


/*
up_message最大4100个字节。字符串类型，须用双引号括住。
注:消息中内嵌的双引号请用\22表达；控制字符回车
Nr(Ox0D）请用\OD表达;控制字符换行\n（OxOA)
请用\0A表达；控制字符反斜杠丶（Ox5C）请用\5C
表达
如果是MCU发消息，可能需要用\\22，\\OD，
\\0A，\\5C来表达，即\需要转义成\\
*/
//void AIR780EX_Init(void)
//{
//	HAL_Delay(5000);
//	sprintf(text,"AT+MCONFIG=\"68653eacd582f20018375cb4_Helmet_Black_0_0_2025070214\",\"68653eacd582f20018375cb4_Helmet_Black\",\"b37a819dac32ccf1bb3b565a66f5eaba6aca18536bfda0c90e5a0e65d2f1c1d1\"\r\n");
//	HAL_UART_Transmit(&huart3,(uint8_t *)text,strlen(text),1000);
//	HAL_Delay(500);
//	sprintf(text,"AT+MIPSTART=\"6baef12253.st1.iotda-device.cn-north-4.myhuaweicloud.com\",\"1883\"\r\n");
//	HAL_UART_Transmit(&huart3,(uint8_t *)text,strlen(text),1000);
//	HAL_Delay(500);
//	sprintf(text,"AT+MCONNECT=1,60\r\n");
//	HAL_UART_Transmit(&huart3,(uint8_t *)text,strlen(text),1000);
//	HAL_Delay(500);
//}

void AIR780EX_Transmit(char Transmit_text[])
{
	char text1[200];
	sprintf(text1,"AT+MPUB=\"$oc/devices/68653eacd582f20018375cb4_Helmet_Black/sys/messages/up\",0,0,\"%s\"\r\n",Transmit_text);
	HAL_UART_Transmit(&huart3,(uint8_t *)text1,strlen(text1),1000);
}

void AIR780EXRxBufferHandle(uint8_t* AIR780EXRxFlag)
{
//	if(*AIR780EXRxFlag)
//	{
//		*AIR780EXRxFlag = 0;
		printf("%s\n",AIR780EX_rx_buf);
		memset(AIR780EX_rx_buf,0,sizeof(AIR780EX_rx_buf));
		HAL_UARTEx_ReceiveToIdle_IT(&huart3,(uint8_t *)AIR780EX_rx_buf,200);
//	}
}

