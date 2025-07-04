#ifndef SENSOR_MENUPRESENTER_HPP
#define SENSOR_MENUPRESENTER_HPP

#include <gui/model/ModelListener.hpp>
#include <mvp/Presenter.hpp>

using namespace touchgfx;

class sensor_menuView;

class sensor_menuPresenter : public touchgfx::Presenter, public ModelListener
{
public:
    sensor_menuPresenter(sensor_menuView& v);
    virtual void ToggleLED();
    virtual void SensorGetBlueToothCode(char* Data);
    void LEDfunction(bool state);
    virtual void Get_Humidity(float humidityvalue);

    /**
     * The activate function is called automatically when this screen is "switched in"
     * (ie. made active). Initialization logic can be placed here.
     */
    virtual void activate();

    /**
     * The deactivate function is called automatically when this screen is "switched out"
     * (ie. made inactive). Teardown functionality can be placed here.
     */
    virtual void deactivate();

    virtual ~sensor_menuPresenter() {}
        
    
private:
    sensor_menuPresenter();

    sensor_menuView& view;
};

#endif // SENSOR_MENUPRESENTER_HPP
