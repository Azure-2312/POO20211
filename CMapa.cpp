#include <iostream>
#include "CMapa.h"
#include <cstdlib>
#include <ctime>
//Dimensionar el mapa. Invocacion uno por nivel
void CMapa::resizePlano(TipoEntero pAltura, TipoEntero pAncho){
    m_Plano = new TipoCaracter*[pAltura]; //al atributo m_plano
    for (size_t i = 0; i < pAltura; ++i)
        m_Plano[i] = new TipoCaracter[pAncho];
}

CMapa::CMapa(TipoEntero pAltura, TipoEntero pAncho, TipoEntero pBombas, TipoEntero pObstaculos){
    m_Altura = pAltura;
    m_Ancho = pAncho;
    m_CantJugadores = 0; //esto cambia dependiendo de Modo Batalla. Normal Game es con solo uno
    m_CantBombas = pBombas;
    m_CantObstaculos = pObstaculos;
    resizePlano(m_Altura,m_Ancho) ;
}//constructor de asignacion para configurar el plano
CMapa::~CMapa(){
    for (size_t i = 0; i < m_Altura; ++i) {
        delete[] m_Plano[i];
    }
    delete[] m_Plano;
    m_Plano = nullptr;
}//destructor


//pJugador es un puntero de obejeto
void CMapa::adicionarJugador(CJugadores* pJugador) {//Invocacion uno por nivel
    CJugadores** temp = new CJugadores*[m_CantJugadores + 1];//al principio es 0 + 1
    for (int i  = 0; i < m_CantJugadores; ++i){
        temp[i] = m_Jugadores[i];}

    temp[m_CantJugadores] = pJugador;
    /*delete m_Jugadores[0];
    m_Jugadores[0] = nullptr;*/

    delete [] m_Jugadores;
    m_Jugadores = temp;
    temp = nullptr;
    m_CantJugadores++;
}

void CMapa::eliminarJugador(CJugadores* pJugador){
    delete pJugador;
    pJugador = nullptr;
}

void CMapa::FijarObstaculos(){
    //coloca obstaculos que seran constante hasta completar un nivel, luego cambiara
    srand(time(NULL));
    int random1;
    int random2;
    int inicio = 0;
    int fin = m_Ancho-1;
    int j=0;
    do{
        random1 = inicio + rand() % (fin - inicio + 1);
        random2 = inicio + rand() % (fin - inicio + 1);
        if ((random1>1 && random1<m_Ancho-2) || (random2>1 && random2<m_Altura-2)){
            if ( m_Plano[random1][random2] == objeto){j += 0;}
            else {
                m_Plano[random1][random2] = objeto;
                j++;
            }
        }
    }while(j<m_CantObstaculos);
    //m_Plano[m_Altura-1][m_Ancho-1] = 'P';

}

void CMapa::dibujarMapa(ostream &os){
    os << '\n';
    os << setw(3) << ' ';
    for (size_t j = 0; j < m_Ancho; ++j){os << setw(3) << j;}
    os << '\n';
    for (size_t i = 0; i < m_Altura ; ++i) {
        os << setw(3) << i;
        for (size_t j = 0; j < m_Ancho; ++j) {os << setw(3) << m_Plano[i][j];}
        os << '\n';
    }
}//(no tocar por ahora este)

void CMapa::eliminarBloque() {
    for (size_t i = 0; i < m_Altura; ++i) {
        for (size_t j = 0; j < m_Ancho; ++j) {
            if (m_Plano[i][j] == '-' || m_Plano[i][j] == '0' ) { m_Plano[i][j] = COLOR; }
        }
    }
}
void CMapa::actualizarMapa() {
    //colocar valores de valor COLOR en la matriz dinamica
    for (int i = 0; i < m_Altura; i++) {
        for (int j = 0; j < m_Ancho; j++) {
            /*if(m_Plano[i][j] != objeto && m_Plano[i][j] != '0' && m_Plano[i][j] !='>'
            && m_Plano[i][j] != '<' && m_Plano[i][j] != '^' && m_Plano[i][j] != 'v'){
                m_Plano[i][j] = COLOR;}//OJO CON m_Plano[i][j] != '0'*/
            if(m_Plano[i][j] != objeto && m_Plano[i][j] != '0' && m_Plano[i][j] !='-' && m_Plano[i][j] != 'P' ){
                m_Plano[i][j] = COLOR;}
        }
    }
    //pone en la matriz a los jugadores al momento de actualizar, sino esto se perderia
    //.. al momento de imprimir el mapa otra vez
    for (int k = 0; k < m_CantJugadores; k ++) {
        m_Plano[m_Jugadores[k]->getPosY()][m_Jugadores[k]->getPosX()]= m_Jugadores[k]->getColor();
    }
    //coloca las bomba.. mismo que obstaculos pero con otro caracter y cantidad
    //OJO: este codigo posiblemente se vaya a clase bomba
    srand(time(NULL));
    int inicio = 0;
    int fin = m_Ancho-1;
    int random3;
    int random4;
    for (int m = 0; m < m_CantBombas; m++) {
        random3 = inicio + rand() % (fin - inicio + 1);
        random4 = inicio + rand() % (fin - inicio + 1);
        if (m_Plano[random3][random4] != objeto && (m_Plano[random3][random4] != ('R' && 'B' && 'G' && 'P'))){
            m_Plano[random3][random4] = '0';
        }
    }
}


// Bomba Fuego


void CMapa::eliminarBloque2() {
    for (size_t i = 0; i < m_Altura; ++i) {
        for (size_t j = 0; j < m_Ancho; ++j) {
            if (m_Plano[i][j] == '-' || m_Plano[i][j] == '0' ) { m_Plano[i][j] = COLOR; } 
                      
        }
    }
}
void CMapa::actualizarMapa2() {

    for (size_t i = 0; i < m_Altura; ++i) {
        for (size_t j = 0; j < m_Ancho; ++j) {
            /*if(m_Plano[i][j] != objeto && m_Plano[i][j] != '0' && m_Plano[i][j] !='>'
            && m_Plano[i][j] != '<' && m_Plano[i][j] != '^' && m_Plano[i][j] != 'v'){
                m_Plano[i][j] = COLOR;}//OJO CON m_Plano[i][j] != '0'*/
            if(m_Plano[i][j] != objeto && m_Plano[i][j] != '0' && m_Plano[i][j] !='-'){
                m_Plano[i][j] = COLOR;} 
        }
    }

    for (size_t k = 0; k < m_CantJugadores; ++k) {
        m_Plano[m_Jugadores[k]->getPosY()][m_Jugadores[k]->getPosX()]
                = m_Jugadores[k]->getColor();
    }

    srand(time(NULL));
    int inicio = 0;
    int fin = m_Ancho-1;
    int random3;
    int random4;
    for (size_t m = 0; m < m_CantBombas; ++m) {
        random3 = inicio + rand() % (fin - inicio + 1);
        random4 = inicio + rand() % (fin - inicio + 1);
        if (m_Plano[random3][random4] != objeto && m_Plano[random3][random4] != m_Jugadores[m]->getColor()){
            m_Plano[random3][random4] = '-';
            do{
                m_Plano[random3][random4] = 'P';
            }while(false);
        }
    }
}



TipoEntero CMapa::getAltura(){return m_Altura;}
TipoEntero CMapa::getAncho(){return m_Altura;}
TipoCaracter **CMapa::getPlano() {return m_Plano;}
CJugadores **CMapa::getMJugadores() const {return m_Jugadores;}

void CMapa::setMCantJugadores(TipoEntero mCantJugadores) {m_CantJugadores = mCantJugadores;}


