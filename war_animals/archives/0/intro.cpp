#include <stdio.h>
#include <stdlib.h>

#include <iostream>

using namespace std;

class vehicule
{
    int roues;
    int sieges;
    int vitesse;
    int portes;
    void avancer()
    {
        if (roues <= 2)
            vitesse = vitesse * 2;
        cout << "Je vais à " << vitesse << " km/h" << endl;
    }
};

int main()
{
    int x = 8;
    int reponse;
    printf("%i Hello World\n", x);
    cout << x << " Hello" << " World" << std::endl;

    printf("Veuillez rentrer une valeur : \n");
    scanf("%i", &reponse);
    printf("La valeur est : %i\n", reponse);

    cout << "Veuillez rentrer une valeur : " << endl;
    cin >> reponse;
    cout << "La valeur est : " << reponse << endl;

    return 0;
}

// En cpp des fonctions font partie d'un "espace de nom" (ie. std)
// Un objet incarne une classe dans un contexte