#include "Vettore.h"

	
	
Vettore::Vettore(const int n) {
	dim=n;
	Vet=new T[dim];
}	

Vettore::Vettore(const Vettore & V){
	dim=V.dim;
	Vet=new T[dim];
	for(int i=0; i<dim; i++)
	   Vet[i]=V.Vet[i];
	   //Vet[i]=V[i]; 
}	

const Vettore & Vettore::operator=(const Vettore & V){
	
	if(this!=&V) {
		if(Vet) delete[] Vet;
		dim=V.dim;
		Vet=new T[dim];
        for(int i=0; i<dim; i++)
	         Vet[i]=V.Vet[i];	
	}
	return *this;
}	

T & Vettore::operator[](const int index){
	cout << "operator[]" << endl;
	return Vet[index];
}	

const T & Vettore::operator[](const int index) const{
	cout << "operator[] const" << endl;
	return Vet[index];
	
}	
	   
//ok solo in coppia con l'op seguente	   
ostream & operator<<(ostream & out, const Vettore & V) {
	for (int i=0; i<V.dim; i++)
	  out << V.Vet[i] << ' ';
	//  out << V[i] << ' ';
	return out;
}

//ok solo se la dimensione rimane la stessa
istream & operator>>(istream & in, Vettore & V) {
	for (int i=0; i<V.dim; i++)
	  in >> V.Vet[i];
	return in;
}
