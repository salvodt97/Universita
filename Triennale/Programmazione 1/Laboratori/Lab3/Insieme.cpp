#include "Insieme.h"



namespace Mynamespace{
	istream & operator >>(istream & in, Insieme & I){
		in >> I.dim;
		for(int i=0;i<I.dim;i++)
		in >> I[i];				
		return in;
	}
	
	ostream & operator << (ostream & out, const Insieme & I){
	for(int i=0;i<I.dim;i++)
	out << I[i] <<' ';	
	return out;
	}
	
	bool Insieme::in(const T & elem){
		bool assente=true;
		int i=0;
		while(i<dim && assente)
		if(vett[i]==elem)
		assente=false;
		else i++;
		return assente;
	}
	
}
