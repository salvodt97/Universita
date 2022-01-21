#ifndef _PILA_H
#define _PILA_H

#include <iostream>
#include "Persona.h"
using std::ostream;
using std::endl;

namespace Mynamespace {

struct Nodo;

typedef Persona T;


//typedef Nodo * Pila;

class Pila {

private:
		
class Nodo {               //oppure struct Nodo 
	friend class Pila;
	T elem;
	Nodo * next;
};
  Nodo * P;
  void clear();
  
public:
	
Pila();
bool push(const T &);
bool pop(T &);
bool top(T &) const;
bool isEmpty() const;
bool isFull() const;
~Pila() {clear();}

};


}//namespace

#endif





