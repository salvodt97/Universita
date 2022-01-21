#include "Vetril.h"

namespace Mynamespace{
	Vetril::Vetril(int i, const char * P):Vettore(i){
		Periodo=new char [strlen(P)+1];
		strcpy(Periodo, P);
	}
	
	Vetril::Vetril(const Vetril & V):Vettore(V){
		Periodo=new char [strlen(V.Periodo)+1];
		strcpy(Periodo,V.Periodo);
	}
	
	const Vetril & Vetril::operator=(const Vetril & V){
		if(this != &V){
			Vettore::operator=(V);
			delete [] Periodo;
			Periodo=new char [strlen(V.Periodo)+1];
			strcpy(Periodo,V.Periodo);
		}
		return * this;
	}
	
	void Vetril::Carica_Tmax(const char * s){
		ifstream infile;
		infile.open(s, ios::in);
		if(!infile)
		exit(0);
		int tempmax;
		for(int i=0; i<dim; i++){
		infile >> tempmax;
		vet[i].set_Tmax(tempmax);
		}
		infile.close();	
	}
	
	void Vetril::Carica_Tmin(const char * s){
		ifstream infile;
		infile.open(s, ios::in);
		if(!infile)
		exit(0);
		int tempmin;
		for(int i=0; i<dim; i++){
		infile >> tempmin;
		vet[i].set_Tmin(tempmin);
		}
		infile.close();	
	}
	
	float Vetril::MedieT() const{
		int sommamin=0;
		int sommamax=0;
		for(int i=0; i<dim; i++){
		sommamax=sommamax+vet[i].get_Tmax();
		sommamin=sommamin+vet[i].get_Tmin();
		}
	return (sommamin+sommamax)/dim;
	}
}
