#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <gui_generated/containers/triangleBase.hpp>

class triangle : public triangleBase
{
public:
    triangle();
    virtual ~triangle() {}

    virtual void initialize();
protected:
};

#endif // TRIANGLE_HPP
