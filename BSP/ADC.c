#include "MyHFile.h"


//ADC多通道读取，单次转换，非连续，非扫描
double ADCGetValue(ADC_HandleTypeDef *pin)
{
   double value;
//    HAL_ADC_Start_DMA(pin,&ADCBuffer,1);//开始转换
//    HAL_ADC_PollForConversion(pin,0xffff);//等待完成
//    value = HAL_ADC_GetValue(pin);//读取转换置
//    HAL_ADC_Stop(pin);//关闭转换
    return value;//返回计算值
}

float ADC_Value;
void HAL_ADC_ConvCpltCallback(ADC_HandleTypeDef *hadc)
{
    if(hadc->Instance == ADC1)
    {
        ADC_Value = HAL_ADC_GetValue(hadc);
		if(ADCValueHandle != NULL)//未被释放信号量
		{
			osSemaphoreRelease(ADCValueHandle);
            //printf("%f\r\n",ADC_Value);
		}
    }
}

