/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoAVL.cpp
 * Author: USER
 *
 * Created on 19 de junio de 2019, 10:13 AM
 */

#include "NodoAVL.h"

NodoAVL::NodoAVL(Usuario* user)
{
    hijoIzquierdo = nullptr;
    hijoDerecho = nullptr;
    esHoja = true;
    usuario = user;
}

void NodoAVL::setAltura(int al)
{
    altura = al;
}

Usuario* NodoAVL::getUsuario()
{
    return usuario;
}

void NodoAVL::setEsHoja(bool cambio)
{
    esHoja = cambio;
}

bool NodoAVL::getEsHoja()
{
    return esHoja;
}

void NodoAVL::setFactorEquilibrio(int valor)
{
    factorEquilibrio = valor;
}

int NodoAVL::getFactorEquilibrio()
{
    return factorEquilibrio;
}

void NodoAVL::setUsuario(Usuario* user)
{
    usuario = user;
}
