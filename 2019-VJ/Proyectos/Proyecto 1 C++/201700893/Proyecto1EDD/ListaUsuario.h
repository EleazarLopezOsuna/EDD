#ifndef LISTAUSUARIO_H
#define LISTAUSUARIO_H
#include "NodoUsuario.h"


class ListaUsuario
{
public:
    ListaUsuario();
    NodoUsuario* head;
    void ordenarLista(int tipo);
    bool isEmpty();
    void insertarOrdenado(Usuario* user);
    void eliminarCabeza();
    string recorrer();
    string Top5();
    int getCantidad();
    void setCantidad(int c);
private:
    int cantidad;
};

#endif // LISTAUSUARIO_H
