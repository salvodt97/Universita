#include "stm32f30x.h"
#include "core_cm4.h"

//Generiamo una tensione costante e acquisiamola con il converitore analogico digitale
//Dobbiamo abilitare la periferica; la corrispondente linea di GPIO devo vedere dove sta a pag 35 del datasheet, e trovo DAC1_OUT1 lo trovo su PA4, e DAC1_OUT2 su PA5
//devo legare i pin PA4 e PA2 per esempio: il DAC genera su PA4, e l'ADC prelva da PA2(il canale 3 di ADC1)
//in GPIAOA devo impostre PA4 e PA2 come analogci; dopo vado nel registro di controllo del DAC, dico il trigger esterno, e uso il trigger software

//1)Abilito DAc e GPIOA
//2) Metto PA4 in analogico
//3) DAC->CR: abiito il trigger(TEN), configuro il trigger software(TSEL), abilito il canale OUT1 (EN1)
//4) Scrivo il codice K=Vout*4095/3  in DHR12R1
//5) Do il trigge software SWTRIG1
//6) Acquisisco la rtensione da PA2

float codice;
void main(){
  
  //Abilito le periferiche
   RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
   RCC->AHBENR |= RCC_AHBENR_ADC12EN;
   RCC->APB1ENR |= RCC_APB1ENR_DACEN;
   
   //Imposto le linee come analogoche
   GPIOA->MODER |= GPIO_MODER_MODER4;
   GPIOA->MODER |= GPIO_MODER_MODER2;
   
   //Configuro il Dac
   DAC->CR |= DAC_CR_TEN1;
   DAC->CR |= DAC_CR_TSEL1;
   DAC->CR |= DAC_CR_EN1;
   
   codice = 2730;
   DAC->DHR12R1 = codice;
   DAC->SWTRIGR |= DAC_SWTRIGR_SWTRIG1;
   for(int i=0; i<1000; i++);
   
   ADC1->CR |= ADC_CR_ADVREGEN_0;
   ADC1->CR &=~ ADC_CR_ADVREGEN_1;
   ADC1->CCR &=~ ADC12_CCR_CKMODE;
   


}