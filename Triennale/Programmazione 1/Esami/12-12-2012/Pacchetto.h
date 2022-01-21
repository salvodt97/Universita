#ifndef PACCHETTO_H
#define PACCHETTO_H

#include "Pacco.h"
#include "Data.h"

namespace Mynamespace{
class Pacchetto:public Pacco{
	private:
	char * destinatario;
	Data spedizione;
		
	protected:
	virtual istream & leggi(istream &);
	virtual ostream & stampa(ostream & out) const{return Pacco::stampa(out) <<' ' <<destinatario <<' ' <<spedizione;}
	
	public:
	Pacchetto(const char * ="", const float =0.0, const char * =" ", int =0, int=0, int=0);
	Pacchetto(const Pacchetto &);
	const Pacchetto & operator =(const Pacchetto &);
	const char * get_destinatario() const {return destinatario;}
	void set_destinatario(const char *);
	virtual bool Check() const;
	virtual ~Pacchetto(){delete [] destinatario;}
	
	friend istream & operator >>(istream & in, Pacchetto & P){return P.leggi(in);}
	friend ostream & operator <<(ostream & out, const Pacchetto & P){return P.stampa(out);}
	
};
}

#endif
