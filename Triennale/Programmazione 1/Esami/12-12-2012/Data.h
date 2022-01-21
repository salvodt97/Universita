#ifndef DATA_H
#define DATA_H

using std::istream;
using std::ostream;

namespace Mynamespace{
class Data{
	private:
	int giorno;
	int mese;
	int anno;
	
	public:
	Data(int g=0, int m=0, int a=0){giorno=g; mese=m; anno=a;}
	int get_giorno() const {return giorno;}
	int get_mese() const {return mese;}
	int get_anno() const {return anno;}
	void set_giorno(int g) {giorno=g;}
	void set_mese(int m) {mese=m;}
	void set_anno(int a) {anno=a;}
	
	friend istream & operator >>(istream & in, Data & D){return in >>D.giorno >>D.mese >>D.anno;}
	friend ostream & operator <<(ostream & out, const Data & D){return out <<"(" <<D.giorno <<"-" <<D.mese <<"-" <<D.anno <<")";}
};
}


#endif
