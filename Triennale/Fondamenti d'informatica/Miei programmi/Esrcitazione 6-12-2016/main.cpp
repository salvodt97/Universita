#include <iostream>
#include <cstdlib>
#include "matrice.h"
using namespace std;

int main(){
    stringa s;
    matrice m;
    elemento magg;
    int rig, col;
    float med_pos;
    bool trovato;

    cout <<"Inserisci il nome del file ";
    cin >> s;
    
    leggi_mat(s, m, rig, col);
    trovato=med_pos_mat(m, rig, col, med_pos);
    magg=calc_mag(m, med_pos, rig, col);
    
    cout <<"Il numero piu' grande della media e' : " <<magg.mag <<"\nLa sua riga e': " <<magg.riga <<"\nLa sua colonna e': " <<magg.colonna <<"\n";
    
    system("PAUSE");
    return 0;
}
