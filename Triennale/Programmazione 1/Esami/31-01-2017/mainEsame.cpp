#include "Utente.h"
#include "Utenteposta.h"

using namespace Mynamespace;
using std::cin;
using std::cout;


int main(int argc, char** argv) {
	Utenteposta U;
	Utente U1;
	Utente * v[2];
	v[0]=&U1;
	v[1]=&U;
	for(int i=0;i<2;i++){
	cout <<"Inserire l'utente:\n";
	cin >> *v[i];
	}
	for(int i=0;i<2;i++){
	try{
		if(v[i]->Check()) cout <<"\nL'utente e' " << *v[i];
	}
	catch(Eccezione e){
		cout <<"\n" <<e.what() <<e.get_valore();
	}
}
	return 0;
}
