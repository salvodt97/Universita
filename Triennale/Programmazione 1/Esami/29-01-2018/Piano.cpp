#include "Piano.h"

namespace Mynamespace{
	Piano::Piano(const int n):num_posti(n){
		riemp=0;
		posti_disp=new Posto [num_posti];
		for(int i=0;i<num_posti;i++){
			posti_disp[i].id=i;
			posti_disp[i].occupato=false;
			}		
	}
	
	Piano::Piano(const Piano & P){
		num_posti=P.num_posti;
		riemp=P.riemp;
		posti_disp=new Posto [num_posti];
		for(int i=0;i<num_posti;i++){
			posti_disp[i].id=P.posti_disp[i].id;
			posti_disp[i].occupato=P.posti_disp[i].occupato;
			}
	}
	
	const Piano & Piano::operator =(const Piano & P){
		if(this != &P){
			num_posti=P.num_posti;
			riemp=P.riemp;
			delete [] posti_disp;
			posti_disp=new Posto [num_posti];
			for(int i=0;i<num_posti;i++){
				posti_disp[i].id=P.posti_disp[i].id;
				posti_disp[i].occupato=P.posti_disp[i].occupato;
			}	
		}
		return * this;
	}
	
	int Piano::get_pliberi() const{
		int n=0;
		for(int i=0;i<num_posti;i++)
		if(posti_disp[i].occupato==false)
		n++;
		
		return n;
	}
	
	bool Piano::assegna(int & pos){
		int i=0;
		bool trovato=false;
		if(isfull()) return false;
		while(i<num_posti && !trovato)
			if(posti_disp[i].occupato==false){
				posti_disp[i].occupato==true;
				posti_disp[i].id=i;
				pos=i;
				trovato=true;
				riemp++;
		}
		return true;
	}
	
	bool Piano::libera(int posto)throw (Eccezione){
		if(posto<0 || posto>num_posti) throw Eccezione("Posto inesistente: ",posto);
		if(isempty()) return false;
		else{
		posti_disp[posto].occupato=false;
		riemp --;
		return true;
		}
	}
	
	ostream & operator <<(ostream & out, const Piano & P){
		for(int i=0;i<P.num_posti;i++)
		out << P.posti_disp[i].id <<' ' <<P.posti_disp[i].occupato <<"\n";
		return out;
	}
}
