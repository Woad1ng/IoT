#ifndef EMERGENCY_HPP
#define EMERGENCY_HPP

#include <gui_generated/containers/EmergencyBase.hpp>

class Emergency : public EmergencyBase
{
public:
    Emergency();
    virtual ~Emergency() {}

    virtual void initialize();
protected:
};

#endif // EMERGENCY_HPP
