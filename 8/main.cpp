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
    team_A = new team("Ketchup", 10, 5, 5);
    team_B = new team("Mayo", 10, 5, 5);
    team_C = new team("Mustard", 10, 5, 5);
/*  
    team_A = new team("Ketchup");
    team_B = new team("Mayo");
    team_C = new team();
*/
    // Creation
/*
    team_A->creation();
    team_B->creation();
    team_C->creation();
*/

    team_A->debriefing();
    team_B->debriefing();
    team_C->debriefing();

    team_A->attaquer();
    team_A->debriefing();

    team_A->analyse();

    return 0;
}