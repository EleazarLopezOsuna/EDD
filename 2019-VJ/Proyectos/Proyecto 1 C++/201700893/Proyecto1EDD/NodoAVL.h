/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoAVL.h
 * Author: USER
 *
 * Created on 19 de junio de 2019, 10:13 AM
 */

#ifndef NODOAVL_H
#define NODOAVL_H
#include "Usuario.h"

class NodoAVL
{
public:
    NodoAVL(Usuario* user);
    NodoAVL* hijoIzquierdo;
    NodoAVL* hijoDerecho;
    int altura = 0;


    Usuario* getUsuario();
    void setFactorEquilibrio(int valor);
    int getFactorEquilibrio();
    void setAltura(int al);
    bool getEsHoja();
    void setEsHoja(bool cambio);
    void setUsuario(Usuario* user);

private:
    bool esHoja;
    Usuario* usuario;
    int factorEquilibrio = 0;
};
#endif /* NODOAVL_H */

