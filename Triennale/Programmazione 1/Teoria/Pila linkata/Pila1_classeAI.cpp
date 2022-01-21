#include "Pila1_classeAI.h"
namespace Mynamespace {
	
	
Pila::Pila() { P=0;}

bool Pila::push(const T & e){
	if(isFull()) return false;
	Nodo * q;
	q=new Nodo;
	q->elem=e;
	q->next=P;
	P=q;
	return true;
}

bool Pila::pop(T & e){
	if(isEmpty()) return false;
	Nodo * q;
	q=P;
	e=P->elem;
	P=P->next;
	delete q;
	return true;
}
bool Pila::top(T & e) const {
	if(isEmpty()) return false;
	e=P->elem;
	return true;
}
bool Pila::isEmpty() const {
	return P==0;
}
bool Pila::isFull() const {
	return false;
}


void Pila::clear() {
	Nodo * temp=P;
	while(P){
		P=P->next;
		delete temp;
		temp=P;
	}
}



} //namespace
