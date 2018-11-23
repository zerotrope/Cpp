#ifndef _PANDA_H_
#define _PANDA_H_

#include <iostream>
#include <string>
#include "guerrier.h"

class panda : public guerrier
{
    private:

    public:
    panda();
    panda(std::string nom);

    void adrienne();

    virtual std::string blabla();

    // Masquage
    void prendre_decision();
};

#endif