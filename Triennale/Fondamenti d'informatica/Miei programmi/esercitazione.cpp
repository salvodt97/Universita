#include <iostream>
#include <cstdlib>
using namespace std;

const int DIM_MAX=20;
typedef int vettore[DIM_MAX];
typedef int matrice[DIM_MAX][DIM_MAX];

void leggi_mat(matrice,matrice, int &);
void crea_vett(const matrice, const matrice, int, vettore, vettore, int&, int&);
void stampa_vett(const vettore, const vettore, int, int);

int main(){
    int riemp, riempMin, riempMag, i, j;
    matrice M1, M2;
    vettore VMin, VMag;
    leggi_mat(M1, M2, riemp);
    crea_vett(M1, M2, riemp, VMin, VMag, riempMin, riempMag);
    stampa_vett(VMin, VMag, riempMin, riempMag);
    system("PAUSE");
    return 0;
}

void leggi_mat(matrice M1, matrice M2, int &riemp){
    int i,j;
    cout << "\nIl riempimento e':";
    cin >>riemp;
    for(i=0; i<riemp; i++)
      for(j=0; j<riemp; j++){
          cout <<"Inserisci il valore della matrice M1 [" <<i <<"][" <<j <<"]: ";
          cin >>M1[i][j];}
          cout <<"\n";
          
    for(i=0; i<riemp; i++)
        for(j=0; j<riemp; j++){
          cout <<"Inserisci il valore della matrice M2 [" <<i <<"][" <<j <<"]: ";
          cin >>M2[i][j];}
      
}

void crea_vett(const matrice M1, const matrice M2, int riemp, vettore VMin, vettore VMag, int &riempMin, int &riempMag){
    int i, j,k;
    riempMin=0;
    riempMag=0;
    for(i=0; i<riemp; i++)
      for(j=0; j<riemp; j++)
         if (M1[i][j]<M2[i][j])
           VMin[riempMin++]=M1[i][j];
         else if (M1[i][j]>M2[i][j])
               VMag[riempMag++]=M1[i][j];
               
               
}

void stampa_vett(const vettore VMin, const vettore VMag, int riempMin, int riempMag){
    int k,t;
    if (riempMin!=0){
     cout <<"\nIl vettore VMin e' composto da: ";
    for(k=0;k<riempMin;k++)
       cout <<VMin[k] <<" ";}
     else cout <<"\nNon esiste il vettore VMin";  
      
      if(riempMag!=0){ 
      cout <<"\nIl vettore VMag e' composto da: ";
    for(t=0;t<riempMag;t++)
       cout <<VMag[t] <<" ";}
        else cout <<"\nNon esiste il vettore VMag";
    
}   
