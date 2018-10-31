#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <math.h> 

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
        team::poulets = 10;
        team::superpoulets = 1;
        team::pandas = 5;
        team::autruches = 5;
    }

    // Constructeur surchargé à 1 paramètre
    team::team(std::string _nom)
    {
        team::nom = _nom;
        team::poulets = 10;
        team::superpoulets = 1;
        team::pandas = 5;
        team::autruches = 5;
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

    void team::analyse(team *target)
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

        ------------------------------------------------------

        // from local team
        int team_n = team::get_survivants();
        int team_v = team::get_vie_totale();
        int team_poulets_n = team::get_type(POULET);
        int team_poulets_v = team::get_vie(POULET);
        int team_superpoulets_n = team::get_type(SUPERPOULET);
        int team_superpoulets_v = team::get_vie(SUPERPOULET);
        int team_pandas_n = team::get_type(PANDA);
        int team_pandas_v = team::get_vie(PANDA);
        int team_autruches_n = team::get_type(AUTRUCHE);
        int team_autruches_v = team::get_vie(AUTRUCHE);

        // from target team
        
        int target_n = target.get_survivants();
        int target_v = target.get_vie_totale();
        int target_poulets_n = target.get_type(POULET);
        int target_poulets_v = target.get_vie(POULET);
        int target_superpoulets_n = target.get_type(SUPERPOULET);
        int target_superpoulets_v = target.get_vie(SUPERPOULET);
        int target_pandas_n = target.get_type(PANDA);
        int target_pandas_v = target.get_vie(PANDA);
        int target_autruches_n = target.get_type(AUTRUCHE);
        int target_autruches_v = target.get_vie(AUTRUCHE);

        // from local method
        int up_poulets = std::min(team_poulets_n, target_poulets_n);
        int up_superpoulets = std::max(team_superpoulets_n, target_superpoulets_n);
        int up_pandas = std::max(team_pandas_n, target_pandas_n);
        int up_autruches = std::max(team_autruches_n, target_autruches_n);

        ------------------------------------------------------
*/

        // Définir posture
        std::vector<guerrier*>::iterator it;
        for(it=team::liste.begin(); it!=team::liste.end(); ++it)
        {
           (*it)->setDefending(false);
           //(*it)->prendre_decision(); // DEBUG
        }
        std::vector<guerrier*> liste_target = target->getListe();
        std::vector<guerrier*>::iterator it_target;
        for(it_target=liste_target.begin(); it_target!=liste_target.end(); ++it_target)
        {
            cout << (*it_target)->getNom() << endl;
        }

        // Définir target
        it_target = liste_target.begin();
        for(it=team::liste.begin(); it!=team::liste.end() && it_target!=liste_target.end(); ++it, ++it_target)
        {
           cout << (*it)->getNom() << " attaque " << (*it_target)->getNom()<< endl;
           (*it)->setTarget(*it_target);
        }
    }

    void team::attaquer()
    {
        std::vector<guerrier*>::iterator it;
        for(it=team::liste.begin(); it!=team::liste.end(); ++it)
        {
           cout << (*it)->getNom() << endl;
           //(*it)->prendre_decision(); // DEBUG
           (*it)->attaquer();
        }
    }

    void team::debriefing()
    {
        int team_n = team::get_survivants();
        int team_v = team::get_vie_totale();
        int team_vp = team::get_vie_potentielle();
        int team_vi = team::get_vie_initiale();
        int ratio_team_n = team_n / (team::poulets + team::superpoulets + team::pandas + team::autruches) * 100;
        float ratio_team_v = round((float)team_v / (float)team_vp * 100.0);

        int poulets_n = team::get_type(POULET);
        int poulets_v = team::get_vie(POULET);
        int poulets_vp = poulets_n * 10;
        float ratio_poulets_n = round((float)poulets_n / (float)team::poulets * 100);
        float ratio_poulets_v = round(((float)poulets_v / ((float)team::poulets * 10.0)) * 100.0);
        
        int superpoulets_n = team::get_type(SUPERPOULET);
        int superpoulets_v = team::get_vie(SUPERPOULET);
        int superpoulets_vp = superpoulets_n * 1000;

        int pandas_n = team::get_type(PANDA);
        int pandas_v = team::get_vie(PANDA);
        int pandas_vp = pandas_n * 100;
        float ratio_pandas_n = round((float)pandas_n / (float)team::pandas * 100.0);
        float ratio_pandas_v = round((float)pandas_v / (float)team::pandas);
        float pandas_ultimate = round((float)(pandas_v * 0.5) / (float)team_vp * 100.0);

        int autruches_n = team::get_type(AUTRUCHE);
        int autruches_v = team::get_vie(AUTRUCHE);
        int autruches_vp = autruches_n * 50;
        float ratio_autruches_n = round((float)autruches_n / (float)team::autruches * 100.0);
        float ratio_autruches_v = round((float)autruches_v / (float)(team::autruches * 50.0) * 100.0);

        cout << endl;
        cout << "---------------RAPPORT INTERNE---------------" << endl;
        cout << team::get_nom() << "\t\t\tSurvivants\tVie" << endl;
        cout << team::get_survivants() << " Guerriers" << "\t\t\t" << ratio_team_n << "\%\t" << ratio_team_v << "\%" << endl;
        cout << "---------------------------------------------" << endl;
        cout << " " << poulets_n << " Poulets\t\t\t" <<  ratio_poulets_n << "\%\t" << ratio_poulets_v << "\%" << endl;
        cout << " " << team::get_type(PANDA) << " Pandas\t\t\t" <<  ratio_pandas_n << "\%\t" << ratio_pandas_v << "\%" << endl;
        cout << " " << team::get_type(AUTRUCHE) << " Autruches\t\t\t" <<  ratio_autruches_n << "\%\t" << ratio_autruches_v << "\%" << endl;
        cout << "---------------------------------------------" << endl;
        cout << superpoulets_n << " Superpoulets au combat" << endl;
        if(ratio_poulets_n <= 10)
            cout << "ULTIMATE DES POULETS DISPONIBLES!" << endl;
        cout << "Ultimate des poulets indisponible" << endl;
        cout << "Ultimate des pandas = +" << pandas_ultimate << "\% de vie de l'équipe" << endl;
        cout << "Ultimate des autruches = +" << autruches_v << " poulets" << endl;
        cout << "---------------------FIN---------------------" << endl;
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
            // Je veux compter les guerriers de type (TEST) qui sont vivants
            if((*it)->getType() == test && (*it)->isDead() == false)
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

    std::vector<guerrier*> team::getListe()
    {
        return team::liste;
    }