#ifndef UTENTE_H
#define UTENTE_H

#include "Data.h"
#include "Eccezione.h"

typedef char stringa[17];

namespace Mynamespace{
class Utente{
	private:
	stringa cf;
	char * cognome;
	Data registrazione;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return out <<cf <<' ' <<cognome <<' ' <<registrazione;}
	
	public:
	Utente(const char * ="****************", const char * ="", int =0, int =0, int=0);
	Utente(const Utente &);
	const Utente & operator =(const Utente &);
	
	bool operator ==(const Utente & U) const{return (!strcmp(cf,U.cf) && !strcmp(cognome,U.cognome) && registrazione==U.registrazione);}
	bool operator !=(const Utente & U) const{return (strcmp(cf,U.cf)!=0 || strcmp(cognome,U.cognome)!=0 || !(registrazione==U.registrazione));}
	virtual bool Check() const throw(Eccezione);
	
	virtual ~Utente(){delete [] cognome;}
	
	friend istream & operator >>(istream & in, Utente & U){return U.leggi(in);}
	friend ostream & operator <<(ostream & out, const Utente & U){return U.stampa(out);}
	
};
}

#endif
