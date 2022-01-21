#include "Carta.h"
#include "Bancomat.h"
#include "Tessera.h"
using namespace Mynamespace;

using std::cout;

int main(int argc, char** argv) {
	Bancomat B ("Denaro","Salvatore","12345rtd");
	Tessera T ("Sanitaria", "Salvatore", "23456uhy");
	Carta * v[2];
	v[0]=&B;
	v[1]=&T;
	try{
		char * c;
		for(int i=0;i<2;i++)
		cout <<"Tipo di carta: " <<*v[i] <<"\n";
	}
	catch(const char * s){
		cout << s;
	}
	return 0;
}
