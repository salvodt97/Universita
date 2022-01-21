#include "Manoscritto.h"

namespace Mynamespace{
	Manoscritto::Manoscritto(int c, const char * a, int p, const char * f):codice(c), pagine(p){
		autore=new char [strlen(a)+1];
		strcpy(autore,a);
		formato=new char [strlen(f)+1];
		strcpy(formato,f);
	}
	
	Manoscritto::Manoscritto(const Manoscritto & M){
		autore=new char [strlen(M.autore)+1];
		strcpy(autore,M.autore);
		formato=new char [strlen(M.formato)+1];
		strcpy(formato,M.formato);
		codice=M.codice;
		pagine=M.pagine;
	}
	
	const Manoscritto & Manoscritto::operator =(const Manoscritto & M){
		if(this != &M){
			delete [] autore;
			autore=new char [strlen(M.autore)+1];
			strcpy(autore,M.autore);
			delete [] formato;
			formato=new char [strlen(M.formato)+1];
			strcpy(formato,M.formato);
			codice=M.codice;
			pagine=M.pagine;
		}
		return * this;
	}
	
	void Manoscritto::set_autore(const char * a){
		delete [] autore;
		autore=new char [strlen(a)+1];
		strcpy(autore,a);
	}
	
	void Manoscritto::set_formato(const char * f){
		delete [] formato;
		formato=new char [strlen(f)+1];
		strcpy(formato,f);
	}
	
	istream & Manoscritto::memorizza_dati(istream & in){
		char buffer1[20], buffer2[20];
		
		in >> codice;
		delete [] autore;
		in >> buffer1;
		autore=new char [strlen(buffer1)+1];
		strcpy(autore,buffer1);
		in >> pagine;
		delete [] formato;
		in >> buffer2;
		formato=new char [strlen(buffer2)+1];
		strcpy(formato,buffer2);
		
		return in;
	}
}
