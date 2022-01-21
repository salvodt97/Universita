#ifndef ELENCO_H
#define ELENCO_H
#include "Lettera.h"
#include "Duplicato.h"

namespace Mynamespace{
typedef Manoscritto T;

class Elenco{
	private:
	int dim;
	T * vet;
	int cerca_pos_eli(const T &)const;
	int cerca_pos_ins(const T &)const;
	
	public:
	explicit Elenco(int n=0):dim(n){vet=new T [dim];}
	Elenco(const Elenco &);
	const Elenco & operator =(const Elenco &);
	T & operator [](const int i){return vet[i];}
	const T & operator [](const int i) const {return vet[i];}
	bool inlist(const T &) const;
	bool elimina(T &);
	bool inserisci(const T &) throw (Duplicato);
	~Elenco(){delete [] vet;}
	
	friend ostream & operator <<(ostream &, const Elenco &);
};
}

#endif
