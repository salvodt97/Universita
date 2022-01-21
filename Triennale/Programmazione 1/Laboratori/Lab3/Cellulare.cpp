#include "Cellulare.h"

namespace Mynamespace{
	Cellulare::Cellulare():Oggetto(){
		Costo=0.0;
		Modello=new char[1];
		strcpy(Modello,"");
	}
	
	Cellulare::Cellulare(int C, const char * D,float costo, const char * M):Oggetto(C,D){
		Costo=costo;
		Modello=new char[strlen(M)+1];
		strcpy(Modello,M);
	}
	
	Cellulare::Cellulare(const Cellulare & C):Oggetto(C){
		Costo=C.Costo;
		Modello=new char[strlen(C.Modello)+1];
		strcpy(Modello,C.Modello);
	}
	
	void Cellulare::set_Modello(const char * M){
		delete [] Modello;
		Modello=new char[strlen(M)+1];
		strcpy(Modello,M);
	}
	
	const Cellulare & Cellulare::operator=(const Cellulare & C){
		if(this != &C){
		Oggetto::operator =(C);
		Costo=C.Costo;
		delete [] Modello;
		Modello=new char[strlen(C.Modello)+1];
		strcpy(Modello,C.Modello);
		}
		return * this;
	}
	
	istream & Cellulare::read(istream & in){
		Oggetto::read(in);
		char modello[20];
		
		in >> Costo;
		
		delete [] Modello;
		in >> modello;
		Modello=new char[strlen(modello)+1];
		strcpy(Modello,modello);
		
		return in;
	}
}
