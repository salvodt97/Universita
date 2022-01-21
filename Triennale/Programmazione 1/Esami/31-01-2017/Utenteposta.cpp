#include "Utenteposta.h"

namespace Mynamespace{
	Utenteposta::Utenteposta(const char * c, const char * co, int g, int m, int a, const char * e):Utente(c,co,g,m,a){
		email=new char[strlen(e)+1];
		strcpy(email,e);
	}
	
	Utenteposta::Utenteposta(const Utenteposta & U):Utente(U){
		email=new char[strlen(U.email)+1];
		strcpy(email,U.email);
	}
	
	const Utenteposta & Utenteposta::operator =(const Utenteposta & U){
		if(this != &U){
			Utente::operator =(U);
			delete [] email;
			email=new char[strlen(U.email)+1];
			strcpy(email,U.email);
		}
		return * this;
	}
	
	istream & Utenteposta::leggi(istream & in){
		Utente::leggi(in);
		char buffer[50];
		
		delete [] email;
		in >> buffer;
		email=new char[strlen(buffer)+1];
		strcpy(email,buffer);
		
		return in;
	}
	
	bool Utenteposta::Check() const throw(Eccezione){
		int i=0, count=0;
		while(i<strlen(email) && email[i]!='@'){
		i++;
		count++;
		}
		if(count==strlen(email)) throw Eccezione("Errore nell' email, non c'e' alcuna @ ",email);
		
		return (Utente::Check());
	}
}
