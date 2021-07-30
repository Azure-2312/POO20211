#ifndef CNIVELES_CPP_CENEMIGO_H
#define CNIVELES_CPP_CENEMIGO_H
#include "CVidas.h"
#include "CMapa.h"

class CEnemigo: public CJugadores{
private:
    TipoString nombre = "Maquina";
public:
    CEnemigo(CMapa *pEnenmigo){
        TipoEntero nivel;
        cout<<"Nivel 1: 1 vida"<<endl;
        cout<<"Nivel 2: 2 vida"<<endl;
        cout<<"Nivel 3: 3 vida"<<endl;
        cout<<"Nivel de dificultad del enemigo: "; cin>>nivel;
        srand(time(NULL));
        int inicio = 0;
        int fin = pEnenmigo->getAncho()-1;
        int random1;
        int random2;
        random1 = inicio + rand() % (fin - inicio + 1);
        random2 = inicio + rand() % (fin - inicio + 1);
        cout<<"Se crea enemigo"<<endl;

        CJugadores *pMaquina = new CJugadores(nombre, 'E', random1, random2);
        CVidas *pVida = new CVidas(1);
        if(nivel ==1){
            pMaquina->setVidas(pVida->get_vidas());
        }
        if(nivel ==2){
            ++*pVida;
            pMaquina->setVidas(pVida->get_vidas());
        }
        if(nivel ==3){
            ++*pVida;
            ++*pVida;
            pMaquina->setVidas(pVida->get_vidas());
        }
        cout<<"El enemigo tiene "<<pMaquina->getVidas()<<" vidas"<<endl;
        pEnenmigo->adicionarJugador(pMaquina);
    }
    friend class CNiveles;
};
#endif //CNIVELES_CPP_CENEMIGO_H
