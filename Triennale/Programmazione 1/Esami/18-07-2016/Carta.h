#ifndef CARTA_H
#define CARTA_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::ostream;

namespace Mynamespace{
class Carta{
	private:
	char * Tipo;
	char * Intestatario;
	char * Numero;
	
	protected:
	virtual ostream & stampa(ostream & out) const {return out <<Tipo <<' ' <<Intestatario <<' ' <<Numero;}
	
	public:
	Carta(const char * = "",const char * = "",const char * = "");
	Carta(const Carta &);
	const Carta & operator=(const Carta &);
	const char * get_Tipo() const {return Tipo;}
	const char * get_Intestatario() const {return Intestatario;}
	const char * get_Numero() const {return Numero;}
	void set_Tipo(const char *);
	void set_Intestatario(const char *);
	void set_Numero(const char *);
	bool check_Numero() const throw(const char *);
	virtual bool Check(const char *) =0;
	virtual ~Carta(){delete [] Tipo; delete [] Intestatario; delete [] Numero;}
	
	friend ostream & operator <<(ostream & out, const Carta & C){return C.stampa(out);}
};
}
#endif
