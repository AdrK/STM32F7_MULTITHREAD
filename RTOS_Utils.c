#include "main.h"

osMutexId mid_GUI_Mutex;
osMutexDef (Touch_Mutex);

void Init_RTOS_Utils(void)
{
	mid_GUI_Mutex = osMutexCreate(osMutex(Touch_Mutex));
}
