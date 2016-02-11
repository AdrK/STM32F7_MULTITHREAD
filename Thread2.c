
#include "main.h"

 		/****************************************************
			CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8
			PG7, PB4, PA8, PG6, PH6, PC6, PI3, PC7
		****************************************************/

extern void Error_Handler(void);
extern osMutexId mid_Thread_Mutex;                               	// mutex id
void Thread2 (void const *argument);                            	// thread function
osThreadId tid_Thread2;                                          	// thread id
osThreadDef (Thread2, osPriorityRealtime, 1, 1024);               // thread object
osMutexDef (Majn_Mutex);                                       		// mutex name definition
TOUCH_STATE g_Touched_Cur;
static TOUCH_STATE gs_Touched_New;

int Init_Thread2(void)
{
	mid_Thread_Mutex = osMutexCreate(osMutex(Majn_Mutex));
	tid_Thread2 = osThreadCreate (osThread(Thread2),NULL);
  if (!tid_Thread2) Error_Handler();
  return(0);
}

void Thread2 (void const *argument) {

	static uint16_t th2_counter=0;
	char tab1[5];
	char tab2[30];

	while(1)
	{
		osDelay(10);
		Touch_GetState( &gs_Touched_New );
		
		if( (gs_Touched_New.x != g_Touched_Cur.x) || (gs_Touched_New.y != g_Touched_Cur.y) || (gs_Touched_New.pressed != g_Touched_Cur.pressed) )
		{
			osMutexWait(mid_Thread_Mutex,osWaitForever);
			g_Touched_Cur = gs_Touched_New;
			
			th2_counter++;
			sprintf( tab1, "%d", th2_counter );
			(void)strncpy(tab2,"Touch Screen counts: ",30);
			(void)strncat(tab2,tab1,30);
			
			GUI_DispStringHCenterAt( tab2, 240, 150 );
			osDelay(10);
			osMutexRelease(mid_Thread_Mutex);
		}
		osThreadYield();
	}
}
