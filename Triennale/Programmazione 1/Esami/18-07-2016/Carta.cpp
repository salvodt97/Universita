#include "Carta.h"

namespace Mynamespace{
	Carta::Carta(const char * T,const char * I,const char * N){
		Tipo=new char[strlen(T)+1];
		strcpy(Tipo,T);
		Intestatario=new char[strlen(I)+1];
		strcpy(Intestatario,I);
		Numero=new char[strlen(N)+1];
		strcpy(Numero,N);
	}
	
	Carta::Carta(const Carta & C){
		Tipo=new char[strlen(C.Tipo)+1];
		strcpy(Tipo,C.Tipo);
		Intestatario=new char[strlen(C.Intestatario)+1];
		strcpy(Intestatario,C.Intestatario);
		Numero=new char[strlen(C.Numero)+1];
		strcpy(Numero,C.Numero);
	}
	
	const Carta & Carta::operator=(const Carta & C){
		if(this != &C){
		delete [] Tipo;
		Tipo=new char[strlen(C.Tipo)+1];
		strcpy(Tipo,C.Tipo);
		delete [] Intestatario;
		Intestatario=new char[strlen(C.Intestatario)+1];
		strcpy(Intestatario,C.Intestatario);
		delete [] Numero;
		Numero=new char[strlen(C.Numero)+1];
		strcpy(Numero,C.Numero);
		}
		return * this;
	}
	
	void Carta::set_Tipo(const char * T){
		delete [] Tipo;
		Tipo=new char[strlen(T)+1];
		strcpy(Tipo,T);
	}
	
	void Carta::set_Intestatario(const char * I){
		delete [] Intestatario;
		Intestatario=new char[strlen(I)+1];
		strcpy(Intestatario,I);
	}
	
	void Carta::set_Numero(const char * N){
		delete [] Numero;
		Numero=new char[strlen(N)+1];
		strcpy(Numero,N);
		
	}
	
	bool Carta::check_Numero() const throw(const char *){
		bool ok=true;
		int i=0;
		
		while(i<5 && ok)
		if(!(Numero[i]>='0' && Numero[i]<='9')){
		throw("\nErrore nel numero della carta!");
		ok=false;
		}
		else i++;
		
		return(strlen(Numero)==8 && ok);
	}
}
