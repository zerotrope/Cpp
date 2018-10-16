#include "vehicule.h"
using namespace std;

    // CONSTRUCTEURS
    vehicule::vehicule()
    {
        cout << "Construction " << endl;
        vehicule::roues = 4;
        vehicule::sieges = 4;
        vehicule::portes = 5;
        vehicule::vitesse = 50;
        vehicule::nom = "nouveau_vehicule";
    }

    vehicule::vehicule(int _roues, int _vitesse, string _nom)
    {
        cout << "Construction " << endl;
        vehicule::vitesse = _vitesse;
        vehicule::nom = _nom;
        vehicule::roues = _roues;
        if(_roues <= 2)
        {
            vehicule::sieges = 2;
            vehicule::portes = 0;
        }
        else
        {
            vehicule::sieges = 4;
            vehicule::portes = 5;
        }
    }

    // DESTRUCTEUR
    vehicule::~vehicule()
    {
        cout << nom << " se prend un mur et est détruit " << endl;
    }

    // METHODES
    void vehicule::avancer()
    {
        if (roues <= 2)
            vitesse = vitesse * 2;
        cout << nom << " va à " << vitesse << " km/h" << endl;
    }

    void vehicule::setNom(string nom)
    {
        vehicule::nom = nom;
    }

    void vehicule::setVitesse(int nouvelle)
    {
        if(nouvelle < 0)
            nouvelle = 90;
        vehicule::vitesse = nouvelle;
    }

    void vehicule::setRoues(int nouvelle)
    {
        if(nouvelle < 0 || nouvelle >= 10)
            nouvelle = 3;
        vehicule::roues = nouvelle;
    }