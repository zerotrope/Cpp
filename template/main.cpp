#include <iostream>
#include <string>
#include "template.h"

using namespace std;

int main()
{
	calcul<int> *toto;
	toto = new calcul<int>(5,6);
	cout << toto->multiplication() << endl;

	calcul<float> *titi;
	titi = new calcul<float>(5.2,9.4);
	cout << titi->multiplication() << endl;

	calcul<std::string> *tutu;
	tutu = new calcul<std::string>("un", "deux");
	cout << tutu->multiplication() << endl;

	double tata = division(1.0,2.0);
	cout << tata << endl;

	return 0;
}
