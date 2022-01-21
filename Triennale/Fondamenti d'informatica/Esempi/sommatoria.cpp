#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
   
  // Dichiarazioni 
  int ris,n; 

  // Messaggi di output  
  cout << "Calcolo della somma dei primi n numeri interi.\n\n";
  cout << "Inserisci il valore di n: ";
    
  // Lettura
  cin >> n;
    
  // Calcolo del risultato                               
  ris = (n*(n+1))/2;
                                                                                                    
  // Stampa del risultato
  cout << "Il risultato e': " << ris << "\n\n";
      
  system ("PAUSE");
}
