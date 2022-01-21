#ifndef TRATTAMENTO_H
#define TRATTAMENTO_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::istream;
using std::ostream;

namespace Mynamespace{
class Trattamento{
	private:
	char * Codice;
	char * Descrizione;
	
	protected:
	virtual istream & read(istream &);
	virtual ostream & print(ostream & out) const {return out << Codice <<' ' << Descrizione;}
	
	public:
	Trattamento(const char * ="", const char * ="");
	Trattamento(const Trattamento &);
	const Trattamento & operator =(const Trattamento &);
	const char * get_Codice() const {return Codice;}
	const char * get_Descrizione() const {return Descrizione;}
	void set_Codice(const char * &);
	void set_Descrizione(const char * &);
	virtual float calcola_costo() const =0;
	virtual ~Trattamento(){delete [] Codice; delete [] Descrizione;}
	
	friend istream & operator >>(istream & in, Trattamento & T){return T.read(in);}
	friend ostream & operator <<(ostream & out, const Trattamento & T){return T.print(out);}
};
}
#endif
