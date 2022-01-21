#ifndef INSIEME_H
#define INSIEME_H

#include "Oggetto.h"
#include <iostream>
#include <cstring>
#include <cstdlib>

using std::istream;
using std::ostream;
const int MAX=100;

namespace Mynamespace{
	typedef Oggetto T;
	
	class Insieme{
		friend istream & operator >> (istream &, Insieme &);
		friend ostream & operator << (ostream &, const Insieme &);
		
		private:
		int dim;
		T vett[MAX];
		
		public:
		Insieme(const int n = 0){dim=n;}
		T & operator [] (const int i ){return vett[i];}
		const T & operator [] (const int i) const {return vett[i];}
		int get_dim()const {return dim;}
		bool in(const T &);
	};
	
	
	
	
	
	
}






#endif
