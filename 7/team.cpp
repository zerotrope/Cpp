#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>

#include "team.h"
#include "guerrier.h"
#include "poulet.h"
#include "autruche.h"
#include "panda.h"

using namespace std;

    // Constructeur par défaut
    team::team()
    {
        team::nom = "Default";
        team::poulets = 0;
        team::superpoulets = 0;
        team::pandas = 0;
        team::autruches = 0;
    }

    // Constructeur surchargé à 1 paramètre
    team::team(std::string _nom)
    {
        team::nom = _nom;
        team::poulets = 0;
        team::superpoulets = 0;
        team::pandas = 0;
        team::autruches = 0;
    }

    // Constructeur surchargé
    team::team(std::string _nom, int _poulets, int _pandas, int _autruches)
    {
        int i = 0;
        stringstream ss;

            for (i=0; i<_poulets; i++)
            {
                ss << "Poulet_" << i+1;
                liste.push_back(new poulet(ss.str()));
                ss.str("");
            }
            for (i=0; i<_pandas; i++)
            {
                ss << "Panda_" << i+1;
                liste.push_back(new panda(ss.str()));
                ss.str("");
            }
            for (i=0; i<_autruches; i++)
            {
                ss << "Autruche_" << i+1;
                liste.push_back(new autruche(ss.str()));
                ss.str("");
            }
        team::nom = _nom;
        team::poulets = _poulets;
        team::pandas = _pandas;
        team::autruches = _autruches;
        cout << "L'équipe " << team::nom << " est composée de " << team::get_survivants() << " guerriers" << endl;
    }

    // Destrcuteur
    team::~team()
    {
        cout << team::nom << " entre dans la légende..." << endl;
    }

    // Fonctions
    void team::creation()
    {
        int i = 0;
        stringstream ss;

        cout << "Création de l'équipe " << team::nom << endl;
        cout << "Combien de poulets voulez-vous créer?" << endl;
        cin >> team::poulets;
        cout << "Combien de pandas voulez-vous créer?" << endl;
        cin >> pandas;
        cout << "Combien d'autruches voulez-vous créer?" << endl;
        cin >> autruches;
        cout << endl << endl;

        for (i=0; i<team::poulets; i++)
        {
            ss << "Poulet_" << i+1;
            liste.push_back(new poulet(ss.str()));
            ss.str("");
        }
        for (i=0; i<team::pandas; i++)
        {
            ss << "Panda_" << i+1;
            liste.push_back(new panda(ss.str()));
            ss.str("");
        }
        for (i=0; i<team::autruches; i++)
        {
            ss << "Autruche_" << i+1;
            liste.push_back(new autruche(ss.str()));
            ss.str("");
        }
    }

    void team::analyse()
    {
        /*
        Pour team & target :
            santé totale et par race
            stats :
                puissance d'attaque
                défense
                ratio
            nombre de super attaques disponibles
            recommandation attaque/défense
        scoring
        comparaison par ratios team vs. target
        nombre de tours min/max avant victoire/défaite
        */
    }

    void team::attaquer()
    {
        /*

        */
    }

    void team::debriefing()
    {
        int team_n = team::get_survivants();
        int team_v = team::get_vie_totale();
        int team_vp = team::get_vie_potentielle();
        int team_vi = team::get_vie_initiale();
        int ratio_team_n = team_n / (team::poulets + team::superpoulets + team::pandas + team::autruches) * 100;
        int ratio_team_v = team_v / team_vp * 100;

        int poulets_n = team::get_type(POULET);
        int poulets_v = team::get_vie(POULET);
        int poulets_vp = poulets_n * 10;
        int ratio_poulets_n = poulets_n / team::poulets * 100;
        int ratio_poulets_v = poulets_v / (team::poulets * 10) * 100;

        int superpoulets_n = team::get_type(SUPERPOULET);
        int superpoulets_v = team::get_vie(SUPERPOULET);
        int superpoulets_vp = superpoulets_n * 1000;

        int pandas_n = team::get_type(PANDA);
        int pandas_v = team::get_vie(PANDA);
        int pandas_vp = pandas_n * 100;
        int ratio_pandas_n = pandas_n / team::pandas * 100;
        int ratio_pandas_v = pandas_v / (team::pandas * 100) * 100;
        int pandas_ultimate = pandas_v * 0.5 / team_vp * 100;

        int autruches_n = team::get_type(AUTRUCHE);
        int autruches_v = team::get_vie(AUTRUCHE);
        int autruches_vp = autruches_n * 50;
        int ratio_autruches_n = autruches_n / team::autruches * 100;
        int ratio_autruches_v = autruches_v / (team::autruches * 50) * 100;

        cout << endl;
        cout << "---------------RAPPORT INTERNE---------------" << endl;
        cout << team::get_nom() << "\t\t\tSurvivants\tVie" << endl;
        cout << "---------------------------------------------" << endl;
        cout << team::get_survivants() << " Guerriers" << "\t\t\t" << ratio_team_n << "\%\t" << ratio_team_v << "\%" << endl;
        cout << " " << team::get_type(POULET) << " Poulets\t\t\t" <<  ratio_poulets_n << "\%\t" << ratio_poulets_v << "\%" << endl;
        cout << " " << team::get_type(PANDA) << " Pandas\t\t\t" <<  ratio_pandas_n << "\%\t" << ratio_pandas_v << "\%" << endl;
        cout << " " << team::get_type(AUTRUCHE) << " Autruches\t\t\t" <<  ratio_autruches_n << "\%\t" << ratio_autruches_v << "\%" << endl;
        cout << "---------------------------------------------" << endl;
        cout << superpoulets_n << " Superpoulets au combat" << endl;
        if(ratio_poulets_n <= 10)
            cout << "ULTIMATE DES POULETS DISPONIBLES!" << endl;
        cout << "Ultimate des poulets indisponible" << endl;
        cout << "Ultimate des pandas = +" << pandas_ultimate << "\% de vie de l'équipe" << endl;
        cout << "Ultimate des autruches = +" << autruches_v << " poulets" << endl;
        cout << "---------------------------------------------" << endl;
        cout << endl;
    }

    // Gets
    string team::get_nom()
    {
        return team::nom;
    }

    int team::get_survivants()
    {
        return team::liste.size();
    }

    int team::get_type(Type test)
    {
        int count = 0;
        std::vector<guerrier*>::iterator it; // adresse donc *it pour accéder à la donnée pointée
        for(it=team::liste.begin(); it!=team::liste.end(); ++it)
        {
            if((*it)->getType() == test)
                count++;
        }
        return count;
    }

    int team::get_vie(Type test)
    {
        int vie = 0;
        std::vector<guerrier*>::iterator it;
        for(it=team::liste.begin(); it!=team::liste.end(); ++it)
        {
            if((*it)->getType() == test)
                vie = vie + (*it)->getVie();
        }
        return vie;
    }

    int team::get_vie_totale()
    {
        int vie = 0;
        std::vector<guerrier*>::iterator it;
        for(it=team::liste.begin(); it!=team::liste.end(); ++it)
        {
            vie = vie + (*it)->getVie();
        }
        return vie;
    }

    int team::get_vie_potentielle()
    {
        int vie = 0;
        int vie_poulets = team::get_type(POULET) * 10;
        int vie_superpoulets = team::get_type(SUPERPOULET) * 1000;
        int vie_pandas = team::get_type(PANDA) * 100;
        int vie_autruches = team::get_type(AUTRUCHE) * 50;
        vie = vie_poulets + vie_superpoulets + vie_pandas + vie_autruches;
        return vie;
    }

    int team::get_vie_initiale()
    {
        int vie = 0;
        int vie_poulets = team::poulets * 10;
        int vie_superpoulets = team::superpoulets * 1000;
        int vie_pandas = team::pandas * 100;
        int vie_autruches = team::autruches * 50;
        vie = vie_poulets + vie_superpoulets + vie_pandas + vie_autruches;
        return vie;
    }