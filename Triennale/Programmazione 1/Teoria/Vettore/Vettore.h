#ifndef _VETTORE_H
#define _VETTORE_H

#include <iostream>

using namespace std;

typedef int T;

class Vettore {
	
	friend ostream & operator<<(ostream &, const Vettore &);
	friend istream & operator>>(istream &, Vettore &);
	
	private:
		T* Vet;
		int dim;
	public:
	   Vettore(const int =10);	
	   Vettore(const Vettore &);
	   const Vettore & operator=(const Vettore &);
	   T & operator[](const int);
	   const T & operator[](const int) const;
	   int get_dim() const {return dim;}
	   ~Vettore() {delete [] Vet;}
};


#endif
