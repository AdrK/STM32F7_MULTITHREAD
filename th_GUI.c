
#include "th_GUI.h"
extern osMutexId mid_GUI_Mutex;

int Init_th_GUI(void)
{		
	tid_th_GUI = osThreadCreate (osThread(th_GUI), NULL );
  if ( !tid_th_GUI ) Error_Handler();	
  return(0);
}

void th_GUI (void const *argument) {
	
	static uint8_t Brush_flag;
	static uint8_t Clear_flag;
	static char tab1[5];
	static char tab2[30];
	uint8_t button_H = 40;
	uint8_t button_W = 80;
	GUI_MEMDEV_Handle h_MemDevButtons, h_MemDevMain;
	
	GUI_Init();	
	
	osMutexWait( mid_GUI_Mutex,osWaitForever );
	{
		Hello_MSG();
		GUI_Clear();
		
		GUI_SelectLayer(0);
		h_MemDevButtons = GUI_MEMDEV_Create( 0, 0, 480, button_H );
		h_MemDevMain = GUI_MEMDEV_Create( 0, button_H+1, 480, 272 );
		GUI_MEMDEV_Select( h_MemDevButtons );
		GUI_MEMDEV_Clear( h_MemDevButtons );
		
		GUI_SetColor( GUI_BLUE );
		GUI_SetBkColor( GUI_BLUE );
		GUI_FillRect( 1, 1, button_W+1, button_H );
		GUI_FillRect( button_W+1, 1, 2*button_W+1, button_H );
		GUI_SetColor( GUI_ORANGE );
		GUI_DrawRect( 1, 1, button_W+1, button_H-1 );
		GUI_DrawRect( button_W+1, 1, 2*button_W+1, button_H-1 );
		GUI_DispStringHCenterAt( "Clear", button_W/2, button_H/2 );
		GUI_DispStringHCenterAt( "Pen",button_W*1.5, button_H/2 );		
		
		GUI_MEMDEV_CopyToLCD( h_MemDevButtons );
	}
	osMutexRelease( mid_GUI_Mutex );

	GUI_MEMDEV_Select( h_MemDevMain );
	GUI_MEMDEV_Clear( h_MemDevMain );
	GUI_SetBkColor( GUI_BLACK );
	
	while(1)
	{
		osDelay(2);
		osMutexWait(mid_GUI_Mutex,osWaitForever);
		
		GUI_SetColor( GUI_GREEN );
		
		sprintf( tab1, "%d", g_th_Touch_counter );
		(void)strncpy(tab2,"Touch Screen counts: ",30);
		(void)strncat(tab2,tab1,30);
		GUI_SetFont(&GUI_Font16_1);		
		GUI_DispStringHCenterAt( tab2, 240, 150 );
		
		th_GUI_counter++;
		sprintf( tab1, "%d", th_GUI_counter );
		(void)strncpy(tab2,"Refresh counts: ",30);
		(void)strncat(tab2,tab1,30);
		GUI_SetFont(&GUI_Font16_1);
		GUI_DispStringHCenterAt( tab2, 240, 100 );
		
		GUI_SetColor( GUI_ORANGE );
		
		if ( g_Touched_Cur.y < button_H && g_Touched_Cur.pressed )
		{
			if ( g_Touched_Cur.x < button_W )
				Clear_flag = 1;
			else if ( g_Touched_Cur.x < 2*button_W ) // g_Touched_Cur.x > button_W
				Brush_flag = !Brush_flag;
		}
		
		if ( Brush_flag )
		{
			GUI_DrawLineTo(g_Touched_Cur.x,g_Touched_Cur.y);
		}
		else
		{
			GUI_DrawPoint(g_Touched_Cur.x,g_Touched_Cur.y);
		}
		
		if ( Clear_flag )
		{
			Clear_flag = 0;
			GUI_Clear();
		}
		
		GUI_CURSOR_SetPosition(g_Touched_Cur.x,g_Touched_Cur.y);
		osMutexRelease(mid_GUI_Mutex);
		GUI_MEMDEV_CopyToLCD(h_MemDevMain);
		osThreadYield();
	}
}

void Hello_MSG(void) {

	GUI_SetColor(GUI_BLUE);
	GUI_SetFont(&GUI_Font16_1);
	GUI_DispStringHCenterAt("Oscyloskop cyfrowy v1.1" , 240, 150);
	GUI_DispStringHCenterAt("Adrian Kurylak" , 240, 175);
	GUI_DispStringHCenterAt("Politechnika Wroclawska" , 240, 200);
	GUI_SetFont(&GUI_Font32_1);
	GUI_DispStringHCenterAt("Inicjalizacja" , 240, 120);
	osDelay(250);
	GUI_DispStringHCenterAt("Inicjalizacja." , 240, 120);
	osDelay(500);
	GUI_DispStringHCenterAt("Inicjalizacja.." , 240, 120);
	osDelay(500);
	GUI_DispStringHCenterAt("Inicjalizacja..." , 240, 120);
	osDelay(750);
	GUI_Clear();
}

