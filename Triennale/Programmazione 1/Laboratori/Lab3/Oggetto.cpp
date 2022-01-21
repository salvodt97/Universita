#include "Oggetto.h"

namespace Mynamespace{
	Oggetto::Oggetto():Codice(0){
		Descrizione=new char[1];
		strcpy(Descrizione,"");
	}
	
	Oggetto::Oggetto(int C, const char * D){
		Codice=C;
		Descrizione=new char[strlen(D)+1];
		strcpy(Descrizione,D);
	}
	
	Oggetto::Oggetto(const Oggetto & O){
		Codice=O.Codice;
		Descrizione=new char[strlen(O.Descrizione)+1];
		strcpy(Descrizione,O.Descrizione);
	}
	
	void Oggetto::set_Descrizione(const char * D){
		delete [] Descrizione;
		Descrizione=new char[strlen(D)+1];
		strcpy(Descrizione,D);
	}
	
	const Oggetto & Oggetto::operator=(const Oggetto & O){
		if(this != &O){
		Codice=O.Codice;
		delete [] Descrizione;
		Descrizione=new char[strlen(O.Descrizione)+1];
		strcpy(Descrizione,O.Descrizione);
		}
		return * this;
	}
	
	istream & Oggetto::read(istream & in){
		char descrizione[20];
		
		in >> Codice;
		
		delete [] Descrizione;
		in >> descrizione;
		Descrizione=new char[strlen(descrizione)+1];
		strcpy(Descrizione,descrizione);
		
		return in;
	}
}
