#include "oeuf.h"
using namespace std;

    oeuf::oeuf()
    {
        oeuf::couvage = 3;
        cout << "Je suis passé par là !" << endl;
    }

    oeuf::oeuf(int _couvage)
    {
        oeuf::couvage = _couvage;
    }

    void oeuf::presentation()
    {
        cout << "Bonjour je suis un oeuf! " << endl;
    }

    bool oeuf::isEclos()
    {
        if(oeuf::couvage <= 0)
            return true;
        return false;
    }

    void oeuf::couvee()
    {
        if(oeuf::couvage == 0)
            return;
        oeuf::couvage--;
        cout << "Couvage en cours, encore " << oeuf::couvage << " tours avant eclosion!" << endl;
    }