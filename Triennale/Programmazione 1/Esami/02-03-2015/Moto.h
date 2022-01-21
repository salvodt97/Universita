#ifndef MOTO_H
#define MOTO_H

#include"Veicolo.h"

namespace Mynamespace{
class Moto:public Veicolo{
	private:
	char * Tipologia;
	
	protected:
	virtual istream & read(istream &);
	virtual ostream & print(ostream & out) const {return Veicolo::print(out) <<' ' <<Tipologia;}
	
	public:
	Moto(const char * ="", const char * ="", const char * ="");
	Moto(const Moto &);
	const Moto & operator =(const Moto &);
	virtual const char * ToText() const;
	virtual ~Moto(){delete [] Tipologia;}
	
	friend istream & operator >>(istream & in, Moto & A){return A.read(in);}
	friend ostream & operator <<(ostream & out, const Moto & A){return A.print(out);}
};
}

#endif
