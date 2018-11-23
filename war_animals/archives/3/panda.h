#ifndef _PANDA_H_
#define _PANDA_H_

#include <iostream>
#include <string>

class panda : public guerrier
{
    private:

    public:
    panda();
    panda(std::string nom);

    void adrienne();

    // Masquage
    void prendre_decision();
};

#endif