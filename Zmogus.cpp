#include "Zmogus.h"

#include<string>
#include<vector>
#include<algorithm>
#include<fstream>

using namespace std;

Zmogus::Zmogus(istream& is) {
	is >> vardas;
	is >> pavarde;
}

Zmogus::Zmogus(const Zmogus& zmogus) {
	vardas = zmogus.vardas;
	pavarde = zmogus.pavarde;
}
