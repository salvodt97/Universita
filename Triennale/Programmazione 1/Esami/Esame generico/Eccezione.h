#ifndef ECCEZIONE_H
#define ECCEZIONE_H
#include "Data.h"

#include <string.h>
using std::string;

namespace Mynamespace{
class Eccezione{
	private:
	string msg;
	Data data;
	
	public:
	Eccezione(const string & ms="Errore", int g=0, int m=0, int a=0):data(g,m,a){msg=ms;}
	string what() const {return msg;}
	Data get_data() const {return data;}
};
}

#endif
