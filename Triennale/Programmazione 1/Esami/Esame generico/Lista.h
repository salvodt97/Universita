#ifndef LISTA_H
#define LISTA_H
#include "Oggetto.h"

namespace Mynamespace{
typedef Oggetto T;
struct Nodo;

class Lista{
	private:
	struct Nodo{
		T elem;
		Nodo * next;
	};
	Nodo * testa;
	bool push(const T &);
	bool pop(T &);
	
	public:
	Lista(){testa=0;}
	bool inlist(const T &) const;
	bool isempty() const {return testa==0;}
	bool isfull() const {return false;}
	bool insert(const T &);
	bool remove(T &);
	~Lista();
	
	friend ostream & operator <<(ostream &, const Lista &);
};
}

#endif
