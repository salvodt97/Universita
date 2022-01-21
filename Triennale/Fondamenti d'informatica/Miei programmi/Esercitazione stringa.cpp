#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

//Definizione utile per tutto il programma
const int MAX_DIM=20;
typedef char stringa[MAX_DIM+1];

//Prototipi
void leggi_stringa(stringa, stringa);
void crea_stringa(const stringa, const stringa, stringa);
void stampa(const stringa);

//main
int main(){
    stringa s1, s2, s3;
    char tasto;
    
    do{
    leggi_stringa(s1, s2);
    crea_stringa(s1, s2, s3);
    stampa(s3);
    cout <<"\nSe vuoi riprovare, premi il tasto Y.";
    cin >>tasto;
    }
    while(tasto=='Y');
    
    system("PAUSE");
    return 0;
}

//Definizioni delle funzioni
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
     cout << s1;
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
      
        
     
