#include <time.h>
#include <stdlib.h>

#include "guerrier.h"
#include "oeuf.h"
#include "poulet.h"

using namespace std;

    poulet::poulet() : guerrier("Ginger", 10, 1, 1), oeuf(1)
    {
        cout << "Le poulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    poulet::poulet(string nom) : guerrier(nom, 10, 1, 1), oeuf(1)
    {
        cout << "Le poulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    void poulet::cocorico()
    {
        cout << guerrier::getNom() << " se redresse et hurle: Coco-ricoooooooooooooo!! " << endl;
    }