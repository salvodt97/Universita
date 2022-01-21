#include <iostream>
#include "Vettore.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void stampa(const Vettore &, int n);

int main(int argc, char** argv) {
	
	Vettore vett1(5), vett2;
	
	cout << "dimensione di vett1: " << vett1.get_dim() << endl;
	cout << "dimensione di vett2: " << vett2.get_dim() << endl;
	
	cout << "inserire il vettore vett1" << endl;
	cin >> vett1;
	cout << vett1 << endl;
	
	vett2=vett1;
	cout << vett2 << endl;
	
	cout << "inserire il vettore vett1" << endl;
	for(int i=0; i<5; i++)
	   cin >> vett1[i];
	cout << vett1 << endl;
	
	cout << "dimensione di vett2: " << vett2.get_dim() << endl;
	cout << "inserire il vettore vett2" << endl;
	for(int i=0; i<vett2.get_dim(); i++)
	   cin >> vett2[i];
	cout << vett2 << endl;
	
	cout << "chiamo stampa" << endl;
	stampa(vett2,3);
	
	return 0;
}


void stampa(const Vettore & v, int n) {
	for(int i=0; i<n; i++)
	   cout<< v[i];
}









