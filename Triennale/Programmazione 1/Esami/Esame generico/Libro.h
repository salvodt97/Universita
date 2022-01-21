#ifndef LIBRO_H
#define LIBRO_H
#include "Oggetto.h"

namespace Mynamespace{
class Libro:public Oggetto{
	private:
	char * titolo;
	int pagine;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return Oggetto::stampa(out) <<' ' <<titolo <<' ' <<pagine;}
	
	public:
	Libro(int =0, const char * ="", int =0, int =0, int =0, const char * ="", int =0);
	Libro(const Libro &);
	const Libro & operator =(const Libro &);
	const char * get_titolo() const {return titolo;}
	int get_pagine() const {return pagine;}
	void set_titolo(const char *);
	void set_pagine(const int p){pagine=p;}
	bool operator ==(const Libro & L) const {return (Oggetto::operator ==(L) && !strcmp(titolo,L.titolo) && pagine==L.pagine);}
	bool operator >(const Libro & L) const {return (Oggetto::operator >(L) && pagine>L.pagine);}
	bool operator <(const Libro & L) const {return (Oggetto::operator <(L) && pagine<L.pagine);}
	virtual ~Libro(){delete [] titolo;}
	
	friend istream & operator >>(istream & in, Libro & L){return L.leggi(in);}
	friend ostream & operator <<(ostream & out, const Libro & L){return L.stampa(out);}
};
}
#endif
