#include "Parcheggio.h"
#include <fstream>
using namespace Mynamespace;

using std::cin;
using std::cout;
using std::ofstream;
using std::ios;

int main(int argc, char** argv) {
	Parcheggio P("Salvatore","Messercola",2,3);
	ofstream file;
	file.open("Parcheggio.txt", ios::out);
	if(file){
	file << P;
	cout <<"Dati salvati correttamente."}
	else cout <<"File non aperto."	
	file.close();
	return 0;
}
