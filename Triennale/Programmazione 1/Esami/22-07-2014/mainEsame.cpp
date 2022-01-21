#include "Rilevamenti.h"
#include "Vetril.h"

using namespace Mynamespace;
using std::cin;
using std::cout;

int main(int argc, char** argv) {
	Rilevamento R;
	int a, m, g, tmax, tmin;
	cout <<"Inserire i dati del rilevamento:\n";
	cin >> R >> a >> m >> g >> tmax >> tmin;
	R.set_Anno(a);
	R.set_Tmax(tmax);
	R.set_Tmin(tmin);
	
	try{
		R.set_Mese(m);
		R.set_Giorno(g);
		cout <<"Il Rilevamento e': " <<R;
	}
	catch(Eccezione a){
		cout <<"\n" << a.what() <<" " << a.get_valore();
	}

	/*Vetril v;
	v.Carica_Tmin("Tmin.txt");
	v.Carica_Tmax("Tmax.txt");
	cout << "La media e': " <<v.MedieT();*/
	
	
	return 0;
}
