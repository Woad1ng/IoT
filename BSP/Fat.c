#include "MyHFile.h"

FAT_Information SD;		//定义SD卡信息结构体

extern SD_HandleTypeDef hsd;
//挂载文件系统后的信息判断
void Mount_Judge(FATFS* FatFs)
{
	BYTE work[_MAX_SS];					//定义文件系统的工作区
	uint8_t OKFlag=0;
	//SD卡挂载文件系统
	UART_Test();
	if(FatFs==&SDFatFS)
	{
		printf("\r\nSD卡开始初始化\n");
		retSD=f_mount(&SDFatFS,SDPath,1);//尝试挂载文件系统,并接收返回值
		printf("\r\n%d\n",retSD);
		if(retSD!=FR_OK)
		{
			switch(retSD)
			{
				case FR_NO_FILESYSTEM:			//如果没有文件系统
				{
					retSD=f_mkfs(SDPath,FM_FAT32,512,work,sizeof work);//格式化文件系统
					if(FR_OK!=retSD){printf("SD卡上无文件系统!\n");while(1);}
					break;
				}
				case FR_OK:{printf("SD卡初始化成功!\n");OKFlag=1;break;}//0
				case FR_DISK_ERR:{printf("SD卡底层硬件错误!\n");OKFlag=0;break;}//1
				case FR_INT_ERR:{printf("SD卡断言失败!\n");OKFlag=0;break;}//2
				case FR_NOT_READY:{printf("SD卡物理驱动没有工作!\n");OKFlag=0;break;}//3
				case FR_NO_FILE:{printf("SD卡文件不存在!\n");OKFlag=0;break;}//4
				case FR_NO_PATH:{printf("SD卡路径不存在!\n");OKFlag=0;break;}//5
				case FR_INVALID_NAME:{printf("SD卡无效文件名!\n");OKFlag=0;break;}//6
				case FR_DENIED:{printf("SD卡由于禁止访问或者目录已满访问被拒绝!\n");OKFlag=0;break;}//7
				case FR_EXIST:{printf("SD卡由于访问被禁止访问被拒绝!\n");OKFlag=0;break;}//8
				case FR_INVALID_OBJECT:{printf("SD卡文件或者目录对象无效!\n");OKFlag=0;break;}//9
				case FR_WRITE_PROTECTED:{printf("SD卡物理驱动被写保护!\n");OKFlag=0;break;}//10
				case FR_INVALID_DRIVE:{printf("SD卡逻辑驱动号无效!\n");OKFlag=0;break;}//11
				case FR_NOT_ENABLED:{printf("SD卡卷中无工作区!\n");OKFlag=0;break;}//12
				case FR_MKFS_ABORTED:{printf("SD卡由于参数错误f_mkfs()被终止!\n");OKFlag=0;break;}//14
				case FR_TIMEOUT:{printf("SD卡在规定的时间内无法获得访问卷的许可!\n");OKFlag=0;break;}//15
				case FR_LOCKED:{printf("SD卡由于文件共享策略操作被拒绝!\n");OKFlag=0;break;}//16
				case FR_NOT_ENOUGH_CORE:{printf("SD卡无法分配长文件名工作区!\n");OKFlag=0;break;}//17
				case FR_TOO_MANY_OPEN_FILES:{printf("SD卡当前打开的文件数大于_FS_SHARE!\n");OKFlag=0;break;}//18
				case FR_INVALID_PARAMETER:{printf("SD卡参数无效!\n");OKFlag=0;break;}//19
				default:printf("SD卡其他错误!\n");SD.InitFlag=0;
			}
			if(OKFlag!=1){printf("SD卡初始化失败!\n");SD.InitFlag=0;}
		}
		else
		{
			SD.InitFlag=1;
			printf("SD卡初始化成功!\n");
		}
		OKFlag=0;
	}
}
//Flash、SD卡初始化+挂载文件系统
void FATFS_Init(void)
{
	Mount_Judge(&SDFatFS);		//SD卡初始化+挂载文件系统
	if(SD.InitFlag==1)
	{
		FATFS_Information(&SDFatFS);
	}
}
//获取存储介质的基本信息
void FATFS_Information(FATFS* FatFs)
{
	FRESULT res;			//定义返回值
	DWORD fre_clust,fre_sect,tot_sect;
	//0-SD卡
	if(FatFs==&SDFatFS)
	{
		res=f_getfree("0:",&fre_clust,&FatFs);
		if(res!=FR_OK){printf("获取信息失败\r\n");return;}//获取失败
		//判断文件系统类型
		if(FatFs->fs_type==1){printf("文件系统：FAT12\r\n");}
		else if(FatFs->fs_type==2){printf("文件系统：FAT16\r\n");}
		else if(FatFs->fs_type==3){printf("文件系统：FAT32\r\n");}
		tot_sect=(FatFs->n_fatent-2)*FatFs->csize;//总扇区个数
		fre_sect=fre_clust*FatFs->csize;//剩余扇区个数
		SD.SumKB=tot_sect/1024*512;
		SD.FreeKB=fre_sect/1024*512;
		SD.SumMB=SD.SumKB/1024;
		SD.FreeMB=SD.FreeKB/1024;
		SD.SumGB=SD.SumMB/1024;
		SD.FreeGB=SD.FreeMB/1024;
		//存储级别判断
		if(SD.SumMB>1000){SD.StoreLevel=1;}			//GB
		else if(SD.SumKB>1000){SD.StoreLevel=2;}	//MB
		else{SD.StoreLevel=3;}						//KB
		if(SD.StoreLevel==1)						//GB
		{
			printf("总GB  ：%.2fGB\r\n",SD.SumGB);		//打印总GB大小
			printf("剩余GB：%.2fGB\r\n",SD.FreeGB);	//打印剩余GB大小
		}
		else if(SD.StoreLevel==2)					//MB
		{
			printf("总MB  ：%.2fMB\r\n",SD.SumMB);		//打印总MB大小
			printf("剩余MB：%.2fMB\r\n",SD.FreeMB);	//打印剩余MB大小
		}
		else										//KB
		{
			printf("总KB  ：%.2fKB\r\n",SD.SumKB);		//打印总KB大小
			printf("剩余KB：%.2fKB\r\n",SD.FreeKB);	//打印剩余KB大小
		}
	}
}

