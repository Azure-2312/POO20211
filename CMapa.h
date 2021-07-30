#ifndef UNTITLED13_CMAPA_H
#define UNTITLED13_CMAPA_H

#include "Tipos.h"
#include "CJugadores.h"
//#include "CEnemigo.h"

const TipoCaracter COLOR ='.';
const TipoCaracter objeto = '#';
//si el jugador llegar en la posicion Meta en el mapa, pasa al otro nivel. falta implementar
const TipoCaracter Meta = 'F';

class CMapa {
private:
    TipoEntero m_Altura;
    TipoEntero m_Ancho;
    TipoCaracter **m_Plano;//plano caracter
    TipoEntero m_CantJugadores;
    TipoEntero m_CantBombas;
    TipoEntero  m_CantObstaculos;
    CJugadores **m_Jugadores =nullptr; //aqui se guardan a los jugadores. Hubiera sido mejor con vector
    void resizePlano(TipoEntero pAltura, TipoEntero pAncho);
public:
    CMapa(){}
    CMapa(TipoEntero pAltura, TipoEntero pAncho, TipoEntero pBombas, TipoEntero pObstaculos);
    virtual ~CMapa();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoCaracter  **getPlano();
    void adicionarJugador(CJugadores* pJugador);
    void eliminarJugador(CJugadores* pJugador);
    void eliminarBloque();
    void dibujarMapa(ostream &os);
    void actualizarMapa(); //pregunta al jugador su posicion en cada jugada
    //friend class CBattle_mode;//este por ahora no es necesario. Para esto falta modificar codigo CMAPA en la parte de adicionar y cantidad de jugadores
    void FijarObstaculos(); // obstaculos al alzar hasta que llegue a otro nivel para cambiar posiciones
    //TipoCaracter **getMPlano() const;
    void eliminarBloque2();
    void actualizarMapa2();

    friend class CBomba;
    friend class CBombaFuego;
    friend class CNiveles;
    
    void setMCantJugadores(TipoEntero mCantJugadores);

    CJugadores **getMJugadores() const;
};
#endif //UNTITLED13_CMAPA_H
