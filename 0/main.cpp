#include <iostream>
#include <string>

using namespace std;

class vehicule
{
    // TOUS les attributs dans une classe sont privés!! (sécu, convention, nécessité)
    private:
    int roues;
    int sieges;
    int vitesse;
    int portes;
    string nom;

    public:

    // CONSTRUCTEURS
    // méthode : Constructeur par défaut (sans paramètres, OBLIGATOIRE)
    vehicule()
    {
        cout << "Construction " << endl;
        vehicule::roues = 4;
        vehicule::sieges = 4;
        vehicule::portes = 5;
        vehicule::vitesse = 50;
        vehicule::nom = "nouveau_vehicule";
    }

    // méthode : constructeur surchagé (unicité déterminée par l'ordre et le nombre des variables)
    // Pas d'autre constructeur surchargé vehicule(int, int, string) puisque déjà existant
    vehicule(int _roues, int _vitesse, string _nom)
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

    // DESTRUCTEUR - ne prend jamais aucun paramètres, callé à chaque destruction d'un objet même en cas d'erreur
    // intervient au moment du kill du programme
    ~vehicule()
    {
        cout << nom << " se prend un mur et est détruit " << endl;
    }

    void avancer()
    {
        if (roues <= 2)
            vitesse = vitesse * 2;
        cout << nom << " va à " << vitesse << " km/h" << endl;
    }

    void setNom(string nom)
    {
        vehicule::nom = nom;
    }

    void setVitesse(int nouvelle)
    {
        if(nouvelle < 0)
            nouvelle = 90;
        vehicule::vitesse = nouvelle;
    }

    void setRoues(int nouvelle)
    {
        if(nouvelle < 0 || nouvelle >= 10)
            nouvelle = 3;
        vehicule::roues = nouvelle;
    }
};

int main()
{
    vehicule *twingo;
    twingo = new vehicule(4, 90, "titine"); // initialisation équivalent au malloc
    // Twingo est un nouveau vehicule surchargé de ses 3 paramètres
    /*twingo->setNom("titine");
    twingo->setRoues(4);
    twingo->setVitesse(90);*/
/*
    twingo.portes = 3;
    twingo.sieges = 3;
*/
    vehicule kawa(2, 100, "kawabunga"); // statique
    /*kawa.setNom("fuseedelespaceinfinieteternel");
    kawa.setRoues(2);
    kawa.setVitesse(200);*/
/*
    kawa.portes = 0;
    kawa.sieges = 1;
*/
    twingo->avancer();
    delete twingo;
    kawa.avancer();
    kawa.avancer();

    return 0;
}

/*
Next :
    Construction - Destruction
    Utilisation des classes
*/