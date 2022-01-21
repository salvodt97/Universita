#include <iostream>
#include "Pila1_classeAI.h"
using namespace Mynamespace;

using std::cin;
using std::cout;
using std::endl;
const int dim=10;

int main(int argc, char** argv) {
	
    Pila p1, p2;
    T elem;
    Persona P1("Mario", "Rossi", 4);
    Persona P2("Luca", "Rossi", 45);
    Persona P3("Laura", "Rossi", 37);

   
    if(p1.push(P1)) cout << "elemento inserito" << endl;
    else cout << "pila piena!" << endl;
    if(p1.push(P2)) cout << "elemento inserito" << endl;
    else cout << "pila piena!" << endl;
    if(p1.push(P3)) cout << "elemento inserito" << endl;
    else cout << "pila piena!" << endl;
    
     if(p1.top(elem)) cout << "elemento di testa: " << elem << endl;
    else cout << "pila vuota!" << endl;
    
    
    if(p1.pop(elem)) cout << "elemento estratto: " << elem << endl;
    else cout << "pila vuota!" << endl;
     if(p1.pop(elem)) cout << "elemento estratto: " << elem << endl;
    else cout << "pila vuota!" << endl;
     if(p1.pop(elem)) cout << "elemento estratto: " << elem << endl;
    else cout << "pila vuota!" << endl;
     if(p1.pop(elem)) cout << "elemento estratto: " << elem << endl;
    else cout << "pila vuota!" << endl;
    
    
	
	return 0;
}


