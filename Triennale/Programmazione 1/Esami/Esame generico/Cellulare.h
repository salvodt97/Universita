#ifndef CELLULARE_H
#define CELLULARE_H
#include "Oggetto.h"

namespace Mynamespace{
class Cellulare:public Oggetto{
	private:
	char * modello;
	float costo;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return Oggetto::stampa(out) <<' ' <<modello <<' ' <<costo;}
	
	public:
	Cellulare(int =0, const char * ="", int =0, int =0, int =0, const char * ="", float =0.0);
	Cellulare(const Cellulare &);
	const Cellulare & operator =(const Cellulare &);
	const char * get_modello() const {return modello;}
	float get_costo() const {return costo;}
	void set_modello(const char *);
	void set_costo(const float p){costo=p;}
	bool operator ==(const Cellulare & L) const {return (Oggetto::operator ==(L) && !strcmp(modello,L.modello) && costo==L.costo);}
	bool operator >(const Cellulare & L) const {return (Oggetto::operator >(L) && costo>L.costo);}
	bool operator <(const Cellulare & L) const {return (Oggetto::operator <(L) && costo<L.costo);}
	virtual ~Cellulare(){delete [] modello;}
	
	friend istream & operator >>(istream & in, Cellulare & L){return L.leggi(in);}
	friend ostream & operator <<(ostream & out, const Cellulare & L){return L.stampa(out);}
};
}

#endif
