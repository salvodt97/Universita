#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include "Oggetto.h"
#include <string>
using std::string;

namespace Mynamespace{
typedef Oggetto T;
class Eccezione{
	private:
	string msg;
	T oggetto;
	
	public:
	Eccezione(string m ="Errore", int c =0, const char * d ="", const char * f =""):oggetto(c,d,f){msg=m;}
	string what() const{return msg;}
	const T & get_oggetto() const{return oggetto;}
};
}

#endif
