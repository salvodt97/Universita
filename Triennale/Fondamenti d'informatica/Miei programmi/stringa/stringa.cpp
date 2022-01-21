#include <iostream>
#include <fstream>
#include <cstring>
#include "stringa.h"
using namespace std;

void leggi_parole(stringa s, vett_str v){
   ifstream input;
   cout <<"Inserisci il nome del file di testo ";
   cin >>s;
   input.open (s);
   if (input.fail())
     exit (1);
     
   int i=0;
   while(!input.eof()){
     input >> v[i];
     i++;
     }
      input.close();  
   
}

void crea_stringa_max(const vett_str v, int &riemp, stringa max_car){
     cout <<"Inserisci il numero di parole contenute nel file ";
     cin >> riemp;
     int i, j, lun=0;
     int lun1=0;
     char max;
     for(i=0;i<riemp;i++){
       lun=strlen(v[i]);
       max=v[i][0];
       for(j=0; j<lun; j++)
         if(v[i][j]>max)
          max=v[i][j];
       max_car[i]=max;
     }

} 
       
void stampa_vett_str(const vett_str v, int riemp, const stringa max_car){
     int i, lun1=0;
     cout << "Parole lette da file:\n";
     for (i=0;i<riemp;i++)
      cout << v[i] <<" ";
     
     cout << "\nStringa ottenuta:\n";
     for (i=0;i<riemp;i++)
      cout << max_car[i];
      cout << "\n";
}
