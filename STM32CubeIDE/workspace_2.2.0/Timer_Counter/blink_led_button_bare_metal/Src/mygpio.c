#include <stdint.h>
#include "mygpio.h"

void delay_ms(uint32_t delay){
	RCC_APB1ENR |= (1U << 0);

	TIM2->PSC = 15999;
	TIM2->ARR = delay;
	TIM2->CNT = 0;
	TIM2->SR = 0;

	TIM2->CR1 |= (1U << 0);

	while((TIM2->SR & (1U << 0)) == 0){

	}

	TIM2->CR1 &= ~(1U << 0);
	TIM2->SR = 0;
}

void GPIO_init(GPIO_typeDef *port,uint8_t pin, uint8_t mode){
	if(port == GPIOD){
		RCC_AHB1ENR |= (1U << 3);
	}
	if(port == GPIOA){
		RCC_AHB1ENR |= (1U << 0);
	}

	if(mode == GPIO_PIN_OUTPUT){
		GPIOD->MODER &= ~(3U << (pin*2));
		GPIOD->MODER |= (1U << (pin*2));
	}

	GPIOA->MODER &= ~(3U << 0);
}
void GPIO_PIN_WRITE(GPIO_typeDef *port, uint8_t pin, uint8_t mode){
	if(mode == GPIO_PIN_SET){
		uint8_t pr;
		if(pin == 15){
			pr = 31;
		}
		if(pin == 14){
			pr = 30;
		}
		if(pin == 13){
			pr = 29;
		}
		if(pin == 12){
			pr = 28;
		}
				GPIOD->BSRR |= (1U << pin);
				delay_ms(100);
				GPIOD->BSRR |= (1U << pr);
				delay_ms(100);
	}
	else{
		port->ODR &= ~(1U << pin);
	}
}

uint8_t GPIO_PIN_READ(GPIO_typeDef *port, uint8_t mode){
	if(port->IDR & (1U << 0)){
		return 1;
	}
	else{
		return 0;
	}
}


