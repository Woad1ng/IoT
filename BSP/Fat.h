#ifndef __SD_H__
#define __SD_H__
#include "MyHFile.h"

typedef struct
{
	uint8_t InitFlag;		//初始化标志位
	float SumMB;			//总MB
	float FreeMB;			//剩余KB
	float SumKB;			//总MB
	float FreeKB;			//剩余KB
	float SumGB;			//总GB
	float FreeGB;			//剩余GB
	uint8_t StoreLevel;		//存储级别先判断MB>1000时Level=1,
							//规定1->GB		2->MB		3-->KB
}FAT_Information;

extern FAT_Information SD;				//定义SD卡信息结构体

void Mount_Judge(FATFS* FatFs);			//挂载文件系统后的信息判断

void FATFS_Init(void);					//Flash、SD卡初始化+挂载文件系统
void FATFS_Information(FATFS* FatFs);	//获取存储介质的大小于剩余空间


#endif


//typedef char TCHAR;
///*定义自己的存储设备*/
///*用户存储设备扇区字节数*/
//#define User_Sector 512
///*用户存储设备FatFs对象*/
//#define User_FatFs 	SDFatFS
///*用户存储设备卷路径*/
//#define User_SDPath SDPath
///*用户存储设备初始化类型*/
//#define User_FatType FM_FAT32

