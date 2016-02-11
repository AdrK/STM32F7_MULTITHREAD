
#include "main.h"
#include "GUI.h"                        // Segger.MDK-Pro::Graphics:CORE
#include <string.h>

 		/****************************************************
			CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8
			PG7, PB4, PA8, PG6, PH6, PC6, PI3, PC7
		****************************************************/

extern void Error_Handler(void);
void Thread1 (void const *argument);                             // thread function
osThreadId tid_Thread1;                                          // thread id
osThreadDef (Thread1, osPriorityHigh, 1, 1024);                // thread object
volatile osMutexId mid_Thread_Mutex;                             // mutex id

int Init_Thread1(void)
{
	tid_Thread1 = osThreadCreate (osThread(Thread1),NULL);
  if (!tid_Thread1) Error_Handler();
  return(0);
}

void Thread1 (void const *argument) {
	static uint16_t th1_counter=0;
	char tab2[5];
	const char *tab1=" ->THREAD 1 ";

	while(1)
	{
																											Anal_CH1_Set();
		osDelay(300);
																											Anal_CH2_Set();
		osMutexWait(mid_Thread_Mutex,osWaitForever);
																											Anal_CH2_Reset();
		th1_counter++;
		sprintf( tab2, "%d", th1_counter );

		(void)strcat(tab2,tab1);
		GUI_DispStringHCenterAt( tab2, 240, 100 );


		osDelay(300);
																											Anal_CH3_Set();
		osMutexRelease(mid_Thread_Mutex);
																											Anal_CH3_Reset();
																											Anal_CH1_Reset();
		osThreadYield();
	}
}
