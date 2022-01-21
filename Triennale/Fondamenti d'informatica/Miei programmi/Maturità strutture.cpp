#include <iostream>
#include <cstring>
#include <cstdlib>
using namespace std;

//Definizioni utili
const int MAX_ELM=20;
typedef char stringa[MAX_ELM+1];
struct materia{
       int voto;
       stringa nome;
};

typedef materia vettore[MAX_ELM];

//Prototipi
void leggi_materia(vettore, int&);
void stampa_pagella(const vettore, int &);
float calcola_media(const vettore, int);

int main(){
    int riemp;
    vettore v;
    float media;
    
    leggi_materia(v, riemp);
    stampa_pagella(v, riemp);
    media=calcola_media(v, riemp);
    cout<<"\nLa media dei voti e': " <<media <<"\n\n";
    
    system("PAUSE");
    return 0;
}

//Funzioni
void leggi_materia(vettore v, int &riemp){
     int i;
     cout <<"Inserisci il numero di materie. ";
     cin >>riemp;
     for (i=0;i<riemp;i++){
         cout <<"Inserisci il nome della materia " <<i+1 <<": ";
         cin >>v[i].nome;
         cout <<"Inserisci il voto conseguito nella materia " <<i+1 <<": ";
         cin >>v[i].voto;
         }
}

void stampa_pagella(const vettore v, int &riemp){
     int i;
     cout <<"\n";
     for (i=0;i<riemp;i++)
         cout <<"Il voto che hai conseguito in " <<v[i].nome <<" e': " <<v[i].voto <<"\n";
}

float calcola_media(const vettore v, int riemp){
      int i, somma=0;
      float media;
      for (i=0;i<riemp;i++)
         somma=somma+v[i].voto;
      media=float(somma)/riemp;
      return media;
}
      
