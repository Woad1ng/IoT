#ifndef SENSOR_MENUVIEW_HPP
#define SENSOR_MENUVIEW_HPP

#include <gui_generated/sensor_menu_screen/sensor_menuViewBase.hpp>
#include <gui/sensor_menu_screen/sensor_menuPresenter.hpp>

class sensor_menuView : public sensor_menuViewBase
{
public:
    sensor_menuView();
    void SensorGetBlueToothCode(char* Data);
    virtual ~sensor_menuView() {}
    virtual void setupScreen();
    virtual void tearDownScreen();
        
    void ToggleLED();
    void Get_Humidity(float humidityvalue);
    virtual void LEDfunction();
       
protected:
};

#endif // SENSOR_MENUVIEW_HPP
