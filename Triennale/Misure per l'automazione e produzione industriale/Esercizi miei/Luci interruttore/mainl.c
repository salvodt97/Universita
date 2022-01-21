#include "stm32f30x.h"

void main(){
 
  //abilito le periferiche;
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN; 
  
  //impostp PA0 come input digitale
  GPIOA->MODER &=~ GPIO_MODER_MODER0_0;
  GPIOA->MODER &=~ GPIO_MODER_MODER0_1;
  
  //imposto PE8 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER8_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER8_1;
  
  //imposto PE9 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER9_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER9_1;
  
  //imposto PE10 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER10_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER10_1;
  
  //imposto PE11 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER11_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER11_1;
  
  //imposto PE12 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER12_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER12_1;
  
  //imposto PE13 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER13_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER13_1;
  
  //imposto PE14 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER14_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER14_1;
  
  //imposto PE15 come output digitale
  GPIOE->MODER |= GPIO_MODER_MODER15_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER15_1;
  
  while(1){
    if(GPIOA->IDR & GPIO_IDR_0==1){ //se il pulsante user è premuto
      
      while(1){
      //Accendo i led 9,11,13,15
      GPIOE->ODR |= GPIO_ODR_9;
      GPIOE->ODR |= GPIO_ODR_11;
      GPIOE->ODR |= GPIO_ODR_13;
      GPIOE->ODR |= GPIO_ODR_15;
      
      //Spengo i led 9,11,13,15
      for(int i=0;i<200000;i++);
      GPIOE->ODR &=~ GPIO_ODR_9;
      GPIOE->ODR &=~ GPIO_ODR_11;
      GPIOE->ODR &=~ GPIO_ODR_13;
      GPIOE->ODR &=~ GPIO_ODR_15;
      
      //Accendo i led 8,10,12,14
      for(int i=0;i<200000;i++);
      GPIOE->ODR |= GPIO_ODR_8;
      GPIOE->ODR |= GPIO_ODR_10;
      GPIOE->ODR |= GPIO_ODR_12;
      GPIOE->ODR |= GPIO_ODR_14;
      
      //Spengo i led 8,10,12,14
      for(int i=0;i<200000;i++);
      GPIOE->ODR &=~ GPIO_ODR_8;
      GPIOE->ODR &=~ GPIO_ODR_10;
      GPIOE->ODR &=~ GPIO_ODR_12;
      GPIOE->ODR &=~ GPIO_ODR_14;
      
      }
}
}
}