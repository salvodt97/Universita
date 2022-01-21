#include <fstream>
#include <cstdlib>
#include <iostream>
using namespace std;

// Dichiarazioni
const int MAX=50;
typedef int lista[MAX];

int main(){
  int i,n;
  lista l;
  ifstream input;
  ofstream output;
  
  // apertura file di input
  input.open("dati.txt");
  
  if (input.fail())
    exit(1);
  // lettura da file di input
  
//  input >> riemp:
//  for (i=0;i<riemp;i++)
//     input >> l[i];	
  
  i=0;
  while (!input.eof()){ // equivale a input.eof()==false
    input >> l[i];
    i++;
  }

  n=i;
  // chiusura file di input
  input.close();
  // apertura file di output
  output.open("output.txt");
  // scrittura su file di output
  for (i=0;i<n;i++){
    output << l[i] << ' ';
    cout << l[i] <<" ";}
  // chiusura file di output
  output.close();
  system("PAUSE");
  return 0;
}
