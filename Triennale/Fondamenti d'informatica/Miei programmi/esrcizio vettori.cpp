#include <iostream>
#include <cstdlib>
using namespace std;

const int DIM_MAX=30;
typedef int vettore [DIM_MAX];

void leggi_vettore(vettore, int&);
void inverti_vettore(const vettore, vettore, int&);
void leggi_nuovo(const vettore, int&);
int main(){
    vettore v, v1;
    int riemp;
    
    leggi_vettore(v, riemp);
    inverti_vettore(v, v1, riemp);
    leggi_nuovo(v1, riemp);
    
    system("PAUSE");
    return 0;
}

void leggi_vettore(vettore v, int &riemp){
     int i;
     cout <<"Dimmi quanti elementi ha il vettore. ";
     cin >>riemp;
     cout <<"\nInserisci gli elementi.\n";
     for(i=0; i<riemp; i++){
         cout <<"L'elemento del vettore numero " <<i+1 <<" e': ";
         cin >>v[i];}
}     
        
void inverti_vettore(const vettore v, vettore v1, int &riemp){
     int i, j;
     j=0;
     for(i=riemp-1; i>=0; i--)
        v1[j++]=v[i];
}

void leggi_nuovo(const vettore v1, int &riemp){
     int j=0;
     cout <<"Il vettore invertito ha elementi: ";
     for(j=0; j<riemp; j++)
        cout <<v1[j] <<" ";
}
