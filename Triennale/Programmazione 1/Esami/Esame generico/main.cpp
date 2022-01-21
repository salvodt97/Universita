#include <fstream>
#include "Libro.h"
#include "Cellulare.h"
#include "Lista.h"

using namespace Mynamespace;
using std::cin;
using std::cout;
using std::fstream;
using std::ios;

int main(int argc, char** argv) {
	Libro L; Cellulare C; Lista l;
	fstream file;
	Oggetto * v[2];
	v[0]=&L; v[1]=&C;
	
	for(int i=0;i<2;i++){
		cout <<"Inserire l'oggetto:\n";
		cin >> *v[i];
		}
		
	for(int j=0;j<2;j++){
		try{
			if(v[j]->check())
				if(l.insert(*v[j])) cout << "Oggetto numero " <<j+1 <<" inserito nella lista.\n ";		
			}
		catch(Eccezione e){
			cout << e.what() << e.get_data() <<"; oggetto numero "  <<j+1 <<" non inserito nell lista.\n";
		}
	}

	file.open("Oggetti.txt", ios::out);
	if(!file) exit(0);
	file <<"\nLa lista e' composta da: " <<l;
	file.close();
	cout <<"\nDati salvati nel file.";
	
	return 0;
}
