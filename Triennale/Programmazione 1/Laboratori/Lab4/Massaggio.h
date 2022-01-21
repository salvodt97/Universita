#ifndef MASSAGGIO_H
#define MASSAGGIO_H

#include "Trattamento.h"
#include "Eccezione.h"

namespace Mynamespace{
class Massaggio:public Trattamento{
	private:
	bool Completezza;
	int Minuti;
	
	protected:
	virtual istream & read(istream & in){return Trattamento::read(in) >> Completezza >> Minuti;}
	virtual ostream & print(ostream & out) const {return Trattamento::print(out) <<' ' << Completezza <<' ' << Minuti;}
	
	public:
	Massaggio(const char * C = "", const char * D ="", bool Co=true, int Min=0):Trattamento(C,D){Completezza=Co; Minuti=Min;}
	bool get_Completezza() const {return Completezza;}
	int get_Minuti() const {return Minuti;}
	void set_Completezza(const bool C){Completezza=C;}
	void set_Minuti(const int Min) throw(bad_data) {if(Min!=25 && Min!=40 && Min!=50 && Min!=80) throw bad_data("\nErrore in set_Minuti ",Min); else Minuti=Min;}
	virtual float calcola_costo() const;
	
	friend istream & operator >>(istream & in, Massaggio & M){return M.read(in);}
	friend ostream & operator <<(ostream & out, const Massaggio & M){return M.print(out);}
};
}
#endif
