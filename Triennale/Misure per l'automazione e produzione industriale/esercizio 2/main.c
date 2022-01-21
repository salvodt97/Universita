#include "stm32f30x.h"
#include <math.h>
#define n 100

//traccia pag 17 di "Tracce mapi"

short int LUT[n];
short int LUT2[n];

void abilita_periferiche();
void disabilita_periferiche();
void setup_ADC();
void setup_DAC();
void setup_TIM2();
void setup_DMA1();
void setup_DMA2();
void fseno();
void setup_user_interrupt();
void abilita_led_user();

void main()
{
  fseno();
  abilita_periferiche();
  abilita_led_user();
  
  setup_DMA1();
  setup_DMA2();
  setup_DAC();
  setup_ADC();
  setup_user_interrupt();
  setup_TIM2();
  
  TIM2->CNT=0;
  
   
  while(1);
 /* {
     if((GPIOA->IDR & GPIO_IDR_0)==1)
    {
      ADC1->CR|=ADC_CR_ADSTART;
     GPIOE->ODR=0x0000FF00;
    }
    if((GPIOA->IDR & GPIO_IDR_0)==1)
    {
 //      ADC1->CR|=ADC_CR_ADSTP;
      GPIOE->ODR&=~ 0x0000FF00;
    }
  }*/
  
  disabilita_periferiche();
}


void abilita_periferiche()
{
   RCC->AHBENR|= RCC_AHBENR_GPIOAEN | RCC_AHBENR_GPIOEEN | RCC_AHBENR_ADC12EN;
   RCC->AHBENR|= RCC_AHBENR_DMA1EN | RCC_AHBENR_DMA2EN;
   RCC->APB1ENR |= RCC_APB1ENR_DACEN | RCC_APB1ENR_TIM2EN;
    RCC->APB2ENR |=  RCC_APB2ENR_SYSCFGEN;  //--> registro per NVIC
}

void abilita_led_user()
{
  GPIOE->MODER|=0x55550000;
  GPIOA->MODER&=~ GPIO_MODER_MODER0;            //user come input
}

void disabilita_periferiche()
{
 ADC1->CR|=ADC_CR_ADDIS;
 DAC->CR &=~ DAC_CR_EN1;
 DMA1_Channel1->CCR &=~ DMA_CCR_EN;  
 DMA2_Channel3->CCR &=~ DMA_CCR_EN;   
}

void fseno()
{
  float Vsin;
  for(int i=0; i<n;i++)
  {
    Vsin=1.5+1.5*sin(2*i*3.14/n);
    LUT[i]=(short int)(Vsin*4095.0/3.0);
  }
}

void setup_TIM2()
{
  TIM2->ARR=76923076;   //t=1s
  TIM2->CR2 |= TIM_CR2_MMS_1;
 // TIM2->CNT=0;
  TIM2->DIER|=TIM_DIER_UIE;
  NVIC->ISER[1]|=1<<23;
}

void setup_user_interrupt()
{
   NVIC->ISER[0]|= 1<<6;
   SYSCFG->EXTICR[0]|=SYSCFG_EXTICR1_EXTI0_PA;
   EXTI->IMR|= EXTI_IMR_MR0;
   EXTI->RTSR|= EXTI_RTSR_TR0;         //fronte di salita
}

void setup_ADC()
{
  ADC1->CR &=~ ADC_CR_ADVREGEN_0;
  ADC1->CR &=~ ADC_CR_ADVREGEN_1;
  for(int i=0; i<1000;i++);
  
  ADC1_2->CCR |= ADC12_CCR_CKMODE_0;
  
  ADC1->CR|= ADC_CR_ADCAL;
  while((ADC1->CR & ADC_CR_ADCAL)==ADC_CR_ADCAL);
  
  ADC1->CR|= ADC_CR_ADEN;
  while((ADC1->ISR & ADC_ISR_ADRD)!=ADC_ISR_ADRD);
  
  ADC1->CFGR &=~ ADC_CFGR_CONT;
  
  ADC1->CFGR|= ADC_CFGR_DMAEN;
  ADC1->CFGR|= ADC_CFGR_EXTEN_0;
  ADC1->CFGR|= 11<<6;
  
  ADC1->SQR1|=3<<6;
  ADC1->SQR1 &=~ ADC_SQR1_L;
  ADC1->SMPR1|= ADC_SMPR1_SMP3;
}

void setup_DAC()
{
  DAC->CR|=DAC_CR_TEN1 | DAC_CR_TSEL1_2;
  DAC->CR |= DAC_CR_DMAEN2;
  DAC->CR |= DAC_CR_EN1;
}

void setup_DMA1()
{
 DMA1_Channel1->CPAR=(uint32_t)&ADC1->DR;
 DMA1_Channel1->CMAR=(uint32_t)LUT2;
 DMA1_Channel1->CNDTR=n;
 DMA1_Channel1->CCR|=DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_0; 
 DMA1_Channel1->CCR|=DMA_CCR_MINC;        //incremento la memoria
 DMA1_Channel1->CCR&=~ DMA_CCR_DIR;     //trasferimento da periferica a memoria
 DMA1_Channel1->CCR|=DMA_CCR_EN;
}

void setup_DMA2()
{
 DMA2_Channel3->CPAR=(uint32_t)&DAC->DHR12R1;
 DMA2_Channel3->CMAR=(uint32_t)LUT;
 DMA2_Channel3->CNDTR=n;
 DMA2_Channel3->CCR|=DMA_CCR_MSIZE_0 | DMA_CCR_PSIZE_0; 
 DMA2_Channel3->CCR|=DMA_CCR_MINC;              //incremento la memoria
 DMA2_Channel3->CCR|= DMA_CCR_CIRC; 
 DMA2_Channel3->CCR|= DMA_CCR_DIR;   //trasferimento da memoria a periferica
 DMA2_Channel3->CCR|=DMA_CCR_EN;
}


void EXTI0_IRQHandler()
{
  EXTI->PR|= EXTI_PR_PR0;

//premo il pulsante e inizia la conversione
   if((GPIOA->IDR & GPIO_IDR_0)==1)     
  {
   TIM2->CR1|= TIM_CR1_CEN;
   ADC1->CR|=ADC_CR_ADSTART;
    GPIOE->ODR=0x0000FF00;
  }
   
/*premo di nuovo il pulsante e si ferma la conversione  ---> ????
  if((GPIOA->IDR & GPIO_IDR_0)==1)     
  {
      ADC1->CR|=ADC_CR_ADSTP;
     TIM2->CR1&=~ TIM_CR1_CEN;
     GPIOE->ODR&=~ 0x0000FF00;
  }*/
  
}