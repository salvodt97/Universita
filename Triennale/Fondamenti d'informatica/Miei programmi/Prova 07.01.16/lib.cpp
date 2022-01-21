#include <iostream>
#include <fstream>
#include <cstdlib>
#include "lib.h"
using namespace std;

void leggi_mat(stringa s, matrice m, int &riga, int &colonna){                       
     ifstream input;                                                         
     input.open(s);
     if(input.fail())
      exit (1);
     int i, j;       
     input >> riga;
     input >> colonna;
     for(i=0; i<riga; i++)
       for(j=0; j<colonna; j++)
         input >> m[i][j];         
      input.close();
}

bool calc_vett_struct(const matrice m, int riga, int colonna, vettore VS){
     int i, j;
     elemento x;
     bool trovato=false;
     
     for(i=0; i<riga; i++){
       for(j=1; j<colonna; j++)
        if(m[i][j]>m[i][j-1]){
          x.val=m[i][j];
          x.rig=i;
          x.col=j;
          trovato=true;
          break;
          }
          VS[i]=x;}
       
       return trovato;
}
     
void salva_struct(stringa s1, const vettore VS, int riga){ 
     int i;
     ofstream output;
     
     output.open(s1);
     if(output.fail())
     exit (1);
     
     output << "La struttura e':\n";
     for(i=0; i<riga; i++)
      if(VS[i].val!=VS[i+1].val){
       output << VS[i].val <<" " << VS[i].rig <<" " << VS[i].col;
       output << "\n";}
       
     output.close();
}
