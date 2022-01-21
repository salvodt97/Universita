#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

const int MAX_DIM=16;
typedef char stringa[MAX_DIM+1];

// prototipi
void leggi(int &, int &);
void converti(int, int, stringa);


int main (){
  int num,base;
  stringa out;

  leggi(num,base);
  converti(num,base,out);
  cout<<"\nIl numero "<< num <<" dopo la conversione di base e': " << out << "\n\n";

  system("PAUSE");
  return 0;
}

void leggi(int &numero,int &base){
  cout<<"\nDammi il numero in base 10 da convertire: ";
  cin>>numero;
  cout<<"Dammi la base: ";
  cin>>base;
}

void converti(int numero, int base, stringa str){
  const char ch[]="0123456789ABCDEF";
  int i=0;

  while (numero>=base){
    str[i] = ch[numero % base]; 
    numero = numero / base;    // si puo' scrivere anche: 
	                           //numero /= base;
    i++;
  }

  str[i]=ch[numero]; // si puo' scrivere anche: 
  i++;               //    str[i++]=ch[numero];
  str[i]='\0';
  strrev(str);
}

