#include "Garage.h"

namespace Mynamespace{
	int Garage::Immetti(const T & e) throw(Eccezione){
		int pos=0;
		if(riemp>=dim){
			pos=-1;
			throw Eccezione("Il numero di posti e' gia': ",riemp);
		}		
		if(!strcmp(e.get_Tipo(),"Auto") || !strcmp(e.get_Tipo(),"Moto")){
		v[riemp]=e;
		riemp++;
		pos=riemp;
			}
		else{
		pos=-1;
		throw Eccezione("Veicolo errato!", pos);
		}
		return pos;
	}
	
	void Garage::Togli(const int pos){
		for(int i=pos;i<riemp-1;i++)
		v[i]=v[i+1];
		riemp--;
	}
	
	ostream & operator <<(ostream & out, const Garage & G){
		for(int i=0;i<G.riemp;i++)
		out << G[i];
		
		return out;
	}
}
