#include "Elenco.h"
using namespace Mynamespace;

using std::cin;
using std::cout;

int main(int argc, char** argv){
	Elenco E(1);
	Manoscritto M1, M2, M3;
	cin >> M1 >> M2 >>M3;
	if(E.inserisci(M1)) cout <<"elemento inserito";
	else cout << "\nno";
	if(E.inserisci(M1)) cout <<"elemento inserito";
	else cout << "\nno";
	E.inserisci(M3);
	cout << E;
	return 0;
}
