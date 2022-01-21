#ifndef DATA_H
#define DATA_H

#include <iostream>
using std::ostream;

namespace Mynamespace{
class Data{
	private:
	int Giorno;
	int Mese;
	int Anno;
	
	public:
	Data(int G=0, int M=0, int A=0):Giorno(G),Mese(M),Anno(A){}
	int get_Giorno() const {return Giorno;}
	int get_Mese() const {return Mese;}
	int get_Anno() const {return Anno;}
	void set_Giorno(const int G){Giorno=G;}
	void set_Mese(const int M){Mese=M;}
	int set_Anno(const int A){Anno=A;}
	virtual ostream & stampa(ostream & out) const {return out <<"(" << Giorno <<"-" <<Mese <<"-" <<Anno <<")";}
	
	friend ostream & operator <<(ostream & out, const Data & D){return D.stampa(out);}
};
}
#endif
