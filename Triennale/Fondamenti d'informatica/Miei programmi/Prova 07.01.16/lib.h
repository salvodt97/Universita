const int MAX_COL=20;
const int MAX_RIG=20;
const int MAX_CAR=20;
typedef float matrice[MAX_RIG][MAX_COL];
typedef char stringa [MAX_CAR];
typedef struct elemento{
                 float val;
                 int rig;
                 int col;
                };
typedef elemento vettore[MAX_COL];

void leggi_mat(stringa, matrice, int &, int &);
bool calc_vett_struct(const matrice, int, int, vettore);
void salva_struct(stringa, const vettore, int);
