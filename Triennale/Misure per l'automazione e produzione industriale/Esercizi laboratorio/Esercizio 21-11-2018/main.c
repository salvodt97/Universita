#include "stm32f30x.h"
//Convertire la tensione dalla linea PA0
//Devo capire la linea PA0 a quale linea di quale ADC sta, e lo vedo nel datasheet nel capitolo pinaouts(4). si va nella tabella 11, e voglio legare il suo pin non all'input o output, ma a ADC
//Il PA0 si trova sulla linea 1 di ADC1, cioè su ADC1_IN1: PA= deve essere quindi trattato come input analogico, scrivendo nel suo moder 11


float data=0;
void main(){
  //abilito GPIOA e ADC1
  //Imposto PA0 come analogica scrivendo 11 nel suo moder
  //Abilito il regolatore di tensione(ADVREGEN in ADC1->CR)
  //Aspetto 10 microsecondi
  //Configuro il clock(CKMODE in ADC12->CCR)
  //Avvio la calibrazione(ADCAL)
  //Aspetto la fine (ADCAL=0)
  //Abilito l'ADC(ADEN) e spetto che sia pronto(che ADRDY=1)
  //Configuto ADC1->SQR1 per fare una conversione del canale ADC1_IN1
  //Configuro SMP1
  //while(1){avvio la conversione (ADSTART) e aspetto la fine(EOC), risultato=ADC1->SR}

  
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->AHBENR |= RCC_AHBENR_ADC12EN;
  
  GPIOA->MODER |= GPIO_MODER_MODER0;
  ADC1->CR |= ADC_CR_ADVREGEN_1;
  for(int i=0; i<80000; i++);
  
  ADC1->CCR &=~ ADC12_CCR_CKMODE;
  ADC1->CR |= ADC_CR_ADCAL;
  
  while(1){
    if((ADC1->CR & ADC_CR_ADCAL)==0) break
  }
  
  ADC1->CR |= ADC_CR_ADEN;
  
  while(1){
    if((ADC1->CR & ADC_CR_ADRDY)==1) break
  }

}