#include "Lista.h"

namespace Mynamespace{
	bool Lista::inlist(const T & e) const{
		bool trovato=false;
		Nodo * temp=testa;
		while(temp && !trovato)
		if(temp->elem==e) trovato=true;
		else temp=temp->next;
		return trovato;
	}
	
	Lista::~Lista(){
		Nodo * temp;
		while(testa){
			temp=testa;
			delete temp;
			testa=testa->next;
		}
	}
	
	bool Lista::push(const T & e){
		if(inlist(e) || isfull()) return false;
		Nodo * temp=new Nodo;
		temp->elem=e;
		temp->next=testa;
		testa=temp;
		return true;
	}
	
	bool Lista::pop(T & e){
		if(!inlist(e) || isempty()) return false;
		Nodo * temp=testa;
		e=temp->elem;
		testa=testa->next;
		delete temp;
		return true;
	}
	
	bool Lista::insert(const T & e){
		if(inlist(e) || isfull()) return false;
		if(testa==0 || testa->elem>e) {push(e); return true;}
		Nodo * prec=testa;
		Nodo * succ;
		Nodo * temp=new Nodo;
		temp->elem=e;
		temp->next=0;
		while(prec->next && prec->next->elem<e) prec=prec->next;
		succ=prec->next;
		temp->next=succ;
		prec->next=temp;
		return true;
	}
	
	bool Lista::remove(T & e){
		if(!inlist(e) || isempty()) return false;
		if(testa->elem==e) {T c; pop(c); return true;}
		Nodo * temp=testa;
		while(temp->next->elem!=e) temp=temp->next;
		Nodo * q=temp->next;
		temp->next=temp->next->next;
		delete q;
		return true;
	}
	
	ostream & operator <<(ostream & out, const Lista & L){
		Lista::Nodo * temp=L.testa;
		while(temp){
			out << temp->elem <<' ';
			temp=temp->next;
		}
		return out;
	}
}
