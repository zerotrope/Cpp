#include <iostream>
#include <string>
#include "vehicule.h"

using namespace std;

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
    // Constructeur 'par copie'
    vehicule suzuki = kawa; // copie kawa tel qu'il a été créé plus tôt (pas pointé sur mais copié/collé)

    twingo->avancer();
    delete twingo;
    kawa.avancer();
    suzuki.avancer();

    return 0;
}