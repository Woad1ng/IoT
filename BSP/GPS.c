#include "MyHFile.h"

GPSDATA GPSData;

void GPSRxBufferHandle(uint8_t* GPSRxFlag)
{
    char txt[12];
    //if(*GPSRxFlag==1)
    {
        
        //*GPSRxFlag=0;
        sprintf((char *)Buffer,"%s\r\n",GPSRxBuffer);
        if(Buffer[0]=='$')//固定开头
        {
            if(Buffer[1]=='G'&&Buffer[2]=='N'&&Buffer[3]=='G'&&Buffer[4]=='G'&&Buffer[5]=='A'&&Buffer[6]==',')//GNGGA
            {
                if(Buffer[7]==','&&Buffer[8]==','&&Buffer[9]==','&&Buffer[10]==',')
                {
//                    MyLog("检查到GPS,但信号接收不良\r\n");
                }
                else
                {
                    if(Buffer[7]!=',')
                    {
                        txt[0]=Buffer[7];txt[1]=Buffer[8];//小时解析
                        GPSData.GPSTime.Hour=atoi(txt);//小时赋值
                        GPSData.GPSTime.Hour+=8;        //考虑时区问题
                        txt[0]=Buffer[9];txt[1]=Buffer[10];//分钟解析
                        GPSData.GPSTime.Minute=atoi(txt);//分钟赋值
                        txt[0]=Buffer[11];txt[1]=Buffer[12];//秒解析
                        GPSData.GPSTime.Second=atoi(txt);//秒赋值
                        MyLog("时:%d,分:%d,秒:%d\r\n",GPSData.GPSTime.Hour,GPSData.GPSTime.Minute,GPSData.GPSTime.Second);
                    }
                    else
                    {
                        MyLog("小时接收错误\r\n");
                    }
                    if(Buffer[18]!=',')
                    {
                        strncpy(txt,&GPSRxBuffer[18],10);
                        GPSData.latitude=convertToDecimal(atoi(txt));//纬度解析+换算
                        strncpy(txt,&GPSRxBuffer[31],10);
                        GPSData.longitude=convertToDecimal(atoi(txt));//经度解析+换算
                        GPSData.NSDirection=GPSRxBuffer[29];//南北纬
                        GPSData.WEDirection=GPSRxBuffer[31];//东西经
                        MyLog("%c经度:%f,%c纬度:%f\r\n",GPSData.NSDirection,GPSData.longitude,\
                        GPSData.WEDirection,GPSData.latitude);
                    }
                    else
                    {
                        MyLog("经纬度接收错误\r\n");
                    }
                }
            }
        }
        //printf("%s\r\n",Buffer);
        memset(GPSRxBuffer,'\0',DataLength);
    }
}

//经纬度单位换算
//将ddmm.mmmmm格式转换为十进制度
double convertToDecimal(double coordinate)
{
    int degrees = (int)(coordinate / 100);     // 提取度部分
    double minutes = coordinate - degrees * 100; // 提取分部分
    return degrees + minutes / 60.0;
}


