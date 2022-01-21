//Lavoriasmo ora con gli input, cioè colleghiamo una circuteria esterna (il pulsante) per inserire una tensione di 3V. Ci sono due pulsanti:
//uno di reset(il nero), che da partire il pogramma dalla prima istruzione
//-uno user serve a debuggare i nostri programmi
//Posso controllare solo il bottone user(blu) tramite la linea PA0, che ho visto nel discovery
//Devo quindi impopstare PA0 come imput digitale usando la periferica GPIOA, e quindi andrò nel moder a dire che la linea 0 è input digitale.
//Deo prima però abilitare GPIOA usando il registro RCC, e pr impostare gli input uso i registri IDR

 //Devo lavorare con la periferica GPIO, ma con 2 linee(A e E), e l'unica cosa che varia è il base address
/*
  //Definisco quindi un nuovo tipi, GPIO come una struct i cui campi sono i registri, che metto nello stesso ordine che mi fa vedere il refman
  
typedef GPIO{
  struct{
    unsigned int MODER;
    unsigned int OTYPER;
    unsigned int OSPEEDR;
    unsigned int PUPDR;
    unsigned int IDR;
    unsigned int ODR;
    unsigned int BSRR;    
  };    
}
  
//Dopo la struct creo dei puntatori che puntano a questa struttura il cui valore è un base adrress, per esempio quello di GPIOA, GPIOE....
GPIO * GPIOE=0x48001000;
GPIO * GPIOA=0x48000000;   //Questi indirizzi li ho visti nel ref man, nella mappa degli indirizzi

//Così quindi posso scrivere nel moder di GPIOE con la notazione .
*GPIOE.MODER=...
*GPIOA.MODER=...

//Stessa cosa con GPIOA:
*GPIOA.ODR=...  //In particolare, GPIOA.ODR è l'indirizzo base di GPIOA + l'offset di ODR(che è lo stesso che trovo nel ref man perchè i registri nella struct l'ho messa in ordine)
*GPIOA.IDR=...  //Devo però specificare che ogni struttura occupa 32 bit

//In realtà questa struttura già sta nella cartella MAPI, in Libreria, che devo sempre incollare nelle cartelle di ogni progetto
*/

#include "stm32f30x.h" //Ho incluso il .h di libreria che mi serve, così posso usare quei puntatori
//Devo ricordare però che poi i Option-> C/C++ Compiler-> Preprocessor->Additional Include e poi ci metto tutta la cartella Libreria

void main(){
  
  RCC->AHBENR |= RCC_AHBENR_GPIOEEN;
  RCC->AHBENR |= RCC_AHBENR_GPIOAEN;   //così non ho duvuto dichiarare un puntatore, ma ho usato direttamente quello che mi ha dato il .h che sta nella carella Libreria
  //In realtà, nlla libreria trovo anche i typedefdei singoli bit, in questo caso posso anche scrivere:
  //RCC->AHBENR |= RCC_AHBENR_GPIOEEN;  Questo equiovale a fre la OR con (1<<21)
  //1) Devo prima abilitare le periferiche GPIOA(per rilevare il pulsante) e poi GPIOE(per i led);
  //2) In MODER di GPIOA imposto PA0 come input e in MODER di GPIOE imposto PE8 come autput(accendo il led blu)
  GPIOE->MODER |= GPIO_MODER_MODER8_0;
  GPIOE->MODER &=~ GPIO_MODER_MODER8_1;
  GPIOA->MODER &=~ GPIO_MODER_MODER0_0;
  GPIOA->MODER &=~ GPIO_MODER_MODER0_1;
  
  
  
  
  
  while(1){
    //se il pulsante è premuto(il bit 0 di GPIOA è alto, perchè lavoro con PA0, cioè il bit di IDR deve essere alto)
    /*Questo if si fa con una and biti a bit con una stringa fatta di tutti 0, tranne un 1 nella posizione che mi interessa, e il risultato della and può avere 2 risultati:
    - o è 1, e questosignifica che qualcuno sta premendo il pulsante
    -o è 0, cioè il pulsante non è premuto
    
    In realtà questo vale perchè il bit che mi interessa è l'ultimo; se fosse ilm penultimo, il risultato potrebbe esere 0 oppure 2 ecc...
    
    */
      //led acceso
    //altrimenti
      //led spento
    
    if(GPIOA->IDR & GPIO_IDR_0==1) GPIOE->ODR |= GPIO_ODR_8;
    else GPIOE->ODR &=~ GPIO_ODR_8;
  
}

}