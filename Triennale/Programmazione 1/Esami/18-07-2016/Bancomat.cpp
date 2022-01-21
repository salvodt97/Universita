#include "Bancomat.h"

namespace Mynamespace{
	Bancomat::Bancomat(const char * T,const char * I,const char * N,const char * P,bool a, const Data & D):Carta(T,I,N), DataScadenza(D){
		PIN=new char[strlen(P)+1];
		strcpy(PIN,P);
		attiva=a;
	}
	
	Bancomat::Bancomat(const Bancomat & B):Carta(B){
		PIN=new char[strlen(B.PIN)+1];
		strcpy(PIN,B.PIN);
		attiva=B.attiva;
		DataScadenza=B.DataScadenza;
	}
	void Bancomat::set_PIN(const char * P){
		delete [] PIN;
		PIN=new char[strlen(P)+1];
		strcpy(PIN,P);
		
	}
	
	const Bancomat & Bancomat::operator=(const Bancomat & B){
		if(this != &B){
		Carta::operator=(B);
		delete [] PIN;
		PIN=new char[strlen(B.PIN)+1];
		strcpy(PIN,B.PIN);
		attiva=B.attiva;
		DataScadenza=B.DataScadenza;
		}
		return * this;
	}
	
	bool Bancomat::Attiva(){
		if(Carta::check_Numero()){
		attiva=true;
		delete [] PIN;
		PIN=new char[11];
		for(int i=0;i<5;i++)
		PIN[i]=Carta::get_Numero()[i];
		for(int i=5;i<11;i++)
		PIN[i]=rand() % 9;
		return true;
		}
		else{
		attiva=false;
		return false;
		}
	}
}


