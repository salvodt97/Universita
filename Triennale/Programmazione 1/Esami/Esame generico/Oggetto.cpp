#include "Oggetto.h"

namespace Mynamespace{
	Oggetto::Oggetto(int c, const char * d, int g, int m, int a):creazione(g,m,a), codice(c){
		descrizione=new char [strlen(d)+1];
		strcpy(descrizione,d);
	}
	
	Oggetto::Oggetto(const Oggetto & O){
		codice=O.codice;
		descrizione=new char [strlen(O.descrizione)+1];
		strcpy(descrizione,O.descrizione);
		creazione=O.creazione;
	}
	
	const Oggetto & Oggetto::operator =(const Oggetto & O){
		if(this != &O){
			codice=O.codice;
			delete [] descrizione;
			descrizione=new char [strlen(O.descrizione)+1];
			strcpy(descrizione,O.descrizione);
			creazione=O.creazione;
		}
		return * this;
	}
	
	void Oggetto::set_descrizione(const char * d){
		delete [] descrizione;
		descrizione=new char [strlen(d)+1];
		strcpy(descrizione,d);
	}
	
	istream & Oggetto::leggi(istream & in){
		char buffer[40];
		
		in >> codice;
		delete [] descrizione;
		in >> buffer;
		descrizione=new char [strlen(buffer)+1];
		strcpy(descrizione,buffer);
		in >> creazione;
		
		return in;
	}
	
	bool Oggetto::check() const throw(Eccezione){
		if((creazione.get_giorno()>=1 && creazione.get_giorno()<=31) && (creazione.get_mese()>=1 && creazione.get_mese()<=12)) return true;
		else throw Eccezione("Data inesistente: ",creazione.get_giorno(), creazione.get_mese(), creazione.get_anno());
	}
}
