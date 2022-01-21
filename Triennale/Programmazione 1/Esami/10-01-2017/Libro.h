#ifndef LIBRO_H
#define LIBRO_H

#include "Oggetto.h"

namespace Mynamespace{
class Libro:public Oggetto{
	private:
	int numpagine;
	char * titolo;

	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return Oggetto::stampa(out) <<' ' <<numpagine <<' ' <<titolo;}
	
	public:
	Libro(int =0, const char * ="", const char * ="", int=0, const char * ="");
	Libro(const Libro &);
	const Libro & operator =(const Libro &);
	int get_numpagine() const {return numpagine;}
	const char * get_titolo() const {return titolo;}
	void set_numpagine(int c){numpagine=c;}
	void set_titolo(const char *);
	bool operator ==(const Libro & O) const {return (Oggetto::operator ==(O) && !strcmp(titolo,O.titolo) && numpagine==O.numpagine);}
	virtual ~Libro(){delete [] titolo;}
	
	friend istream & operator >>(istream & in, Libro & O){return O.leggi(in);}
	friend ostream & operator <<(ostream & out, const Libro & O){return O.stampa(out);}
	
};
}

#endif
