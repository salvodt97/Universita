#include "Vettore.h"

namespace Mynamespace{
	Vettore::Vettore(int d){
		dim=d;
		vet=new T [dim];
	}
	
	Vettore::Vettore(const Vettore & V){
		dim=V.dim;
		vet= new T [dim];
		for(int i=0; i<dim; i++)
		vet[i]=V[i];
	}
	
	const Vettore & Vettore::operator =(const Vettore & V){
		if(this != &V){
		dim=V.dim;
		vet= new T [dim];
		for(int i=0; i<dim; i++)
		vet[i]=V[i];
		}
		return * this;
	}
	
	ostream & Vettore::stampa(ostream & out) const {
		for(int i=0; i<dim; i++)
		out << vet[i];
		return out;
	}
}
