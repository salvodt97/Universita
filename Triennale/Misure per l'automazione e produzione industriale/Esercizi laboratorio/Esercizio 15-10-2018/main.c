//Devo ora attivare la linea del bus
unsigned int * puntatore;
void main(){
  
      /*
  Per esempio se voglio alzare il penultimo bit della sequenza seguente, faccio:
  010011001
      |
  000000010
      =
  010011011
  
  Se invece voglio abbassare un bit, devo fare una end con una sequenza di bit che sono tutti 1, tranne quello della posizione che mi serve, che lo metto 0;
  01001101
     &
  11111011
     =
  01001001
  */
  
  puntatore=(unsigned int *)0x40021014; //si deve fare un tipe cast per dire che è un  punatore intero senza segno
  *puntatore|=(1<<21); //mettendo *puntatore=*puntatore|(1<<20), cambio solo il bit interessato, oppure faccio *puntatore|=(1<<20)
  
  puntatore=(unsigned int *)0x48001000;
  *puntatore=*puntatore|(1<<20);
  //se poi voglio abbassare un bit, uso la notazione del negato con ~, facendo *punatore&=~(1<<21) sto facendo una and bit a bit con la mia sequenza di bit negando l'1 che ho messo in realtà;
  *puntatore&=~(1<<21);
  
  puntatore=(unsigned int *)0x48001014;
  while(1){ //con questo while accendo e spengo;
  *puntatore|=(1<<10);//accendo il led;
  for(int i=0;i<100000;i++); //così creo un'attesa per vedere il led che si spegne e si accende;
  *puntatore&=~(1<<10); //così spengo il LED interessato
  for(int i=0;i<100000;i++);
  }
  //while(1); //con questo codice eseguo il codice finchè 1 è 1, cioè quindi il microcontrollore fa solo questo.
  
}