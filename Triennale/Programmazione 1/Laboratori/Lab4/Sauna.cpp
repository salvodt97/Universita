#include "Sauna.h"

namespace Mynamespace{
	float Sauna::calcola_costo() const{
		float costo;
		if(Temperatura<=45 && Umidita<=30)
		costo=18;
		else if(Temperatura<=110 && Umidita<=15)
		costo=24;
		
		return costo;
	}
}
