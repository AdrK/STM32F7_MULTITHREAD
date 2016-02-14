#include "main.h"
#include "GUI.h"                        // Segger.MDK-Pro::Graphics:CORE
#include <string.h>

void th_GUI (void const *argument);                             	// thread function
extern void Error_Handler(void);
extern void Draw_GraphGrid(uint16_t XSize, uint16_t YSize, uint8_t XDense, uint8_t YDense);
extern uint8_t g_FPS;
extern osThreadId tid_th_FPS;
osThreadId tid_th_GUI;                                          	// thread id
osThreadDef (th_GUI, osPriorityHigh, 1, 1024);                		// thread object
uint16_t th_GUI_counter=0;
extern uint16_t g_th_Touch_counter;
extern TOUCH_STATE g_Touched_Cur;
