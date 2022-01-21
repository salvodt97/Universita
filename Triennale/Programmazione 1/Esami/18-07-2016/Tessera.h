#ifndef TESSERA_H
#define TESSERA_H

#include "Carta.h"
#include "Data.h"

namespace Mynamespace{
class Tessera:public Carta{
	private:
	char * CF;
	Data DataRilascio;
	Data DataScadenza;
		
	protected:
	virtual ostream & stampa(ostream & out) const {return Carta::stampa(out) <<' ' <<CF <<' ' <<DataRilascio <<' ' <<DataScadenza;}
	
	public:
	Tessera(const char * = "",const char * = "",const char * = "",const char * ="", const Data & = 0, const Data & = 0);
	Tessera(const Tessera &);
	const Tessera & operator=(const Tessera &);
	const char * get_CF() const {return CF;}
	Data get_DataRilascio() const {return DataRilascio;}
	Data  get_DataScadenza() const {return DataScadenza;}
	void set_CF(const char *);
	void set_DataRilascio(const Data & D){DataRilascio=D;}
	void set_DataScadenza(const Data & D){DataScadenza=D;};
	virtual bool Check(const char * cf){if(Carta::check_Numero()) return !strcmp(CF,cf);}
	virtual ~Tessera(){delete [] CF;}
	
	friend ostream & operator <<(ostream & out, const Tessera & T){return T.stampa(out);}
};
}
#endif
