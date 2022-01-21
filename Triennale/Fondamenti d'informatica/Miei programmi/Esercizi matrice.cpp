#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_RIG=20;
const int MAX_COL=20;
typedef int vettore[MAX_COL];
typedef vettore matrice[MAX_RIG];

void leggi_matrice(matrice, int &, int &);
void stampa_matrice(const matrice, int &, int &); 
void trova_minimo(const matrice, int, int, vettore);

int main(){
    matrice m;
    int rig, col;
    vettore v;
    
    leggi_matrice(m, rig, col);
    stampa_matrice(m, rig, col);
    trova_minimo(m, rig, col, v);
    
    system("PAUSE");
    return 0;
}

void leggi_matrice(matrice m, int &rig, int &col){
     cout <<"Il numero di righe e': ";
     cin >>rig;
     cout <<"Il numero di colonne e': ";
     cin >>col;
     int i, j;
     for (i=0; i<rig; i++)
       for (j=0; j<col; j++){
          cout <<"Inserisci l'elemento [" <<i <<"][" <<j <<"]: ";
          cin >>m[i][j];
          }
} 

void stampa_matrice(const matrice m, int &rig, int &col){
     cout <<"\nLa matrice e': \n";
     int i, j;
     for (i=0; i<rig; i++){
       for (j=0; j<col; j++)
           cout <<m[i][j] <<" ";
       cout <<"\n";
       }
}

void trova_minimo(const matrice m, int rig, int col, vettore v){
     int i, j, min;
      for (i=0; i<rig; i++){
          min=m[i][0];
          for (j=0; j<col;j++)
              if(m[i][j]<min)
               min=m[i][j];
          v[i]=min;
      }
      cout <<"Il minimo di ciascuna riga e': ;
      for(i=0; i<rig; i++)
         cout <<v[i] <<" ";
}
