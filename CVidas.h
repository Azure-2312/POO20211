
#ifndef CNIVELES_CPP_CVIDAS_H
#define CNIVELES_CPP_CVIDAS_H
#include "Tipos.h"

class CVidas {
protected:
    TipoEntero vidas = 1;
public:
    CVidas(){}
    CVidas(TipoEntero vida):vidas(vida){};
    TipoEntero get_vidas(){return vidas;};

    friend ostream &operator<<(ostream &os,CVidas pVidas1);
    friend CVidas operator++(CVidas &pVidas2);
    friend CVidas operator--(CVidas&pVidas3);
};


#endif //CNIVELES_CPP_CVIDAS_H
