#ifndef _TEAM_H_
#define _TEAM_H_

#include <iostream>
#include <string>
#include <vector>
#include "guerrier.h"

class team
{
    private:
        std::string nom;
        std::vector<guerrier*> liste;
        int poulets;
        int superpoulets;
        int pandas;
        int autruches;

    protected:

    public:
        team();
        team(std::string _nom);
        team(std::string _nom, int _poulets, int _pandas, int _autruches);

        ~team();

        void creation();
        void analyse();
        void attaquer(team &target);
        void debriefing();

        std::string get_nom();
        int get_survivants();
        int get_type(Type);
        int get_defense(Type);
        int get_force(Type);
        int get_vie(Type);
        int get_vie_totale();
        int get_vie_potentielle();
        int get_vie_initiale();

        // team_creation() : demande au user combien de poulets, pandas, autruches
        // prise de décision pour l'équipe totale en fonction de son état
};

#endif