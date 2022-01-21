#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// dichiarazioni
const int MAX_ELEM=30;
const int MAX_DIM=20;
typedef char stringa[MAX_ELEM+1];
typedef stringa vett_stringa[MAX_DIM];

// si puo' anche dichiarare: 
// typedef char vett_stringa[MAX_DIM][MAX_ELEM+1];

// prototipi
void leggi(vett_stringa, int&);
void conta_vocali(const vett_stringa, int, int &, int &, int &, int &, int &, int &);
void stampa(int, int, int, int, int, int);

//main
int main() {
  vett_stringa VS;
  int riemp,a,e,i,o,u,altro;
  
  leggi(VS,riemp);
  conta_vocali(VS,riemp,a,e,i,o,u,altro);
  stampa(a,e,i,o,u,altro);
  
  system("PAUSE");
  return 0;
}

// definizione delle funzioni
void leggi(vett_stringa VS, int & riemp){
  int i;
    
  cout<<"Inserire il numero di parole (MAX "<<MAX_DIM<<") che compongono la frase: ";
  cin>>riemp;
  for(i=0;i<riemp;i++){
    cout<<"Inserire la parola n. "<< i+1 << ": ";
    cin>>VS[i];
  }
} 

void conta_vocali(const vett_stringa VS, int riemp, int& num_a, int &num_e, int &num_i, int & num_o, int &num_u, int& altro){
  int i,j,lun;
  
  num_a=num_e=num_i=num_o=num_u=altro=0;
  
  for (i=0;i<riemp;i++){
    lun=strlen(VS[i]);
    for(j=0;j<lun;j++)
      switch (VS[i][j]){
        case 'a':
        case 'A':
          num_a++;
          break;
        case 'e':
        case 'E':
          num_e++;
          break;
        case 'i':
        case 'I':
          num_i++;
          break;
        case 'o':
        case 'O':
          num_o++;
          break;
        case 'u':
        case 'U':  
          num_u++;
          break;
        default:
          altro++;
      }
  }
}


void stampa(int num_a,int num_e,int num_i,int num_o,int num_u, int altro){
  
  cout << "\nNumero di 'a': "<<num_a<< '\n';
  cout << "Numero di 'e': "<<num_e<< '\n';
  cout << "Numero di 'i': "<<num_i<< '\n';
  cout << "Numero di 'o': "<<num_o<< '\n';
  cout << "Numero di 'u': "<<num_u<< '\n';
  cout << "Altri caratteri: "<<altro<< '\n';
}
