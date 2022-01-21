#include <iostream>
#include <cstring>
#include "libr.h"
using namespace std;


void leggi_stringa(stringa s1, stringa s2){
     int lun1, lun2;
     cout <<"Inserisci due parole di uguale lunghezza\n";
     do {cout <<"La prima parola e': ";
         cin >>s1;
         cout <<"La seconda parola e': ";
         cin >>s2;
         lun1=strlen(s1);
         lun2=strlen(s2);
         if (lun1!=lun2)
         cout <<"Le parole devono contenere lo stesso numero di lettere!" <<"\n\nInserisci altre due parole\n"; 
          }
          while (lun1!=lun2);
}     
     
void crea_stringa(const stringa s1, const stringa s2, stringa s3){
     int i, k, lun;
     lun=strlen(s1);
     k=0;
     for (i=0; i<lun; i++){
         if(s1[i]==s2[i]){
          s3[k]=s1[i];
          k++;}
         s3[k]='\0';
              }
        
}

void stampa(const stringa s3){
     int lun3;
     lun3=strlen(s3);
     if (lun3!=0)
     cout <<"I caratteri uguali in posizione omologa sono: " <<s3 <<"\n"; 
     else cout <<"Non ci sono caratteri uguali, in posizioni omologhe, nelle due parole\n";
}
