#include "Vettore.h"

namespace Mynamespace{
	Vettore::Vettore(int d){
		nelem=d;
		vet=new T[nelem];
	}
	
	Vettore::Vettore(const Vettore & V){
		nelem=V.nelem;
		vet=new T[nelem];
		for(int i=0; i<nelem; i++)
		vet[i]=V.vet[i];
	}
	
	const Vettore & Vettore::operator =(const Vettore & V){
		if(this != &V){
		nelem=V.nelem;
		delete [] vet;
		vet=new T[nelem];
		for(int i=0; i<nelem; i++)
		vet[i]=V.vet[i];
		}
		return * this;
	}
	
	istream & operator >>(istream & in, Vettore & V){
		in >> V.nelem;
		
		delete [] V.vet;
		V.vet=new T[V.nelem];
		for(int i=0; i<V.nelem; i++)
		in >> V[i];
		
		return in;
	}
	
	ostream & operator <<(ostream & out, const Vettore & V){
		for(int i=0; i<V.nelem; i++)
		out << V[i] <<" ";
		
		return out;
	}
	
	void Vettore::Elimina(){
		for(int i=0; i<nelem; i++)
			if(vet[i].get_peso()>0.5){
				vet[i]=vet[i+1];
				nelem --;
			}
	}
}
