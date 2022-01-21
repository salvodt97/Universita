#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <string>
using std::string;

namespace Mynamespace{
class Eccezione{
	private:
	string msg;
	string valore;
	
	public:
	Eccezione(const string m="Errore", const string v=""){msg=m; valore=v;}
	string what() const {return msg;}
	string get_valore() const {return valore;}
};
}
#endif
