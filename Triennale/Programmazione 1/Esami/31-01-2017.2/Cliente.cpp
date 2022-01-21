#include "Cliente.h"

namespace Mynamespace{
	Cliente::Cliente(const char * c, const char * p){
		codice=new char [strlen(c)+1];
		strcpy(codice,c);
		profilo=new char [strlen(p)+1];
		strcpy(profilo,p);
	}
	
	Cliente::Cliente(const Cliente & C){
		codice=new char [strlen(C.codice)+1];
		strcpy(codice,C.codice);
		profilo=new char [strlen(C.profilo)+1];
		strcpy(profilo,C.profilo);
	}
	
	const Cliente & Cliente::operator =(const Cliente & C){
		if(this != &C){
			delete [] codice;
			codice=new char [strlen(C.codice)+1];
			strcpy(codice,C.codice);
			delete [] profilo;
			profilo=new char [strlen(C.profilo)+1];
			strcpy(profilo,C.profilo);
		}
		return * this;
	}
	
	istream & Cliente::leggi(istream & in){
		char buffer1[50], buffer2[50];
		
		delete [] codice;
		in >> buffer1;
		codice=new char [strlen(buffer1)+1];
		strcpy(codice,buffer1);
		delete [] profilo;
		in >> buffer2;
		profilo=new char [strlen(buffer2)+1];
		strcpy(profilo,buffer2);
		
		return in;
	}
	
	bool Cliente::check() const throw (Eccezione){
		if(strlen(codice)<7) throw Eccezione("Numero di caratteri insufficiente nel codice: ", codice);
		bool ok=true;
		int i=0;
		while(i<strlen(codice) && ok)
		if(!(codice[i]>='A' && codice[i]<='Z') && !(codice[i]>='a' && codice[i]<='z') && !(codice[i]>='0' && codice[i]<='9'))
		ok=false;
		else i++;
		
		if(ok==false) throw Eccezione("Carattere errato nel codice: ", codice);
		else return true;
	}
}
