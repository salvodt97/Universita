#ifndef RILEVAMENTI_H
#define RILEVAMENTI_H

#include <iostream>
#include <cstring>
#include <cstdlib>

#include "Eccezione.h"

using std::ostream;
using std::istream;

namespace Mynamespace{
class Rilevamento{
	private:
	char * Regione;
	char * Provincia;
	char * Citta;
	int Anno;
	int Mese;
	int Giorno;
	int Tmax;
	int Tmin;
	
	public:
	Rilevamento();
	Rilevamento(const char *, const char *, const char *);
	Rilevamento(const Rilevamento &);
	const Rilevamento & operator =(const Rilevamento &);
	
	const char * get_Regione()const {return Regione;}
	const char * get_Provincia()const {return Provincia;}
	const char * get_Citta()const {return Citta;}
	int get_Anno() const {return Anno;}
	int get_Mese() const {return Mese;}
	int get_Giorno() const {return Giorno;}
	int get_Tmax() const {return Tmax;}
	int get_Tmin() const {return Tmin;}
	
	void set_Regione(const char *);
	void set_Provincia(const char *);
	void set_Citta(const char *);
	void set_Anno(int A){Anno=A;}
	void set_Mese(int M) throw(Eccezione) {if(M>0 && M<13 ) Mese=M; else throw Eccezione("Mese errato", M);}
	void set_Giorno(int G) throw(Eccezione) {if(G>0 && G<32) Giorno=G; else throw Eccezione("Giorno errato", G);}
	void set_Tmax(int T){Tmax=T;}
	void set_Tmin(int t){Tmin=t;}
	
	~Rilevamento(){delete [] Regione; delete [] Provincia; delete [] Citta;}
	
	friend istream & operator >>(istream &, Rilevamento &);
	friend ostream & operator <<(ostream & out, const Rilevamento & R){return out <<R.Regione <<' ' <<R.Provincia <<' ' <<R.Citta <<" (" <<R.Giorno <<"-" <<R.Mese <<"-" <<R.Anno <<") " <<R.Tmax <<" gradi " <<R.Tmin <<" gradi";}
};
}

#endif
