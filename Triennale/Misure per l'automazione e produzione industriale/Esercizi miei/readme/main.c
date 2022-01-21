#include "stm32f30x.h"
#define MATRICOLA 3.208
#define DIM 10

void abilita();
void setup_TIM2();
void TIM2_IRQHandler();
void setup_GPIO();
void setup_TIMNGR();
void start();
void stop();
void setup_trasmissione(int);
void trasmissione(int);
void setup_ricezione(int);
void ricezione();

int16_t z;
int16_t campioni[DIM];
int testa=0;
uint8_t ris[6];

void main(){

  
  abilita();
  setup_TIM2();
  setup_GPIO();
  I2C1->CR1 |= I2C_CR1_PE;
  setup_TIMNGR();

  TIM2->CNT = 0;
  TIM2->CR1 |= TIM_CR1_CEN;
  
  while(1);
}

void abilita(){
  RCC->AHBENR |= RCC_AHBENR_GPIOBEN;
  RCC->APB1ENR |= RCC_APB1ENR_I2C1EN;
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
}

void setup_TIM2(){
  TIM2->ARR = MATRICOLA*72000000;
  TIM2->DIER |= TIM_DIER_UIE;
  NVIC->ISER[0] |= (1<<28);
}

void setup_GPIO(){
  //Metto 10 in MODER6 e MODER7 di GPIOB per indicare la modalità alternativa
  GPIOB->MODER |= GPIO_MODER_MODER6_1;
  GPIOB->MODER |= GPIO_MODER_MODER7_1;
  //Dico che sto usando la modalità alternativa(I2C) scrivendo i bit AFRL6 e AFRL7 in AFR[0] di GPIOB
  GPIOB->AFR[0] |= GPIO_AFRL_AFRL6;
  GPIOB->AFR[0] |= GPIO_AFRL_AFRL7;
}

void setup_TIMNGR(){
  //valori da copiare a pag. 684 del ref.man.
  I2C1->TIMINGR |= (1<<28);
  I2C1->TIMINGR |= (0x4<<20);
  I2C1->TIMINGR |= (0x2<<16);
  I2C1->TIMINGR |= (0xF<<8);
  I2C1->TIMINGR |= (0x12<<0);
}

void setup_trasmissione(int n){
  I2C1->CR2 = 0;
  I2C1->CR2 |= (n<<16);                 //con n indico quante cose devo trasmettere(per esempio indirizzo e/o dato)
  I2C1->CR2 &=~ I2C_CR2_RD_WRN;         //con WRN=0 indico che sto scrivendo(trasmettendo)
  I2C1->CR2 |= (0x19<<1);               //sto "abilitando" I2C1
}

void start(){
  I2C1->CR2 |= I2C_CR2_START;                           //inizio a trasmettere o a ricevere
  while((I2C1->CR2 & I2C_CR2_START) == I2C_CR2_START);  //aspetto la fine dell'inizio
}

void stop(){
  I2C1->CR2 |= I2C_CR2_STOP;                            //fermo la trasmissione o la ricezione
  while((I2C1->ISR & I2C_ISR_STOPF) != I2C_ISR_STOPF);  //aspetto che lo stop sia effettivo
  I2C1->ICR |= I2C_ICR_STOPCF;
}

void trasmissione(int valore){
  I2C1->TXDR |= valore;                                 //trasmetto ciò che voglio(indirizzo o dato) in TXDR
  while((I2C1->ISR & I2C_ISR_TXE) != I2C_ISR_TXE);      //aspetto l'avvenuta trasmissione
}

void setup_ricezione(int n){
  I2C1->CR2 = 0;
  I2C1->CR2 |= (n<<16);                
  I2C1->CR2 |= I2C_CR2_RD_WRN;          //con WRN=1 indico che sto leggendo(ricevendo)
  I2C1->CR2 |= (0x19<<1);
}

void ricezione(){
  for(int i=0; i<6; i++){
    while((I2C1->ISR & I2C_ISR_RXNE) == I2C_ISR_RXNE);    //aspetto che il registro RXDR non sia vuoto
    ris[i] = I2C1->RXDR;
  }
}

void TIM2_IRQHandler(){
  TIM2->SR &=~ TIM_SR_UIF;
  //Trasmetto il dato
  setup_trasmissione(2);
  start();
  trasmissione(0x20);                   //trasmetto l'indirro del registro
  trasmissione(0x17);                   //trasmetto il dato
  stop();
  
  //Dico che sono pronto a ricevere
  setup_trasmissione(1);
  start();
  trasmissione(0xA8);
  stop();
  
  //Ricevo
  setup_ricezione(6);
  start();
  ricezione();
  stop();
  
  z=( (int16_t) ((uint16_t)ris[5]<<8) + ris[4]) >> 4;
  campioni[testa]=z;
  testa=(testa+1)%DIM;
}
