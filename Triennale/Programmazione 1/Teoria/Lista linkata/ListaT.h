#ifndef LISTA_H
#define LISTA_H

#include <iostream>
#include <string>
using namespace std;

namespace Mynamespace {
    
typedef string T;

struct Nodo;

class Lista {

   private:    
    
   struct Nodo { 
    T elem;
    Nodo * next; 
    }; 
   Nodo * testa;
   bool push(const T &);
   bool pop(T &);


public:
    Lista() {testa=0;}
	bool insert(const T &);
	bool remove(const T &);
	bool inList(const T &) const;
	int  lenght() const;  // calcola il numero di elementi corrente
    bool empty() const {return testa==0;}
    bool full()  const {return false;}
    bool print() const;
    ~Lista();
    friend ostream & operator << (ostream &, const Lista &);
    
};     
}

#endif

