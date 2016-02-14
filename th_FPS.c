
#include "th_FPS.h"

int Init_th_FPS(void)
{	
	tid_th_FPS = osThreadCreate (osThread(th_FPS), NULL );
  if ( !tid_th_FPS ) Error_Handler();
  return(0);
}

void th_FPS (void const *argument) {

	static uint16_t FPS_counter;	
	static uint8_t flag=1;
	static uint32_t Time_counter_a;
	static uint32_t Time_counter_b;
	
	while(1)
	{
		if( flag )
		{
			Time_counter_a = HAL_GetTick();
			flag = 0;
		}
		
		osSignalWait( Sig_FPS, osWaitForever );		
		Time_counter_b = HAL_GetTick();
		
		if ( (Time_counter_b - Time_counter_a) >= 1000 )
		{
			FPS_counter=0;
			flag = 1;
			osMutexWait( mid_FPS_Mutex, osWaitForever );
			{
				g_FPS=FPS_counter;
			}
			osMutexRelease( mid_FPS_Mutex );
		}
		else
		{
			FPS_counter++;
		}
		osDelay(1);
		osThreadYield();
	}
}
