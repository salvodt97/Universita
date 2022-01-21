#ifndef BANCOMAT_H
#define BANCOMAT_H

#include "Carta.h"
#include "Data.h"

namespace Mynamespace{
class Bancomat:public Carta{
	private:
	char * PIN;
	bool attiva;
	Data DataScadenza;
	
	void set_PIN(const char *);
		
	protected:
	virtual ostream & stampa(ostream & out) const {return Carta::stampa(out) <<' ' <<PIN <<' ' <<attiva <<' ' <<DataScadenza;}
	
	public:
	Bancomat(const char * = "",const char * = "",const char * = "",const char * ="", bool=true, const Data & = 0);
	Bancomat(const Bancomat &);
	const Bancomat & operator=(const Bancomat &);
	Data  get_DataScadenza() const {return DataScadenza;}
	void set_DataScadenza(const Data & D){DataScadenza=D;};
	bool Attiva();
	virtual bool Check(const char * P){if(Attiva())return !strcmp(PIN,P);}
	virtual ~Bancomat(){delete [] PIN;}
	
	friend ostream & operator <<(ostream & out, const Bancomat & B){return B.stampa(out);}
};
}
#endif
