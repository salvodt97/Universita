#include "Libro.h"

namespace Mynamespace{
	Libro::Libro():Oggetto(){
		NumPagine=0;
		Titolo=new char[1];
		strcpy(Titolo,"");
	}
	
	Libro::Libro(int C, const char * D,int N, const char * T):Oggetto(C,D){
		NumPagine=N;
		Titolo=new char[strlen(T)+1];
		strcpy(Titolo,T);
	}
	
	Libro::Libro(const Libro & L):Oggetto(L){
		NumPagine=L.NumPagine;
		Titolo=new char[strlen(L.Titolo)+1];
		strcpy(Titolo,L.Titolo);
	}
	
	void Libro::set_Titolo(const char * T){
		delete [] Titolo;
		Titolo=new char[strlen(T)+1];
		strcpy(Titolo,T);
	}
	
	const Libro & Libro::operator=(const Libro & L){
		if(this != &L){
		Oggetto::operator =(L);
		NumPagine=L.NumPagine;
		delete [] Titolo;
		Titolo=new char[strlen(L.Titolo)+1];
		strcpy(Titolo,L.Titolo);
		}
		return * this;
	}
	
	istream & Libro::read(istream & in){
		Oggetto::read(in);
		char titolo[20];
		
		in >> NumPagine;
		
		delete [] Titolo;
		in >> titolo;
		Titolo=new char[strlen(Titolo)+1];
		strcpy(Titolo,titolo);
		
		return in;
	}
}
