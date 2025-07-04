#include <gui/sensor_menu_screen/sensor_menuView.hpp>
#include <gui/sensor_menu_screen/sensor_menuPresenter.hpp>

sensor_menuPresenter::sensor_menuPresenter(sensor_menuView& v)
    : view(v)
{

}

void sensor_menuPresenter::activate()
{

}

void sensor_menuPresenter::deactivate()
{
   
}
//按键控制翻转LED
void sensor_menuPresenter::ToggleLED()
{
    view.ToggleLED();
}

void sensor_menuPresenter::Get_Humidity(float humidityvalue)
{
    view.Get_Humidity(humidityvalue);
}

void sensor_menuPresenter::LEDfunction(bool state)
{
    model->LEDfunction(state);
}

void sensor_menuPresenter::SensorGetBlueToothCode(char* Data)
{
    view.SensorGetBlueToothCode(Data);
}


