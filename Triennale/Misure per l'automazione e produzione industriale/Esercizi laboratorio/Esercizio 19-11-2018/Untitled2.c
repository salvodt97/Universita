#include "stm32f30x.h"
#include "core_cm4.h"

//realizzare con gli 8 led un contator binario di secondi, generando un interrupt ogni secondo:quando viene premuto il pulsante, il conteggio si deve azzerare
//gestiamo quindi un interrupt quando si accende il pulsante, cioè si alza la linea PA0, quindi è un'interrupt di una linea esterna
//1) devo abilitare PA0 come linea digitale
//2) abilitare gli 8 led come contatore di secondi
//3) incrementare il conta
//4) associo a EXTI0 la linea PA0(si a nella periferica SYSCFG con il registro EXTICR1)
//lo vedo quindi nel capitolo 10 del refman: del registro si usano solo gli ultimi 16 bit, divisi in gruppi di 4 bit: i primi 4 sono EXTI3, gli ultii 4 EXTI0. Quindi scrivo nella parte EXTI0 x000(con x che può essere 0 o 1)
//così EXTI0 viene legato alla linea PA0(che di default ci sta)
//5) devo smascherare l'interrupt associata a EXTI0: ciò va fatto nel registro IMR1 della periferica ETI0
//6)Scelgo il fronte su cui devo abilitare l'interrupt, nel nostro caso il fronte di salita: quindi alzo il bit 0 nel registro RTSR1
//7) devo abilitre l'interrupt da NVIC, cioè lui deve servire le interrupt di EXTI0. Vedo quindi la tabella del capitolo 11 per la posizione delle interruzioni, e cerco la posizione di EXTI0
//Vedo che la posizione è 0
//8) Devo gestire poi la ISR: dentro devo cancellare la pending requesr, cioè andare nel registro PR1 di EXTI e scrivo 1 nel reòativo bit, e poi azzero il conteggio(per l'esercizi)
//quindi mi serve una variabile globaòe per il conteggio, che nella ISR del timer si incrementa, mentre nell'ISR di dopo lo azzero

int contatore=0;
void main(){
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
  //Abilito la periferica SYSCFG
  RCC->APB2ENR |= RCC_APB2RSTR_SYSCFGRST;
  
  //Imposto PA0 come input digitale
  GPIOA->MODER &=~ GPIO_MODER_MODER0;
  
  //Imposto da PE08 a PE15 come output digitale
  GPI0E->MODER &=~ GPIO_MODER_MODER8_1;
  GPI0E->MODER |= GPIO_MODER_MODER8_0;
  GPI0E->MODER &=~ GPIO_MODER_MODER9_1;
  GPI0E->MODER |= GPIO_MODER_MODER9_0;
  GPI0E->MODER &=~ GPIO_MODER_MODER10_1;
  GPI0E->MODER |= GPIO_MODER_MODER10_0;
  GPI0E->MODER &=~ GPIO_MODER_MODER11_1;
  GPI0E->MODER |= GPIO_MODER_MODER11_0;
  GPI0E->MODER &=~ GPIO_MODER_MODER12_1;
  GPI0E->MODER |= GPIO_MODER_MODER12_0;
  GPI0E->MODER &=~ GPIO_MODER_MODER13_1;
  GPI0E->MODER |= GPIO_MODER_MODER13_0;
  GPI0E->MODER &=~ GPIO_MODER_MODER14_1;
  GPI0E->MODER |= GPIO_MODER_MODER14_0;
  GPI0E->MODER &=~ GPIO_MODER_MODER15_1;
  GPI0E->MODER |= GPIO_MODER_MODER15_0;
 
  //Associo EXTI0 alla linea PA0
  SYSCFG->EXTICR &=~ SYSCFG_EXTICR1_EXTI0;
  EXTI->IMR |= EXTI_IMR_MR0;
  EXTI->RTSR |= EXTI_RTSR_TR0;
  
  //Abilito il timer 7
  RCC->APB1ENR |= RCC_APB1ENR_TIM7EN; 
  
  TIM7->ARR=400000;
  TIM7->PSC=199;                        //Imposto il prescaler a 199 in modo da avere un valor che rientra nei 16 bit di ARR
  TIM7->CR1 |= TIM_CR1_CEN;             //Abilito il conteggio
  TIM7->CNT=0;                          //azzero il conteggio
  TIM7->DIER |= TIM_DIER_UIE;           //Alzo il flag del timer
  NVIC->ISER[1] |= (1<<24);             //Dico di gestire l'interrupt tramite ISR che sta nella posizione 24 del file stratup di ISER[1];
  NVIC->ISER[0] |= (1<<6);  
  
  
  while(1);
  exit(0);
}

void TIM7_IRQHandler  {
  TIM7->SR &=~ TIM_SR_UIF;
  contatore++;
  GPIOE->ODR = contatore<<8;
}

void EXTI0_IRQHandler{
  EXTI->PR |= EXTI_PR_PR0;
  contatore=0;
  
  
}