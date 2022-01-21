#include "Pacchetto.h"

namespace Mynamespace{
	Pacchetto::Pacchetto(const char * f, float p, const char * d, int g, int m, int a):Pacco(f,p), spedizione(g,m,a){
		destinatario=new char[strlen(d)+1];
		strcpy(destinatario,d);
	}
	
	Pacchetto::Pacchetto(const Pacchetto & P):Pacco(P){
		destinatario=new char[strlen(P.destinatario)+1];
		strcpy(destinatario,P.destinatario);
	}
	
	const Pacchetto & Pacchetto::operator =(const Pacchetto & P){
		if(this != &P){
			Pacco::operator =(P);
			delete [] destinatario;
			destinatario=new char[strlen(P.destinatario)+1];
			strcpy(destinatario,P.destinatario);
			spedizione=P.spedizione;
		}
		return * this;
	}
	
	void Pacchetto::set_destinatario(const char * d){
		delete [] destinatario;
		destinatario=new char[strlen(d)+1];
		strcpy(destinatario,d);
	}
	
	istream & Pacchetto::leggi(istream & in){
		Pacco::leggi(in);
		char buffer[40];
		
		delete [] destinatario;
		in >> buffer;
		destinatario=new char[strlen(buffer)+1];
		strcpy(destinatario,buffer);
		
		in >> spedizione;
		
		return in;
	}
	
	bool Pacchetto::Check() const{
		bool ok=true;
		int i=0;
		while(i<strlen(destinatario) && ok)
		if(!(destinatario[i]>='A' && destinatario[i]<='Z') && !(destinatario[i]>='a' && destinatario[i]<='z'))
		ok=false;
		else i++;
		
		return ok;
		
	}
}
