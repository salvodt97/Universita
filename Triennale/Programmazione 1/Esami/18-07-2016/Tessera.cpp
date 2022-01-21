#include "Tessera.h"

namespace Mynamespace{
	Tessera::Tessera(const char * T,const char * I,const char * N,const char * cf,const Data & D1, const Data & D):Carta(T,I,N), DataRilascio(D1), DataScadenza(D){
		CF=new char[strlen(cf)+1];
		strcpy(CF,cf);
	}
	
	Tessera::Tessera(const Tessera & T):Carta(T){
		CF=new char[strlen(T.CF)+1];
		strcpy(CF,T.CF);
		DataRilascio=T.DataRilascio;
		DataScadenza=T.DataScadenza;
	}
	void Tessera::set_CF(const char * cf){
		delete [] CF;
		CF=new char[strlen(cf)+1];
		strcpy(CF,cf);
		
	}
	
	const Tessera & Tessera::operator=(const Tessera & T){
		if(this != &T){
		Carta::operator=(T);
		delete [] CF;
		CF=new char[strlen(T.CF)+1];
		strcpy(CF,T.CF);
		DataRilascio=T.DataRilascio;
		DataScadenza=T.DataScadenza;
		}
		return * this;
	}
	
}
