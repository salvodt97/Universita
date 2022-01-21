#ifndef PARCHEGGIO_H
#define PARCHEGGIO_H

#include "Piano.h"

namespace Mynamespace{
class Parcheggio{
	private:
	string nome;
	string indirizzo;
	Piano P1;
	Piano P2;
	
	public:
	Parcheggio(const string & no="", const string & i="", int n=0, int m=0):P1(n), P2(m){nome=no; indirizzo=i;}
	int get_liberi() const {return (P1.get_pliberi()+P2.get_pliberi());}
	bool inserisci(int &);
	bool estrai(int);
	
	friend ostream & operator <<(ostream & out, const Parcheggio & P){return out << P.nome <<' '<< P.indirizzo <<"\n" <<P.P1 <<P.P2;}
};
}

#endif
