#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

const int MAX_CHAR=30;
const int NMAX=22;

typedef char stringa[MAX_CHAR+1]; 

struct esame{
   int voto;     
   stringa nome;  // equivale a: char nome[MAX_CHAR+1]; 
};

typedef esame vett_esami[NMAX]; 


int main(){

  vett_esami v;
  stringa nome_esame; 

  // Inserimento dei dati degli esami superati
  int i,riemp;
  cout <<"\nQuanti esami hai superato? ";
  cin >> riemp;
  cout << "Inserire voto e nome di questi esami:\n";
  for (i=0;i<riemp;i++){
    cin >> v[i].voto;
    cin >> v[i].nome;
  }

  // Ricerca del voto, a partire dal nome dell'esame 
  cout << "\nInserire il nome di un esame:\n"; 
  cin >> nome_esame;
  
  i=0;
  int voto_esame;
  bool trovato=false;

  while (i<riemp && !trovato)
    if (strcmp(v[i].nome,nome_esame)==0){
      trovato=true;
      voto_esame=v[i].voto;
    } 
    else i++;  

  // Stampa del risultato della ricerca
  if (trovato)
    cout<<"Voto di " << nome_esame << ": " << voto_esame << '\n';
  else cout<<"Esame non superato\n";     
   
  system("PAUSE");
  return 0; 
}
