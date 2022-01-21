#include "Moto.h"

namespace Mynamespace{
	Moto::Moto(const char * T, const char * M, const char * A):Veicolo(T,M){
		Tipologia=new char[strlen(A)+1];
		strcpy(Tipologia,A);
	}
	
	Moto::Moto(const Moto & A):Veicolo(A){
		Tipologia=new char[strlen(A.Tipologia)+1];
		strcpy(Tipologia,A.Tipologia);
	}
	
	const Moto & Moto::operator =(const Moto & A){
		if(this != &A){
			Veicolo::operator =(A);
			delete [] Tipologia;
			Tipologia=new char[strlen(A.Tipologia)+1];
			strcpy(Tipologia,A.Tipologia);
		}
		return * this;
	}
	
	istream & Moto::read(istream & in){
		Veicolo::read(in);
		char buffer[20];
		
		in >> buffer;
		delete [] Tipologia;
		Tipologia=new char[strlen(buffer)+1];
		strcpy(Tipologia,buffer);
		
		return in;
	}
	
	const char * Moto::ToText() const{
		char * S=new char[strlen(Veicolo::get_Tipo())+strlen(Veicolo::get_Marca())+strlen(Tipologia)+3];
		strcpy(S,Veicolo::get_Tipo());
		strcat(S," ");
		strcat(S,Veicolo::get_Marca());
		strcat(S," ");
		strcat(S,Tipologia);
		return S;
	}
}
