#include "MyHFile.h"

extern UART_HandleTypeDef huart6;

uint8_t uart6RxBuffer[UART6_RX_BUFFER_SIZE];
uint8_t atk_imu901_yaw_low,atk_imu901_yaw_high;
float Pitch,Yaw,Roll;
int16_t mag_x,mag_y,mag_z;

uint8_t atk_imu901_rx_counter=0;
uint8_t atk_imu901_rx_state[13]={0};
uint8_t atk_ms53l1m_rx_state = 0;	
uint8_t atk_mag_rx_state = 0;	
uint8_t atk_imu901_rx_flag = 0;
uint8_t atk_imu901_read_data = 0;
uint8_t atk_imu901_check_sum = 0;

void IMURxBufferHandle()
{ 
		atk_imu901_read_data = *uart6RxBuffer;
			
		if(atk_ms53l1m_rx_state==0&&atk_imu901_read_data==0x55)//帧头1：0x55
		{
			atk_ms53l1m_rx_state=1;
			atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
		}
		else if(atk_ms53l1m_rx_state==1&&atk_imu901_read_data==0x55)//帧头2：0x55
		{
			atk_ms53l1m_rx_state=2;
			atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
		}
		else if(atk_ms53l1m_rx_state==2&&atk_imu901_read_data==0x01)//帧ID：0x01
		{
			atk_ms53l1m_rx_state=3;atk_mag_rx_state=0;
			atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
		}
		else if(atk_ms53l1m_rx_state==3&&atk_imu901_read_data==0x06)//长度
		{
			atk_ms53l1m_rx_state=4;
			atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
		}			
		else if(atk_ms53l1m_rx_state==4)//
		{           
			atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
			if(atk_imu901_rx_counter == 11)
			{

				atk_imu901_check_sum = 0x55+0x55+0x01+0x06+atk_imu901_rx_state[4]+atk_imu901_rx_state[5]+
				atk_imu901_rx_state[6]+atk_imu901_rx_state[7]+atk_imu901_rx_state[8]+atk_imu901_rx_state[9];
				if(atk_imu901_check_sum == atk_imu901_rx_state[10])
				{
					//Roll = ((int16_t)(atk_imu901_rx_state[5]<<8)|atk_imu901_rx_state[4])/32768.0f * 180; 
					//Pitch = ((int16_t)(atk_imu901_rx_state[7]<<8)|atk_imu901_rx_state[6])/32768.0f * 180; 
					Yaw = ((int16_t)(atk_imu901_rx_state[9]<<8)|atk_imu901_rx_state[8])/32768.0f * 180; 
					atk_ms53l1m_rx_state = 0;	
					atk_imu901_rx_counter = 0;	
					//printf("%d\n",((int16_t)Yaw));					
				}
				else
				{
					Yaw = 0;
					atk_ms53l1m_rx_state = 0;
					atk_imu901_rx_counter = 0;
				}
			}
		}
		HAL_UART_Receive_IT(&huart6,uart6RxBuffer,UART6_RX_BUFFER_SIZE);
}


//        atk_imu901_read_data = *uart6RxBuffer;
//        if(atk_ms53l1m_rx_state==0&&atk_imu901_read_data==0x55)//帧头1：0x55
//        {         
//            atk_ms53l1m_rx_state=1;
//            atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
//        }
//        else if(atk_ms53l1m_rx_state==1&&atk_imu901_read_data==0x55)//帧头2：0x55
//        {
//            atk_ms53l1m_rx_state=2;
//            atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
//        }
//        else if(atk_ms53l1m_rx_state==2&&atk_imu901_read_data==0x04)//帧ID：0x04
//        {
//            atk_ms53l1m_rx_state=3;
//            atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
//        }
//        else if(atk_ms53l1m_rx_state==3&&atk_imu901_read_data==0x08)//
//        {
//            atk_ms53l1m_rx_state=4;
//            atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
//        }                
//        else if(atk_ms53l1m_rx_state==4)//
//        {           
//            atk_imu901_rx_state[atk_imu901_rx_counter++]=atk_imu901_read_data;
//            if(atk_imu901_rx_counter == 13)
//            {

//                atk_imu901_check_sum = 0x55+0x55+0x04+0x08+atk_imu901_rx_state[4]+atk_imu901_rx_state[5]+
//                atk_imu901_rx_state[6]+atk_imu901_rx_state[7]+atk_imu901_rx_state[8]+atk_imu901_rx_state[9]+atk_imu901_rx_state[10]+atk_imu901_rx_state[11];
//                if(atk_imu901_check_sum == atk_imu901_rx_state[12])
//                {
//                    mag_x = (int16_t)(atk_imu901_rx_state[5]<<8)|atk_imu901_rx_state[4]; 
//                    mag_y = (int16_t)(atk_imu901_rx_state[7]<<8)|atk_imu901_rx_state[6]; 
//                    mag_z = (int16_t)(atk_imu901_rx_state[9]<<8)|atk_imu901_rx_state[8]; 
//                    atk_ms53l1m_rx_state = 0;    
//                    atk_imu901_rx_counter = 0;    
//                    //printf("%d,%d,%d\n",mag_x,mag_y,mag_z);                    
//                }
//                else
//                {
//                    atk_ms53l1m_rx_state = 0;
//                    atk_imu901_rx_counter = 0;
//                }
//            }
//        }


