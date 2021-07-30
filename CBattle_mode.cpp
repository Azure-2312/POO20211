#include "CBattle_mode.h"
#include "CBomba.h"

CBattle_mode::CBattle_mode(TipoEntero pJugadores){jugadores = pJugadores;}
CBattle_mode::~CBattle_mode() {}

void CBattle_mode::Batallar(CMapa *pMapa, TipoEntero pJugadores){
    TipoEntero Turno_Jugador= 0;//me ayuda a a "pasar turnos"
    TipoString opcion;
    TipoString opcion2;
    vector<CJugadores*> Jugadores(pJugadores);//vector de objetos jugadores
    CBomba *pBomba = new CBomba;
    CBombaFuego *pBomba2 = new CBombaFuego;


    for(TipoEntero i = 0; i<pJugadores; i++){
        Jugadores[i] = new CJugadores;}

    //primero reservo un espacio
    for(TipoEntero i = 0; i<pJugadores; i++){
        cout<<"crea jugador"<<endl;
        pMapa->adicionarJugador(Jugadores[i] );}//agrego en esos espacio
    //pMapa->setMCantJugadores(pJugadores);
    if(pJugadores==1){
        CEnemigo *pEnemigo = new CEnemigo(pMapa);
    }

    //for(TipoEntero i = 0; i<pJugadores+1; i++){ pMapa->m_Jugadores[i] = Jugadores[i];}
    //Jugadores = pMapa->m_Jugadores;

    cout<<"Instruciones: "<<endl;
    cout<<"A: izquierda "<<endl;
    cout<<"D: derecha "<<endl;
    cout<<"W: arriba "<<endl;
    cout<<"S: abajo "<<endl;
    pMapa->FijarObstaculos();
    bool turno_oponente;
    do{
        pMapa->actualizarMapa();
        pMapa->dibujarMapa(cout);
        pMapa->actualizarMapa();
        pMapa->eliminarBloque();
        cout<<"Turno de Jugador "<<Jugadores[Turno_Jugador]->getNombre()<<endl;
        cout<<"Desea colocar una bomba?: \n"; cin>>opcion;
        turno_oponente= not(bool(Turno_Jugador));
        if(opcion == "SI"){
            cout<<"Que tipo de bomba desea colocar? ( Normal o Fuego ): \n"; cin>>opcion2;         
            if(opcion2 == "Normal"){
            pBomba->Colocar_Bomba(pMapa, int(turno_oponente));
            }
            if(opcion2 == "Fuego"){
            pBomba2->Colocar_Bomba2(pMapa, int(turno_oponente));              
            }
        }
        if(!pBomba->isGameOver()){
            Jugadores[Turno_Jugador]->moverse();
        }

        ++Turno_Jugador;
        if(Turno_Jugador == pJugadores){Turno_Jugador = 0;}
    }while(!pBomba->isGameOver());//por mientras sera true..falta implementar cuando uno muere y se pare el juego
}
TipoEntero CBattle_mode::getTiempo() const {return tiempo;}

