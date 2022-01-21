#ifndef TIMESTAMP_H
#define TIMESTAMP_H

#include <iostream>
using std::istream;
using std::ostream;

namespace Mynamespace{
class Timestamp{
	private:
	int ora;
	int minuti;
	int secondi;
	
	public:
	Timestamp(int o=0, int m=0, int s=0){ora=o; minuti=m; secondi=s;}
	int get_ora() const {return ora;}
	int get_minuti() const {return minuti;}
	int get_secondi() const {return secondi;}
	void set_ora(const int o){ora=o;}
	void set_minuti(const int m){minuti=m;}
	void set_secondi(const int s){secondi=s;}
	bool operator ==(const Timestamp & T) const {return (ora==T.ora && minuti==T.minuti && secondi==T.secondi);}
	bool operator !=(const Timestamp & T) const {return (ora!=T.ora || minuti!=T.minuti || secondi!=T.secondi);}
	
	friend istream & operator >>(istream & in, Timestamp & T){return in >>T.ora >>T.minuti >>T.secondi;}
	friend ostream & operator <<(ostream & out, const Timestamp & T){return out <<T.ora <<":" <<T.minuti <<":" <<T.secondi;}
};
}

#endif
