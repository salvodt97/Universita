#include "Genitore.h"

namespace Mynamespace{
	Genitore::Genitore(const char * N, const char * C, const char * cf, const int E,const char * S, const int nf):Persona(N,C,cf,E){
		Sesso=new char[strlen(S)+1];
		strcpy(Sesso, S);
		NumFigli=nf;
	}
	
	void Genitore::set_Sesso(const char * S){
		if(Sesso) delete [] Sesso;
		Sesso=new char[strlen(S)+1];
		strcpy(Sesso,S);
	}
	
	Genitore::Genitore(const Genitore & G):Persona(G){
		Sesso=new char[strlen(G.Sesso)+1];
		strcpy(Sesso,G.Sesso);
		NumFigli=G.NumFigli;
	}
	
	const Genitore & Genitore::operator =(const Genitore & G){
		if(this != &G){
		Persona::operator =(G);
		if(Sesso) delete [] Sesso;
		Sesso=new char[strlen(G.Sesso)+1];
		strcpy(Sesso,G.Sesso);
		NumFigli=G.NumFigli;
		}
		return * this;
	}
	
	istream & Genitore::read(istream & in){
		Persona::read(in);
		char sesso[10];
		
		if(Sesso) delete [] Sesso;
		in >> sesso;
		Sesso=new char[strlen(sesso)];
		strcpy(Sesso,sesso);
		
		in >> NumFigli;
		
		return in;
	}
}
