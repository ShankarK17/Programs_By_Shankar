#include <stdint.h>



#define PERIP_BASE (0x40000000UL)
#define AHB1_PERIP_BASE (PERIP_BASE + 0x00020000UL)
#define APB1_PERIP_BASE PERIP_BASE

#define GPIOA_BASE (AHB1_PERIP_BASE + 0x0000UL)
#define GPIOD_BASE (AHB1_PERIP_BASE + 0x0C00UL)

#define GPIO_PIN_INPUT 0
#define GPIO_PIN_OUTPUT 1

#define GPIO_PIN_SET 1
#define GPIO_PIN_RESET 0

#define RCC_BASE (AHB1_PERIP_BASE + 0x3800UL)


#define RCC_APB1ENR *(volatile uint32_t *)(RCC_BASE + 0x40)

#define TIM2_BASE (APB1_PERIP_BASE + 0x0000UL)

typedef struct {
	volatile uint32_t MODER;
	volatile uint32_t OTYPER;
	volatile uint32_t OSPEEDR;
	volatile uint32_t PUPDR;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
} GPIO_typeDef;

#define GPIOA ((GPIO_typeDef *) GPIOA_BASE)
#define GPIOD ((GPIO_typeDef *) GPIOD_BASE)

typedef struct
{
  volatile uint32_t CR1;
  volatile uint32_t CR2;
  volatile uint32_t SMCR;
  volatile uint32_t DIER;
  volatile uint32_t SR;
  volatile uint32_t EGR;
  volatile uint32_t CCMR1;
  volatile uint32_t CCMR2;
  volatile uint32_t CCER;
  volatile uint32_t CNT;
  volatile uint32_t PSC;
  volatile uint32_t ARR;
  volatile uint32_t RCR;
  volatile uint32_t CCR1;
  volatile uint32_t CCR2;
  volatile uint32_t CCR3;
  volatile uint32_t CCR4;
  volatile uint32_t BDTR;
  volatile uint32_t DCR;
  volatile uint32_t DMAR;
  volatile uint32_t OR;
} TIM_typeDef;


#define TIM2 ((TIM_typeDef *) (TIM2_BASE))

#define RCC_AHB1ENR *(volatile uint32_t *)(RCC_BASE + 0x30)

void GPIO_init(GPIO_typeDef *,uint8_t, uint8_t);
void GPIO_PIN_WRITE(GPIO_typeDef *, uint8_t, uint8_t);
uint8_t GPIO_PIN_READ(GPIO_typeDef *, uint8_t);
void delay_ms(uint32_t );

