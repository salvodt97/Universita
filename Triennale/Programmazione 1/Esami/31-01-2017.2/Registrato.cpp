#include "Registrato.h"

namespace Mynamespace{
		Registrato::Registrato(const char * c, const char * p, const char * l, const char * pa, int o, int m, int s):Cliente(c,p), ora(o,m,s){
		login=new char [strlen(l)+1];
		strcpy(login,l);
		password=new char [strlen(pa)+1];
		strcpy(password,pa);
	}
	
	Registrato::Registrato(const Registrato & C):Cliente(C){
		login=new char [strlen(C.login)+1];
		strcpy(login,C.login);
		password=new char [strlen(C.password)+1];
		strcpy(password,C.password);
		ora=C.ora;
	}
	
	const Registrato & Registrato::operator =(const Registrato & C){
		if(this != &C){
			Cliente::operator =(C);
			delete [] login;
			login=new char [strlen(C.login)+1];
			strcpy(login,C.login);
			delete [] password;
			password=new char [strlen(C.password)+1];
			strcpy(password,C.password);
			ora=C.ora;
		}
		return * this;
	}
	
	istream & Registrato::leggi(istream & in){
		Cliente::leggi(in);
		char buffer1[50], buffer2[50];
		
		delete [] login;
		in >> buffer1;
		login=new char [strlen(buffer1)+1];
		strcpy(login,buffer1);
		delete [] password;
		in >> buffer2;
		password=new char [strlen(buffer2)+1];
		strcpy(password,buffer2);
		in >> ora;
		
		return in;
	}
	
	ostream & Registrato::stampa(ostream & out) const {
		Cliente::stampa(out);
		out <<' ' <<login <<' ';
		for(int i=0;i<strlen(password);i++)
		out <<'*';
		out <<' ' << ora;
		
		return out;
	}
	
	bool Registrato::check() const throw (Eccezione){
		Cliente::check();
		if(strlen(password)<8) throw Eccezione("Numero di caratteri insufficiente nella password: ", password);
		
		int i=0;
		bool trovato=false;	
		while(i<strlen(password) && !trovato)
		if((password[i]>'A' && password[i]<'Z'))
		trovato=true;
		else i++;
		
		int j=0;
		bool trovato1=false;
		while(j<strlen(password) && !trovato1)
		if((password[i]>'0' && password[i]<'9'))
		trovato1=true;
		else i++;
		
		if(trovato==false) throw Eccezione("Deve esserci almeno una lettera maisucola nella password: ", password);
		if(trovato1==false) throw Eccezione("Deve esserci almeno un numero nella password: ", password);
	
		return (Cliente::check() && trovato && trovato1);
	}
	
}
