#ifndef CJUGADORES_H_CBOMBA_H
#define CJUGADORES_H_CBOMBA_H
#include "Tipos.h"
#include "CMapa.h"


class CBomba {
private:
    TipoEntero cant_bombas;
    TipoCaracter bomba = '0';
    TipoEntero alcance = 2;
    TipoEntero    b_PosX;
    TipoEntero    b_PosY;
    bool game_over = false;
public:
    CBomba(){}
    virtual ~CBomba();
    //TipoCaracter get_bomba();
    TipoEntero get_cant_bombas();
    void Bomba_Alcance();
    void Explosion(CMapa *pMapa, TipoEntero oponente);
    void Explosion_Facil(CMapa *pPlano,TipoEntero,TipoEntero);
    void Colocar_Bomba(CMapa *pMapa, TipoEntero oponente);

    bool isGameOver() const;
};

//CODIGO BOMBA FUEGO
class CBombaFuego{
  private:
    TipoEntero cant_bombas2;
    TipoCaracter bomba2 = '0';
    TipoEntero alcance = 3;
    TipoEntero    b2_PosX;
    TipoEntero    b2_PosY;
    bool game_over = false;
  public:
    CBombaFuego(){}
    virtual ~CBombaFuego();
    TipoEntero get_cant_bombas2();
    void Bomba_Alcance2();
    void Explosion2(CMapa *pMapa2, TipoEntero oponente2);
    void Colocar_Bomba2(CMapa *pMapa2, TipoEntero oponente2);

    bool isGameOver2() const;


};


#endif //CJUGADORES_H_CBOMBA_H
