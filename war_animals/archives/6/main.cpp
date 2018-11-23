#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <stdlib.h>

#include "time.h"
#include "guerrier.h"
#include "oeuf.h"
#include "poulet.h"
#include "panda.h"
#include "autruche.h"
#include "superpoulet.h"

using namespace std;

void team_creation(int n, int a, int b, int c);

int main()
{
    int k = 0;
    int i = 0;

    /*
    guerrier *monguerrier;
    monguerrier = new poulet("Toto");
    poulet monpoulet;

    monguerrier->prendre_decision();
    //monpoulet.prendre_decision();
    monguerrier->attaquer(monpoulet);

    // Cast
    ((poulet*)(monguerrier))->cocorico();
    */


    /*std::vector<guerrier*> team_A;
    cout << "Combien de poulets voulez-vous intégrer à votre équipe?" << endl;
    cin >> k;
    stringstream ss;
    // EXERCICE : k ne doit pas dépasser la capacité (capacity max) de stockage du vecteur (max)
    for (i=0; i<k; i++)
    {
        //stringstream ss;
        ss << "Poulet_" << i+1;
        team_A.push_back(new poulet(ss.str()));
        ss.str("");
    }
    cout << "Combien de pandas voulez_vous intégrer à votre équipe?" << endl;
    cin >> k;
    for (i=0; i<k; i++)
    {
        //stringstream ss;
        ss << "Panda_" << i+1;
        team_A.push_back(new panda(ss.str()));
        ss.str("");
    }
    cout << "Combien d'autruches voulez_vous intégrer à votre équipe?" << endl;
    cin >> k;
    for (i=0; i<k; i++)
    {
        //stringstream ss;
        ss << "Autruche_" << i+1;
        team_A.push_back(new autruche(ss.str()));
        ss.str("");
    }
    cout << team_A.size() << endl;*/
    team_creation(2,5,5,5);

    // lorsqu'on créé la teamA_temp on réamorce le constructeur de la classe team
    // Attention aux cout sur constructeurs, parfois ne peut plus se permettre
    team teamA_temp;
    teamA_temp = teamA;
    teamB->atomisation(teamA);

    return 0;
}

void team_creation(int n, int a, int b, int c)
{
    int k = 0;
    int i = 0;
    stringstream ss;

    for(i=0; i<n; i++)
    {
        std::vector<guerrier*> team;
        for (i=0; i<a; i++)
        {
            ss << "Poulet_" << i+1;
            team.push_back(new poulet(ss.str()));
            ss.str("");
        }
        for (i=0; i<b; i++)
        {
            ss << "Panda_" << i+1;
            team.push_back(new panda(ss.str()));
            ss.str("");
        }
        for (i=0; i<c; i++)
        {
            ss << "Autruche_" << i+1;
            team.push_back(new autruche(ss.str()));
            ss.str("");
        }
        cout << team.size() << endl;
    }
}