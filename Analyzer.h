void Analyzer_Init(void);

		/****************************************************
			CH1, CH2, CH3, CH4, CH5, CH6, CH7, CH8
			PG7, PB4, PA8, PG6, PH6, PC6, PI3, PC7
		****************************************************/
		
#ifdef debug_mode
	// Set
	#define Anal_CH1_Set();	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_SET);//PG7
	#define Anal_CH2_Set();	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_SET);//PB4
	#define Anal_CH3_Set();	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_SET);//PA8
	#define Anal_CH4_Set();	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,GPIO_PIN_SET);//PG6
	#define Anal_CH5_Set();	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_6,GPIO_PIN_SET);//PH6
	#define Anal_CH6_Set();	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_SET);//PC6
	#define Anal_CH7_Set();	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_3,GPIO_PIN_SET);//PI3
	#define Anal_CH8_Set();	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_SET);//PC7
	// Reset
	#define Anal_CH1_Reset();	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_7,GPIO_PIN_RESET);//PG7
	#define Anal_CH2_Reset();	HAL_GPIO_WritePin(GPIOB,GPIO_PIN_4,GPIO_PIN_RESET);//PB4
	#define Anal_CH3_Reset();	HAL_GPIO_WritePin(GPIOA,GPIO_PIN_8,GPIO_PIN_RESET);//PA8
	#define Anal_CH4_Reset();	HAL_GPIO_WritePin(GPIOG,GPIO_PIN_6,GPIO_PIN_RESET);//PG6
	#define Anal_CH5_Reset();	HAL_GPIO_WritePin(GPIOH,GPIO_PIN_6,GPIO_PIN_RESET);//PH6
	#define Anal_CH6_Reset();	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_6,GPIO_PIN_RESET);//PC6
	#define Anal_CH7_Reset();	HAL_GPIO_WritePin(GPIOI,GPIO_PIN_3,GPIO_PIN_RESET);//PI3
	#define Anal_CH8_Reset();	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_7,GPIO_PIN_RESET);//PC7
#else
	// Set
	#define Anal_CH1_Set();
	#define Anal_CH2_Set();
	#define Anal_CH3_Set();
	#define Anal_CH4_Set();
	#define Anal_CH5_Set();
	#define Anal_CH6_Set();
	#define Anal_CH7_Set();
	#define Anal_CH8_Set();
	// Reset
	#define Anal_CH1_Reset();
	#define Anal_CH2_Reset();
	#define Anal_CH3_Reset();
	#define Anal_CH4_Reset();
	#define Anal_CH5_Reset();
	#define Anal_CH6_Reset();
	#define Anal_CH7_Reset();
	#define Anal_CH8_Reset();
#endif
