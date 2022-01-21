#include "Pacco.h"

namespace Mynamespace{
	Pacco::Pacco(const char * f, float p):peso(p){
		forma=new char[strlen(f)+1];
		strcpy(forma,f);
	}
	
	Pacco::Pacco(const Pacco & P){
		forma=new char[strlen(P.forma)+1];
		strcpy(forma,P.forma);
		peso=P.peso;
	}
	
	const Pacco & Pacco::operator =(const Pacco & P){
		if(this != &P){
			delete [] forma;
			forma=new char[strlen(P.forma)+1];
			strcpy(forma,P.forma);
			peso=P.peso;
		}
		return * this;
	}
	
	void Pacco::set_forma(const char * f){
		delete [] forma;
		forma=new char[strlen(f)+1];
		strcpy(forma,f);
	}
	
	istream & Pacco::leggi(istream & in){
		char buffer[40];
		
		delete [] forma;
		in >> buffer;
		forma=new char[strlen(buffer)+1];
		strcpy(forma,buffer);
		
		in >> peso;
		
		return in;
	}
}
