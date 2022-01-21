#ifndef INSIEME_H
#define INSIEME_H

#define MAX 20

#include "Eccezione.h"

namespace Mynamespace{
class Insieme{
	private:
	int riemp;
	T vet[MAX];
	
	public:
	explicit Insieme(int r =0){riemp=r;}
	T & operator[](const int i) {return vet[i];}
	const T & operator[](const int i) const {return vet[i];}
	bool in(const T &) const;
	void Inserisci(const T &) throw(Eccezione);
	void Elimina(const T &) throw(Eccezione);
	const Insieme operator +(const Insieme &) const;
	//const Insieme operator -(const Insieme &)
	
	istream & leggi(istream &);
	friend istream & operator >>(istream & in, Insieme & I){return I.leggi(in);}
	friend ostream & operator <<(ostream & out, const Insieme & I){return I.stampa(out);} 
	ostream & stampa(ostream &) const;
};
}

#endif
