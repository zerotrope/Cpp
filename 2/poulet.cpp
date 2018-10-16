#include <time.h>
#include <stdlib.h>

#include "guerrier.h"
#include "poulet.h"

using namespace std;

    // Constructeur surchargé guerrier pour remplir constructeur par défaut poulet
    poulet::poulet() : guerrier("Poulette", 10, 1, 1)
    {
        cout << "Le poulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    // Constructeur surchargé guerrier avec nom en input pour remplir constructeur surcharé du poulet
    poulet::poulet(string nom) : guerrier(nom, 10, 1, 1)
    {
        cout << "Le poulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    void poulet::cocorico()
    {
        cout << guerrier::getNom() << " Coco-ricoooooooooooooo!! " << endl;
    }