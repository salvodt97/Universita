#ifndef LETTERA_H
#define LETTERA_H
#include "Manoscritto.h"

namespace Mynamespace{
class Lettera:public Manoscritto{
	private:
	char * mittente;
	char * destinatario;
	
	protected:
	virtual istream & memorizza_dati(istream &);
	virtual ostream & visualizza_dati(ostream & out) const {return Manoscritto::visualizza_dati(out) <<' ' <<mittente <<' ' <<destinatario;}
	
	public:
	Lettera(int =0, const char * ="Sconosciuto", int =0, const char * ="", const char * ="Sconosciuto", const char * ="Sconosciuto");
	Lettera(const Lettera &);
	const Lettera & operator =(const Lettera &);
	const char * get_mittente() const {return mittente;}
	const char * get_destinatario() const {return destinatario;}
	void set_mittente(const char *);
	void set_destinatario(const char *);
	~Lettera() {delete [] mittente; delete [] destinatario;}
	
	friend istream & operator >>(istream & in, Lettera & M){return M.memorizza_dati(in);}
	friend ostream & operator <<(ostream & out, const Lettera & M){return M.visualizza_dati(out);}
};
}

#endif
