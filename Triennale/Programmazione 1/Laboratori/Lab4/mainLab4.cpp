#include <fstream>
#include "Massaggio.h"
#include "Sauna.h"
#include "pilaLab4.h"

using namespace Mynamespace;
using namespace Contenitore;

using std::cin;
using std::cout;
using std::ofstream;

int main(int argc, char** argv) {
	Massaggio M;
	Sauna S, S1;
	Pila P;
	ofstream myfile;
	
	Trattamento * v[2];
	v[0]=&M;
	v[1]=&S;
	for(int i=0;i<2;i++){
		cout <<"\nScegliere il trattamento:\n";
		cin >> *v[i];
		cout << "Il trattamento da lei scelto e' : " <<*v[i] <<" al costo di:"<< v[i]->calcola_costo();
	}
	
	try{
		S1.set_Umidita(40);
		cout <<"\nL'Umidita scelta e' "<< S1.get_Umidita() <<" %";
	}
	catch(bad_data b){
		cout << b.what() <<"per l'umidita di: " <<b.get_valore();
	}
	
	myfile.open("Lab4.txt");
	if(myfile){
		for(int i=0;i<2;i++)
		myfile << *v[i] <<"\n";
		myfile.close();
		cout <<"\nCopia su file eseguita";
	}
	else cout <<"\nErrore nella copia su file!";
	
	if(P.push(S)) cout <<"\nElemento inserito";
	else cout <<"Elemento non inserito";


	return 0;
}
