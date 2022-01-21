#ifndef AUTO_H
#define AUTO_H

#include"Veicolo.h"

namespace Mynamespace{
class Auto:public Veicolo{
	private:
	char * Alimentazione;
	
	protected:
	virtual istream & read(istream &);
	virtual ostream & print(ostream & out) const {return Veicolo::print(out) <<' ' <<Alimentazione;}
	
	public:
	Auto(const char * ="", const char * ="", const char * ="");
	Auto(const Auto &);
	const Auto & operator =(const Auto &);
	virtual const char * ToText() const;
	virtual ~Auto(){delete [] Alimentazione;}
	
	friend istream & operator >>(istream & in, Auto & A){return A.read(in);}
	friend ostream & operator <<(ostream & out, const Auto & A){return A.print(out);}
};
}

#endif
