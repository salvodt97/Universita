#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
  // Dichiarazioni 
  int i,ris,somma,n;

  // Messaggi di output
  cout<< "Calcolo della somma dei primi n numeri interi.\n"; 
  cout<< "Inserisci il valore di n: ";
    
  // Lettura
  cin >> n;
  
  // Calcolo del risultato con ciclo for
  somma=0;
  for(i=1;i<=n;i++)
     somma=somma+i;
      
  // Calcolo del risultato con la formula diretta                              
  ris=(n*(n+1))/2;
                             
  // Stampa del risultato
  cout<< "\nIl risultato calcolato con il ciclo for e': "<< somma << '\n';                             
  cout<< "Il risultato calcolato con la formula diretta e': "<< ris << '\n';                             
      
  if(ris==somma)    
     cout << "Tutto ok!\n\n";
  else cout << "C'e' qualche problema...\n\n";
	  
  system("PAUSE");
}
