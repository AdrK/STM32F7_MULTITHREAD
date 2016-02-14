
#include "th_Touch.h"

int Init_th_Touch(void)
{	
	tid_th_Touch = osThreadCreate (osThread(th_Touch), NULL );
  if ( !tid_th_Touch ) Error_Handler();	
  return(0);
}

void th_Touch (void const *argument) {

	while(1)
	{
		osDelay(10);
		Touch_GetState( &gs_Touched_New );
		
		if( (gs_Touched_New.x != g_Touched_Cur.x) || (gs_Touched_New.y != g_Touched_Cur.y) || (gs_Touched_New.pressed != g_Touched_Cur.pressed) )
		{
			osMutexWait(mid_GUI_Mutex,osWaitForever);
			{
				g_th_Touch_counter++;
				g_Touched_Cur = gs_Touched_New;
			}
			osMutexRelease(mid_GUI_Mutex);
			osDelay(10);
		}
		osThreadYield();
	}
}
