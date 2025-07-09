#include <gui/model/Model.hpp>
#include <gui/model/ModelListener.hpp>

#define copmuter   0   //0:不在电脑上运行模拟器  1:在电脑上运行模拟器

#if copmuter == 0
#include "MyHFile.h"

#endif

Model::Model() : modelListener(0)
{
    
}
char Data[10];
uint8_t screennum=0;
extern uint8_t getangleflag;
void Model::tick()
{
    #if copmuter == 0
    if(K0.KeyFinalState==KEY_SHORT)
    {
        K0.KeyFinalState=KEY_EMPTY;
        modelListener->ToggleLED();
    }
    if(RxFlag==1)
    {
        if(screennum==0)
        {
            modelListener->MainGetBlueToothCode(RxBuffer);//主界面
        }
        else if(screennum==1)
        {
            modelListener->MapGetBlueToothCode(RxBuffer);//地图
            modelListener->MainGetBlueToothCode(RxBuffer);//主界面
        }
        else if(screennum==2)
        {
            modelListener->ActGetBlueToothCode(RxBuffer);//行动
            modelListener->MainGetBlueToothCode(RxBuffer);//主界面
        }
        else if(screennum==3)
        {
            modelListener->SensorGetBlueToothCode(RxBuffer);//传感器
            modelListener->MainGetBlueToothCode(RxBuffer);//主界面
        }
        else if(screennum==4)
        {
            modelListener->SetGetBlueToothCode(RxBuffer);//设置
            modelListener->MainGetBlueToothCode(RxBuffer);//主界面
        }
        else if(screennum==5)
        {
            //modelListener->AboutGetBlueToothCode(RxBuffer);//关于
            modelListener->MainGetBlueToothCode(RxBuffer);//主界面
        }
        else if(screennum==6)
        {
            modelListener->FpvGetBlueToothCode(RxBuffer);//FPV
        }
         RxFlag=0;
	}
    if(osSemaphoreAcquire(ADCValueHandle,portMAX_DELAY) == osOK)
    {
        modelListener->Get_Humidity(ADC_Value);
        modelListener->Get_Angle(Yaw);
	} 
    
//    if(getangleflag==1)
//    {
//        getangleflag=0;
//       
//    }
    #endif
}

void Model::LEDfunction(bool state)
{
    #if copmuter == 0
    if(state==true)
    {
        LED_ON();
    }
    else
    {
        LED_OFF();
    }
    #endif
}

