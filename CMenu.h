#ifndef CJUGADORES_CPP_CMENU_H
#define CJUGADORES_CPP_CMENU_H
//#include "Tipos.h"
#include "CMapa.h"
#include "CNiveles.h"
#include "CBattle_mode.h"
#include "CEnemigo.h"
class CMenu {
private:
    TipoEntero m_Opcion;
public:
    CMenu();
    virtual ~CMenu();
    void Menu();
    void Normal_Game();
    void Battle_mode();
    void Instruction();//ignorar. no afecta en nada el codigo
    void Exit();
};

#endif //CJUGADORES_CPP_CMENU_H
