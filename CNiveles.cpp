#include "CMapa.h"
#include "CNiveles.h"
#include "CBomba.h"
#include<vector>

//creo los niveles desde un principio y solo los invoco con los punteros
CNiveles::CNiveles(){
    CMapa *pNivel1 = new CMapa(10, 10, 5 ,45 );
    CMapa *pNivel2 = new CMapa(13, 13, 10,100);
    CMapa *pNivel3 = new CMapa(16, 16,15,  180);
    m_niveles ={pNivel1, pNivel2, pNivel3};//vector que almacena objeto puntero de niveles
}
void CNiveles::Nivel(TipoEntero nivel){
    //direccion(izq, derec, abaj, arri) y pasos(si no choca) es para mover jugador
    CJugadores *jugador = new CJugadores;
    cout<<"Instruciones: "<<endl;
    cout<<"A: izquierda "<<endl;
    cout<<"D: derecha "<<endl;
    cout<<"W: arriba "<<endl;
    cout<<"S: abajo "<<endl;
    m_niveles[nivel-1]->FijarObstaculos();
    //m_niveles[nivel-1]->adicionarJugador(new CJugadores());
    if (nivel == 1){ m_niveles[nivel - 1]->adicionarJugador(jugador); }
    CBomba *pBomba = new CBomba;
//    bool turno_oponente;
    TipoString opcion;
    do{
        m_niveles[nivel-1]->getPlano()[m_niveles[nivel-1]->getAncho()-1][m_niveles[nivel-1]->getAltura()-1] = 'P';
        m_niveles[nivel-1]->actualizarMapa();
        m_niveles[nivel-1]->dibujarMapa(cout);
        m_niveles[nivel-1]->actualizarMapa();
        cout<<"Desea colocar una bomba?: \n"; cin>>opcion;
        if(opcion == "SI"){
                pBomba->Colocar_Bomba(m_niveles[nivel-1], 10000);
        }
        jugador->moverse();
        if ( m_niveles[nivel-1]->getPlano()[jugador->getPosX()][jugador->getPosY()] == 'P'){
            cout <<"\nVamos al siguiente nivel"<< endl;
            nivel++;
            m_nivel++;
            CNiveles::Nivel(nivel);
        }
    }while(m_nivel !=3);
}

TipoEntero CNiveles::get_m_nivel(){return m_nivel;}
void CNiveles::set_nivel(){}
vector<CMapa *> CNiveles::get_nivel(){return m_niveles;}

