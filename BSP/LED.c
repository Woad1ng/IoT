#include "MyHFile.h"

void LED_ON(void)
{
	HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_RESET);
}

void LED_OFF(void)
{
	HAL_GPIO_WritePin(LED_GPIO_Port,LED_Pin,GPIO_PIN_SET);
}

void LED_TOGGLE(void)
{
	HAL_GPIO_TogglePin(LED_GPIO_Port,LED_Pin);
}





