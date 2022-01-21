#ifndef OGGETTO_H
#define OGGETTO_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::istream;
using std::ostream;

namespace Mynamespace{
class Oggetto{
	private:
	int codice;
	char * descrizione;
	char * forma;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return out <<codice <<' ' <<descrizione <<' ' <<forma;}
	
	public:
	Oggetto(int =0, const char * ="", const char * ="");
	Oggetto(const Oggetto &);
	const Oggetto & operator =(const Oggetto &);
	int get_codice() const {return codice;}
	const char * get_descrizione() const {return descrizione;}
	const char * get_forma() const {return forma;}
	void set_codice(int c){codice=c;}
	void set_descrizione(const char *);
	void set_forma(const char *);
	bool operator ==(const Oggetto & O) const {return (!strcmp(descrizione,O.descrizione) && !strcmp(forma,O.forma) && codice==O.codice);}
	virtual ~Oggetto(){delete [] descrizione; delete [] forma;}
	
	friend istream & operator >>(istream & in, Oggetto & O){return O.leggi(in);}
	friend ostream & operator <<(ostream & out, const Oggetto & O){return O.stampa(out);}
	
};
}

#endif
