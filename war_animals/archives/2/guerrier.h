#ifndef _GUERRIER_H_
#define _GUERRIER_H_

#include <iostream>
#include <string>

class guerrier
{
    private:
        std::string nom;
        int vie;
        int force;
        int defense;
        bool defense_active;

    public:
        guerrier();
        guerrier(std::string _nom, int _vie, int _force, int _defense);
        //guerrier(const guerrier &);

        ~guerrier();

        void attaquer(guerrier &target);
        void prendre_decision();

        void setNom(std::string nom);
        void setVie(int nouveau);
        void setForce(int nouveau);
        void setDefense(int nouveau);
        int &getVie();
        int &getDefense();
        std::string getNom();
        bool isDefending();
};

#endif