#include <time.h>
#include <stdlib.h>
#include "guerrier.h"
using namespace std;

    guerrier::guerrier()
    {
        //srand(time(NULL));
        #ifndef _SRAND_
        #define _SRAND_
        srand(time(NULL));
        #endif
        //cout << endl;
        //cout << "...création d'un guerrier standard en cours... " << endl;
        guerrier::nom = "nouveau_guerrier";
        guerrier::vie = 10;
        guerrier::force = 10;
        guerrier::defense = 10;
        guerrier::type_guerrier = SANS_TYPE;
        guerrier::defense_active = false;
        guerrier::target = NULL;
    }

    guerrier::guerrier(std::string _nom, Type _type_guerrier, int _vie, int _force, int _defense)
    {
        //srand(time(NULL));
        #ifndef _SRAND_
        #define _SRAND_
        srand(time(NULL));
        #endif
        //cout << endl;
        //cout << "...création de votre guerrier en cours... " << endl;
        guerrier::nom = _nom;
        guerrier::vie = _vie;
        guerrier::force = _force;
        guerrier::defense = _defense;
        guerrier::type_guerrier = _type_guerrier;
        guerrier::defense_active = false;
        guerrier::target = NULL;
    }

    guerrier::~guerrier()
    {
        cout << nom << " retourne à la terre mère..." << endl;
    }

    void guerrier::attaquer(guerrier &target) // référence
    {
        if(guerrier::isDefending() == true)
        {
            return;
        }
        if(target.isDefending() == true)
        {
            if((target.getVie() + target.getDefense()) > guerrier::force)
            {
                // Si la cible a plus de défense que l'attaquant d'attaque alors seule le capital défense de la cible est consommé
                if(target.getDefense() > guerrier::force)
                {
                    target.getDefense() = target.getDefense() - guerrier::force;
                }
                // Si le capital défense au moment de l'attaque est déjà consommé, alors c'est le capital vie de la cible qui sera directement consommé
                else if (target.getDefense() == 0)
                {
                    target.getVie() = target.getVie() - guerrier::force;
                }
                // Sinon, lorsque l'attaque est supérieure au capital défense existant, c'est la totalité du capital défense qui est consommé et le résidu qui entamme le capital vie
                else
                {
                    target.getVie() = target.getVie() - (guerrier::force - target.getDefense());
                    target.getDefense() = 0;
                }
            }
            else
            {
                target.getVie() = 0;
                target.getDefense() = 0;
                //cout << target.getNom() << " est tombé!" << endl;
            }
        }
        else
        {
            if(target.getVie() > guerrier::force)
            {
                target.getVie() = target.getVie() - guerrier::force;
                //cout << guerrier::getNom() << " frappe " << target.getNom() << endl;
            }
            else
            {
                target.setVie(0);
                //cout << "Votre ennemi " << target.getNom() << " est tombé!" << endl;
            }
        }
        cout << endl;
        cout << target.getNom() << " dispose de :" << endl;
        cout << target.getVie() << " points de vie" << endl;
        cout << target.getDefense() << " points de défense" << endl;
    }

        void guerrier::attaquer() // surchargée
    {
        guerrier::setTarget(this); // DEBUG
        if(guerrier::target == NULL)
        {
            cerr << "pas de cible" << endl;
            return;
        }
        guerrier::attaquer(*guerrier::target);
    }

/*
    void guerrier::prendre_decision()
    {
        int random = rand()%100;
        if(guerrier::vie < guerrier::force)
        {
            if(random >= 80)
            {
                guerrier::defense_active = true;
            }
            else
            {
                guerrier::defense_active = false;
            }
        }
        if(guerrier::vie >= guerrier::force)
        {
            if(random <= 70)
            {
                guerrier::defense_active = false;
            }
            else
            {
                guerrier::defense_active = true;
            }
        }
        if(guerrier::defense_active == true)
        {
            cout << guerrier::getNom() << " se défend!" << endl;
        }
        else
        {
            cout << guerrier::getNom() << " attaque (" << guerrier::force << " points de force)" << endl;
        }
    }
*/

    void guerrier::cri_guerre()
    {
        cout << this->blabla() << endl;
    }

    bool guerrier::isDefending()
    {
        return guerrier::defense_active;
    }

    void guerrier::setNom(string nom)
    {
        guerrier::nom = nom;
    }

    void guerrier::setVie(int nouveau)
    {
        guerrier::vie = nouveau;
        if(nouveau < 0)
            guerrier::vie = 10;
    }

    void guerrier::setForce(int nouveau)
    {
        guerrier::force = nouveau;
        if(nouveau < 0)
            guerrier::force = 10;
    }

    void guerrier::setDefense(int nouveau)
    {
        guerrier::defense = nouveau;
        if(nouveau < 0)
            guerrier::defense = 10;
    }

    // La référence vers la valeur de retour permet de manipuler depuis l'extérieur la donnée locale vie grâce à getVie()=x
    int &guerrier::getVie()
    {
        return guerrier::vie;
    }

    string guerrier::getNom()
    {
        return guerrier::nom;
    }

    int &guerrier::getDefense()
    {
        return guerrier::defense;
    }

    int guerrier::getForce()
    {
        return guerrier::force;
    }

    guerrier *guerrier::getTarget()
    {
        return guerrier::target;
    }

    void guerrier::setTarget(guerrier *new_target)
    {
        guerrier::target = new_target;
    }

    // Fonctions domaine protected
    void guerrier::setDefending(bool decision)
    {
        guerrier::defense_active = decision;
        //cout << "debug" << endl; // DEBUG
    }

    Type guerrier::getType()
    {
        return guerrier::type_guerrier;
    }