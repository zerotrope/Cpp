#ifndef _OEUF_H_
#define _OEUF_H_

#include <iostream>

class oeuf
{
    private:
    int couvage;

    protected:

    public:
    oeuf();
    oeuf(int couvage);

    ~oeuf(){}

    void presentation();
    bool isEclos();
    void couvee();
};

#endif