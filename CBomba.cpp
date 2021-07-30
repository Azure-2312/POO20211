#include "CBomba.h"
#include "CVidas.h"
//TipoCaracter CBomba::get_bomba(){return }
TipoEntero CBomba::get_cant_bombas(){return cant_bombas;}
void CBomba::Bomba_Alcance(){}

void CBomba::Explosion(CMapa *pMapa, TipoEntero oponente){
    TipoEntero PosX;
    TipoEntero PosY;
    CVidas *pVida = new CVidas;
    bool jugador = not(oponente);
    cout<<"cantidad de jugadores "<<pMapa->m_CantJugadores<<endl;

    PosX = pMapa->getMJugadores()[oponente]->getPosX();
    PosY = pMapa->getMJugadores()[oponente]->getPosY();
    //PosY =  pMapa->getMJugadores()[int(jugador)]->getColor();
    for(int i = 0; i<alcance; i++){
        for(int j = 0; j<alcance; j++){
            if(pMapa->m_Plano[b_PosY][b_PosX - alcance + j] == pMapa->m_Plano[PosY][PosX]){
                if(pMapa->m_CantJugadores ==1){
                    --*pVida;
                    pMapa->getMJugadores()[oponente]->setVidas(pVida->get_vidas());
                    cout<<"Ahora el enemigo tiene "<<pVida->get_vidas()<<endl;
                    break;
                }
                else{
                    pMapa->actualizarMapa();
                    pMapa->dibujarMapa(cout);
                    cout<<"El jugador "<<pMapa->getMJugadores()[int(jugador)]->getNombre()<<" gano...Felicidades"<<endl;
                    game_over = true;
                    pMapa->eliminarJugador(pMapa->getMJugadores()[oponente]);
                    break;
                }
            }
            else{pMapa->m_Plano[b_PosY][b_PosX + 1 + j] = '-';
                pMapa->m_Plano[b_PosY][b_PosX - alcance + j] = '-';}
        }
    }
    for(int i = 0; i<alcance; i++){
        for(int j = 0; j<alcance; j++){
            if(pMapa->m_Plano[b_PosY][b_PosX - alcance + j] == pMapa->m_Plano[PosY][PosX]){
                if(pMapa->m_CantJugadores ==1){
                    --*pVida;
                    pMapa->getMJugadores()[oponente]->setVidas(pVida->get_vidas());
                    cout<<"Ahora el enemigo tiene "<<pVida->get_vidas()<<endl;
                    break;
                }
                else{
                    pMapa->actualizarMapa();
                    pMapa->dibujarMapa(cout);
                    cout<<"El jugador "<<pMapa->getMJugadores()[int(jugador)]->getNombre()<<" gano...Felicidades"<<endl;
                    pMapa->eliminarJugador(pMapa->getMJugadores()[oponente]);
                    game_over = true;
                    break;
                }

            }
            else{pMapa->m_Plano[b_PosY + 1 + j][b_PosX] = '-';
                pMapa->m_Plano[b_PosY - alcance + j][b_PosX] = '-';}
        }
    }
}
void CBomba::Explosion_Facil(CMapa *pMapa, TipoEntero _X,TipoEntero _Y) {
//    pMapa->m_Plano[_Y][_X] = '.';
    pMapa->m_Plano[_Y-1][_X] = '.';
    pMapa->m_Plano[_Y+1][_X] = '.';
    pMapa->m_Plano[_Y][_X-1] = '.';
    pMapa->m_Plano[_Y][_X+1] = '.';
}


TipoEntero CBombaFuego::get_cant_bombas2(){return cant_bombas2;}
void CBombaFuego::Bomba_Alcance2(){}
void CBombaFuego::Explosion2(CMapa *pMapa2, TipoEntero oponente2){
    TipoEntero PosX;
    TipoEntero PosY;
    bool jugador = not(oponente2);

    PosX = pMapa2->getMJugadores()[oponente2]->getPosX();
    PosY = pMapa2->getMJugadores()[oponente2]->getPosY();
    //PosY =  pMapa->getMJugadores()[int(jugador)]->getColor();
    for(int i = 0; i<alcance; i++){
        for(int j = 0; j<alcance; j++){
            if(pMapa2->m_Plano[b2_PosY][b2_PosX - alcance + j] == pMapa2->m_Plano[PosY][PosX]){
                pMapa2->actualizarMapa();
                pMapa2->dibujarMapa(cout);
                cout<<"El jugador "<<pMapa2->getMJugadores()[int(jugador)]->getNombre()<<"gano...Felicidades"<<endl;
                game_over = true;
                pMapa2->eliminarJugador(pMapa2->getMJugadores()[oponente2]);
            }
            else{pMapa2->m_Plano[b2_PosY][b2_PosX + 1 + j] = '-';
                pMapa2->m_Plano[b2_PosY][b2_PosX - alcance + j] = '-';}
        }
    }
    //pMapa->m_Plano[b_PosY - alcance + j][b_PosX] == Color1 || pMapa->m_Plano[b_PosY][b_PosX - alcance + j] == Color2
    for(int i = 0; i<alcance; i++){
        for(int j = 0; j<alcance; j++){
            if(pMapa2->m_Plano[b2_PosY][b2_PosX - alcance + j] == pMapa2->m_Plano[PosY][PosX]){
                pMapa2->actualizarMapa();
                pMapa2->dibujarMapa(cout);
                cout<<"El jugador "<<pMapa2->getMJugadores()[int(jugador)]->getNombre()<<" gano...Felicidades"<<endl;
                pMapa2->eliminarJugador(pMapa2->getMJugadores()[oponente2]);
            }
            else{pMapa2->m_Plano[b2_PosY + 1 + j][b2_PosX] = '-';
                pMapa2->m_Plano[b2_PosY - alcance + j][b2_PosX] = '-';}
        }
    }
}


void CBomba::Colocar_Bomba(CMapa *pMapa, TipoEntero oponente){
    cout<<"Coloque una bomba: "<<endl;
    cout<<"PosX: "; cin>>b_PosX;
    cout<<"PosY: "; cin>>b_PosY;

    pMapa->m_Plano[b_PosY][b_PosX] = bomba;
    if (oponente == 10000){Explosion_Facil(pMapa,b_PosX,b_PosY);}
    else{Explosion(pMapa, oponente);}
}

void CBombaFuego::Colocar_Bomba2(CMapa *pMapa2, TipoEntero oponente2){
    cout<<"Coloque una bomba Fuego: "<<endl;
    cout<<"PosX: "; cin>>b2_PosX;
    cout<<"PosY: "; cin>>b2_PosY;

    pMapa2->m_Plano[b2_PosY][b2_PosX] = bomba2;
    Explosion2(pMapa2, oponente2);
}


CBomba::~CBomba(){}
CBombaFuego::~CBombaFuego(){}
bool CBomba::isGameOver() const {return game_over;}
bool CBombaFuego::isGameOver2() const {return game_over;}
