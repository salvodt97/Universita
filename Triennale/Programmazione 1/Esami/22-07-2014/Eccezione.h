#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <iostream>
#include <string>

using std::string;

namespace Mynamespace{
class Eccezione{
	private:
	string msg;
	int valore;
	
	public:
	Eccezione(const string & m="Errore", int v=0){msg=m; valore=v;}
	string what() const {return msg;}
	int get_valore() const {return valore;}
};
}

#endif
