#ifndef _AUTRUCHE_H_
#define _AUTRUCHE_H_

#include <iostream>
#include <string>

class autruche : public guerrier
{
    private:

    public:
    autruche();
    autruche(std::string nom);

    void cotcote();

    // Masquage
    void prendre_decision();
};

#endif