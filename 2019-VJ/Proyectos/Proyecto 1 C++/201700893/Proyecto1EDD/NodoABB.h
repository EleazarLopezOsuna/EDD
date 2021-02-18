/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoArbolBinario.h
 * Author: USER
 *
 * Created on 18 de junio de 2019, 08:33 PM
 */

#ifndef NODOARBOLBINARIO_H
#define NODOARBOLBINARIO_H
#include "Capa.h"

class NodoABB
{
public:
    NodoABB(Capa* layer);
    NodoABB* hijoIzquierdo;
    NodoABB* hijoDerecho;

    Capa* getCapa();
    bool getEsHoja();
    void setEsHoja(bool cambio);

private:
    bool esHoja;
    Capa* capa;
};

#endif /* NODOARBOLBINARIO_H */

