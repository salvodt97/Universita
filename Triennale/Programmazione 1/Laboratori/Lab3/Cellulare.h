#ifndef CELLULARE_H
#define CELLULARE_H

#include "Oggetto.h"

namespace Mynamespace{
	class Cellulare:public Oggetto{
		private:
		float Costo;
		char * Modello;
		
		protected:
		istream & read(istream &);
		ostream & print(ostream & out) const {return Oggetto::print(out) <<' ' << Costo << ' ' << Modello;}
		
		public:
		Cellulare();
		Cellulare(int,const char *,float,const char*);
		Cellulare(const Cellulare &);
		const Cellulare & operator =(const Cellulare &);
		bool operator == (const Cellulare & C) const {return ( Oggetto::operator==(C) && Costo==C.Costo && !strcmp(Modello,C.Modello));}
		float get_Costo() const {return Costo;}
		const char * get_Modello() const {return Modello;}
		void set_Costo(const int C){Costo=C;}
		void set_Modello(const char *);
		virtual ~Cellulare(){delete [] Modello;}
		
		friend istream & operator >>(istream & in, Cellulare & C){return C.read(in);}
		friend ostream & operator <<(ostream & out, const Cellulare & C){return C.print(out);}

	};
}
#endif
