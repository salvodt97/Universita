#include "Cellulare.h"

namespace Mynamespace{
	Cellulare::Cellulare(int c, const char * d, const char * f, float n, const char * t):Oggetto(c,d,f){
		costo=n;
		modello=new char[strlen(t)+1];
		strcpy(modello,t);
	}
	
	Cellulare::Cellulare(const Cellulare & O):Oggetto(O){
		costo=O.costo;
		modello=new char[strlen(O.modello)+1];
		strcpy(modello,O.modello);
	}
	
	const Cellulare & Cellulare::operator =(const Cellulare & O){
		if(this != &O){
		Oggetto::operator =(O);
		costo=O.costo;
		delete [] modello;
		modello=new char[strlen(O.modello)+1];
		strcpy(modello,O.modello);
		}
		return * this;
	}
	
	void Cellulare::set_modello(const char * d){
		delete [] modello;
		modello=new char[strlen(d)+1];
		strcpy(modello,d);
	}
	
	
	istream & Cellulare::leggi(istream & in){
		Oggetto::leggi(in);
		char buffer[40];
		
		in >> costo;
		
		delete [] modello;
		in >> buffer;
		modello=new char[strlen(buffer)+1];
		strcpy(modello,buffer);
		
		return in;
	}
}
