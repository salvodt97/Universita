#ifndef VEICOLO_H
#define VEICOLO_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::istream;
using std::ostream;

namespace Mynamespace{
class Veicolo{
	private:
	char * Tipo;
	char * Marca;
	
	protected:
	virtual istream & read(istream &);
	virtual ostream & print(ostream & out) const {return out <<Tipo <<' ' <<Marca;}
	
	public:
	Veicolo(const char * ="", const char * ="");
	Veicolo(const Veicolo &);
	const Veicolo & operator =(const Veicolo &);
	const char * get_Tipo() const {return Tipo;}
	const char * get_Marca() const {return Marca;}
	virtual const char * ToText() const;
	virtual ~Veicolo(){delete [] Tipo; delete [] Marca;}
	
	friend istream & operator >>(istream & in, Veicolo & V){return V.read(in);}
	friend ostream & operator <<(ostream & out, const Veicolo & V){return V.print(out);}
};
}

#endif
