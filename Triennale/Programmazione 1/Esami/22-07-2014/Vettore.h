#ifndef VETTORE_H
#define VETTORE_H

#include "Rilevamenti.h"
namespace Mynamespace{
typedef Rilevamento T;

class Vettore{
	protected:
	int dim;
	T * vet;
	ostream & stampa(ostream &) const;
	
	public:
	Vettore(int = 0);
	Vettore(const Vettore &);
	const Vettore & operator=(const Vettore &);
	T & operator [] (const int i) {return vet[i];}
	const T & operator [] (const int i) const {return vet[i];}
	virtual ~Vettore(){delete [] vet;}
};
}

#endif
