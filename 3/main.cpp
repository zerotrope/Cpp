#include <iostream>
#include <string>

#include "guerrier.h"
#include "oeuf.h"
#include "poulet.h"
#include "panda.h"
#include "autruche.h"

using namespace std;

int main()
{
    poulet *poulet1;
    poulet1 = new poulet();
    poulet1->cocorico();
    poulet1->couvee();

    panda *panda1;
    panda1 = new panda();
    panda1->adrienne();

    autruche *autruche1;
    autruche1 = new autruche();
    autruche1->cotcote();

    poulet1->prendre_decision();
    panda1->prendre_decision();
    autruche1->prendre_decision();

    poulet1->attaquer(*panda1);
    panda1->attaquer(*autruche1);
    autruche1->attaquer(*panda1);

    delete poulet1;
    delete panda1;
    delete autruche1;

    return 0;
}