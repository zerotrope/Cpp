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

int main()
{
    int poulets = 0;
    int pandas = 0;
    int autruches = 0;

    string firstname;
    //char lastname[5];

    srand(time(NULL));

    // Introduction
    cout << "Bienvenue à la baston!" << endl;
    cout << "Des combattants vont s'affronter dans l'arène, commençons..." << endl;
    cout << "Combien de poulets voulez-vous créer?" << endl;
    cin >> poulets;
    cout << "Combien de pandas voulez-vous créer?" << endl;
    cin >> pandas;
    cout << "Combien d'autruches voulez-vous créer?" << endl;
    cin >> autruches;

    // Création du vecteur poulets
    std::vector<poulet*> liste_poulets;
    for(int i=0; i<poulets; i++)
    {
        stringstream ss;
        ss << "poulet_" << i+1;
        liste_poulets.push_back(new poulet(ss.str()));

        for(int j=0; j<4; j++)
        {
            firstname = firstname + (char)('a' + rand()%25);
            //lastname[j] = 'a' + rand()%26;
        }
        cout << firstname << endl;
        //ss << firstname << " " << lastname;
        //cout << ss << endl;

    }
        // Observation du vecteur
    cout << endl;
    cout << "La taille du vecteur est : " << liste_poulets.size() << endl;
    cout << "La capacité du vecteur est : " << liste_poulets.capacity() << endl;
        // Retrait d'un poulet du vecteur
    cout << "Retrait d'un individu de l'équipe..." << endl;
    liste_poulets.pop_back();
    cout << "La nouvelle taille du vecteur est : " << liste_poulets.size() << endl;
        // Sélection d'un poulet dans le vecteur
    liste_poulets[liste_poulets.size()-2]->cocorico();

    // Création d'un unique superpoulet
    superpoulet *poulet2;
    poulet2 = new superpoulet();
    poulet2->cocorico();
    poulet2->couvee();

    // Création du vecteur pandas
    std::vector<panda*> liste_pandas;
    for(int i=0; i<pandas; i++)
    {
        stringstream ss;
        ss << "panda_" << i+1;
        liste_pandas.push_back(new panda(ss.str()));
    }
        // Observation du vecteur
    cout << endl;
    cout << "La taille du vecteur est : " << liste_pandas.size() << endl;
    cout << "La capacité du vecteur est : " << liste_pandas.capacity() << endl;
        // Retrait d'un panda du vecteur
    cout << "Retrait d'un individu de l'équipe..." << endl;
    liste_pandas.pop_back();
    cout << "La nouvelle taille du vecteur est : " << liste_pandas.size() << endl;
        // Sélection du dernier panda dans le vecteur
    liste_pandas[liste_pandas.size()]->adrienne();

    // Création du vecteur autruche
    std::vector<autruche*> liste_autruches;
    for(int i=0; i<autruches; i++)
    {
        stringstream ss;
        ss << "autruche_" << i+1;
        liste_autruches.push_back(new autruche(ss.str()));
    }
        // Observation du vecteur
    cout << endl;
    cout << "La taille du vecteur est : " << liste_autruches.size() << endl;
    cout << "La capacité du vecteur est : " << liste_autruches.capacity() << endl;
        // Retrait d'une autruche du vecteur
    cout << "Retrait d'un individu de l'équipe..." << endl;
    liste_autruches.pop_back();
    cout << "La nouvelle taille du vecteur est : " << liste_autruches.size() << endl;
        // Sélection d'une autruche dans le vecteur
    liste_autruches[liste_autruches.size()-2]->cotcote();

    // Prises de décision des groupes
    poulet2->prendre_decision();
    for (int i=0;i<liste_poulets.size();i++)
    {
        // Décision attaque ou défense
        liste_poulets[i]->prendre_decision();
        liste_pandas[i]->prendre_decision();
        liste_autruches[i]->prendre_decision();
        // Action
        liste_poulets[i]->attaquer(*liste_pandas[i]);
        liste_autruches[i]->attaquer(*liste_pandas[i]);
    }
    return 0;
}