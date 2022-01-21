#include "Utente.h"

namespace Mynamespace{
	Utente::Utente(const char * c, const char * co, int g, int m, int a):registrazione(g,m,a){
		strcpy(cf,c);
		cognome=new char[strlen(co)+1];
		strcpy(cognome,co);
	}
	
	Utente::Utente(const Utente & U){
		strcpy(cf,U.cf);
		cognome=new char[strlen(U.cognome)+1];
		strcpy(cognome,U.cognome);
		registrazione=U.registrazione;
	}
	
	const Utente & Utente::operator =(const Utente & U){
		if(this != &U){
		strcpy(cf,U.cf);
		delete [] cognome;
		cognome=new char[strlen(U.cognome)+1];
		strcpy(cognome,U.cognome);
		registrazione=U.registrazione;
		}
		return * this;
	}
	
	istream & Utente::leggi(istream & in){
		char buffer[50];
		
		in >> cf;
		
		delete [] cognome;
		in >> buffer;
		cognome=new char[strlen(buffer)+1];
		strcpy(cognome,buffer);
		
		in >> registrazione;
		
		return in;
	}
	
	bool Utente::Check() const throw(Eccezione){
		bool ok=true;
		int i=0;
		while(i<16 && ok)
		if((cf[i]>='0' && cf[i]<='9') || (cf[i]>='A' && cf[i]<='Z')){
		ok=true;
		i++;
		}
		else{
		ok=false;
		throw Eccezione("Errore nel codice fiscale: ",cf);
		}
		return ok;		
	}
}
