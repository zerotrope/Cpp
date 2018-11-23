#ifndef _VEHICULE_H_
#define _VEHICULE_H_

#include <iostream>
#include <string>

class vehicule
{
    // TOUS les attributs dans une classe sont privés!! (sécu, convention, nécessité)
    private:
    int roues;
    int sieges;
    int vitesse;
    int portes;
    std::string nom;

    public:
    // CONSTRUCTEURS
    vehicule();
    vehicule(int _roues, int _vitesse, std::string _nom);
    //vehicule(const vehicule &);

    // DESTRUCTEUR
    ~vehicule();

    // METHODES
    void avancer();
    void setNom(std::string nom);
    void setVitesse(int nouvelle);
    void setRoues(int nouvelle);
};

#endif