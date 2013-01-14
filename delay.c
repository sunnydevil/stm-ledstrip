
#include "stm32f4xx.h"
#include <stdio.h>

volatile uint32_t system_time = 0;

void init_systick(void)
{
	RCC_ClocksTypeDef RCC_Clocks;

	// 10�s
	RCC_GetClocksFreq(&RCC_Clocks);
	if(0 != SysTick_Config(RCC_Clocks.SYSCLK_Frequency / 100000)) {
		while(1);
	}
}


void delay_ms(uint32_t ms)
{
	volatile uint32_t te = system_time + ms * 100;
	while(system_time < te);
}

void SysTick_Handler(void)
{
	system_time++;
}
