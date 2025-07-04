#ifndef __GPS_H__
#define __GPS_H__

#include "MyHFile.h"

typedef struct
{
    uint8_t Hour;
    uint8_t Minute;
    uint8_t Second;
}GPSTIME;

typedef struct
{
    GPSTIME GPSTime;        //GPS时间
    double latitude;        //GPS纬度
    double longitude;       //GPS经度
    char NSDirection;       //南北
    char WEDirection;       //东西
}GPSDATA;



void GPSRxBufferHandle(uint8_t* GPSRxFlag);

double convertToDecimal(double coordinate);


#endif

