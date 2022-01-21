//Voglio accendere e spegnere tutti i led, quindi devo lavorare sulle linee da PE08 a PE15

unsigned int * ptr;
main(){
  //Vado nella tabella a pag 51 del datasheet per vedere gli indirizzi di memoria che mi servono, e devo inziare a lavorare nel registro AHB1 RCC.
  //e vedo che il base address è 0x4002 1000, poi vado nel ref man e vedo che l'offste per spostarmi nel registro RCC è 14, cioè devo sommare
  //14 al base address
  ptr=(unsigned int *)0x40021014;
  
  //una volta fatto ciò, devo ,odificare il bit corrisponednte alla porta E(visto che voglio lavorare sulla linea GPIOE, e i led stanno sui PE, da
  //08 a 15); in particolare sta scritto che il bit della porta E è 21, e lo deve mettere a 1 per abilitare il clock, cioè per abilitarla
  *ptr |= (1<<21); //ho quindi abilitato la posta E
  
  //Una volta alzata la porta E, devo lavorare sul registro GPIOE, che ha base address 0x4800 1000(lo vedo sempre nel datasheet a pag 51, nella
  //sezione AHB2, che sarebbe il bus dove lavora la porta E di GPIO)
  //in particolare devo modificare i bit del registro MODER, e vedo che l'offset per andare in tale registro è 0, quindi:
  ptr=(unsigned int *)0x48001000;
  
  //Devo ora impostare a output digitali tutti i registri relativi ai led(che vanno da PE8 aPE15), e quindi devo mettere 01 in tutti i registri
  //MODER che vanno da 8 a 15;
  *ptr |= (1<<16);   //// Così ho messo a 01 il registro MODER 8; che corrisponde
  *ptr &=~(1<<17);  //alla linea PE08, devo fare questo per tutti gli altri MODER  // Così ho messo a 01 il registro MODER 8; che corrisponde
  
  *ptr |= (1<<18); //01 in MODER9
  *ptr &=~(1<<19);
  
  *ptr |= (1<<20); //01 in MODER10
  *ptr &=~(1<<21);
  
  *ptr |= (1<<22); //01 in MODER11
  *ptr &=~(1<<23);
  
  *ptr |= (1<<24); //01 in MODER12
  *ptr &=~(1<<25);
  
  *ptr |= (1<<26); //01 in MODER13
  *ptr &=~(1<<27);
  
  *ptr |= (1<<28); //01 in MODER14
  *ptr &=~(1<<29);
  
  *ptr |= (1<<30); //01 in MODER15
  *ptr &=~(1<<31);
  
  //Impostati i moder, ora posso andare ad accendere i led, che sono dei digital output; sto sempre in GPIOE, con base address sempre
  //0x4800 1000, solo che stavolta l'offset sarà diverso, e lo vado a vedere nel ref man nella sezione GPIO_ODR, che è 14;
  
  ptr=(unsigned int *)0x48001014;  //mi son spostato nel registro ODR di GPIOE
  
  //Accendo ora tutti i led:
  *ptr |= (1<<8);
  for(int i=0;i<200000;i++);
  *ptr |= (1<<9);
  for(int i=0;i<200000;i++);
  *ptr |= (1<<10);
  for(int i=0;i<200000;i++);
  *ptr |= (1<<11);
  for(int i=0;i<200000;i++);
  *ptr |= (1<<12);
  for(int i=0;i<200000;i++);
  *ptr |= (1<<13);
  for(int i=0;i<200000;i++);
  *ptr |= (1<<14);
  for(int i=0;i<200000;i++);
  *ptr |= (1<<15);
  
  //Spengo i led:
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<15);
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<14);
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<13);
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<12);
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<11);
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<10);
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<9);
  for(int i=0;i<200000;i++);
  *ptr &=~ (1<<8);
  
  
  for(int i=0;i<200000;i++);
  for(int i=8;i<16;i++)
   *ptr |= (1<<i);

   for(int i=0;i<300000;i++);
   for(int i=8;i<16;i++)
   *ptr &=~ (1<<i);

   
  
}