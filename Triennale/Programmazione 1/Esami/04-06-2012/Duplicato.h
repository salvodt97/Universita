#ifndef DUPLICATO_H
#define DUPLICATO_H

#include <iostream>
#include <string>
using std::string;

class Duplicato{
	private:
	string msg;
	int valore;
	
	public:
	Duplicato(const string & m="Errore", int v=0){msg=m; valore=v;}
	string what() const {return msg;}
	int get_valore() const {return valore;}
};

#endif
