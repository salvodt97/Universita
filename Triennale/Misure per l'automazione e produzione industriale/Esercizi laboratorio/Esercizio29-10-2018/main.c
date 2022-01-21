
#include "stm32f30x.h"

//voglio fare un contatore che dipende dal numero di vote che premo il tasto user, e quindi creo una variabile contatrice dove salvo questo numero
//per fare ciò uso li 8 led, che contano in binario, cioè rappresentano gli 8 bit di un contatore(per esempio 111 devono essere 3 led consecutivi accesi)
//gli 8 bit sono i bit più significativi del registro GPIO_ODR, con il led blu il meno significativo

int contatore=0;
int main(){
  //Attivo le periferiche GPIOE e GPIOA
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;
  
  //Devo ora impostare PA0 come input digitale
  GPIOA->MODER &=~ GPIO_MODER_MODER0_0;
  GPIOA->MODER &=~ GPIO_MODER_MODER0_1;
  
  //Imposto da PE8 a PE15 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER8_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER8_1;
  GPIOE->MODER |= GPIO_MODER_MODER9_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER9_1;
  GPIOE->MODER |= GPIO_MODER_MODER10_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER10_1;
  GPIOE->MODER |= GPIO_MODER_MODER11_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER11_1;
  GPIOE->MODER |= GPIO_MODER_MODER12_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER12_1;
  GPIOE->MODER |= GPIO_MODER_MODER13_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER13_1;
  GPIOE->MODER |= GPIO_MODER_MODER14_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER14_1;
  GPIOE->MODER |= GPIO_MODER_MODER15_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER15_1;
  
  while(1){
    if((GPIOA->IDR & GPIO_IDR_0)==1){
      while((GPIOA->IDR & GPIO_IDR_0)==1); //Questo while serve per attendere, cioè contatore non si deve incrementare se il tasto rimane premuto
      contatore++;
    }
      GPIOE->ODR=(contatore<<8); //Visto che in ODR i led partono dal bit 8, devo spostare il contatore
  }
}