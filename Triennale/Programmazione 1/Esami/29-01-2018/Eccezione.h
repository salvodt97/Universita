#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <string>
using std::string;

namespace Mynamespace{
class Eccezione{
	private:
	string msg;
	int valore;
	
	public:
	Eccezione(const string & m="Errore", int n=0){msg=m; valore=n;}
	string what() const {return msg;}
	int get_valore() const {return valore;}
};
}

#endif
