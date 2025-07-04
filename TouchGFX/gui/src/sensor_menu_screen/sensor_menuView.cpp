#include <gui/sensor_menu_screen/sensor_menuView.hpp>
#include "MyHFile.h"
sensor_menuView::sensor_menuView()
{

}

void sensor_menuView::setupScreen()
{
    sensor_menuViewBase::setupScreen();
}

void sensor_menuView::tearDownScreen()
{
    sensor_menuViewBase::tearDownScreen();
}


void sensor_menuView::ToggleLED()
{
    LED.setVisible(!LED.isVisible());
    LED.invalidate();
}

void sensor_menuView::Get_Humidity(float humidityvalue)
{
    humidity_circle.setValue(225+270*humidityvalue/4095);
    humidity_circle.invalidate();
    uint16_t persent=humidityvalue*100/4096;
    Unicode::snprintf(humidity_valueBuffer,HUMIDITY_VALUE_SIZE,"%d",persent);
    humidity_value.invalidate();
    
    temperature_circle.setValue(225+270*humidityvalue/4095);
    temperature_circle.invalidate();
    Unicode::snprintf(temperature_valueBuffer,TEMPERATURE_VALUE_SIZE,"%d",persent);
    temperature_value.invalidate();
}

void sensor_menuView::LEDfunction()
{
    presenter->LEDfunction(LEDButton.getState());
}

void sensor_menuView::SensorGetBlueToothCode(char* Data)
{
    if ((uint8_t)Data[0]==0xAA&&(uint8_t)Data[1]==0xBB&&(uint8_t)Data[2]==0x05&&(uint8_t)Data[3]==0xBB&&(uint8_t)Data[4]==0xAA)
    {
        printf("back\r\n");
        screennum=0;
        application().gotomain_menuScreenCoverTransitionWest();
    }
}

