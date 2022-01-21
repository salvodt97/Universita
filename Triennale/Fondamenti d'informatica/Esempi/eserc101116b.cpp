#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_RIG=10;
const int MAX_COL=10;
typedef int vettore[MAX_COL];
typedef vettore matrice[MAX_RIG];


int main(){
  matrice mat;
  int riga,col,riemp;
  int i,j,temp,somma,min;
  float media;
  vettore v;
  
 // lettura e stampa di una matrice
  
  cout << "\nLettura e stampa di una matrice\n";
  cout << "Dammi il numero di righe: ";
  cin >> riga;
  cout << "Dammi il numero di colonne: ";
  cin >> col;
  
  // lettura matrice
  for (i=0;i<riga;i++)
    for (j=0;j<col;j++) {
      cout << "Inserisci l'elemento mat["<<i<<"]["<<j<<"]: ";
      cin >> mat[i][j]; 
    }      

  // stampa matrice
  cout << "\nMATRICE ("<<riga<<"x"<<col<<")\n";
  for (i=0;i<riga;i++) {
    for (j=0;j<col;j++)
        cout << mat[i][j] << ' ';
    cout << '\n';
  }
    
  // calcolo della media degli elementi della matrice
  somma=0;
  for (i=0;i<riga;i++)
    for(j=0;j<col;j++)
      somma=somma+mat[i][j]; 
  media=float(somma)/(riga*col); 
  
  cout << "\nLa media dei valori della matrice e': "<< media <<"\n\n";
  
    
 // calcolo del minimo per ciascuna riga ed inserimento in un vettore
  
  for(i=0;i<riga;i++){
  	min=mat[i][0];
  	for(j=1;j<col;j++)
  	  if(mat[i][j]<min)
  	    min=mat[i][j];
  	v[i]=min;
  }
  // stampa del vettore dei minimi
 
  cout << "Valori minimi per ciascuna riga:\n";
  for(i=0;i<riga;i++)
      cout << v[i] << ' ';
  cout << '\n';
 
  
 // calcolo della trasposta di una matrice
  
  cout << "\nCalcolo della trasposta di una matrice quadrata\n";
  cout << "\nMatrice quadrata: dammi il riempimento: ";
  cin >> riemp;
  // lettura matrice
  for (i=0;i<riemp;i++)
    for (j=0;j<riemp;j++){
      cout << "Inserisci l'elemento mat["<<i<<"]["<<j<<"]: ";
      cin >> mat[i][j];
    }
  // stampa matrice
  cout << "\nMATRICE DI PARTENZA ("<<riemp<<"x"<<riemp<<")\n";
  for (i=0;i<riemp;i++) {
    for (j=0;j<riemp;j++)
      cout << mat[i][j] << ' ';
    cout << '\n';
  }  
  
  cout << "\nCalcolo la matrice trasposta ...\n";
  for (i=0;i<riemp-1;i++)
    for (j=i+1;j<riemp;j++){
      temp=mat[i][j];
      mat[i][j]=mat[j][i];
      mat[j][i]=temp;
    }  
	
  // stampa matrice trasposta
  cout << "\nMATRICE TRASPOSTA ("<<riemp<<"x"<<riemp<<")\n";
  for (i=0;i<riemp;i++) {
    for (j=0;j<riemp;j++)
      cout << mat[i][j] << ' ';
    cout << '\n';
  }  
  
  system("PAUSE");
}
