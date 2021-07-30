#include "CVidas.h"

ostream &operator<<(ostream &os,CVidas pVidas1){
    os<<pVidas1.vidas;
    return os;
}

CVidas operator ++(CVidas &pVidas2){
    pVidas2.vidas++;
    return pVidas2;
}

CVidas operator--(CVidas &pVidas3){
    pVidas3.vidas--;
    return pVidas3;
}