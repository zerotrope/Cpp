#include <iostream>
#include <string>
using namespace std;

template<typename X> class calcul
{
	private:
		X a;
		X b;

	public:
		calcul()
		{
			a = 0;
			b = 0;
		}
		calcul(X _a, X _b)
		{
			a = _a;
			b = _b;
		}
	X addition()
	{
		return a + b;
	}
	X multiplication()
	{
		return a * b;
	}
	X soustraction()
	{
		return a - b;
	}
};

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

	return 0;
}