#ifndef _POULET_H_
#define _POULET_H_

#include <iostream>
#include <string>

// Expliquer pourquoi 'public' ici
// L'héritage publique correspond vulgairement à un copier/coller de la classe guerrier dans le publique de la classe poulet. Ce qui est privé du guerrier le reste.
// La réciproque est fausse, lorsque l'héritage est privé, ce qui est publique du guerrier devient privé.
class poulet : public guerrier
{
    private:

    public:
    poulet();
    poulet(std::string nom);

    void cocorico();
};

#endif