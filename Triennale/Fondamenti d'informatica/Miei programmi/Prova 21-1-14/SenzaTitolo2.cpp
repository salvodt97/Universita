#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

//lib.h
const int MAX_DIM=20;
typedef int matrice[MAX_DIM][MAX_DIM];
typedef int vettore[MAX_DIM];

void leggi_mat(matrice, int &);
void calc_ind_min(const matrice, int &);
void trova_punto_sella(const matrice, int);

//main.cpp
int main(){
    matrice mat;
    int riemp;
    
    leggi_mat(mat, riemp);
    calc_ind_min(mat, riemp);
    trova_punto_sella(mat, riemp);
    
    system("PAUSE");
    return 0;
}


//lib.cpp
void leggi_mat(matrice mat, int &riemp){
     char s[MAX_DIM+1];
     int i, j;
     cout <<"Inserire il nome del file ";
     cin >>s;
     ifstream input;
     input.open(s);
     if(input.fail())
     exit (1);
     
     input >> riemp;
     for(i=0;i<riemp;i++)
       for(j=0;j<riemp;j++)
          input >> mat[i][j];
          
     input.close();
       
       }
     
void calc_ind_min(const matrice mat, int &riemp){
     int i,j,k, min;
     vettore v;
     for(i=0;i<riemp;i++){
      min=mat[i][0];
      for (j=0;j<riemp;j++)
        if(mat[i][j]<min)
        min=mat[i][j];
      v[i]=min;
      }               
}  

void trova_punto_sella(const matrice mat, int riemp){ 
     int i, j, max;
     vettore v1;
     bool trovato=false;
     while(j<riemp && !trovato){
         max=mat[0][j];
         while(i<riemp && !trovato){
             if (mat[i][j]>max){
                  trovato=true;
                  max=mat[i][j];
                  } 
              else j++;
              }
              i++;
              v1[i]=max;
              }
              for(i=0;i<riemp;i++)
              cout << v1[i] << " ";
           
     }          
       
              
  
          
    
     
