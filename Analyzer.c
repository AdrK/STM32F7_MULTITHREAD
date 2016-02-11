#include "analyzer.h"
#include "main.h"

		/****************************************************
			CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8
			PG7, PB4, PA8, PG6, PH6, PC6, PI3, PC7
		****************************************************/
		
// All needed macros are defined in header

#ifdef debug_mode
	void Analyzer_Init()
	{

		GPIO_InitTypeDef GPIO_InitStruct;
		__HAL_RCC_GPIOA_CLK_ENABLE();
		__HAL_RCC_GPIOB_CLK_ENABLE();
		__HAL_RCC_GPIOC_CLK_ENABLE();
		__HAL_RCC_GPIOG_CLK_ENABLE();
		__HAL_RCC_GPIOH_CLK_ENABLE();
		__HAL_RCC_GPIOI_CLK_ENABLE();
		
		GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
		GPIO_InitStruct.Pull = GPIO_PULLDOWN;
		GPIO_InitStruct.Speed = GPIO_SPEED_HIGH;
		
		GPIO_InitStruct.Pin = GPIO_PIN_4;								//PB4
		HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;	//PG6 & PG7
		HAL_GPIO_Init(GPIOG, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_8;								//PA8
		HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_6;								//PH6
		HAL_GPIO_Init(GPIOH, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;	//PC6 & PC7
		HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
		GPIO_InitStruct.Pin = GPIO_PIN_3;								//PI3
		HAL_GPIO_Init(GPIOI, &GPIO_InitStruct);
		
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_SET);//PG7
		HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);//PB4
		HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);//PA8
		HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,GPIO_PIN_SET);//PG6
		HAL_GPIO_WritePin(GPIOH,GPIO_PIN_6,GPIO_PIN_SET);//PH6
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_SET);//PC6
		HAL_GPIO_WritePin(GPIOI,GPIO_PIN_3,GPIO_PIN_SET);//PI3
		HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);//PC7
		
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_7);//PG7
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);//PB4
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8);//PA8
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_6);//PG6
		HAL_GPIO_TogglePin(GPIOH,GPIO_PIN_6);//PH6
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_6);//PC6
		HAL_GPIO_TogglePin(GPIOI,GPIO_PIN_3);//PI3
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_7);//PC7
		
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_7);//PG7
		HAL_GPIO_TogglePin(GPIOB,GPIO_PIN_4);//PB4
		HAL_GPIO_TogglePin(GPIOA,GPIO_PIN_8);//PA8
		HAL_GPIO_TogglePin(GPIOG,GPIO_PIN_6);//PG6
		HAL_GPIO_TogglePin(GPIOH,GPIO_PIN_6);//PH6
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_6);//PC6
		HAL_GPIO_TogglePin(GPIOI,GPIO_PIN_3);//PI3
		HAL_GPIO_TogglePin(GPIOC,GPIO_PIN_7);//PC7

	}
#else
	void Analyzer_Init() {}
#endif
