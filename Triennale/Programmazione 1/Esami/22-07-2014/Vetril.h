#ifndef VETRIL_H
#define VETRIL_H

#include "Vettore.h"
#include <fstream>
using std::ifstream;
using std::ios;

namespace Mynamespace{
class Vetril:public Vettore{
	private:
	char * Periodo;
	
	public:
	Vetril(int = 0, const char * = "");
	Vetril(const Vetril &);
	const Vetril & operator =(const Vetril &);
	void Carica_Tmax(const char *);
	void Carica_Tmin(const char *);
	float MedieT() const;
	virtual ~Vetril(){delete [] Periodo;}
	
};
}

#endif
