#ifndef MANOSCRITTO_H
#define MANOSCRITTO_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::istream;
using std::ostream;

namespace Mynamespace{
class Manoscritto{
	private:
	int codice;
	char * autore;
	int pagine;
	char * formato;
	
	protected:
	virtual istream & memorizza_dati(istream &);
	virtual ostream & visualizza_dati(ostream & out) const {return out <<codice <<' ' <<autore <<' ' <<pagine <<' ' <<formato;}
	
	public:
	Manoscritto(int =0, const char * ="Sconosciuto", int =0, const char * ="");
	Manoscritto(const Manoscritto &);
	const Manoscritto & operator =(const Manoscritto &);
	int get_codice() const {return codice;}
	const char * get_autore() const {return autore;}
	int get_pagine() const {return pagine;}
	const char * get_formato() const {return formato;}
	void set_codice(const int c){codice=c;}
	void set_autore(const char *);
	void set_pagine(const int p){pagine=p;}
	void set_formato(const char *);
	bool operator >(const Manoscritto & M) const {return codice>M.codice;} 
	bool operator ==(const Manoscritto & M) const {return codice==M.codice;}
	~Manoscritto() {delete [] autore; delete [] formato;}
	
	friend istream & operator >>(istream & in, Manoscritto & M){return M.memorizza_dati(in);}
	friend ostream & operator <<(ostream & out, const Manoscritto & M){return M.visualizza_dati(out);}
};
}

#endif
