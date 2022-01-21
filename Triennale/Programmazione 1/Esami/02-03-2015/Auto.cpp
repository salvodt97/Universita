#include "Auto.h"

namespace Mynamespace{
	Auto::Auto(const char * T, const char * M, const char * A):Veicolo(T,M){
		Alimentazione=new char[strlen(A)+1];
		strcpy(Alimentazione,A);
	}
	
	Auto::Auto(const Auto & A):Veicolo(A){
		Alimentazione=new char[strlen(A.Alimentazione)+1];
		strcpy(Alimentazione,A.Alimentazione);
	}
	
	const Auto & Auto::operator =(const Auto & A){
		if(this != &A){
			Veicolo::operator =(A);
			delete [] Alimentazione;
			Alimentazione=new char[strlen(A.Alimentazione)+1];
			strcpy(Alimentazione,A.Alimentazione);
		}
		return * this;
	}
	
	istream & Auto::read(istream & in){
		Veicolo::read(in);
		char buffer[20];
		
		in >> buffer;
		delete [] Alimentazione;
		Alimentazione=new char[strlen(buffer)+1];
		strcpy(Alimentazione,buffer);
		
		return in;
	}
	
	const char * Auto::ToText() const{
		char * S=new char[strlen(Veicolo::get_Tipo())+strlen(Veicolo::get_Marca())+strlen(Alimentazione)+3];
		strcpy(S,Veicolo::get_Tipo());
		strcat(S," ");
		strcat(S,Veicolo::get_Marca());
		strcat(S," ");
		strcat(S,Alimentazione);
		return S;
	}
}
