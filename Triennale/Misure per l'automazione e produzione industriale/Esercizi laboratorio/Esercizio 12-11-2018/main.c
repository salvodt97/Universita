#include "stm32f30x.h"
#include "core_cm4.h"   //serve per NVIC

//In generale, quando faccio operazione tra interi devo fare un cast se voglio un float. o metto intero.0 per avere almeno una cifra float

//Usiamo l'interrupt di timer2, usato come base dei tempi, e quando è trascorso u  tempo Dt non voglio interrogare sempre UIF ma voglio usare le interruptù
//Devo quindi configurare tim2 per fargli fare un'interrupt request, e lo vedo nel refman, nella sezione tim2, nel registro DIER. Per timer 2 posso gestire più tipi di interrupt: per farlo mi serve solo 
//il bit meno significativo (UIE), in cui scrivendo 1 dico al TIM2 di lanciare un'ìinterrupot ogni volta che il CNT ha raggiunto il contrggio di ARR

//in core_cm4.h, trovo la struct di NVIC, dove il primo campo è proprio il vettore di registri ISER
//supponiamo di avere una base dei temopi di 1s, dopo il quale abilito l'interrupt
//Per configurare bene l'interrupt devo includere altri 2 file con add files con tasto destro sul nome del progetto, lo sturtup_stm32f30x.s (un assembler) e system_stm32f30x.c
//Si usa un file assemler visto che per gestire l'ISR, devo scrivere nel programm counter un indirizzo preciso, che trovo nella sezione vector table dove trovo tutte istruzione di salto a delle etichette
//che sono le interrupt così come sono indicate nel refman, e la posizione dell'ISR è la position del tipo di interrupt che sta nel refman
//L'ISR che mi interessa è la 28, la TIM2_IRQHandler

int main(){
  //Abilito le periferiche GPIOE(per controllare) e TIM2
  //Configuro poi ARR per avere una base dei tempi di 1s
  //Configuro poi TIM2 per generare un'interrupt su update (UIE)
  //Configuro poi NVIC per servire l'interrupt
  //Abilito il conteggio
  //Dopo mi metto in un while(1), e se tutto va bene deve essere gestita l'interrupt
  
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN;            //Abilito la GPIOE
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;           //Abilito TIM2
  GPIOE->MODER |= GPIO_MODER_MODER8_0;
   GPIOE->MODER &=~ GPIO_MODER_MODER8_1;
 
  TIM2->ARR=72000000;
  TIM2->CR1 |= TIM_CR1_CEN;
  TIM2->CNT=0;
  TIM2->DIER |= TIM_DIER_UIE;
  NVIC->ISER[0] |= (1<<28);  //lzo la posizione giusta dell'ISER0 per gestire l'interrupt con la funzione che metto
  
  
  while(1);
}
  
  void TIM2_IRQHandler(){
    //Questa è la ISR: una funzione utile è quella di abbassare il flag UIF nello SR
    TIM2->SR &=~ TIM_SR_UIF;
    if((GPIOE->ODR & GPIO_ODR_8) == 0) GPIOE->ODR |= GPIO_ODR_8;
    else GPIOE->ODR &=~ GPIO_ODR_8;
    //Per gestire l'interrupt, posso accendere o spegnere un led   
  }
  