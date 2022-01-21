#include "Rilevamenti.h"

namespace Mynamespace{
	Rilevamento::Rilevamento(){
		Regione=new char [1];
		strcpy(Regione,"");
		Provincia=new char [1];
		strcpy(Provincia,"");
		Citta=new char [1];
		strcpy(Citta,"");
		Anno=0;
		Mese=0;
		Giorno=0;
		Tmax=0;
		Tmin=0;		
	}
	
	Rilevamento::Rilevamento(const char * R, const char * P, const char * C){
		Regione=new char [strlen(R)+1];
		strcpy(Regione,R);
		Provincia=new char [strlen(P)+1];
		strcpy(Provincia,P);
		Citta=new char [strlen(C)+1];
		strcpy(Citta,C);
	}
	
	Rilevamento::Rilevamento(const Rilevamento & R){
		Regione=new char [strlen(R.Regione)+1];
		strcpy(Regione,R.Regione);
		Provincia=new char [strlen(R.Provincia)+1];
		strcpy(Provincia,R.Provincia);
		Citta=new char [strlen(R.Citta)+1];
		strcpy(Citta,R.Citta);
		Anno=R.Anno;
		Mese=R.Mese;
		Giorno=R.Giorno;
		Tmax=R.Tmax;
		Tmin=R.Tmin;	
	}
	
	const Rilevamento & Rilevamento::operator =(const Rilevamento & R){
		if(this != &R){
		delete [] Regione;
		Regione=new char [strlen(R.Regione)+1];
		strcpy(Regione,R.Regione);
		delete [] Provincia;
		Provincia=new char [strlen(R.Provincia)+1];
		strcpy(Provincia,R.Provincia);
		delete [] Citta;
		Citta=new char [strlen(R.Citta)+1];
		strcpy(Citta,R.Citta);
		Anno=R.Anno;
		Mese=R.Mese;
		Giorno=R.Giorno;
		Tmax=R.Tmax;
		Tmin=R.Tmin;		
		}
		return * this;
	}
	
	void Rilevamento::set_Regione(const char * R){
		delete [] Regione;
		Regione=new char [strlen(R)+1];
		strcpy(Regione,R);
	}
	
	void Rilevamento::set_Provincia(const char * P){
		delete [] Provincia;
		Provincia=new char [strlen(P)+1];
		strcpy(Provincia,P);
	}
	
	void Rilevamento::set_Citta(const char * C){
		delete [] Citta;
		Citta=new char [strlen(C)+1];
		strcpy(Citta,C);
	}
	
	istream & operator >>(istream & in, Rilevamento & R){
		char buffer1[40], buffer2[40], buffer3[40];
		
		delete [] R.Regione;
		in >> buffer1;
		R.Regione=new char [strlen(buffer1)+1];
		strcpy(R.Regione,buffer1);
		
		delete [] R.Provincia;
		in >> buffer2;
		R.Provincia=new char [strlen(buffer2)+1];
		strcpy(R.Provincia,buffer2);
		
		delete [] R.Citta;
		in >> buffer3;
		R.Citta=new char [strlen(buffer3)+1];
		strcpy(R.Citta,buffer3);
		
		return in;
	}
}
