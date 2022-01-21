//generiamo una tensione costante e acquisiamola con il convertitore analogico digitale
//Dobbiamo abilitare la periferica: prendo il datashett, pag 35 e vedo che  su PA4 trovo DAC1_OUT1 e su PA5 trovo DAC1_OUT2
//devo allora legare un convertitore AC con un DC e quindi prendo un jumper e li collego
// in GPIOA devo abilitare come digitale PA4 e PA2.
//vado nel registro di controllo del DAC, dico il trigger esteno e uso il trigger software.

#include <stdio.h>
#include "stm32f30x.h"
#include "core_cm4.h"

void main(){
  int codice_in=500;
  float tensione_out;
  float tensione_in;
  int codice_out;
  
  //abilito le periferiche
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; //abilito la perifericha GPIOA
  RCC->AHBENR |= RCC_AHBENR_ADC12EN; //abilito la periferica ADC12
  RCC->APB1ENR |= RCC_APB1ENR_DACEN; //abilito DAC1
  
  //devo abilitare PA4 e PA2 in modalità analogico
  GPIOA->MODER |= GPIO_MODER_MODER4;
  GPIOA->MODER |= GPIO_MODER_MODER2;
  
  //operazioni sul DAC
  DAC->CR |= DAC_CR_TEN1; 
  DAC->CR |= DAC_CR_TSEL1; //abilito il tsel
  DAC->CR |= DAC_CR_EN1; //abilito il canale
  printf("La tensione Vout che si vuole misurare è : %d", codice_in);
  DAC->DHR12R1 = 500; //scrivo il valore nel DHR
  DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
  for(int i=0; i<1000; i++); //attendo che passi il tempo per generare la tensione
  
  //operazioni sul ADC
  ADC1->CR &=~ADC_CR_ADVREGEN_1; //abilito il regolatore di tensione passando i bit da 10 a 00
  ADC1->CR |= ADC_CR_ADVREGEN_0; //e da 00 a 01
  for(int i=0; i<1000; i++);     //aspetto un tempo di 10 us
  
  //configuro il clock
  ADC1_2->CCR |= ADC12_CCR_CKMODE_0;
  
  //calibro ADC
  ADC1->CR |= ADC_CR_ADCAL;
  while((ADC1->CR & ADC_CR_ADCAL) == ADC_CR_ADCAL); //attesa ADCA=0
  
  //abilito ADC
  ADC1->CR |= ADC_CR_ADEN;
  while((ADC1->ISR & ADC_ISR_ADRD) != ADC_ISR_ADRD);
  
  //configuro ADC
  ADC1->CFGR &=~ ADC_CFGR_CONT;
  ADC1->SQR1 = (3<<6);  //SQ1=00011: canale 3->PA2
  ADC1->SQR1 &=~ ADC_SQR1_L;  //L=0->1 conversione
  ADC1->SMPR1 |= ADC_SMPR1_SMP3; //smp3=111, cioè 601.5ck
  
  //effettua la conversione
  ADC1->CR |= ADC_CR_ADSTART;   
  while((ADC1->ISR & ADC_ISR_EOC) != ADC_ISR_EOC); //fin quando non ho EOC=1 si va avanti
  
  //calcolo il risultato del DAC
  tensione_out = codice_in *(3.0/4095.0);
  printf("\nDAC\n");
  printf("Ingresso: %d", codice_in);
  printf("\nUscita: %f", tensione_out);
  
  //risultato ADC
  codice_out = ADC1->DR;
  tensione_in = codice_out*(3.0/4096.0);
  printf("\nADC");
  printf("\nIngresso: %f", tensione_in);
  printf("\nUscita: %d", codice_out);
  
  //disabilito ADC e DAC
  ADC1->CR |= ADC_CR_ADDIS;
  DAC->CR &=~ DAC_CR_EN1;
  
  while(1);
  
  
  
  
  
}