#ifndef __MYHFILE_H__
#define __MYHFILE_H__

#include "main.h"
#include "string.h"
#include "stdlib.h"
#include <stdio.h>
#include "stdbool.h"

#include "UART.h"

#include "LED.h"

#include "Time.h"

#include "SDRAM.h"

#include "lcd_rgb.h"

#include "cmsis_os.h"

#include "MyTask.h"

#include "ADC.h"
#include "GPS.h"



extern osSemaphoreId_t ADCValueHandle;
extern osSemaphoreId_t BlueToothHandle;


extern UART_HandleTypeDef huart6;
extern UART_HandleTypeDef huart4;
extern ADC_HandleTypeDef hadc1;
extern CRC_HandleTypeDef hcrc;
extern DMA2D_HandleTypeDef hdma2d;
extern LTDC_HandleTypeDef hltdc;
extern TIM_HandleTypeDef htim8;
extern TIM_HandleTypeDef htim17;
extern UART_HandleTypeDef huart1;
extern UART_HandleTypeDef huart2;
extern UART_HandleTypeDef huart7;
extern SDRAM_HandleTypeDef hsdram1;
extern uint8_t screennum;


#include "cmsis_os.h"
#include "queue.h"
#include "semphr.h"



extern TIM_HandleTypeDef htim17;


extern uint8_t screennum;
extern int8_t X,Y;

#include "touch_iic.h"
#include "touch_800x480.h"




//FatFs



#endif


