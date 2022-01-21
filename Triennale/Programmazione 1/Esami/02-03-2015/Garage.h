#ifndef GARAGE_H
#define GARAGE_H

#include "Veicolo.h"
#include "Eccezione.h"

namespace Mynamespace{
typedef Veicolo T;

class Garage{
	private:
	static const int dim=20;
	T v[dim];
	int riemp;
	
	public:
	explicit Garage(const int r=0){riemp=r;}
	T & operator [] (const int i){return v[i];}
	int get_riemp() const {return riemp;}
	const T & operator [] (const int i) const {return v[i];} 
	int Immetti(const T &) throw(Eccezione);
	void Togli(const int);
	
	friend ostream & operator <<(ostream &, const Garage &);
};
}
#endif
