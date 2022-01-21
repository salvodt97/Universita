#include <iostream>
#include <fstream>
#include "Registrato.h"

using namespace Mynamespace;
using std::cin;
using std::cout;
using std::ofstream;
using std::ios;

int main(int argc, char** argv) {
	Cliente C;
	Registrato R1, R2;
	ofstream myfile;
	
	Cliente * v[3];
	v[0]=&C; v[1]=&R1; v[2]=&R2;
	
	for(int i=0; i<3; i++){
		cout <<"Inserire il cliente: \n";
		cin >> *v[i];
	}
	
	myfile.open("Clienti.txt", ios::out);
	if(!myfile) exit(0);
	
	for(int j=0; j<3; j++){
		try{
			if(v[j]->check()) myfile <<"Il cliente e': " << *v[j] <<"\n";
			} 	
		catch (Eccezione e){
			myfile << e.what() << e.get_valore() << " del cliente numero " <<j+1 <<"\n";
		}
	}
	
	myfile.close();
	cout <<"Dati salvati sul file.";
	return 0;
}

