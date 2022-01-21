#include "stm32f30x.h"
#include <math.h>
#define AMPIEZZA 1
#define OFFSET 1.5
#define MATRICOLA 3.208
#define N_DAC 100
#define N_ADC 50
#define PERIODI 5

double campioni_DAC[N_DAC];
double campioni_ADC[N_ADC*PERIODI];

void abilita();
void setup_TIM2();
void setup_DAC();
void setup_ADC();
void setup_DMA();
void genera();

void main(){
  abilita();
  genera();
  GPIOA->MODER |= GPIO_MODER_MODER2;
  GPIOA->MODER |= GPIO_MODER_MODER4;
  setup_TIM2();
  setup_DAC();
  setup_ADC();
  setup_DMA();
  
  TIM2->CR1 |= TIM_CR1_CEN;
  
  for(int i=0; i<N_ADC*PERIODI; i++){
    ADC1->CR |= ADC_CR_ADSTART;
    while((ADC1->ISR & ADC_ISR_EOC) != ADC_ISR_EOC);
    campioni_ADC[i] = ADC1->DR;
  }
  
  double somma=0;
  for(int i=0; i<N_ADC*PERIODI; i++)
    somma=somma + pow(campioni_ADC[i] - OFFSET, 2);
  double veff=(double)sqrt(somma/MATRICOLA);
  
}

void abilita(){
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; 
  RCC->AHBENR |= RCC_AHBENR_DMA2EN;
  RCC->AHBENR |= RCC_AHBENR_ADC12EN;
  RCC->APB1ENR |= RCC_APB1ENR_DACEN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
}

void setup_DAC(){
  DAC->CR |= DAC_CR_EN1;
  DAC->CR |= DAC_CR_BOFF1;
  DAC->CR |= DAC_CR_TEN1;       //abilito il trigger, per dire il periodo con il qiale il DAC genera
  
  DAC->CR |= DAC_CR_TSEL1_2;    //dico che il trigger viene da TIM2 mettendo 100 in TSEL
  DAC->CR &=~ DAC_CR_TSEL1_1;
  DAC->CR &=~ DAC_CR_TSEL1_0;
  
  DAC->CR |= DAC_CR_DMAEN2;
}

void setup_TIM2(){
  TIM2->ARR = MATRICOLA * 72000000;
  TIM2->CR2 |= TIM_CR2_MMS_1;
  TIM2->CNT = 0;
}

void setup_ADC(){
  ADC1->CR &=~ ADC_CR_ADVREGEN_1;
  ADC1->CR |= ADC_CR_ADVREGEN_0;
  for(int i=0; i<1000; i++);
  
  ADC1->CR |= ADC_CR_ADCAL;
  for(int i=0; i<1000000; i++);
  //while((ADC1->CR & ADC_CR_ADCAL) == ADC_CR_ADCAL);
  
  ADC1_2->CCR &=~ ADC12_CCR_CKMODE_1;
  ADC1_2->CCR |= ADC12_CCR_CKMODE_0;
  
  ADC1->CR |= ADC_CR_ADEN;
  while((ADC1->ISR & ADC_ISR_ADRD) != ADC_ISR_ADRD);
  
  ADC1->CFGR &=~ ADC_CFGR_CONT;
  ADC1->SQR1 &=~ ADC_SQR1_L;
  ADC1->SMPR1 |= ADC_SMPR1_SMP1;
  ADC1->SQR1 |= (3<<6);
}

void setup_DMA(){
  DMA2_Channel3->CPAR |= (uint32_t)&DAC->DHR12R1;       //la periferica su cui devo portare i dati è il DAC(il registro l'ho scelto io)
  DMA2_Channel3->CMAR |= (uint32_t)campioni_DAC;        //i dati stanno nel vettore, cioè li prendo dalla memoria
  DMA2_Channel3->CNDTR = N_DAC;
  DMA2_Channel3->CCR |= DMA_CCR_CIRC;
  DMA2_Channel3->CCR |= DMA_CCR_PINC;
  DMA2_Channel3->CCR |= DMA_CCR_MINC;
  DMA2_Channel3->CCR |= DMA_CCR_PSIZE_0;
  DMA2_Channel3->CCR |= DMA_CCR_MSIZE_0;
  DMA2_Channel3->CCR |= DMA_CCR_DIR;                    //quindi la direzione è memoria->periferica(DIR=1)
  DMA2_Channel3->CCR |= DMA_CCR_EN;
}

void genera(){
  for(int i=0; i<N_DAC; i++)
    campioni_DAC[i]=(double)(AMPIEZZA*((i*(N_DAC-1))/N_DAC)+OFFSET); 
}
  
 