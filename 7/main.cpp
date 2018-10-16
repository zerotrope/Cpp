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
#include "team.h"

using namespace std;

int main()
{
    int actions;
    int tour = 1;
    int reponse = 1;
    team *team_A;
    team *team_B;
    team *team_C;

    // Malloc
    team_A = new team("Ketchup");
    team_B = new team("Mayo");
    team_C = new team();

    // Creation
    team_A->creation();
    team_B->creation();
    team_C->creation();

    team_A->debriefing();
    team_B->debriefing();
    team_C->debriefing();

/*
    // Creation
    team_A->team();
    team_B->team();

    cout << "Combien d'action souhaitez-vous : ";
    cin >> actions;
    if(actions <= 0)
    {
        actions = 0;
        cout << "Chaque équipe pourra réaliser autant d'actions que de membres" << endl;
    }
    team_A->set_actions(actions);
    team_B->set_actions(actions);

    while(team_A->get_survivants() > 0 && team_B->get_survivants() > 0 && reponse == 1)
    {
        cout << "Êtes-vous prêt pour le tour n°" << tour << "? (1 pour oui / 0 pour quitter)" << endl;
        cin >> reponse;
        if(reponse == 1)
        {
            team_A->analyse_situation(team_B);
            team_B->analyse_situation(team_A);
                                                // apres les fonctions creations, et les gets, commentez de 49 à 53 pour tests
            team_A->attaquer(team_B);
            team_B->attaquer(team_A);

            team_A->debriefing();               // debrief par team effectif des races, pourcentage de vie globale? (implique stocker l'initial)
            team_B->debriefing();               // debrief du tour (cb de morts...etc.)
        }
        tour++;
    }
    if(reponse == 1)
    {
        if(team_A->get_survivants() == 0 && team_B->get_survivants() == 0)
            cout << "Egalité!!" << endl;
        else if(team_A->get_survivants() == 0)
            cout << "L'équipe " << team_B->get_nom() << " remporte le combat !" << endl;
        else
            cout << "L'équipe " << team_A->get_nom() << " remporte le combat !" << endl;
    }
*/
    return 0;
}