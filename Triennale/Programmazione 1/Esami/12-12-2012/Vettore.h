#ifndef VETTORE_H
#define VETTORE_H

#include "Pacchetto.h"
#include "Eccezione.h"

namespace Mynamespace{
typedef Pacchetto T;
class Vettore{
	private:
	int nelem;
	T * vet;
	
	public:
	explicit Vettore(int =0);
	Vettore(const Vettore &);
	const Vettore & operator =(const Vettore &);
	int get_nelem() const {return nelem;}
	T & operator [](int i){return vet[i];}
	const T & operator [](int i) const {return vet[i];}
	void Elimina();
	T & Access(int i) throw(Eccezione){if(i<0 || i>=nelem) throw Eccezione("Posizione inesistente: ", i); else return vet[i];}
	const T & Access(int i) const throw(Eccezione){if(i<0 || i>=nelem) throw Eccezione("Posizione inesistente: ", i); else return vet[i];}
	~Vettore(){delete [] vet;}
	
	friend istream & operator >>(istream &, Vettore &);
	friend ostream & operator <<(ostream &, const Vettore &);
};
}

#endif
