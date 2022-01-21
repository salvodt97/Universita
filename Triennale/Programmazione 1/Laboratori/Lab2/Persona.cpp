#include "Persona.h"

const int MAX=100;
namespace Mynamespace{
	Persona::Persona(const char * N, const char * C, const char * cf, const int E){
		Nome=new char[strlen(N)+1];
		strcpy(Nome,N);
		Cognome=new char[strlen(C)+1];
		strcpy(Cognome,C);
		strcpy(CF,cf);
		Eta=E;
	}
	
	Persona::Persona(const Persona & P){
		Nome=new char[strlen(P.Nome)+1];
		strcpy(Nome,P.Nome);
		Cognome=new char[strlen(P.Cognome)+1];
		strcpy(Cognome,P.Cognome);
		strcpy(CF,P.CF);
		Eta=P.Eta;
	}
	
	void Persona::set_Nome(const char * N){
		if(Nome) delete [] Nome;
		Nome=new char[strlen(N)+1];
		strcpy(Nome,N);
	}
	
	void Persona::set_Cognome(const char * C){
		if(Cognome) delete [] Cognome;
		Nome=new char[strlen(C)+1];
		strcpy(Cognome,C);
	}	
	
	const Persona & Persona::operator =(const Persona & P){
		if(this != &P){
		if(Nome) delete [] Nome;
		Nome=new char[strlen(P.Nome)+1];
		strcpy(Nome,P.Nome);
		if(Cognome) delete [] Cognome;
		Cognome=new char[strlen(P.Cognome)+1];
		strcpy(Cognome,P.Cognome);
		strcpy(CF,P.CF);
		Eta=P.Eta;
		}
		return * this;
	}
		
	istream & Persona::read(istream & in){
		char nome[MAX], cognome[MAX];

		if(Nome) delete [] Nome;
		in.getline(nome,MAX);
		Nome=new char[strlen(nome)];
		strcpy(Nome,nome);
		
		if(Cognome) delete [] Cognome;
		in.getline(cognome,MAX);
		Cognome=new char[strlen(cognome)];
		strcpy(Cognome,cognome);
		
		in >> CF;
		in >> Eta;
		
		return in;
		
	}
	
	ostream & Persona::print(ostream & out) const{
		out << Nome <<' ' <<Cognome<<' ';
		for(int i=0;i<N;i++)
		out << CF[i];
		out <<' ' <<Eta;
		return out;
	}
	
	bool Persona::controllo_CF() const{
		bool trovato=true;
		int i=0;
		while(i<N && trovato)
		if(!(CF[i]>='0' && CF[i]<='9') && !(CF[i]>='A' && CF[i]<='Z'))
		trovato=false;
		else i++;
		return (strlen(CF)==16 && trovato);
	}

}
