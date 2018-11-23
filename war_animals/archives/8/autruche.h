#ifndef _AUTRUCHE_H_
#define _AUTRUCHE_H_

#include <iostream>
#include <string>
#include "guerrier.h"
#include "oeuf.h"

class autruche : public guerrier, public oeuf
{
    private:

    public:
    autruche();
    autruche(std::string nom);

    void cotcote();
    virtual std::string blabla();

    // Masquage
    void prendre_decision();
};

#endif