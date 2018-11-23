#include <iostream>
#include <string>

using namespace std;

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

// fonctions templates en premier puis exceptions
template<typename X> X division(X a, X b);
double division(int a, int b);


// Dans le cas d'un template, tout doit être dans le même fichier

template<typename X> calcul<X>::calcul()
{
	a = 0;
	b = 0;
}

template<typename X> calcul<X>::calcul(X _a, X _b)
{
	a = _a;
	b = _b;
}

template<typename X> X calcul<X>::addition()
{
	return a + b;
}

template<typename X> X calcul<X>::multiplication()
{
	return a * b;
}

template<> std::string calcul<std::string>::multiplication()
{
	return "ça ne marche pas";
}

template<typename X> X calcul<X>::soustraction()
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
