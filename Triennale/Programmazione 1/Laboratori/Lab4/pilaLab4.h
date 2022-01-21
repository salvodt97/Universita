#ifndef PILALAB4_H
#define PILALAB_H

#include "Sauna.h"
using namespace Mynamespace;

namespace Contenitore{
typedef Sauna T;
struct Nodo;

class Pila{
	private:
	class Nodo{
		friend class Pila;
		T elem;
		Nodo * next;
	};
	Nodo * P;
	void clear();
	
	public:
	Pila(){P=0;}
	bool isempty() const {return P==0;}
	bool isfull() const {return false;}
	bool push(const T &);
	bool pop(T &);
	bool top(T &);
	~Pila(){clear();}	
	};
}
#endif
