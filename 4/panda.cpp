#include <time.h>
#include <stdlib.h>

#include "guerrier.h"
#include "panda.h"

using namespace std;

    panda::panda() : guerrier("Po Ping", 100, 10, 20)
    {
        cout << "Le panda " << guerrier::getNom() << " a été créé!" << endl;
    }

    panda::panda(string nom) : guerrier(nom, 100, 10, 20)
    {
        cout << "Le panda " << guerrier::getNom() << " a été créé!" << endl;
    }

    void panda::adrienne()
    {
        cout << guerrier::getNom() << " se redresse et hurle: Kung Fuuu YAAAAA! " << endl;
    }

void panda::prendre_decision()
{
    guerrier::prendre_decision();
    guerrier::setDefending(!guerrier::isDefending());
    if(guerrier::isDefending() == true)
    {
        cout << "J'men fout je suis un panda je fais ce que je veux, JE DEFENDS!! " << endl;
        cout << endl;
        //guerrier::setDefending(false);
    }
    else
    {
        cout << "J'men fout je suis un panda je fais ce que je veux, J'ATTAQUE!! " << endl;
        cout << endl;
        //guerrier::setDefending(true);
    }
}