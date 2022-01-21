#include <iostream>
#include <cstdlib>
using namespace std;

int main(){
  
  // Dichiarazioni
  int a,b,c;

   // Input con controllo sui dati
  cout << "Inserire i valori di a, b e c: ";
  cin >> a >> b >> c;

  while (a+b<=c || a+c<=b || b+c<=a) {
    cout << "Attenzione devi rispettare la disuguaglianza triangolare.\n";
	cout << "Inserire i valori di a, b e c: ";
    cin >> a >> b >> c;
  }
                                                                                                   
  // Istruzioni per la verifica del tipo di triangolo
  if (a==b && b==c)
    cout<< "Triangolo equilatero\n\n";
  else if (a==b || a==c || b==c)
         cout<< "Triangolo isoscele" << "\n\n";
       else cout<< "Triangolo scaleno\n\n";   
           
  system("PAUSE");
}




