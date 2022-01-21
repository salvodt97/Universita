#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>
#include <cstring>
#include <cstdlib>

const int N=16;
using std::istream;
using std::ostream;


namespace Mynamespace{
	class Persona{
		private:
		char * Nome;
		char * Cognome;
		char CF[N+1];
		int Eta;
		
		protected:
		istream & read(istream &);
		ostream & print(ostream & ) const;
		
		public:
		Persona(const char * ="", const char * ="", const char * ="****************", const int = 0);
		Persona(const Persona &);
		const Persona & operator =(const Persona &);
		const char * get_Nome() const {return Nome;}
		const char * get_Cognome() const {return Cognome;}
		const char * get_CF() const {return CF;}
		int get_Eta() const {return Eta;}		
		void set_Nome(const char *);
		void set_Cognome(const char *);
		void set_CF(const char * cf){strcpy(CF,cf);}
		void set_Eta(const int E){Eta=E;}	
		bool controllo_Eta() const {return (Eta>=0 && Eta<=120);}
		bool controllo_CF() const;
		~Persona(){delete [] Nome; delete [] Cognome;}
		
		friend istream & operator >> (istream & in, Persona & P){return P.read(in);}
		friend ostream & operator << (ostream & out, const Persona & P){return P.print(out);}
			
		
			
			
	};
}








#endif

