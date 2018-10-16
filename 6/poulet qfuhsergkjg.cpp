#include <time.h>
#include <stdlib.h>

#include "guerrier.h"
#include "oeuf.h"
#include "poulet.h"

using namespace std;

    poulet::poulet() : guerrier("Ginger", Type::POULET, 10, 1, 1), oeuf(2)
    {
        cout << "Le poulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    poulet::poulet(string nom) : guerrier(nom, POULET, 10, 1, 1), oeuf(1)
    {
        cout << "Le poulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    poulet::poulet(string nom, int vie) : guerrier(nom, POULET, vie, 1, 1)
    {
        cout << "Le poulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    void poulet::cocorico()
    {
        cout << guerrier::getNom() << " se redresse et hurle: Coco-ricoooooooooooooo!! " << endl;
    }

    void poulet::prendre_decision()
    {
        cout << "Je suis passé par là" << endl;
    }

    string poulet::blabla()
    {
        return("blabla");
    }