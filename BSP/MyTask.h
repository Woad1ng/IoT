#ifndef __MYTASK_H__
#define __MYTASK_H__

#include "MyHFile.h"

extern osThreadId_t InitTaskHandle;
extern uint32_t InitTaskBuffer[ 128 ];
extern StaticTask_t InitTaskControlBlock;
extern const osThreadAttr_t InitTask_attributes;
void vInitTask(void *argument);


extern osThreadId_t LEDTaskHandle;
extern uint32_t LEDTaskBuffer[ 128 ];
extern StaticTask_t LEDTaskControlBlock;
extern const osThreadAttr_t LEDTask_attributes;
void vLEDTask(void *argument);




#endif



