#include "Persona.h"
#include "Genitore.h"
using namespace Mynamespace;

using std::cin;
using std::cout;


int main(int argc, char** argv) {
	
	Genitore G,G1;
	cout << "Inserisci i dati relativi al genitore:" <<"\n";
	cin >> G;
	cout <<"Il genitore e':'" << "\n" << G;
	if(G.controllo_Eta()) cout <<"\nL'eta e' corretta";
	else cout << "\nL'eta non e' corretta";
	if(G.controllo_CF()) cout <<"\nIl CF e' corretto";
	else cout << "\nIl CF e' errato\n";
	G1=G;
	cout << G1;
	
	return 0;
}
