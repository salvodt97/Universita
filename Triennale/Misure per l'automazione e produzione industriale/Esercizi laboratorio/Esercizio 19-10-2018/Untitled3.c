//dichiaro un puntatore per puntare tuuti i registri che mi servono
unsigned int * puntatore;
//in systems and emory overview cap 2 nel refman vedo l'indirrizzo di partenza(BASE ADDRESS) a cui devo sommare l'offset

void main(){
  
  //voglio usare la GPIOE
  //1) Agisco sul RESET e CONTROL RCC nel cap 7 del refman
  // vado i RCC_AHBENR, e voglio alzare solo il bit 21 lasciando inalterarti gli alrti facendo una OR bit a bit con tutti 0 tranne un 1 
  //in quello che voglio alzare
  
  puntatore=(unsigned int *)0x40021014;
  *puntatore |= (1<<21);
  
  //2) ora vado nei registri della periferica GPIO cap 8, vado in moder, e vedo che l'offset e 0 quindi il base address
  //è l'indirizzo del mosder. PE8 deve essere un output digitale, quindi devo mettere
  //il bit 17 a 0 e il bit 16 a 1, quindi una OR e una AND bit a bit(AND tutti 1 tranne uno 0)
  //imposto PE8 quindi come output digitale
  
  puntatore = (unsigned int *)0x48001000;
  *puntatore |= (1<<16);
  *puntatore &=~ (1<<17);
  *puntatore |= (1<<18);
  *puntatore &=~ (1<<19);
  
  //3) devo ora alzare P8, quindi vado sui registri ODR dove il base address  non cambia, ma cambia l'offset
  //devo mettere quindi a 1 il registro 8 di odr con una OR bit a bit
  
  puntatore=(unsigned int *) 0x48001014;
  while(1){
    for(int i=0;i<200000;i++)
      *puntatore |= (1<<8);
    for(int i=0;i<200000;i++)
     *puntatore &=~ (1<<8);
      
      
 
  
  }
  
}