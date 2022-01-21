#ifndef _PERSONA_H
#define _PERSONA_H

#include <iostream>
#include <cstring>
using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

//classe persona prima versione: esempio di classe
//con estensione dinamica e costruttore di copia
namespace Mynamespace {

class Persona {
	
	friend istream & operator>>(istream &, Persona &);
	friend ostream & operator<<(ostream &, const Persona &);
	
	private:
	char * nome;
	char * cognome;
	int eta;
	
	protected:
		virtual ostream & print(ostream & out) const;
	
	public:
		Persona();
		Persona(const char *, const char *, const int);
		Persona(const Persona &);  //costruttore di copia
		const Persona & operator=(const Persona &);
		virtual ~Persona(); //distruttore
		void set_C(const char *);
		const char * get_C() const; // torna un puntatore!
	    bool operator==(const Persona &) const;
};
}
#endif
