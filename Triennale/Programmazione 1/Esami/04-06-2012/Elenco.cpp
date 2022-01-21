#include "Elenco.h"

namespace Mynamespace{
	Elenco::Elenco(const Elenco & E){
		dim=E.dim;
		vet= new T [dim];
		for(int i=0; i<dim; i++)
		vet[i]=E.vet[i];
	}
	
	const Elenco & Elenco::operator =(const Elenco & E){
		if(this != &E){
			dim=E.dim;
			delete [] vet;
			vet= new T [dim];
			for(int i=0; i<dim; i++)
			vet[i]=E.vet[i];
		}
		return * this;
	}
	
	bool Elenco::inlist(const T & e) const{
		bool trovato=false;
		int i=0;
		while(i<dim && !trovato)
		if(vet[i]==e) trovato=true;
		else i++;
		
		return trovato;
	}
	
	ostream & operator <<(ostream & out, const Elenco & E){
		for(int i=0;i<E.dim;i++)
		out << E[i] <<"\n";
		return out;
	} 
	
	int Elenco::cerca_pos_eli(const T & e)const{
		if(inlist(e)){
		int i=0;
		while(i<dim)
		if(vet[i]==e) return i;
		else i++;
		}
	}
	
	int Elenco::cerca_pos_ins(const T & e)const{
		//if(dim==0) return 0;
		int i=0;
		while(i<dim)
		if(vet[i]>e) return i;
		else i++;
		
	}
	
	bool Elenco::inserisci(const T & e) throw (Duplicato){
		if(inlist(e)) throw Duplicato("Manoscritto gia' presente nell'elenco: ", e.get_codice());
		if(dim==0) {vet[dim]=e; dim++; return true;}
		else {
			for(int i=dim;i>cerca_pos_ins(e);i--)
			vet[i]=vet[i-1];
			vet[cerca_pos_ins(e)]=e;
			dim++;
			return true;}
	}
	
	bool Elenco::elimina(T & e){
		if (!inlist(e)) return false;
		
		for(int i=cerca_pos_eli(e);i<dim;i++)
		vet[i]=vet[i+1];
		dim--;
		
	}
}
