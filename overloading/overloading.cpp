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

		bool operator==(calcul const& x) // x is "the other side"
		{
			cout << "operator== vs class attributes" << endl;
			if((a+b) == (x.get_a()+x.get_b()))
			{
				return true;
			}
			return false;
		}

		bool operator>(calcul const& x)
		{
			cout << "operator> vs class attributes" << endl;
			if((a+b) > (x.get_a()+x.get_b()))
			{
				return true;
			}
			return false;
		}

		bool operator>(int const& x)
		{
			cout << "operator> vs const int" << endl;
			if((a+b) > x)
			{
				return true;
			}
			return false;
		}

		int get_a() const;
		int get_b() const;
};

bool operator>(int const& gauche, calcul const& droite)
{
	cout << "type int operator> to type calcul?" << endl;
	if(gauche > (droite.get_a() + droite.get_b()))
	{
		return true;
	}
	return false;
}

/* Impossible case bacause at least one element of type class (own type, ie here "calcul" type) non-generic is required.
int operator+(int const& left, int const& right)
{
	cout << "cheating maths test?" << endl;
	return(gauche * droite);
}
*/
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

	calcul titi(250,3);
	//calcul *titi;
	//titi = new calcul(6,3);

	// par défaut "==" vérifie si les pointeurs pointent vers la même adresse
	if(titi == toto) // equivalent à : titi.operator==(toto)
	{
		cout << "Titi equals Toto" << endl;
	}
	else
	{
		cout << "Titi does not equal Toto" << endl;
	}

	if(titi > toto)
	{
		cout << "Titi greater than Toto" << endl;
	}
	else
	{
		cout << "Titi smaller than Toto" << endl;
	}

	// si Titi > 250 alors afficher "Titi est superieur a 250"
	// Check addition de a et b si > 250
	int value = 250;

	if(value > titi)
	{
		cout << "Titi greater than 250" << endl;
	}
	else
	{
		cout << "Titi smaller than 250" << endl;
	}
}
