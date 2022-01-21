#ifndef DERIVATI_H
#define DERIVATI_H

#include "Persona.h"
namespace Mynamespace{
	class Genitore:public Persona{
		private:
		char * Sesso;
		int NumFigli;
		
		protected:
		istream & read(istream &);
		ostream & print(ostream & out) const{return Persona::print(out) <<' ' <<Sesso <<' ' <<NumFigli;}
		
		public:
		Genitore(const char * ="", const char * ="", const char * ="****************", const int = 0,const char * ="", const int = 0);
		Genitore(const Genitore &);
		const Genitore & operator =(const Genitore &);
		const char * get_Sesso() const {return Sesso;}
		int get_NumFigli() const {return NumFigli;}		
		void set_Sesso(const char *);
		void set_NumFigli(const int nf){NumFigli=nf;}	
		~Genitore(){delete [] Sesso;}
		
		friend istream & operator >> (istream & in, Genitore & G){return G.read(in);}
		friend ostream & operator << (ostream & out, const Genitore & G){return G.print(out);}
			
			
			
	};
}

#endif

