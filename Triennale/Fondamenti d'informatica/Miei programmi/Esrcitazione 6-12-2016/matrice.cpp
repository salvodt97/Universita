#include <iostream>
#include <fstream>
#include "matrice.h"
using namespace std;

void leggi_mat(stringa s, matrice m, int &rig, int &col){
    
    ifstream input;
    input.open(s);
    if (input.fail())
    exit (1);
    int i, j;
    input >> rig;
    input >> col;
    for(i=0; i<rig; i++)
     for(j=0; j<col; j++)
      input >> m[i][j]; 
    input.close();
}  

bool med_pos_mat(const matrice m, int &rig, int &col, float &med_pos){
    int i, j;
    float somma=0;
    int el=0;
    
    for(i=0; i<rig; i++)
     for(j=0; j<col; j++)
      if (m[i][j]>0){
       somma=somma+m[i][j];
       el++;
      }   
     med_pos=somma/el;
     cout <<"\nLa media dei numeri positivi e': " << med_pos <<"\n";
     
     bool trovato;
      if (somma==0)
        trovato=false;
      else trovato=true;
      
      if (trovato=false)
        cout <<"Non ci sono elemnti positivi nella matrice";
      
        return trovato;  
 }     
  
elemento calc_mag(const matrice m, float &med_pos, int rig, int col){
    
  elemento magg;
  int i,j;
  for(i=0; i<rig; i++){
   for(j=0; j<col; j++)
     if (m[i][j]>med_pos){
       magg.mag=m[i][j];
       magg.riga=i+1;
       magg.colonna=j+1;
       }
   break;
  }
    return magg;
} 
