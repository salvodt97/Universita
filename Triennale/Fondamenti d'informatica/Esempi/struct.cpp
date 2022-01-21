#include <iostream>
#include <cstdlib>
using namespace std;

struct point{
  int x;
  int y;
};

// Dichiarazione del vettore al posto 
// della struttura:
// typedef int point[2];  

int main(){
	
  point p1,p2;       
  
  p1.x=3;
  p1.y=2;
  p2=p1;  // equivale a p2.x=p1.x;
          //            p2.y=p1.y;
 
  cout << "\nDimensione in byte del tipo point: " << sizeof(point) << "\n\n";
  cout << "Coordinate di p1: " << p1.x << ' ' << p1.y << '\n';
  cout << "Coordinate di p2: " << p2.x << ' ' << p2.y << "\n\n";

  /*
   .--------.q
   |         |   Rettangolo definito da una coppia di punti (p,q)
   p.--------.
  */
      
  struct rect{
    point p;
    point q;
  }r;
  
  r.p.x=2;
  r.p.y=3;
  r.q.x=4;
  r.q.y=5;
             
  cout << "Coordinate del rettangolo: ";    
  cout << r.p.x << ' ' << r.p.y << ' ' << r.q.x << ' ' << r.q.y << '\n';
    
  system("PAUSE");
  return 0; 
}
