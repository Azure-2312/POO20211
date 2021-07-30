#ifndef UNTITLED13_CJUGADORES_H
#define UNTITLED13_CJUGADORES_H
#include "Tipos.h"

class CJugadores {
protected:
    TipoString    m_Nombre;
    TipoCaracter  m_Color;
    TipoEntero    m_PosX;
    TipoEntero    m_PosY;
    TipoEntero    vidas = 1;
public:
    CJugadores(TipoString pNombre, TipoCaracter pColor,
               TipoEntero pPosX, TipoEntero pPosY);
    CJugadores();
    virtual ~CJugadores();
    void moverse();

    void setVidas(TipoEntero vidas);

    TipoString getNombre();
    TipoCaracter getColor();
    TipoEntero getPosX();
    TipoEntero getPosY();
    TipoEntero getVidas() const;

};
#endif //UNTITLED13_CJUGADORES_H
