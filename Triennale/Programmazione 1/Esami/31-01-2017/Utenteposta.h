#ifndef UTENTEPOSTA_H
#define UTENTEPOSTA_H

#include "Utente.h"

namespace Mynamespace{
class Utenteposta:public Utente{
	private:
	char * email;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const {return Utente::stampa(out) <<' ' <<email;}
	
	public:
	Utenteposta(const char * ="****************", const char * ="", int =0, int =0, int=0, const char * ="");
	Utenteposta(const Utenteposta &);
	const Utenteposta & operator =(const Utenteposta &);
	
	bool operator ==(const Utenteposta & U) const{return (Utente::operator ==(U) && !strcmp(email,U.email));}
	bool operator !=(const Utenteposta & U) const{return (Utente::operator !=(U) || strcmp(email,U.email)!=0);}
	virtual bool Check() const throw(Eccezione);
	
	virtual ~Utenteposta(){delete [] email;}
	
	friend istream & operator >>(istream & in, Utenteposta & U){return U.leggi(in);}
	friend ostream & operator <<(ostream & out, const Utenteposta & U){return U.stampa(out);}
	
};
}

#endif
