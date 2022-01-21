#include "Oggetto.h"
#include "Libro.h"
#include "Cellulare.h"
#include "Insieme.h"

using namespace Mynamespace;
using std::cin;
using std::cout;


int main(int argc, char** argv) {
	Oggetto O1,O2,O3;
	cout <<"Inserisci l' oggetto O1:\n";
	cin >> O1;
	cout <<"L'oggetto e': " << O1;;

	cout <<"\nInserisci l' oggetto O2:\n";
	cin >> O2;
	cout <<"L'oggetto e': " << O2;
	if (O1==O2) cout <<"\nGli oggetti sono uguali!";
	else cout <<"\nGli oggetti sono diversi";
	
	O3=O2;
	cout << "\nL'Oggetto O3 e': " << O3;
	
	Libro L1,L2,L3;
	cout <<"\nInserisci il Libro L1:\n";
	cin >> L1;
	cout <<"Il Libro e': " << L1;;

	cout <<"\nInserisci il Libro L2:\n";
	cin >> L2;
	cout <<"Il Libro e': " << L2;
	if (L1==L2) cout <<"\nI libri sono uguali!";
	else cout <<"\nI libri sono diversi";
	
	L3=L2;
	cout << "\nIl Libro L3 e': " << L3;

	Cellulare C1,C2,C3;
	cout <<"\nInserisci il cellulare L1:\n";
	cin >> C1;
	cout <<"Il Cellulare e': " << C1;;

	cout <<"\nInserisci il cellulare C2:\n";
	cin >> C2;
	cout <<"Il Cellulare e': " << C2;
	if (C1==C2) cout <<"\nI cellulari sono uguali!";
	else cout <<"\nI cellulari sono diversi";
	
	C3=C2;
	cout << "\nIl cellulare C3 e': " << C3;
	
	Insieme I;
	cout << "Inserisci l'insieme:\n";
	cin >> I;
	cout << "L'insieme e' formato da:\n" << I;
	
/*	Oggetto O;
	cin >> O;
	I.insert(O);
	cout << I;*/
	
	return 0;
}
