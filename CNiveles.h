#ifndef CJUGADORES_H_CNIVELES_H
#define CJUGADORES_H_CNIVELES_H

#include "CMapa.h"
//#include "CMenu.h"
#include<vector>
class CNiveles {
private:
    vector<CMapa *> m_niveles;
    TipoEntero m_nivel = 1;

public:
    CNiveles();
    vector<CMapa *> get_nivel();//almacena los niveles
    TipoEntero get_m_nivel();
    void set_nivel();
    void Nivel(TipoEntero nivel);
    //friend class CJugadores;
};
#endif //CJUGADORES_H_CNIVELES_H
