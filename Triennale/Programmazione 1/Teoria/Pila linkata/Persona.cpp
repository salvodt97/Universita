#include "Persona.h"
namespace Mynamespace {
Persona::Persona(){
	eta=0;
	cognome=new char[1];
	strcpy(cognome, "");
	nome=new char[1];
	strcpy(nome, "");
}

Persona::Persona(const char * N, const char * C, const int E){
	this->eta=E;
	this->cognome=new char[strlen(C)+1];
	strcpy(this->cognome, C);
	this->nome=new char[strlen(N)+1];
	strcpy(this->nome, N);
}

Persona::Persona(const Persona & P){
	eta=P.eta;
	cognome=new char[strlen(P.cognome)+1];
	strcpy(cognome, P.cognome);
	nome=new char[strlen(P.nome)+1];
	strcpy(nome, P.nome);
}

const Persona & Persona::operator=(const Persona & P) {
	
	if(this!=&P){ 
	if(nome) delete [] nome;
	if(cognome) delete [] cognome;
	eta=P.eta;
	cognome=new char[strlen(P.cognome)+1];
	strcpy(cognome, P.cognome);
	nome=new char[strlen(P.nome)+1];
	strcpy(nome, P.nome);
	}
	return *this;
	
}

Persona::~Persona(){
	cout << "distruttore";
	delete [] cognome;
	delete [] nome;
}

ostream & Persona::print(ostream & out) const
{
   out << cognome << ' ' << nome << ' ' << eta;
   return out;
}

void Persona::set_C(const char * C){
	if(cognome) delete [] cognome;
	cognome=new char[strlen(C)+1];
	strcpy(cognome, C);
}

const char * Persona::get_C() const {return cognome;}

/*
ostream & operator<<(ostream & os, const Persona & P) {
	os << P.nome << ' ' << P.cognome << ' ' << P.eta;
	return os;
}
*/
ostream & operator<<(ostream & out, const Persona & P) {
	return P.print(out);	
}


istream & operator>>(istream & in, Persona & P) {
	char buffer[100];
	cout << "inserisci il nome: " << endl;
	in.getline(buffer, 100);
	if(P.nome) delete [] P.nome;
	P.nome=new char[strlen(buffer)+1];
	strcpy(P.nome,buffer);
	cout << "inserisci il cognome: " << endl;
	in.getline(buffer, 100);
	if(P.cognome) delete [] P.cognome;
	P.cognome=new char[strlen(buffer)+1];
	strcpy(P.cognome,buffer);
	cout << "inserisci l'eta': "  << endl;
	in>> P.eta;
	
	return in;
}

bool Persona::operator==(const Persona & P) const {
 return (!strcmp(nome,P.nome) &&  !strcmp(cognome,P.cognome) && eta==P.eta);
}

}//fine namespace
