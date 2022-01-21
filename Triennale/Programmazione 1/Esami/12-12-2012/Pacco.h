#ifndef PACCO_H
#define PACCO_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::istream;
using std::ostream;

namespace Mynamespace{
class Pacco{
	private:
	char * forma;
	float peso;
	
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const{return out <<forma <<' ' <<peso <<" Kg";}
	
	public:
	Pacco(const char * ="", float =0.0);
	Pacco(const Pacco &);
	const Pacco & operator =(const Pacco &);
	const char * get_forma() const {return forma;}
	float get_peso() const {return peso;}
	void set_forma(const char *);
	void set_peso(const float p){peso=p;}
	virtual bool Check() const =0;
	virtual ~Pacco(){delete [] forma;}
	
	friend istream & operator >>(istream & in, Pacco & P){return P.leggi(in);}
	friend ostream & operator <<(ostream & out, const Pacco & P){return P.stampa(out);}
	
};
}

#endif
