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

    protected:
        void setNom(std::string nom);
        void setForce(int nouveau);
        void setDefense(int nouveau);
        void setDefending(bool decision);

        int &getDefense();
        int getForce();

    public:
        guerrier();
        guerrier(std::string _nom, int _vie, int _force, int _defense);
        //guerrier(const guerrier &);

        ~guerrier();

        void attaquer(guerrier &target);
        void prendre_decision();

        void setVie(int nouveau);
        int &getVie();
        std::string getNom();
        bool isDefending();
};

#endif