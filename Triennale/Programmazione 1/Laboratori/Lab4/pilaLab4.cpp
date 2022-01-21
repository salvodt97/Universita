#include "pilaLab4.h"

namespace Contenitore{
	bool Pila::push(const T & e){
		if(isfull()) return false;
		Nodo * q=new Nodo;
		q->elem=e;
		q->next=P;
		q=P;
		return true;
	}
	
	bool Pila::pop(T & e){
		if(isempty()) return false;
		Nodo * q=P;
		e=P->elem;
		P=P->next;
		delete q;
		return true;
	}
	
	bool Pila::top(T & e){
		if(isempty()) return false;
		e=P->elem;
		return true;
	}
	
	void Pila::clear(){
		Nodo*q=P;
		while(P){
			P=P->next;
			delete q;
			P=q;
		}
	}
}
