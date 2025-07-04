#ifndef COMPASS_HPP
#define COMPASS_HPP

#include <gui_generated/containers/CompassBase.hpp>

class Compass : public CompassBase
{
public:
    Compass();
    virtual ~Compass() {}

    virtual void initialize();
protected:
};

#endif // COMPASS_HPP
