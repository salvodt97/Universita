#include <cstdlib>
#include "stringa.h"

int main(){
  stringa s, max_car;
  int riemp;
  vett_str v;
  
  leggi_parole(s, v);
  crea_stringa_max(v, riemp, max_car);
  stampa_vett_str(v, riemp, max_car);
  
  system("PAUSE");
  return 0;
}
