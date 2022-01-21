#ifndef REGISTRATO_H
#define REGISTRATO_H
#include "Cliente.h"
#include "Timestamp.h"

namespace Mynamespace{
class Registrato:public Cliente{
	private:
	char * login;
	char * password;
	Timestamp ora;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream &) const;
	
	public:
	Registrato(const char * ="", const char * ="", const char * ="", const char * ="", int =0, int=0, int=0);
	Registrato(const Registrato &);
	const Registrato & operator =(const Registrato &);
	bool operator ==(const Registrato & C) const {return (!strcmp(login,C.login) && !strcmp(password,C.password) && (ora==C.ora) && Cliente::operator ==(C));}
	bool operator !=(const Registrato & C) const {return (strcmp(login,C.login)!=0 || strcmp(password,C.password)!=0 || (ora!=C.ora) || Cliente::operator !=(C));}
	virtual bool check() const throw (Eccezione);
	~Registrato(){delete [] login; delete [] password;}
	
	friend istream & operator >>(istream & in, Registrato & C){return C.leggi(in);}
	friend ostream & operator <<(ostream & out, const Registrato & C){return C.stampa(out);}
};
}

#endif
