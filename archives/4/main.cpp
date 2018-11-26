#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "guerrier.h"
#include "oeuf.h"
#include "poulet.h"
#include "panda.h"
#include "autruche.h"
#include "superpoulet.h"

using namespace std;

int main()
{
    int poulets = 0;
    int pandas = 0;
    int autruches = 0;

    cout << "Bienvenue à la baston!" << endl;
    cout << "Combien de poulets voulez-vous créer?" << endl;
    cin >> poulets;
    cout << "Combien de pandas voulez-vous créer?" << endl;
    cin >> pandas;
    cout << "Combien d'autruches voulez-vous créer?" << endl;
    cin >> autruches;

    std::vector<poulet*> liste_poulets;
    for(int i = 0; i < poulets; i++)
    {
        stringstream ss;
        ss << "chicken " << i+1;
        liste_poulets.push_back(new poulet(ss.str()));
    }
    cout << "La taille du vecteur est :" << liste_poulets.size() << endl;

    cout << "La capacité du vecteur est : " << liste_poulets.capacity() << endl;

    liste_poulets.pop_back();

    cout << "La nouvelle taille du vecteur est : " << liste_poulets.size() << endl;

    liste_poulets[liste_poulets.size()-2]->cocorico();
    //poulet1 = new poulet();
    //poulet1->cocorico();
    //poulet1->couvee();

    superpoulet *poulet2;
    poulet2 = new superpoulet();
    poulet2->cocorico();
    poulet2->couvee();

    panda *panda1;
    panda1 = new panda();
    panda1->adrienne();

    autruche *autruche1;
    autruche1 = new autruche();
    autruche1->cotcote();
    autruche1->couvee();

    //poulet1->prendre_decision();
    poulet2->prendre_decision();
    panda1->prendre_decision();
    autruche1->prendre_decision();

    //poulet1->attaquer(*poulet2);
    panda1->attaquer(*poulet2);
    autruche1->attaquer(*poulet2);

    //delete poulet1;
    delete panda1;
    delete autruche1;

    return 0;
}