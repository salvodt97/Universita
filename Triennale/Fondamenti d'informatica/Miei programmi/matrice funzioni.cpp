#include<iostream>
#include<cstdlib>
using namespace std;

//Dichiarazioni utili per le funzioni
const int MAX_RIG=10;
const int MAX_COL=10;
typedef int matrice[MAX_RIG][MAX_COL];
typedef int vettore[MAX_RIG]; 

//Prototipi
void lettura(matrice, int &, int &);
void stampa(const matrice, int, int);
float media(const matrice, int, int);
void el_mag(const matrice, int, int);

int main(){
    matrice mat;
    int rig, col;
    float med;
    
    cout <<"Lettura e stampa di una matrice\n";
    lettura(mat, rig, col);
    stampa( mat, rig, col);
    med=media(mat, rig, col);
    el_mag(mat, rig, col);
    cout << "La media e': " <<med;
    system("PAUSE"); 
    return 0;   
}

void lettura(matrice mat, int &rig, int &col){
     int i, j;
     cout << "Il numero di righe e':  ";
     cin >>rig;
     cout << "Il numero di colonne e': ";
     cin >> col;
     for(i=0; i<rig; i++)
         for(j=0; j<col; j++){
            cout <<"Inserisci l'elemento mat[" <<i <<"][" <<j <<"]: ";
            cin >>mat[i][j];
            }
}

void stampa(const matrice mat, int rig, int col){
     int i, j;
    cout <<"Gli elementi della matrice sono: \n";
    for(i=0; i<rig; i++){
         for(j=0; j<col; j++)
             cout <<mat[i][j] <<" ";
          cout<<"\n";
    }

}  

float media(const matrice mat, int rig, int col){
      int i, j;
      int somma=0;
      float med;
      for(i=0; i<rig; i++){
         for(j=0; j<col; j++)
         somma=somma+mat[i][j];
         }
         med=float(somma)/(rig*col);
         return med;
         }

void el_mag(const matrice mat, int rig, int col){
     int min, i, j;
     vettore v;
    for(i=0;i<rig;i++){
      for(j=1;j<col;j++){    
        min=mat[i][j];
        if(mat[i][j-1]<mat[i][j])
          min=mat[i][j+1];
          break;
             }
                v[i]=min;
         }
         for(i=0;i<rig;i++)
         cout << v[i] <<" ";
         }
         

     
    
