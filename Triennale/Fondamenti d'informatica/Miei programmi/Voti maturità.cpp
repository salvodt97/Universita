#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    // Dichiarazioni
    const int DIM_MAX=11;
    typedef int vett_voti[DIM_MAX];
    int i,riemp,somma;
    float media;
    vett_voti voti;
    
    //lettura dati
    cout << "Il numero di voti che hai conseguito sono: ";
    cin >> riemp;
    cout << "\n"; 
    for (i=0; i<riemp; i++){
       cout << "Il voto che hai conseguito nell'esame numro " << i+1 << " e':";
       cin >> voti[i];};
       
     
     //stampa dei valori
     cout << "\nI tuoi voti sono: ";  
        for (i=0; i<riemp; i++)
        cout << voti[i] << " ";
        
    //calcolo della media
    somma=0;
    for (i=0; i<riemp; i++)
      somma=somma+voti[i];
    media=float(somma)/riemp;
    cout << "\nLa tua media e' " << media;   
    
    
    //calcolo valori pari
    cout<<"\nI voti pari sono: ";
    vett_voti voti1;
    int j,riemp1;
    j=0;
    for (i=0; i<riemp; i++)
       if (voti[i]%2==0)
          voti1[j++]=voti[i];
    riemp1=j;
    
    for(i=0; i<riemp1; i++)
       cout<< voti1[i] <<" ";
     
    //aggiunta di un elemento
    int voto,pos;
    cout << "\nIl voto da inserire e': ";
    cin >> voto;
    cout << "Nella posizione: ";
    cin >> pos;
    if (voto>=6 && voto<=10){
        for (i=riemp-1; i>=pos-1; i--)
            voti[i+1]=voti[i];
        voti[pos-1]=voto;
        riemp++;
        cout << "\nOra i tuoi voti sono: ";
        for(i=0; i<riemp; i++)
            cout << voti[i] << " ";}
     else cout << "\nIl voto inserito e' scorretto ";  
     
     //calcolo del voto più alto
     int max;
     max=voti[0];
     for (i=1; i<riemp; i++)
         if (voti[i]>max)
         max=voti[i];
     cout << "\nIl voto piu' alto e' " <<max;
     cout << "\nOra i tuoi voti sono: ";
     for (i=0; i<riemp; i++)
        cout << voti[i] <<" ";
     cout << "\nQundi la tua media diventa: ";
     somma=0;
     for (i=0; i<riemp; i++)
         somma=somma + voti[i];
     media=float(somma)/riemp;
     cout << media;
 
     system ("PAUSE");  
} 
    
    
