#ifndef CLIENTE_H
#define CLIENTE_H

#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Eccezione.h"

using std::istream;
using std::ostream;

namespace Mynamespace{
class Cliente{
	private:
	char * codice;
	char * profilo;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return out <<codice <<' ' <<profilo;}
	
	public:
	Cliente(const char * ="", const char * ="");
	Cliente(const Cliente &);
	const Cliente & operator =(const Cliente &);
	bool operator ==(const Cliente & C) const {return (!strcmp(codice,C.codice) && !strcmp(profilo,C.profilo));}
	bool operator !=(const Cliente & C) const {return (strcmp(codice,C.codice)!=0 || strcmp(profilo,C.profilo)!=0);}
	virtual bool check() const throw (Eccezione);
	~Cliente(){delete [] codice; delete [] profilo;}
	
	friend istream & operator >>(istream & in, Cliente & C){return C.leggi(in);}
	friend ostream & operator <<(ostream & out, const Cliente & C){return C.stampa(out);}
};
}

#endif
