#include "Insieme.h"
#include <iostream>

using namespace Mynamespace;
using std::cin;
using std::cout;

int main(int argc, char** argv) {
	Insieme I1;
	Insieme I2;
	cin >> I1 >> I2;
	 cout <<I1.operator +(I2);
	return 0;
}
