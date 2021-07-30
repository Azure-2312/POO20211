#include "CJugadores.h"

CJugadores::CJugadores(){
    cout<<"\nPonga su nombre: "; cin>>m_Nombre;
    cout<<"\nBlue: 'B'";
    cout<<"\nRed: 'R'";
    cout<<"\nGreen: 'G'";
    cout<<"\nEliga un color: "; cin>>m_Color;
    cout<<"\nPosicion X: "; cin>>m_PosX;
    cout<<"Posicion Y: "; cin>>m_PosY;
}//defenir constructor por defecto

CJugadores::CJugadores(TipoString pNombre, TipoCaracter pColor,
                       TipoEntero pPosX, TipoEntero pPosY)
                       :m_Nombre{pNombre}, m_Color{pColor},
                        m_PosX{pPosX}, m_PosY{pPosY} {}
CJugadores::~CJugadores() {}
//OPTIMIZAR
void CJugadores::moverse(){
    TipoCaracter direccion;
    TipoEntero pasos;
    bool bandera = true;
    while(bandera){
        cout<<"Direccion: "; cin>>direccion;
        cout<<"Numero de pasos: "; cin>>pasos;
        switch(direccion){
            case 'A': m_PosX -= pasos; bandera = false; break;
            case 'D': m_PosX += pasos; bandera = false; break;
            case 'W': m_PosY -= pasos; bandera = false;break;
            case 'S': m_PosY += pasos; bandera = false;break;
            default: cout<<"Favor de seguir las instrucciones..."<<endl;break;
        }
     }
}

TipoString   CJugadores::getNombre() { return m_Nombre; }
TipoEntero   CJugadores::getPosX()   { return m_PosX; }
TipoEntero   CJugadores::getPosY()   { return m_PosY; }
TipoCaracter CJugadores::getColor()  { return m_Color; }
TipoEntero   CJugadores::getVidas() const {return vidas;}

void CJugadores::setVidas(TipoEntero vidas) {
    CJugadores::vidas = vidas;
}
