
#include "main.h"
#include "GUI.h"                        // Segger.MDK-Pro::Graphics:CORE
#include <string.h>

 		/****************************************************
			CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8
			PG7, PB4, PA8, PG6, PH6, PC6, PI3, PC7
		****************************************************/

extern void Error_Handler(void);
extern volatile osMutexId mid_Thread_Mutex;                               	// mutex id
void Thread2 (void const *argument);                            	// thread function
osThreadId tid_Thread2;                                          	// thread id
osThreadDef (Thread2, osPriorityNormal, 1, 1024);                	// thread object
osMutexDef (Majn_Mutex);                                       		// mutex name definition

int Init_Thread2(void)
{
	mid_Thread_Mutex = osMutexCreate(osMutex(Majn_Mutex));
	tid_Thread2 = osThreadCreate (osThread(Thread2),NULL);
  if (!tid_Thread2) Error_Handler();
  return(0);
}

void Thread2 (void const *argument) {

	static uint16_t th1_counter=0;
	char tab2[5];
	const char *tab1=" ->THREAD 2";
	
	while(1)
	{
																											Anal_CH4_Set();
		osDelay(200);
																											Anal_CH5_Set();
		osMutexWait(mid_Thread_Mutex,osWaitForever);
																											Anal_CH5_Reset();
		th1_counter++;
		sprintf( tab2, "%d", th1_counter );

		(void)strcat(tab2,tab1);
		GUI_DispStringHCenterAt( tab2, 240, 150 );
		osDelay(200);
																											Anal_CH6_Set();
		osMutexRelease(mid_Thread_Mutex);
																											Anal_CH6_Reset();
																											Anal_CH4_Reset();
		osThreadYield();
	}
}
