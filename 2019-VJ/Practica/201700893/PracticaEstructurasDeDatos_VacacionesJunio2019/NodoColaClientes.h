/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPilaClientes.h
 * Author: USER
 *
 * Created on 9 de junio de 2019, 02:23 PM
 */

#ifndef NODOPILACLIENTES_H
#define NODOPILACLIENTES_H
#include "Cliente.h"

class NodoColaClientes {
public:
    NodoColaClientes();
    NodoColaClientes* siguiente;
    void setCliente(Cliente* cart);
    Cliente* getCliente();
    void setSiguinte(NodoColaClientes* next);
    NodoColaClientes* getSiguiente();
private:
    Cliente* cliente;
};

#endif /* NODOPILACLIENTES_H */

