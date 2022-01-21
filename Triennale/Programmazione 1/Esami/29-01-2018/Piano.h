#ifndef PIANO_H
#define PIANO_H

#include "Eccezione.h"
#include <iostream>
#include <cstdlib>
#include <cstring>

using std::istream;
using std::ostream;

namespace Mynamespace{
struct Posto{
	int id;
	bool occupato;
};

class Piano{
	private:
	int num_posti;
	int riemp;
	Posto * posti_disp;
	
	public:
	explicit Piano(const int =0);
	Piano(const Piano &);
	const Piano & operator =(const Piano &);
	int get_pliberi() const;
	bool isfull() const {return riemp==num_posti;}
	bool isempty() const {return riemp==0;}
	bool assegna(int &);
	bool libera(int) throw (Eccezione);
	~Piano(){delete [] posti_disp;}
	
	friend ostream & operator <<(ostream &, const Piano &);
};
	
}

#endif
