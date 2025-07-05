#include "MyHFile.h"

uint16_t IMU_YawtoAngle(float imuyaw)
{
    return abs((int)imuyaw-180)+55;
}

