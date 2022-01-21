#include "Pacchetto.h"
#include "Vettore.h"
#include <fstream>

using namespace Mynamespace;
using std::cin;
using std::cout;
using std::ofstream;
using std::ios;

int main(int argc, char** argv) {
	Pacchetto P1, P;
	Pacco * v[2];
	v[0]=&P;
	v[1]=&P1;
	for(int i=0; i<2; i++){
	cout <<"Inserisci il pacchetto\n";
	cin >> *v[i];
	if(v[i]->Check()) cout <<"Il pacchetto e': " <<*v[i] <<"\n";
	else cout <<"Destinatario errato";}
	Vettore V;
	cout <<"\nInserisci il vettore di pacchetti specificando la dilmesione: ";
	cin >> V;
	try{
	cout << V.Access(V.get_nelem()+1);}
	catch(Eccezione e){
		cout << e.what() << e.get_valore();
	}
	/*V.Elimina();
	cout << V;
	ofstream myfile("Vettore.txt", ios::out);
	myfile.open("Vettore.txt");
	if(!myfile)
	exit(0);
	myfile << V;
	myfile.close();
	cout <<"\nDati salvati sul file";*/
	return 0;
}
