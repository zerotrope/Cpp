#include <iostream>
#include <string>

#include "guerrier.h"
#include "poulet.h"

using namespace std;

int main()
{
    poulet *poupou;
    poupou = new poulet();
    poupou->cocorico();

    guerrier *panda;
    panda = new guerrier("Jack", 100, 10, 20);

    poupou->prendre_decision();
    panda->prendre_decision();

    poupou->attaquer(*panda);
    panda->attaquer(*poupou);

    delete poupou;
    delete panda;

    return 0;
}