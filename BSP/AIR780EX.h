#ifndef __AIR780EX_H__
#define __AIR780EX_H__

#include "MyHFile.h"
	
void AIR780EX_Init(void);
void AIR780EX_Transmit(char Transmit_text[]);
void AIR780EXRxBufferHandle(uint8_t* AIR780EXRxFlag);

#endif

