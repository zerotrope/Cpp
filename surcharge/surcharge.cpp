#include <iostream>
#include <string>

using namespace std;

class calcul
{
	private:
		int a;
		int b;

	public:
		calcul();
		calcul(int _a, int _b);

		bool operator==(calcul const& x) // x est "l'autre coté"
		{
			cout << "coucou == vs class attributes" << endl;
			if((a+b) == (x.get_a()+x.get_b()))
			{
				return true;
			}
			return false;
		}

		bool operator>(calcul const& x)
		{
			cout << "coucou > vs class attributes" << endl;
			if((a+b) > (x.get_a()+x.get_b()))
			{
				return true;
			}
			return false;
		}

		bool operator>(int const& x)
		{
			cout << "coucou > vs const int" << endl;
			if((a+b) > x)
			{
				return true;
			}
			return false;
		}

		int get_a() const;
		int get_b() const;
};

int calcul::get_a() const
{
	return calcul::a;
}

int calcul::get_b() const
{
	return calcul::b;
}

calcul::calcul()
{
	a = 0;
	b = 0;
}

calcul::calcul(int _a, int _b)
{
	a = _a;
	b = _b;
}

int main()
{
	calcul toto(4,6);
	//calcul *toto;
	//toto = new calcul(3,6);

	calcul titi(16,3);
	//calcul *titi;
	//titi = new calcul(6,3);

	// par défaut "==" vérifie si les pointeurs pointent vers la même adresse
	if(titi == toto) // equivalent à : titi.operator==(toto)
	{
		cout << "Titi est egal a Toto" << endl;
	}
	else
	{
		cout << "Titi n'est pas egal Toto" << endl;
	}

	if(titi > toto)
	{
		cout << "Titi superieur a Toto" << endl;
	}
	else
	{
		cout << "Titi inferieur a Toto" << endl;
	}

	// si Titi > 250 alors afficher "Titi est superieur a 250"
	// Check addition de a et b si > 250

	if(titi > 250)
	{
		cout << "Titi superieur a 250" << endl;
	}
	else
	{
		cout << "Titi inferieur a 250" << endl;
	}
}
