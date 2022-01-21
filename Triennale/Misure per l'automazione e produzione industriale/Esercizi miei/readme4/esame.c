#include "stm32f30x.h"
#include "core_cm4.h"
#define MATRICOLA 3.208

void abilita();
void setup_TIM7();
void setup_EXTI();
void EXTI0_IRQHandler();

int i=0;

void main(){
  abilita();
  GPIOE->MODER |= 0x55550000;             //da PE8 a PE15 come output digitale
  GPIOA->MODER &=~ GPIO_MODER_MODER0;    //PA0 come input digitale
  setup_TIM7();
  setup_EXTI();
  
  TIM7->CNT = 0;
  TIM7->CR1 |= TIM_CR1_CEN;
  
  
  while(1){
    if((TIM7->SR & TIM_SR_UIF) == TIM_SR_UIF){
      TIM7->SR &=~ TIM_SR_UIF;
      GPIOE->ODR = (1 << (i++)%8 + 8);
    }
  }
}

void abilita(){
  RCC->APB1ENR |= RCC_APB1ENR_TIM7EN;
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
}

void setup_TIM7(){
  TIM7->ARR = ((MATRICOLA * 8000000)/(999+1));
  TIM7->PSC = 999;
  TIM7->CR1 |= TIM_CR1_ARPE;            //Sto facendo il polling così
}

void setup_EXTI(){
  SYSCFG->EXTICR[1] &=~ 7;  //L'interrupt è del pin PA
  EXTI->IMR |= EXTI_IMR_MR0;                    //Dico che l'interrupt arriva dalla linea 0
  EXTI->RTSR |= EXTI_RTSR_TR0;                  //Trigger sul fronte di salita
  NVIC->ISER[0] |= (1<<6);
}

void EXTI0_IRQHandler(){
  EXTI->PR |= EXTI_PR_PR0;              //Cancello il pending request
  if((((TIM7->ARR)/2)/((TIM7->PSC)+1))<0.1)
    TIM7->ARR = ((MATRICOLA * 8000000)/(999+1));
  else TIM7->ARR = (TIM7->ARR)/2;
}