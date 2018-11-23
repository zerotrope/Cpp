#ifndef _POULET_H_
#define _POULET_H_

#include <iostream>
#include <string>

class poulet : public guerrier, public oeuf
{
    private:

    public:
    poulet();
    poulet(std::string nom);
    poulet(std::string nom, int vie);

    void cocorico();
    virtual std::string blabla();
    virtual void prendre_decision();
};

#endif