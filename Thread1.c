
#include "main.h"
#include "GUI.h"                        // Segger.MDK-Pro::Graphics:CORE
#include <string.h>

 		/****************************************************
			CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8
			PG7, PB4, PA8, PG6, PH6, PC6, PI3, PC7
		****************************************************/

void Thread1 (void const *argument);                             // thread function
extern void Error_Handler(void);

osThreadId tid_Thread1;                                          // thread id
osThreadDef (Thread1, osPriorityHigh, 1, 1024);                // thread object
osMutexId mid_Thread_Mutex;                             // mutex id
extern TOUCH_STATE g_Touched_Cur;

int Init_Thread1(void)
{
	tid_Thread1 = osThreadCreate (osThread(Thread1),NULL);
  if (!tid_Thread1) Error_Handler();	
  return(0);
}

void Thread1 (void const *argument) {
	static uint16_t th1_counter=0;
	char tab1[5];
	char tab2[30];

	while(1)
	{
		osDelay(10);
		osMutexWait(mid_Thread_Mutex,osWaitForever);
		
		th1_counter++;
		sprintf( tab1, "%d", th1_counter );
		(void)strncpy(tab2,"Refresh counts: ",30);
		(void)strncat(tab2,tab1,30);
		
		GUI_DispStringHCenterAt( tab2, 240, 100 );
		
		GUI_CURSOR_SetPosition(g_Touched_Cur.x,g_Touched_Cur.y);
		osDelay(10);
		osMutexRelease(mid_Thread_Mutex);
		osThreadYield();
	}
}
