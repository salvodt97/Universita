#include "Libro.h"

namespace Mynamespace{
	Libro::Libro(int c, const char * d, const char * f, int n, const char * t):Oggetto(c,d,f){
		numpagine=n;
		titolo=new char[strlen(t)+1];
		strcpy(titolo,t);
	}
	
	Libro::Libro(const Libro & O):Oggetto(O){
		numpagine=O.numpagine;
		titolo=new char[strlen(O.titolo)+1];
		strcpy(titolo,O.titolo);
	}
	
	const Libro & Libro::operator =(const Libro & O){
		if(this != &O){
		Oggetto::operator =(O);
		numpagine=O.numpagine;
		delete [] titolo;
		titolo=new char[strlen(O.titolo)+1];
		strcpy(titolo,O.titolo);
		}
		return * this;
	}
	
	void Libro::set_titolo(const char * d){
		delete [] titolo;
		titolo=new char[strlen(d)+1];
		strcpy(titolo,d);
	}
	
	
	istream & Libro::leggi(istream & in){
		Oggetto::leggi(in);
		char buffer[40];
		
		in >> numpagine;
		
		delete [] titolo;
		in >> buffer;
		titolo=new char[strlen(buffer)+1];
		strcpy(titolo,buffer);
		
		return in;
	}
}
