#include "Veicolo.h"

namespace Mynamespace{
	Veicolo::Veicolo(const char * T, const char * M){
		Tipo=new char[strlen(T)+1];
		strcpy(Tipo,T);
		Marca=new char[strlen(M)+1];
		strcpy(Marca,M);
	}
	
	Veicolo::Veicolo(const Veicolo & V){
		Tipo=new char[strlen(V.Tipo)+1];
		strcpy(Tipo,V.Tipo);
		Marca=new char[strlen(V.Marca)+1];
		strcpy(Marca,V.Marca);		
	}
	
	const Veicolo & Veicolo::operator =(const Veicolo & V){
		if(this != &V){
		delete [] Tipo;
		Tipo=new char[strlen(V.Tipo)+1];
		strcpy(Tipo,V.Tipo);
		delete [] Marca;
		Marca=new char[strlen(V.Marca)+1];
		strcpy(Marca,V.Marca);	
		}
		return * this;
	}
	
	istream & Veicolo::read(istream & in){
		char  buffer1[20], buffer2[20];
		
		delete [] Tipo;
		in >> buffer1;
		Tipo=new char[strlen(buffer1)+1];
		strcpy(Tipo,buffer1);
		
		delete [] Marca;
		in >> buffer2;
		Marca=new char[strlen(buffer2)+1];
		strcpy(Marca,buffer2);	
		
		return in;
	}
	
		const char * Veicolo::ToText() const{
		char * S=new char[strlen(Tipo)+strlen(Marca)+2];
		strcpy(S,Veicolo::Tipo);
		strcat(S," ");
		strcat(S,Marca);
		return S;
	}
	
}
