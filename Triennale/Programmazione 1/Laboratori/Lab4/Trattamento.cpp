#include "Trattamento.h"

namespace Mynamespace{
	Trattamento::Trattamento(const char * C, const char * D){
		Codice=new char[strlen(C)+1];
		strcpy(Codice,C);
		Descrizione=new char[strlen(D)+1];
		strcpy(Descrizione,D);
	}
	
	Trattamento::Trattamento(const Trattamento & T){
		Codice=new char[strlen(T.Codice)+1];
		strcpy(Codice,T.Codice);
		Descrizione=new char[strlen(T.Descrizione)+1];
		strcpy(Descrizione,T.Descrizione);
	}
	const Trattamento & Trattamento::operator =(const Trattamento & T){
		delete [] Codice;	
		Codice=new char[strlen(T.Codice)+1];
		strcpy(Codice,T.Codice);
		delete [] Descrizione;
		Descrizione=new char[strlen(T.Descrizione)+1];
		strcpy(Descrizione,T.Descrizione);
		
		return * this;
	} 
	
	void Trattamento::set_Codice(const char * & C){
		delete [] Codice;	
		Codice=new char[strlen(C)+1];
		strcpy(Codice,C);
	}
	void Trattamento::set_Descrizione(const char * & D){
		delete [] Descrizione;
		Descrizione=new char[strlen(D)+1];
		strcpy(Descrizione,D);
	}
	
	istream & Trattamento::read(istream & in){
		char buffer1[100], buffer2[100];
		
		delete [] Codice;
		in >> buffer1;	
		Codice=new char[strlen(buffer1)+1];
		strcpy(Codice,buffer1);
		
		delete [] Descrizione;
		in >> buffer2;
		Descrizione=new char[strlen(buffer2)+1];
		strcpy(Descrizione,buffer2);
		
		return in;
		
	}
}
