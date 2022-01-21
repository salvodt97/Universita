#include <iostream>
#include <stdlib.h>
#include "ListaT.h"
using namespace std;
using namespace Mynamespace;

int main(int argc, char *argv[])
{
  Lista L;
  T E;
  
 
  L.insert("ggg");
  L.insert("ccc");
  cout << "Lista: ";
  //L.print();
  cout << L;
  L.insert("bbb");
  L.insert("ddd");
  cout << "\n";
  cout << "Lista: ";
  //L.print();
  cout << L;
  cout << "\n";
  
  L.insert("ppp");
  cout << "Lista: ";
  //L.print();
  cout << L;
  cout << "\n";
  L.insert("aaa");
  cout << "Lista: ";
  //L.print();
  cout << L;
  cout << "\n";
  
  cout << "\n";
  if(L.inList("eee")) cout << "elemento presente!" << endl;
  else cout << "elemento non presente" << endl;
  if(L.inList("ggg")) cout << "elemento presente!" << endl;
  else cout << "elemento non presente" << endl;
  cout << "numero di elementi in lista: " << L.lenght() << endl;
  cout << "\n";
  
  if(L.remove("ppp")) cout << "elemento rimosso" << endl;
  else cout << "elemento rimosso" << endl;
  cout << L;
  cout << "\n";
  cout << "numero di elementi in lista: " << L.lenght() << endl;
  cout << "\n";
  
  system("PAUSE");	
  return 0;
}
