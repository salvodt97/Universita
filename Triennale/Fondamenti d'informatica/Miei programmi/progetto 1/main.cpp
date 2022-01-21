#include <iostream>
#include <cstdlib>
#include "libr.h"
using namespace std;

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
