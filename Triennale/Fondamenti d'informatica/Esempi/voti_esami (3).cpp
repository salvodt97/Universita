#include <iostream>
#include <cstdlib>
//#define MAX_DIM 22

using namespace std;

const int MAX_DIM=22;
typedef int vett_voti[MAX_DIM];   

int main() {
  
  vett_voti voti1,voti;
  int i,j,riemp,riemp1,max,voto,pos,somma;
  bool trovato;
  float media;
  
  
  // lettura dati
  cout<<"Inserire il numero di esami superati: ";
  cin>>riemp;
  for (i=0;i<riemp;i++){
    cout<<"Inserire il voto conseguito nell'esame numero "<<i+1<<": ";
    cin>>voti[i];
  }
  
  // stampa dei valori inseriti...
  cout << "\nI voti conseguiti sono: ";
  for (i=0;i<riemp;i++)
    cout<< voti[i]<<' ';
  
  // esempio di copia selettiva: 
  // nel vettore voti1 vengono copiati solo i valori pari
  j=0;
  for(i=0;i<riemp;i++)
    if(voti[i]%2==0)
      voti1[j++]=voti[i];
      
  riemp1=j;
  
  // stampa dei valori pari
  cout << "\nI voti pari sono: ";
  for (i=0;i<riemp1;i++)
    cout<< voti1[i]<<' ';
  cout<<"\n\n";  
  
  // inserimento di un elemento in un vettore
  cout << "Quale voto devo inserire? ";
  cin >> voto;
  cout << "In che posizione? "; // si suppone che le
  // posizioni partano da 1 
  
  cin>>pos;
  for(i=riemp-1;i>=pos-1;i--)
    voti[i+1]=voti[i];
  voti[pos-1]=voto;
  riemp++;
  
  // stampa dei valori dopo l'inserimento
  cout << "\nI voti conseguiti dopo l'inserimento sono: ";
  for (i=0;i<riemp;i++)
    cout<< voti[i]<<' ';
    
  // calcolo della media dei voti
  // si suppone che sia stato superato almeno un esame
  somma=0;
  for(i=0;i<riemp;i++)
    somma=somma+voti[i];
  media=float(somma)/riemp;
  
  cout << "\nLa media dei voti e' " << media << "\n\n";
  
  // calcolo del voto piu' alto
  // si suppone che sia stato superato almeno un esame
  max = voti[0];
  for (i=1;i<riemp;i++)
    if (voti[i] > max)
      max = voti[i];
  // stampa del risultato
  cout<<"Il voto piu' alto e' " << max << "\n\n";

  // ricerca
  cout<<"Inserire il valore del voto da eliminare: ";
  cin >> voto;
  
  trovato=false;
  i=0;                          
  while (i<riemp && !trovato) // !trovato equivale a trovato==false 
    if (voti[i]==voto){
      trovato = true;
      pos = i+1;
    }  
    else i++;
   
  //  stampa del risultato della ricerca
  if (trovato){
    cout << "\nC'e' almeno un esame in cui hai conseguito un voto pari a " << voto << '\n';
    cout << "ed e' l'esame numero " << pos << ".\n\n";  

    // viene eliminato il voto trovato
    for(i=pos-1;i<riemp-1;i++)
      voti[i]=voti[i+1];
    riemp--;
  
    cout << "I voti conseguiti dopo l'eliminazione del voto ricercato sono: ";
    for (i=0;i<riemp;i++)
       cout<< voti[i]<<' ';
    cout<<"\n\n";
  
  }
  else cout << "\nNon esiste nessun esame in cui hai conseguito un voto pari a " << voto << "!\n\n"; 
   
  system("PAUSE");
}
