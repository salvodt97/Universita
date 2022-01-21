#include "Massaggio.h"

namespace Mynamespace{
	float Massaggio::calcola_costo() const{
		float costo;
		if(Completezza==true && Minuti>=40)
		costo=Minuti;
		else if(Completezza==false && Minuti<=40)
		costo=Minuti/2;
		
		return costo;
	}
}
