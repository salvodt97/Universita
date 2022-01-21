#include "stm32f30x.h"
#include <math.h>
#define N_DAC 200       //campioni del dac
#define N_ADC 73        //campioni di adc
#define AMPIEZZA 1000
#define OFFSET 2048
#define MATR 3208
#define PI 3.141592

int sinval[N_DAC] =  {0};        //array che ha i campioni da generare
int ris[N_ADC*15] = {0};         //array dei risultati(15 periodi di 73 campioni)
int k=0;
double ARRADC = 0;
double ARRDAC = 0;
double PSCADC = 0;


void genera(int, int, int, int *);
void abilita();
void setup_DMA2(int *, int);
void setup_ADC();
void setup_DAC();
void setup_TIM2(int);
void setup_TIM3(int, int);


void main(){
  genera(AMPIEZZA, N_DAC, OFFSET, sinval);      //genero la sinusoide
  abilita();
  //abilito PA2 e PA4 in modalità analogica
  GPIOA->MODER |= GPIO_MODER_MODER4;
  GPIOA->MODER |= GPIO_MODER_MODER2;
  
  setup_DAC();
  ARRDAC = ((double)MATR*pow(10, -3)*72*pow(10, 6)/(double)N_DAC);
  setup_TIM2((int)ARRDAC);
  setup_DMA2(sinval, N_DAC);
  
  setup_ADC();
  PSCADC=999;
  ARRADC=((double)MATR*pow(10, -3)*72*pow(10, 6)/(double)(N_ADC*(PSCADC+1)));
  setup_TIM3((int)PSCADC, (int)ARRADC);
  
  TIM2->CR1 |= TIM_CR1_CEN;	//avvio il conteggio di TIM2
  TIM3->CR1 |= TIM_CR1_CEN;	//avvio il conteggio di TIM3
  
  while(k<(N_DAC*15));          //attendo la generazione dei 1095 valori in 15 periodi
  ADC1->IER &=~ ADC_IER_EOC;    //termine della conversione
  NVIC->ISER[0] &=~ (1<<18);

}

void genera(int amp, int n, int offset, int * ptr){
  for(int i=0; i<n; i++)
    ptr[i] = (int)(offset+(amp*sinf(2*PI*(double)i/(double)n)));
}

void abilita(){
  RCC->AHBENR |= RCC_AHBENR_DMA2EN;             //abilito dma2
  RCC->AHBENR |=  RCC_AHBENR_GPIOAEN;           //abilito gpioa
  RCC->AHBENR |= RCC_AHBENR_ADC12EN;            //abilito adc
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;           //abilito il timer tim2
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;		//abilito il timer tim3
  RCC->APB1ENR |= RCC_APB1ENR_DACEN;            //abilito il dac
}

void setup_DMA2(int * ind_per, int n){
  DMA2_Channel3->CMAR = (uint32_t)&DAC->DHR12R1;       //indirizzo memoria
  DMA2_Channel3->CPAR = (uint32_t)ind_per;              //indirizzo periferica
  DMA2_Channel3->CNDTR = n;                             //numero di elementi da trasferire(200 campioni);
  DMA2_Channel3->CCR |= DMA_CCR_MSIZE_0;                //dimensione memoria
  DMA2_Channel3->CCR |= DMA_CCR_PSIZE_0;                //dimensione periferica
  DMA2_Channel3->CCR |= DMA_CCR_MINC;                   //incremento la memoria
  DMA2_Channel3->CCR |= DMA_CCR_PINC;                   //incremento automatico della periferica
  DMA2_Channel3->CCR |= DMA_CCR_CIRC;                   //imposto la modalità circolare così da generare infiniti periodi
  DMA2_Channel3->CCR |= DMA_CCR_EN;                     //abilito il canale 3 del dma2
}
 
void setup_ADC(){
  //abilito regolatore di tensione(metto 01 in ADVREGEN)
  ADC1->CR &=~ ADC_CR_ADVREGEN_1;
  ADC1->CR |= ADC_CR_ADVREGEN_0;
  for(int i=0; i<1000; i++);                             //aspetto l'abilitazione
  
  //configuro il clock mettendo 01 CKMODE
  ADC1_2->CCR |= ADC12_CCR_CKMODE_0;          
  ADC1_2->CCR &=~ ADC12_CCR_CKMODE_1;
  
  ADC1->CR |= ADC_CR_ADCAL;                              //abilito ADCAL=1 per iniziare la claibrazione
  while((ADC1->CR & ADC_CR_ADCAL) != ADC_ISR_ADRD);      //aspetto che ADCAL=0, coè termina la calibrazione
  
  ADC1->CR |= ADC_CR_ADEN;                               //abilito adc mettendo ADEN=1
  while((ADC1->ISR & ADC_ISR_ADRD) != ADC_ISR_ADRD);     //aspetto che ADRDY=1
  
  //configuro ADC
  ADC1->CFGR &=~ ADC_CFGR_CONT;                          //CONT=0, conversione singola
  ADC1->SQR1 |= (3<<6);                                  //ho messo SQR1=00011 per impostare il canale 3 di PA2
  ADC1->SQR1 &=~ ADC_SQR1_L;                             //con L=0 dico che sto facendo una conversione
  ADC1->SMPR1 |= ADC_SMPR1_SMP1;                         //imposto il tempo di sampling massimo
  
  //devo campionare quando scatta il timer dell'adc
  ADC1->IER |= ADC_IER_EOC;                             //aspetto la fine della conversione
  NVIC->ISER[0] |= (1<<18);                   //ho abilitato l'interrupt dell' ADC
  
}

void setup_DAC(){
  DAC->CR |= DAC_CR_EN1;                //abilito il DAC;
  DAC->CR |= DAC_CR_TEN1;               //abilito il trigger;
  DAC->CR |= DAC_CR_BOFF1;              //abilito il buffer di output per mantenere la tensione
  
  //dico che il trigger viene da tim2 mettendo 100 in TSEL
  DAC->CR |= DAC_CR_TSEL1_2;
  DAC->CR &=~ DAC_CR_TSEL1_2;
  DAC->CR |=~ DAC_CR_TSEL1_2;
  
  DAC->CR |= DAC_CR_DMAEN1;             //abilito la modalità DMA;
}


void TIM3_IRQHandler(){
  TIM3->SR &=~ TIM_SR_UIF;      //resetto UIF
  ADC1->CR |= ADC_CR_ADSTART;   //inizio la conversione
}

void ADC1_2_IRQHandler(){
  ADC1->ISR &=~ ADC_ISR_EOC;                    //resetto EOC
    if(ADC1->DR != 0 && ADC1->DR != 1)
      ris[k++]=ADC1->DR;
  }

void setup_TIM2(int arr){
  TIM2->ARR = arr;
  TIM2->CR2 = TIM_CR2_MMS_1;            //MSS=010 serve a far scattare il trigger
}

void setup_TIM3(int psc, int arr){
  TIM3->ARR = arr;
  TIM3->PSC = psc;
  TIM3->CR2 = TIM_CR2_MMS_1;            //fa scattare il trigger
  TIM3->DIER |= TIM_DIER_UIE;           //serve ad abilitare l'interrupt
  NVIC->ISER[0] |= (1<<29);
}