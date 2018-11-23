#include <time.h>
#include <stdlib.h>

#include "guerrier.h"
#include "oeuf.h"
#include "autruche.h"

using namespace std;

    autruche::autruche() : guerrier("Hortense", AUTRUCHE, 50, 20, 10), oeuf(4)
    {
        //cout << "L'autruche " << guerrier::getNom() << " a été créée!" << endl;
    }

    autruche::autruche(string nom) : guerrier(nom, AUTRUCHE, 50, 20, 10), oeuf(3)
    {
        //cout << "L'autruche " << guerrier::getNom() << " a été créée!" << endl;
    }

    void autruche::cotcote()
    {
        cout << guerrier::getNom() << " se redresse et hurle: Cot-coooooooooooote!! " << endl;
    }

    void autruche::prendre_decision()
    {
        int random = rand()%100;
        if(random >= 50)
        {
            guerrier::setDefending(true);
        }
        else
        {
            guerrier::setDefending(false);
        }
        if(guerrier::isDefending() == true)
        {
            cout << guerrier::getNom() << " se défend avec ses plumes!" << endl;
        }
        else
        {
            cout << guerrier::getNom() << " attaque avec ses serres (" << guerrier::getForce() << " points de force)" << endl;
        }
    }

    string autruche::blabla()
    {
        return("blabla_autruche");
    }