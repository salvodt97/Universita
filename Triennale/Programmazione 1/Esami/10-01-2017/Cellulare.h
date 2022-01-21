#ifndef CELLULARE_H
#define CELLULARE_H

#include "Oggetto.h"

namespace Mynamespace{
class Cellulare:public Oggetto{
	private:
	float costo;
	char * modello;

	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return Oggetto::stampa(out) <<' ' <<costo <<' ' <<modello;}
	
	public:
	Cellulare(int =0, const char * ="", const char * ="", float =0.0, const char * ="");
	Cellulare(const Cellulare &);
	const Cellulare & operator =(const Cellulare &);
	float get_costo() const {return costo;}
	const char * get_modello() const {return modello;}
	void set_costo(int c){costo=c;}
	void set_modello(const char *);
	bool operator ==(const Cellulare & O) const {return (Oggetto::operator ==(O) && !strcmp(modello,O.modello) && costo==O.costo);}
	virtual ~Cellulare(){delete [] modello;}
	
	friend istream & operator >>(istream & in, Cellulare & O){return O.leggi(in);}
	friend ostream & operator <<(ostream & out, const Cellulare & O){return O.stampa(out);}
	
};
}

#endif
