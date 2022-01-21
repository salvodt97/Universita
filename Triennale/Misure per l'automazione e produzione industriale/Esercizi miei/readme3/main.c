#include "stm32f30x.h"
#include "core_cm4.h"
#include <math.h>

#define MATRICOLA 3.208
#define tck pow(10, -6)

void abilita();
void setup_DAC();
void setup_TIM2();
void setup_EXTI4();
void EXTI4_IRQHandler();

double tempo[1000]= {0};
int flag=0;

void main(){
  
  abilita();
  GPIOA->MODER |= GPIO_MODER_MODER5;
  GPIOF->MODER |= GPIO_MODER_MODER4;
  
  setup_DAC();
  setup_TIM2();
  setup_EXTI4();
  
  while(1){
    TIM2->CR1 |= TIM_CR1_CEN;
    TIM2->CNT = 0;
    DAC->DHR12L1 = 0;                                   //metto il valore basso nel DAC
    while((TIM2->SR & TIM_SR_UIF) != TIM_SR_UIF);       //Lo continuo a mettere fino a quando il conteggio di TIM2 non è finito
    TIM2->SR &=~ TIM_SR_UIF;
    TIM2->CR1 &=~ TIM_CR1_CEN;                          //Finito il conteggio, lo disabilito
    TIM2->CR1 |= TIM_CR1_CEN;                           //Lo riabilito
    TIM2->CNT = 0;                                      //tolgo quello che c'era dentro
    DAC->DHR12L1 = 3;                                   //Ora metto nel DAC il valor basso
    while((TIM2->SR & TIM_SR_UIF) != TIM_SR_UIF);       //Aspetto di nuovo
    TIM2->CR1 &=~ TIM_CR1_CEN;
    TIM2->SR &=~ TIM_SR_UIF;
    flag=1;                                             //Metto flag=1, significa che il periodo è passato
  }
  
  float media=3/2       //la media è il prodotto tra il periodo l'integrale estesa al periodo del segnale: in quaetso caso il segnale vale 3 solo
  //nel mezzo periodo, quindi la media è media=(1/MATRICOLA)*3*(MATRICOLA/2)

}

void abilita(){
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOFEN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM6EN;
  RCC->APB1ENR |= RCC_APB1ENR_DACEN;  
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;           //il TIM2 lo sudo per generare l'onda quadra di periodo 3.208
}

void setup_DAC(){
  DAC->CR |= DAC_CR_EN1;
  DAC->CR |= DAC_CR_BOFF1;
  DAC->CR |= DAC_CR_TEN1;
  //Abilito il trigger su TIM2 mettendo 100 in TSEL
  DAC->CR |= DAC_CR_TSEL1_2;
  DAC->CR &=~ DAC_CR_TSEL1_1;
  DAC->CR &=~ DAC_CR_TSEL1_0;
}

void setup_TIM2(){
  TIM2->ARR = (MATRICOLA/2)*72000000;
}

void setup_EXTI4(){
  SYSCFG->EXTICR[2] |= SYSCFG_EXTIRCR_EXTI4_PF;         //abilito exti su PF4
  EXTI->IMR |= EXTI_IMR_MR4;                            
  EXTI->RTSR |= EXTI_RTSR_TR4;                          //trigger fronte di salita
  NVIC->ISER[0] |= (1<<10);
}

void EXTI4_IRQHandler(){
  EXTI->PR &=~ EXTI_PR_PR4;
  for(int i=0; i<1000; i++){
    TIM6->CR1 |= TIM_CR1_CEN;                   //nella irq inizio a contare su TIM6
    TIM6->CNT = 0;
    while(flag!=1);                             //Aspetto che flag=1, cioè è passato il periodo
    TIM6->CR1 &=~ TIM_CR1_CEN;                  //allora disabilito il conteggio
    tempo[i]=(double)(tck*(TIM6->CNT));            
    flag=0;
  }
}