#include "Lettera.h"

namespace Mynamespace{
	Lettera::Lettera(int c, const char * a, int p, const char * f, const char * m, const char * d):Manoscritto(c,a,p,f){
		mittente=new char [strlen(m)+1];
		strcpy(mittente,m);
		destinatario=new char [strlen(d)+1];
		strcpy(destinatario,d);
	}
	
	Lettera::Lettera(const Lettera & M):Manoscritto(M){
		mittente=new char [strlen(M.mittente)+1];
		strcpy(mittente,M.mittente);
		destinatario=new char [strlen(M.destinatario)+1];
		strcpy(destinatario,M.destinatario);
	}
	
	const Lettera & Lettera::operator =(const Lettera & M){
		if(this != &M){
			Manoscritto::operator =(M);
			delete [] mittente;
			mittente=new char [strlen(M.mittente)+1];
			strcpy(mittente,M.mittente);
			delete [] destinatario;
			destinatario=new char [strlen(M.destinatario)+1];
			strcpy(destinatario,M.destinatario);
		}
		return * this;
	}
	
	void Lettera::set_mittente(const char * a){
		delete [] mittente;
		mittente=new char [strlen(a)+1];
		strcpy(mittente,a);
	}
	
	void Lettera::set_destinatario(const char * f){
		delete [] destinatario;
		destinatario=new char [strlen(f)+1];
		strcpy(destinatario,f);
	}
	
	istream & Lettera::memorizza_dati(istream & in){
		Manoscritto::memorizza_dati(in);
		char buffer1[20], buffer2[20];
		
		delete [] mittente;
		in >> buffer1;
		mittente=new char [strlen(buffer1)+1];
		strcpy(mittente,buffer1);
		delete [] destinatario;
		in >> buffer2;
		destinatario=new char [strlen(buffer2)+1];
		strcpy(destinatario,buffer2);
		
		return in;
	}
}
