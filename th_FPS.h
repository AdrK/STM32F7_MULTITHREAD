#include "main.h"

extern void Error_Handler(void);
void th_FPS (void const *argument);

extern uint8_t g_FPS;
osThreadId tid_th_FPS;
osThreadDef (th_FPS, osPriorityRealtime, 1, 256);
