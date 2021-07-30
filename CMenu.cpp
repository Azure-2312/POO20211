#include "CMenu.h"

CMenu::CMenu(){}
//Es una forma de jerarquizar metodos de clases relacionadas respecto a un atributo
enum class Opciones{Normal_Gamer = 1, Battle_Mode = 2, Instruction = 3, Exit = 4};

void CMenu::Menu(){
    cout<<"1. Normal Game"<<endl;
    cout<<"2. Battle Mode"<<endl;
    cout<<"3. Read Instruction"<<endl;
    cout<<"4. Exit"<<endl;
    cout<<"\nDigite una opcion: "; cin>>m_Opcion;
    //dependiendo de la opcion activa un metodo
    switch(Opciones(m_Opcion)){
        case Opciones::Normal_Gamer: Normal_Game(); break;
        case Opciones::Battle_Mode:  Battle_mode(); break;
        case Opciones::Instruction:  Instruction(); break;
        case Opciones::Exit:         Exit(); break;
    }
}

CMenu::~CMenu(){}
//este enum me servira para asegurar el nivel que estoy en NormalGame u otro metodo
enum class Niveles{ Nivel1 = 1, Nivel2= 2, Nivel3 = 3};

//OPTIMIZAR
void CMenu::Normal_Game(){
    CNiveles *nivel = new CNiveles;
    //vector<CMapa *> pNivel = nivel->get_nivel();
    //cout<<"Nivel 1"<<endl;
    do{
        switch (Niveles(nivel->get_m_nivel())) {
            case Niveles:: Nivel1: cout<<"Nivel 1"<<endl;nivel->Nivel(nivel->get_m_nivel()); break;
            case Niveles:: Nivel2: cout<<"Nivel 2"<<endl;nivel->Nivel(nivel->get_m_nivel()); break;
            case Niveles:: Nivel3: cout<<"Nivel 3"<<endl;nivel->Nivel(nivel->get_m_nivel()); break;
        }
    }while(nivel->get_m_nivel() < 3);//la cosa es que llegue a una meta y se pare cuando llego nivel 3
    delete nivel;
    nivel = nullptr;
    cout<<"Felicidades.. ¡Ganaste!"<<endl;
}
void CMenu::Battle_mode(){
    TipoEntero jugadores;

    CMapa *pMapa = new CMapa(15, 15,0,  120);
    cout<<"Digite la cantidad de jugadores: "; cin>>jugadores;
    CBattle_mode *pBatalla = new CBattle_mode(jugadores);
    pBatalla->Batallar(pMapa, jugadores);
    //Eliminando memoria dinamica
    delete pMapa;
    delete pBatalla;
    pMapa = nullptr;
    pBatalla = nullptr;
}

//solo imprime
void CMenu::Instruction(){
    cout<<"Instruciones: \n"<<endl;
    cout<<"A: izquierda "<<endl;
    cout<<"D: derecha "<<endl;
    cout<<"W: arriba "<<endl;
    cout<<"S: abajo "<<endl;
}
void CMenu::Exit(){cout<<"Hasta pronto...";}

