#ifndef OGGETTO_H
#define OGGETTO_H

#include <iostream>
#include <cstring>
#include <cstdlib>

using std::istream;
using std::ostream;

namespace Mynamespace{
	class Oggetto{
		private:
		int Codice;
		char * Descrizione;
		
		protected:
		istream & read(istream &);
		ostream & print(ostream & out) const {return out << Codice <<' ' <<Descrizione;}
		
		public:
		Oggetto();
		Oggetto(int,const char*);
		Oggetto(const Oggetto &);
		const Oggetto & operator =(const Oggetto &);
		bool operator == (const Oggetto & O) const {return (Codice==O.Codice && !strcmp(Descrizione,O.Descrizione));}
		int get_Codice() const {return Codice;}
		const char * get_Descrizione() const {return Descrizione;}
		void set_Codice(const int C){Codice=C;}
		void set_Descrizione(const char *);
		virtual ~Oggetto(){delete [] Descrizione;}
		
		friend istream & operator >>(istream & in, Oggetto & O){return O.read(in);}
		friend ostream & operator <<(ostream & out, const Oggetto & O){return O.print(out);}

	};
}
#endif
