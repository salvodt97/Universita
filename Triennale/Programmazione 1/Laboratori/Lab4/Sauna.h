#ifndef SAUNA_H
#define SAUNA_H

#include "Trattamento.h"
#include "Eccezione.h"

namespace Mynamespace{
class Sauna:public Trattamento{
	private:
	int Temperatura;
	int Umidita;
	
	protected:
	virtual istream & read(istream & in){return Trattamento::read(in) >> Temperatura >> Umidita;}
	virtual ostream & print(ostream & out) const {return Trattamento::print(out) <<' ' << Temperatura <<' ' << Umidita;}
	
	public:
	Sauna(const char * C = "", const char * D ="", int T=0, int U=0):Trattamento(C,D){Temperatura=T; Umidita=U;}
	bool get_Temperatura() const {return Temperatura;}
	int get_Umidita() const {return Umidita;}
	void set_Temperatura(const int T) throw(bad_data) {if(T<30 || T>110) throw bad_data("\nErrore in set_Temperatura ",T); else Temperatura=T;}
	void set_Umidita(const int U) throw(bad_data) {if(U<15 || U>30) throw bad_data("\nErrore in set_Umidita ",U); else Umidita=U;}
	virtual float calcola_costo() const;
	
	friend istream & operator >>(istream & in, Sauna & S){return S.read(in);}
	friend ostream & operator <<(ostream & out, const Sauna & S){return S.print(out);}
};
}
#endif
