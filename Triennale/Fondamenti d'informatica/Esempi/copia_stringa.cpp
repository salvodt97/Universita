
/*  E S E R C I Z I O
Siano date in ingresso da tastiera 
due stringhe (s1 ed s2) di eguale 
lunghezza. Si scriva un programma che
costruisca una terza stringa s3 
costituita dai caratteri in posizione
omologa di s1 ed s2 che sono uguali.
Si stampi quindi la stringa s3 o un
opportuno messaggio nel caso in cui
la stringa s3 sia vuota.

Es:

s1= p i p p o
s2= p l u t o

s3= p o '\0'

*/

#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// dichiarazioni
const int MAX_ELEM=30;
typedef char stringa[MAX_ELEM+1];

// prototipi
void leggi(stringa);
void copia(const stringa, const stringa, stringa);
void stampa(const stringa);

//main
int main() {
  stringa s1,s2,s3;
  
  leggi(s1);
  leggi(s2);
  copia(s1,s2,s3);
  stampa(s3);
  
system("PAUSE");
  return 0;
}

// definizione delle funzioni
void leggi(stringa s){
  
  cout<<"Inserire una stringa (MAX "<<MAX_ELEM<<" caratteri): ";
  cin>>s;
}
          
void copia(const stringa s1, const stringa s2, stringa s3){
  int lungh,i,j=0;
  
  lungh=strlen(s1);
  for (i=0;i<lungh;i++)
    if (s1[i]==s2[i]){ 
      s3[j]=s1[i];
      j++;
    }    
  s3[j]='\0';  
}

void stampa(const stringa s){
  
  if (strlen(s)!=0){
    cout << "\nLa stringa composta da tutti i caratteri uguali in posizione omologa delle due stringhe inserite e': ";
    cout << s << "\n\n";
  }  
  else cout << "\nNelle due stringhe inserite non esistono caratteri in posizione omologa che siano uguali.\n\n";  
} 
