#ifndef MODELLISTENER_HPP
#define MODELLISTENER_HPP

#include <gui/model/Model.hpp>

class ModelListener
{
public:
    ModelListener() : model(0) {}
    
    virtual ~ModelListener() {}

    void bind(Model* m)
    {
        model = m;
    }
    virtual void ToggleLED() {}
    virtual void MainGetBlueToothCode(char* Data) {}
    virtual void MapGetBlueToothCode(char* Data) {}
    virtual void ActGetBlueToothCode(char* Data) {}
    virtual void SensorGetBlueToothCode(char* Data) {}
    virtual void SetGetBlueToothCode(char* Data) {}
    virtual void AboutGetBlueToothCode(char* Data) {}
    virtual void FpvGetBlueToothCode(char* Data) {}
    virtual void Get_Humidity(float humidity) {}
    virtual void Get_Angle(float angle) {}
protected:
    Model* model;
};

#endif // MODELLISTENER_HPP
