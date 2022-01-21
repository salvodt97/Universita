const int MAX_CAR=20;
const int MAX_RIG=30;
const int MAX_COL=20;
typedef char stringa [MAX_CAR+1];
typedef float matrice [MAX_RIG][MAX_COL];
typedef struct elemento{
                 float mag;
                 int riga;
                 int colonna;
                };

void leggi_mat(stringa, matrice, int &, int &);
bool med_pos_mat(const matrice, int &, int &, float &);
elemento calc_mag(const matrice, float &, int, int);
