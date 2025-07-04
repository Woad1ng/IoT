#include "MyHFile.h"

KEY K0;

void Time_Init(void)
{
	HAL_TIM_Base_Start_IT(&htim17);
	K0.KeyFinalState=KEY_EMPTY;K0.KeyState=KEY_CHECK;K0.KeyTime=0;
}

void KeyHandle(KEY *Kx,GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	switch(Kx->KeyState)
	{
		case KEY_CHECK:
		{
			if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin)==GPIO_PIN_RESET)
			{
				Kx->KeyState=KEY_CONFIRM;
				Kx->KeyTime=1;
			}
			break;
		}
		case KEY_CONFIRM:
		{
			if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin)==GPIO_PIN_RESET)
			{
				Kx->KeyState=KEY_RELEASE;
				Kx->KeyTime=2;
			}
			else
			{
				Kx->KeyState=KEY_CHECK;
			}
			break;
		}
		case KEY_RELEASE:
		{
			if(HAL_GPIO_ReadPin(GPIOx,GPIO_Pin)==GPIO_PIN_RESET)
			{
				Kx->KeyTime++;
			}
			else
			{
				if(Kx->KeyTime<100)
				{
                    Kx->KeyState=KEY_CHECK;
					Kx->KeyFinalState=KEY_SHORT;
				}
				else
				{
					Kx->KeyState=KEY_CHECK;
					Kx->KeyFinalState=KEY_LONG;
				}
			}
			break;
		}
		default:break;
	}
}

