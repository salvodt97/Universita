const int MAX_ELE=20;
const int MAX_DIM=30;
typedef char stringa[MAX_ELE+1];
typedef stringa vett_str[MAX_DIM];

void leggi_parole(stringa, vett_str);
void crea_stringa_max(const vett_str, int &, stringa);
void stampa_vett_str(const vett_str, int, const stringa);
