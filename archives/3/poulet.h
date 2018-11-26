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

    void cocorico();
};

#endif