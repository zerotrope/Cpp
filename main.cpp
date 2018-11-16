#include <iostream>
#include <string>
using namespace std;

// Template de class
// .h
template<typename X> class calcul
{
	private:
		X a;
		X b;

	public:
		calcul();
		calcul(X _a, X _b);

		X addition();
		X multiplication();
		X soustraction();
};

// .cpp
template <typename X> calcul<X>::calcul() 
{
	a = 0;
	b = 0;
}

template <typename X> calcul<X>::calcul(X _a, X _b)
{
	a = _a;
	b = _b;
}

template <typename X> X calcul<X>::addition()
{
	return a + b;
}

template <typename X> X calcul<X>::multiplication()
{
	return a * b;
}

template <> std::string calcul<std::string>::multiplication()
{
	return "ça ne marche pas";
}

template <typename X> X calcul<X>::soustraction()
{
	return a - b;
}

// Template de fonction
template<typename X> X division(X a, X b)
{
	cout << "je passe par ici" << endl;
	if(b == 0)
	{
		return NULL;
	}
	return a/b;
}

// Surchage de fonction type std::string


// Surcharge de fonction type double
double division(int a, int b)
{
	cout << "je passe par là" << endl;
	if(b == 0)
	{
		return 0.0;
	}
	return ((double)a)/((double)b);
}

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