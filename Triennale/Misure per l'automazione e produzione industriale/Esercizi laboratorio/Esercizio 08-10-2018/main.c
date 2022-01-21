//PROGETTO: Portare a 3V la linea PE10

// Devo configurare la linea come output digitale
//Quindi della pereriferica GPIOE_MODER devo indicare la coppia MODER10 come ouput
//Per fare questo setto a 1 il bit della linea 10 del registro GPIO_ODR
//Per sapere come fare vado a vedere nel ref. man. quali bit scrivere: sta scritto di srivere 01(metto a 0 il bit 21 del registro 10 e a 1 il bit 20 sempre del registro 10); visto che di default il bit è già 0,
//setto solo a 1 il bit 20, e quindi tutti gli altri 32 bit del registro li lascio 0. Ci sono più modi per farlo:
/*
1) ho un numero fatto da 32 bit(di cui solo il 20 è 0), quindi gli posso dire di settare il registro 2^(20)
    GPIOE_MODER=1048576  , sarebbe il registro 2^20;

2) posso uare la notazione esadecimale, specificando 0x prima del numero e dividendo i 32 bit a gruppi di 4, scrivo quindi la corrispondente cifra esadecimale del bit
    GPIOE_MODER=0x00100000;

3) Sifto al valore del bit, cipè spostandomi con << dico di andare al bit 20 spostando di 1
    GPIOE_MODER=(1<<20);   indico che mi sposto di un bit per volta fino al 20;
*/

//Devo poi consentire al registro ODR di alzare la linea: vado a vedere nel ref.man. che bit mettere per alzare ODR10(che corrisponde alla linea PE10), e quindi devo settare il bit corrispondente a 1
//Anche qui ho diverse possibilità:
/*
1)valore decimale associato a 2^10;
    GPIO_ODR10=1024;

2)valore esadecimale
    GPIO-ODR=0x00000400;

3)shiftare il valore;
    GPIO_ODR10=(1<<20)
*/

//Devo poi trovare l'indirizzo di memoria corrispondente, guardando l'ADDRESS OFFSET del ref.man.
//Per il MODER l'ADDRESS OFFSET è 0x00;
//PER l' ODR l'ADDRESS OFFSET è 0x04;
//Ricordo che il BASE ADDRESS da cui parrtono i registri delle periferiche GPIOE è 0x4800 1000; nella parte dei registri vado poi a aguardare l'ADDRESS OFFSET, ovvero una quantità da sommare al BASE ADDRESS
//In questo caso vedo che l'offset è 4, infatti i registri sono organizzati:
//32 bit MODER, coè offset 0;
//32 bit OTYPER, cioè offset 4, ovvero l'indirizzo è 0x4800 1004
//32 bit OSPEEDR cioè offset 8, ovvero l'indirizzo è 0x4800 1008
//32 bit PUPDR, cioè offset C, ovvero l'indirizzo è 0x4800 100C
//32 bit IDR, cioè offset 10,ovvero l'indirizzo è 0x4800 1010
//32 bit ODR, cioè offset 14,ovvero l'indirizzo è 0x4800 1014

//Devo quindi trovare l'indirizzo in cui scrivere:
//Indirizzo di GPIO_MODER=0x48001000;
//Indirizzo di GPIOE_ODR=0x48001014;

//Per scrivere devo dichiarare un puntatore, e faccio poi un main

unsigned int* puntatore;
void main()
{
  puntatore=(unsigned int *) 0x48001000; //così sposto il puntatore all'indirizzo che mi serve, sommando l'offset, che qua è 0;
  *puntatore=(1<<20);  //così ho scritto ne registro moder, e poi modifico l'ODR dichiarando un altro puntatore o usando questo, che tanto non mi serve più
  
  puntatore(unsigned int *)0x48801014
  *puntatore=(1<<10);  
}


//fatto questo, per funzionare devo abilitare la periferica: vado nel re.man. al capitolo 7.4 RCC registrer: qui ci sono dei registri APB associate a delle periferiche collegate al bus AHB, e posso abilitare la periferica
//corrispondente al bit settandolo a 1