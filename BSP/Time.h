#ifndef __TIME_H
#define __TIME_H

#include "MyHFile.h"

typedef enum
{
	KEY_CHECK,
	KEY_CONFIRM,
	KEY_RELEASE,
}KEY_STATE;

typedef enum
{
	KEY_EMPTY,
	KEY_SHORT,
	KEY_LONG
}KEY_FINAL_STATE;


typedef struct
{
	KEY_STATE KeyState;
	KEY_FINAL_STATE KeyFinalState;
	uint32_t KeyTime;
}KEY;

extern KEY K0;


void Time_Init(void);

void KeyHandle(KEY *Kx,GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);





#endif

