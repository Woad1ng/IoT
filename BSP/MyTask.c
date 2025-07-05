#include "MyHFile.h"


osThreadId_t InitTaskHandle;
uint32_t InitTaskBuffer[ 128 ];
StaticTask_t InitTaskControlBlock;
const osThreadAttr_t InitTask_attributes = {
  .name = "InitTask",
  .cb_mem = &InitTaskControlBlock,
  .cb_size = sizeof(InitTaskControlBlock),
  .stack_mem = &InitTaskBuffer[0],
  .stack_size = sizeof(InitTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};

void vInitTask(void *argument)
{
    AIR780EXTaskHandle = osThreadNew(vAIR780EXTask, NULL, &AIR780EXTask_attributes);
    LEDTaskHandle = osThreadNew(vLEDTask, NULL, &LEDTask_attributes);
	
	
    vTaskDelete(NULL);
}


osThreadId_t AIR780EXTaskHandle;
uint32_t AIR780EXTaskBuffer[ 128 ];
StaticTask_t AIR780EXTaskControlBlock;
const osThreadAttr_t AIR780EXTask_attributes = {
  .name = "AIR780EXTask",
  .cb_mem = &AIR780EXTaskControlBlock,
  .cb_size = sizeof(AIR780EXTaskControlBlock),
  .stack_mem = &AIR780EXTaskBuffer[0],
  .stack_size = sizeof(AIR780EXTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};

void vAIR780EXTask(void *argument)
{
	char text[200];
    while(1)
    {
		osDelay(5000);
		sprintf(text,"AT+MCONFIG=\"68653eacd582f20018375cb4_Helmet_Black_0_0_2025070214\",\"68653eacd582f20018375cb4_Helmet_Black\",\"b37a819dac32ccf1bb3b565a66f5eaba6aca18536bfda0c90e5a0e65d2f1c1d1\"\r\n");
		HAL_UART_Transmit(&huart3,(uint8_t *)text,strlen(text),1000);
		osDelay(500);
		sprintf(text,"AT+MIPSTART=\"6baef12253.st1.iotda-device.cn-north-4.myhuaweicloud.com\",\"1883\"\r\n");
		HAL_UART_Transmit(&huart3,(uint8_t *)text,strlen(text),1000);
		osDelay(500);
		sprintf(text,"AT+MCONNECT=1,300\r\n");
		HAL_UART_Transmit(&huart3,(uint8_t *)text,strlen(text),1000);
		osDelay(500);
		vTaskDelete(NULL);
    }	
}

osThreadId_t LEDTaskHandle;
uint32_t LEDTaskBuffer[ 128 ];
StaticTask_t LEDTaskControlBlock;
const osThreadAttr_t LEDTask_attributes = {
  .name = "LEDTask",
  .cb_mem = &LEDTaskControlBlock,
  .cb_size = sizeof(LEDTaskControlBlock),
  .stack_mem = &LEDTaskBuffer[0],
  .stack_size = sizeof(LEDTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};

void vLEDTask(void *argument)
{
    while(1)
    {
        LED_TOGGLE();
        //HAL_UART_Transmit(&huart2,(uint8_t*)buffer,sizeof(buffer), HAL_MAX_DELAY);
        osDelay(100);
    }	
}

osThreadId_t BlueToothTaskHandle;
uint32_t BlueToothTaskBuffer[ 128 ];
StaticTask_t BlueToothTaskControlBlock;
const osThreadAttr_t BlueToothTask_attributes = {
  .name = "BlueToothTask",
  .cb_mem = &BlueToothTaskControlBlock,
  .cb_size = sizeof(BlueToothTaskControlBlock),
  .stack_mem = &BlueToothTaskBuffer[0],
  .stack_size = sizeof(BlueToothTaskBuffer),
  .priority = (osPriority_t) osPriorityNormal,
};

void vBlueToothTask(void *argument)
{
    while(1)
    {
        
    }
}

