#ifndef OGGETTO_H
#define OGGETTO_H
#include "Data.h"
#include "Eccezione.h"

namespace Mynamespace{
class Oggetto{
	private:
	int codice;
	char * descrizione;
	Data creazione;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return out <<codice <<' ' <<descrizione <<' ' <<creazione;}
	
	public:
	Oggetto(int =0, const char * ="", int =0, int =0, int =0);
	Oggetto(const Oggetto &);
	const Oggetto & operator =(const Oggetto &);
	int get_codice() const {return codice;}
	const char * get_descrizione() const {return descrizione;}
	Data get_creazione() const {return creazione;}
	void set_codice(const int c){codice=c;}
	void set_descrizione(const char *);
	void set_creazione(const Data & d){creazione=d;}
	bool operator ==(const Oggetto & O) const {return (codice==O.codice && !strcmp(descrizione,O.descrizione) && creazione==O.creazione);}
	bool operator !=(const Oggetto & O) const {return (codice!=O.codice || strcmp(descrizione,O.descrizione)!=0 || creazione!=O.creazione);}
	bool operator >(const Oggetto & O) const {return codice>O.codice;}
	bool operator <(const Oggetto & O) const {return codice<O.codice;}
	bool check() const throw(Eccezione);
	virtual ~Oggetto(){delete [] descrizione;}
	
	friend istream & operator >>(istream & in, Oggetto & O){return O.leggi(in);}
	friend ostream & operator <<(ostream & out, const Oggetto & O){return O.stampa(out);}
};
}

#endif
