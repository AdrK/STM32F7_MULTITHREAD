#include "main.h"

extern void Error_Handler(void);
void th_Touch (void const *argument);                            	// thread function
osThreadId tid_th_Touch;                                          	// thread id
osThreadDef (th_Touch, osPriorityRealtime, 1, 1024);               // thread object
TOUCH_STATE g_Touched_Cur;
uint16_t g_th_Touch_counter=0;
static TOUCH_STATE gs_Touched_New;
