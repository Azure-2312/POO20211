#ifndef CJUGADORES_CPP_CBATTLE_MODE_H
#define CJUGADORES_CPP_CBATTLE_MODE_H
#include "CMapa.h"
#include<vector>
#include "CEnemigo.h"
class CBattle_mode {
private:
    TipoEntero tiempo;//seria chevere contar los minutos
    TipoEntero jugadores;//hubiera utilizado mejor el m_Jugadores que esta en CMapa, ya que ahi estan los jugadores, pero tendria que modificar mucho

public:
    CBattle_mode(){}//no hace nada
    CBattle_mode(TipoEntero pJugadores);
    virtual ~CBattle_mode();
    void Batallar(CMapa *pMapa, TipoEntero pJugadores);

    TipoEntero getTiempo() const;

};
#endif //CJUGADORES_CPP_CBATTLE_MODE_H
