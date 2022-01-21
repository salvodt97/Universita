#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    
  // Dichiarazioni 
  int n,i,prodotto;
  char risposta;
  
  do{

    // Messaggi di output  
    cout<< "\n\nCalcolo del prodotto dei primi n numeri interi.\n"; 
    cout<< "Inserisci il valore di n: ";
    
    // Lettura
    cin >> n ;   
   
    while (n<=0)  {
      cout<< "Valore di n non valido\n"; 
      cout<< "Inserisci un valore maggiore di 0: ";
      cin >> n ;   
    }
      
    // Calcolo del risultato
    prodotto=1;
    for(i=2;i<=n;i++)
      prodotto=prodotto*i;  
                                   
    // Stampa del risultato
    cout<< "Il risultato e': "<< prodotto << '\n';                             
    
    // Chiedo all'utente se vuole rieseguire il programma
 	cout<<"Vuoi rieseguire il programma? Digita Y in caso affermativo: "; 
	cin>>risposta;
	   
  } while (risposta=='Y');   
      
  system("PAUSE");
}
