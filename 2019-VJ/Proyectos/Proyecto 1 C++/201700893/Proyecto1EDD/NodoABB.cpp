/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoArbolBinario.cpp
 * Author: USER
 *
 * Created on 18 de junio de 2019, 08:33 PM
 */

#include "NodoABB.h"

NodoABB::NodoABB(Capa* layer)
{
    hijoIzquierdo = nullptr;
    hijoDerecho = nullptr;
    esHoja = true;
    capa = layer;
}

Capa* NodoABB::getCapa()
{
    return capa;
}

void NodoABB::setEsHoja(bool cambio)
{
    esHoja = cambio;
}

bool NodoABB::getEsHoja()
{
    return esHoja;
}
