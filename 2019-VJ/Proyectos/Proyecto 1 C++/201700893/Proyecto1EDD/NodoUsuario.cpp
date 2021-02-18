/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoLista.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:16 PM
 */

#include "NodoUsuario.h"

NodoUsuario::NodoUsuario()
{
    siguiente = nullptr;
    anterior = nullptr;
}

Usuario* NodoUsuario::getUsuario()
{
    return usuario;
}

void NodoUsuario::setUsuario(Usuario* user)
{
    usuario = user;
}
