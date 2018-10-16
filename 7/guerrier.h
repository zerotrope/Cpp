#ifndef _GUERRIER_H_
#define _GUERRIER_H_

#include <iostream>
#include <string>

enum Type
{
    POULET,
    SUPERPOULET,
    PANDA,
    AUTRUCHE,
    SANS_TYPE
};

class guerrier
{
    private:
        std::string nom;
        int vie;
        int force;
        int defense;
        Type type_guerrier;
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
        guerrier(std::string _nom, Type _type_guerrier, int _vie, int _force, int _defense);
        //guerrier(const guerrier &);

        ~guerrier();

        virtual void attaquer(guerrier &target);
        virtual void prendre_decision() = 0;
        void cri_guerre();
        virtual std::string blabla() = 0;

        void setVie(int nouveau);
        int &getVie();
        std::string getNom();
        bool isDefending();
        Type getType();
};

#endif