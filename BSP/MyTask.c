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
    
    LEDTaskHandle = osThreadNew(vLEDTask, NULL, &LEDTask_attributes);
    vTaskDelete(NULL);
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
        osDelay(1000);
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

