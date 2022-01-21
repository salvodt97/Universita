#include "Cellulare.h"

namespace Mynamespace{
	Cellulare::Cellulare(int c, const char * d, int g, int m, int a, const char * t, float p):Oggetto(c,d,g,m,a){
		modello=new char [strlen(t)+1];
		strcpy(modello,t);
		costo=p;
	}
	
	Cellulare::Cellulare(const Cellulare & L):Oggetto(L){
		modello=new char [strlen(L.modello)+1];
		strcpy(modello,L.modello);
		costo=L.costo;
	}
	
	const Cellulare & Cellulare::operator =(const Cellulare & L){
		if(this != &L){
			Oggetto::operator =(L);
			delete [] modello;
			modello=new char [strlen(L.modello)+1];
			strcpy(modello,L.modello);
			costo=L.costo;
		}
		return * this;
	}
	
	void Cellulare::set_modello(const char * t){
		delete [] modello;
		modello=new char [strlen(t)+1];
		strcpy(modello,t);
	}
	
	istream & Cellulare::leggi(istream & in){
		Oggetto::leggi(in);
		char buffer[40];
		
		delete [] modello;
		in >> buffer;
		modello=new char [strlen(buffer)+1];
		strcpy(modello,buffer);
		in >> costo;
		
		return in;
	}
}
