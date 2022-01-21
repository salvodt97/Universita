#include <iostream>
#include "ListaT.h"

using namespace std;

namespace Mynamespace {
    
bool Lista::push(const T& e){
    if(full() || inList(e)) return false;
    Nodo * q;
    q=new Nodo;
    q->elem=e;
    q->next=testa;
    testa=q;
    return true;
}

// insert versione iterativa
bool Lista::insert(const T & e) {
   if(full() || inList(e)) return false;
   if(testa==0 || testa->elem>e) {push(e); return true;} //l'elemento va inserito in testa  
    //l'elemento va inserito al centro o in coda
      Nodo * prec=testa, * succ;                            
    //alloca ed inizializza il nuovo elemento
      Nodo * q=new Nodo;
      q->elem=e;
      q->next=0;  
      while(prec->next && prec->next->elem<e ) prec=prec->next; //determina prec
      succ=prec->next; //determina succ, se l'inserimento è in coda succ deve valere 0
      // collega il nuovo elemento al resto della lista (anche in coda se è il caso)
      q->next=succ;
      prec->next=q;
      return true;
}
 
bool Lista::pop(T & e){
     if(empty()) return false;
     Nodo * temp=testa; 
     e=testa->elem;
     testa=testa->next;
     delete temp;
     return true;   
 }

 
bool Lista::remove(const T & e) {
    if(empty()|| !inList(e)) return false;
    if(testa->elem==e) {T c; pop(c); return true;}
    //Se l'elemnto non sta in testa:
    Nodo * temp=testa;
    while(temp->next->elem !=e) temp=temp->next;
    Nodo * q=temp->next;
    temp->next=temp->next->next;
    delete q;
    return true;
}     
       
bool Lista::inList(const T & e) const {
    bool trovato=false;
    Nodo * temp=testa;
    while(temp && !trovato)
      if(temp->elem == e)
        trovato=true;
      else temp=temp->next;
    return trovato;    
}

int Lista::lenght() const{
    int count =0;
    Nodo * temp=testa;
    while(temp) {count++; temp=temp->next;} 
    return count;   
}
   
Lista::~Lista(){            
   Nodo * temp;
   while(testa){
     temp=testa; 
     testa = testa->next;
     delete temp;
}
}
 
bool Lista::print() const       
 {   if (empty()) return false;
     else {
     Nodo * temp= testa;
     while(temp) {
       cout << temp->elem << "\t";
       temp=temp->next;
     }      
   }   
   return true; 
 }
 
 
ostream & operator << (ostream & out, const Lista & L) {
     Lista::Nodo * temp= L.testa;
     while(temp) {
       out << temp->elem << "\t";
       temp=temp->next; }  
    return out;
}
 
 
} 
