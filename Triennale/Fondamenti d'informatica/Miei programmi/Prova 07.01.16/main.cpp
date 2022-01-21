#include <iostream>
#include <cstdlib>
#include "lib.h"
using namespace std;

int main(){
    matrice m;
    vettore VS;
    bool trovato;    
    int riga, colonna;
    stringa s, s1;
    cout <<"Inserisci il nome del file: ";
    cin >> s;
    
    leggi_mat(s, m, riga, colonna);
    trovato=calc_vett_struct(m, riga, colonna, VS);
    if(trovato=true){
    cout <<"Inserisci il nome del file su cui salvare la struttura: ";
    cin >> s1;
    salva_struct(s1, VS, riga);
    cout <<"La struttura e' stata salvata nel file scelto.\n";
    }else cout <<"Il vettore VS non contiene elementi.";

    system("PAUSE");
    return 0;
}
