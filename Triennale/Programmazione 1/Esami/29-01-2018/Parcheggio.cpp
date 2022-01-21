#include "Parcheggio.h"

namespace Mynamespace{
	bool Parcheggio::inserisci(int & pos){
		if(get_liberi()==0) return false;
		if(P1.assegna(pos))return true;
		if(P2.assegna(pos)) return true;
	}
	
	bool Parcheggio::estrai(int posto){
		if(P1.libera(posto)) return true;
		if(P2.libera(posto)) return true;
	}
}
