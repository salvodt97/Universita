#ifndef ECCEZIONE_H
#define ECCEZIONE_H

#include <iostream>
#include <string>
using std::string;

namespace Mynamespace{
class bad_data{
	private:
	string Messaggio;
	int valore;
	
	public:
	bad_data(const string & M="Errore", int v=0){Messaggio=M; valore=v;}
	string what() const {return Messaggio;}
	int get_valore() const {return valore;}
};
}
#endif
