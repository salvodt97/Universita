#include "stm32f30x.h"

//realizzare una base dei tempi di un secondo, cioè uhn led che lampeggia ogni secondo
//per fare ciòc chiamo DT l'intervallo di tempo che voglio aspettare(1s), e il conctatore ha una frequenza di clock di 8MHz, quindi si incrementa
//quando il Tck=1/8000000 sù//Devo poi calvocare CNT=DT/Tck, cioè vedo in DT quante volte si è incrementato il registro CNT
//il valore di CNT lo scrivo poi in ARR, che vedendo quel valore alza il flag di overflow raggiunto, poi si azzera e ricomincia da capo
//se il valore di CNT lo poss scrivere in 16 bit, allora lo copio in ARR, altrimenti:
// 1) O uso il timer 2 di 32 bit
// 2) O aumento il valore di Tck tramite il prescaler
//Infatti in realtà CNT=DT/(Tck*(PSC+1)). dove il PSC è il prescaler che di defaul è 0; in partcolare il contatore si incrementa pari al doppio di Tck, il clock esterno
//In partcolare, chiamo Tcnt=Tck(PSC+1), ovverom il tempo in cui si incrementa il registro contatore, e alla fine quindi esprimo CNT=DT/Tcnt. Così, aumentando il prescaler XNT diminuisce e lo posso scrivere in 16 bit
//Per esempio, nel caso di un secondo dove il CNT=8000000, non lo riesco a scrivere in ARR, quindi mi serve il perscaler, che pongo a 7999, cioè Tcnt=1/(8000000*8000), così aumento il tempo a disposizione e trovo che
//CNT finale=1000, che riesco a scrivere 16 bit.
//I particolare, la formula inversa DT=ARR*Tcnt vale solo nel senso della quantizzazione, dove Tcnt è proprio l'errore che posso commettere
//Quindi, mi rendo conto che il PSC non lo posso fare troppo tardi, visto che la risoluzione diminuiesce
//nel registro status devo monitorare il bit 0, cioè UIF, che indica quando è trascorso DT: a questo punto si alza, e lo devo poi riabbassare
  
int flag=0;  //flag per il TIM2
int flagm=0; //flag per il TIM7
void main(){

  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN; //Abilito il timer TIM2
  RCC->APB1ENR |= RCC_APB1ENR_TIM7EN; //Abilito il timer TIM7
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN; //Abilito la periferica GPIOE
  
  //Il timer 7 lo uso invece per accendere e spegnere il led sulla linea PE11 ogni 3208 ms(mia matricola in millisecondi);
  //In questo caso quindi lavoro ogni 3,208 secondi, e ho bisogno del prescaler, cioè DT=3,208 secondi. Metto il prescaer a 999
  
  //Imposto le linee PE8 e PE11 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER8_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER8_1;
  GPIOE->MODER |= GPIO_MODER_MODER11_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER11_1;
  
  //Imposto poi ARR=CNT e, vitso che voglio contare ogni secondo, cioè DT=1, ARR=8000000
  TIM2->ARR=8000000;
  TIM2->CNT=0;
  TIM2->CR1 |= TIM_CR1_CEN;
  
  while(1){
    if((TIM2->SR & TIM_SR_UIF) == TIM_SR_UIF){
          TIM2->SR &=~ TIM_SR_UIF;
          if(flag==0){
            flag=1;
            GPIOE->ODR |= GPIO_ODR_8;
         }
          else{
            flag=0;
            GPIOE->ODR &=~ GPIO_ODR_8;
          }
  }
  }
  
  
}