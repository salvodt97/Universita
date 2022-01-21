#include "Insieme.h"

namespace Mynamespace{
	bool Insieme::in(const T & O) const {
		bool trovato=false;
		int i=0;
		while(i<riemp && !trovato)
		if(vet[i]==O)
		trovato=true;
		else i++;
		return trovato;
	}
	
	void Insieme::Inserisci(const T & O)throw(Eccezione){
		if(!in(O)){
			vet[riemp]=O;
			riemp++;
		}
		else throw Eccezione("Elemento gia' presente: ", O.get_codice(), O.get_descrizione(), O.get_forma());
	}
	
	void Insieme::Elimina(const T & O) throw(Eccezione) {
		if(in(O)){
			bool trovato=false;
			int i=0;
			while(i<riemp && !trovato)
			if(vet[i]==O){
				vet[i]=vet[i+1];
				trovato=true;
				riemp--;
			}else i++;
		} else throw Eccezione("Elemento assente: ", O.get_codice(), O.get_descrizione(), O.get_forma());
	}
	
	istream & Insieme::leggi(istream & in){
		in >> riemp;
		for(int i=0; i<riemp; i++)
		in >> vet[i];
		
		return in;	
	}
	
	ostream & Insieme::stampa(ostream & out) const {
		for(int i=0; i<riemp; i++)
		out << vet[i] <<' ';
		
		return out;
	}
	
	const Insieme Insieme::operator +(const Insieme & I) const{
		Insieme I1;
		for(int i=0; i<riemp; i++)
		I1[i]=vet[i];
		for(int i=riemp; i<I.riemp; i++)
		I1[i]=I[i-riemp];
		
		return I1;
	}
	
	/*	const Insieme Insieme::operator -(const Insieme & I) const{
		Insieme I1;
	}*/
}
