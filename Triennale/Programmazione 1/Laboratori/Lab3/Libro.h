#ifndef LIBRO_H
#define LIBRO_H

#include "Oggetto.h"

namespace Mynamespace{
	class Libro:public Oggetto{
		private:
		int NumPagine;
		char * Titolo;
		
		protected:
		istream & read(istream &);
		ostream & print(ostream & out) const {return Oggetto::print(out) <<' ' << NumPagine << ' ' << Titolo;}
		
		public:
		Libro();
		Libro(int,const char *,int,const char*);
		Libro(const Libro &);
		const Libro & operator =(const Libro &);
		bool operator == (const Libro & L) const {return ( Oggetto::operator==(L) && NumPagine==L.NumPagine && !strcmp(Titolo,L.Titolo));}
		int get_NumPagine() const {return NumPagine;}
		const char * get_Titolo() const {return Titolo;}
		void set_NumPagine(const int N){NumPagine=N;}
		void set_Titolo(const char *);
		virtual ~Libro(){delete [] Titolo;}
		
		friend istream & operator >>(istream & in, Libro & L){return L.read(in);}
		friend ostream & operator <<(ostream & out, const Libro & L){return L.print(out);}

	};
}
#endif
