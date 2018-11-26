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
        guerrier *target;
        bool dead;

    protected:
        void setNom(std::string nom);
        void setForce(int nouveau);
        void setDefense(int nouveau);

        int &getDefense();
        int getForce();

    public:
        guerrier();
        guerrier(std::string _nom, Type _type_guerrier, int _vie, int _force, int _defense);
        //guerrier(const guerrier &);

        ~guerrier();

        virtual void attaquer(guerrier &target);
        virtual void prendre_decision() = 0;
        virtual std::string blabla() = 0;
        virtual void attaquer();
        void cri_guerre();

        void setVie(int nouveau);
        int &getVie();
        std::string getNom();
        bool isDefending();
        Type getType();
        guerrier *getTarget();
        void setTarget(guerrier *new_target);
        void setDefending(bool decision);
        bool isDead();
};

#endif