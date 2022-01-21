#include "Oggetto.h"

namespace Mynamespace{
	Oggetto::Oggetto(int c, const char * d, const char * f){
		codice=c;
		descrizione=new char[strlen(d)+1];
		strcpy(descrizione,d);
		forma=new char [strlen(f)+1];
		strcpy(forma,f);
	}
	
	Oggetto::Oggetto(const Oggetto & O){
		codice=O.codice;
		descrizione=new char[strlen(O.descrizione)+1];
		strcpy(descrizione,O.descrizione);
		forma=new char [strlen(O.forma)+1];
		strcpy(forma,O.forma);
	}
	
	const Oggetto & Oggetto::operator =(const Oggetto & O){
		if(this != &O){
		codice=O.codice;
		delete [] descrizione;
		descrizione=new char[strlen(O.descrizione)+1];
		strcpy(descrizione,O.descrizione);
		delete [] forma;
		forma=new char [strlen(O.forma)+1];
		strcpy(forma,O.forma);
		}
		return * this;
	}
	
	void Oggetto::set_descrizione(const char * d){
		delete [] descrizione;
		descrizione=new char[strlen(d)+1];
		strcpy(descrizione,d);
	}
	
	void Oggetto::set_forma(const char * f){
		delete [] forma;
		forma=new char [strlen(f)+1];
		strcpy(forma,f);
	}
	
	istream & Oggetto::leggi(istream & in){
		char buffer1[40], buffer2[40];
		
		in >> codice;
		
		delete [] descrizione;
		in >> buffer1;
		descrizione=new char[strlen(buffer1)+1];
		strcpy(descrizione,buffer1);
		
		delete [] forma;
		in >> buffer2;
		forma=new char [strlen(buffer2)+1];
		strcpy(forma,buffer2);
		
		return in;
	}
}
