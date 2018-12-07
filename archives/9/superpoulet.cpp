#include <time.h>
#include <stdlib.h>

#include "guerrier.h"
#include "oeuf.h"
#include "poulet.h"
#include "superpoulet.h"

using namespace std;

    superpoulet::superpoulet() : poulet("SuperChickenRun", 1000)
    {
        cout << "Le Superpoulet " << guerrier::getNom() << " a été créé!" << endl;
    }

    superpoulet::superpoulet(string nom) : poulet(nom, 1000)
    {
        cout << "Le Superpoulet " << guerrier::getNom() << " a été créé!" << endl;
    }