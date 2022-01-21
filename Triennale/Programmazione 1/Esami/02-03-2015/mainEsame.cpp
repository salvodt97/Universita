#include "Veicolo.h"
#include "Auto.h"
#include "Moto.h"
#include "Garage.h"
#include "Garage.h"
#include <fstream>
using namespace Mynamespace;

using std::cin;
using std::cout;
using std::ofstream;
using std::ios;

int main(int argc, char** argv){
	ofstream output;
	Veicolo * v[2];
	Auto A; Moto M; Garage G;
	v[0]=&A;
	v[1]=&M;
	
	
	for(int i=0;i<2;i++){
	cout <<"Inserisci il veicolo:\n";
	cin >> *v[i];
	cout <<"Il veicolo e':\n" <<v[i]->ToText() <<"\n";
	}
    try{
    output.open("Garage.txt", ios::out);
    if(output){
	G.Immetti(A);
	G.Immetti(M);
	for(int i=0; i<G.get_riemp(); i++)
	output << G[i] <<"\n";
	cout <<"\nOperazione su file eseguita corettamente!";
	output.close();
	}
	}
	catch(Eccezione e){
		cout << e.what();
	}
	return 0;
}
