/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoLista.h
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:16 PM
 */

#ifndef NODOLISTA_H
#define NODOLISTA_H
#include "Usuario.h"

class NodoUsuario
{
public:

    NodoUsuario();

    NodoUsuario* siguiente;
    NodoUsuario* anterior;

    void setUsuario(Usuario* user);
    Usuario* getUsuario();

private:
    Usuario* usuario;
};

#endif /* NODOLISTA_H */

