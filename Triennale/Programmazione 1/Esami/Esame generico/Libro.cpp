#include "Libro.h"

namespace Mynamespace{
	Libro::Libro(int c, const char * d, int g, int m, int a, const char * t, int p):Oggetto(c,d,g,m,a){
		titolo=new char [strlen(t)+1];
		strcpy(titolo,t);
		pagine=p;
	}
	
	Libro::Libro(const Libro & L):Oggetto(L){
		titolo=new char [strlen(L.titolo)+1];
		strcpy(titolo,L.titolo);
		pagine=L.pagine;
	}
	
	const Libro & Libro::operator =(const Libro & L){
		if(this != &L){
			Oggetto::operator =(L);
			delete [] titolo;
			titolo=new char [strlen(L.titolo)+1];
			strcpy(titolo,L.titolo);
			pagine=L.pagine;
		}
		return * this;
	}
	
	void Libro::set_titolo(const char * t){
		delete [] titolo;
		titolo=new char [strlen(t)+1];
		strcpy(titolo,t);
	}
	
	istream & Libro::leggi(istream & in){
		Oggetto::leggi(in);
		char buffer[40];
		
		delete [] titolo;
		in >> buffer;
		titolo=new char [strlen(buffer)+1];
		strcpy(titolo,buffer);
		in >> pagine;
		
		return in;
	}
}
