#include "stm32f30x.h"
#include <math.h>
#define MATR 3.208
#define PI 3.141592
#define N 20
#define PERIODI 6
#define AMPIEZZA 1
#define OFFSET 1.5

typedef double sinval[N];
typedef double ris[N*PERIODI];

void abilita();
void setup_DAC();
void setup_ADC();
void genera(double *);

void main(){
  sinval s;
  ris r;
  genera(s);
  abilita();
  GPIOA->MODER |= GPIO_MODER_MODER5;    //PA5 in modalità analogica
  GPIOF->MODER |= GPIO_MODER_MODER4;    //PF4 in modalità analogica
  
  setup_ADC();
  setup_DAC();
  
  for(int j=0; j<PERIODI*N; j++){
    for(int i=0; i<N; i++){
      DAC->DHR12R1 = (int)s[i];
      ADC1->CR |= ADC_CR_ADSTART;
      while((ADC1->ISR & ADC_ISR_EOC) != ADC_ISR_EOC);
      r[j]=ADC1->DR;
    }
  }
  
  double somma=0;
  for(int i=0; i<120; i++)
    somma=somma + pow(r[i]-OFFSET, 2);
  double veff=(double)sqrt(somma/N);
  
  double somma1=0;
  for(int i=0; i<120; i++)
    somma=somma+(r[i]-OFFSET);
 double media=(double)somma1/N;
  
}

void abilita(){
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;            //abilito GPIOA per PA5
  RCC->AHBENR |= RCC_AHBENR_GPIOFEN;            //abilito GPIOF per PF4
  RCC->AHBENR |= RCC_AHBENR_ADC12EN;            //abilito ADC
  RCC->APB1ENR |= RCC_APB1ENR_DACEN;            //abilito il DAC
}

void setup_DAC(){
  DAC->CR |= DAC_CR_EN1;
  DAC->CR |= DAC_CR_BOFF1;
}

void setup_ADC(){
  //abilito il regolatore di tensione mettendo 01 in ADVREGEN
  ADC1->CR &=~ ADC_CR_ADVREGEN_1;
  ADC1->CR |= ADC_CR_ADVREGEN_0;
  for(int i=0; i<1000; i++);            //aspetto 10 nano-secondi
  
  //imposto il clock a 01
  ADC1_2->CCR &=~ ADC12_CCR_CKMODE_1;
  ADC1_2->CCR |= ADC12_CCR_CKMODE_0;
  
  ADC1->CR |= ADC_CR_ADCAL;                       //avvio la calibrazione
  while((ADC1->CR & ADC_CR_ADCAL) != 0);          //aspetto la calibrazione
  
  ADC1->CR |= ADC_CR_ADEN;                              //abilito l'ADC
  while((ADC1->ISR & ADC_ISR_ADRD) != ADC_ISR_ADRD);
  
  //configuro ADC
  ADC1->CFGR &=~ ADC_CFGR_CONT;                 //CONT=0, conversione singola
  ADC1->SQR1 &=~ ADC_SQR1_L;
  ADC1->SMPR1 |= ADC_SMPR1_SMP1;                //tempo di sempling massimo
}

void genera(sinval s){
  for(int i=0; i<N; i++)
    s[i]=(double)(OFFSET+AMPIEZZA*sin((2*PI*(double)i)/N));
  
}