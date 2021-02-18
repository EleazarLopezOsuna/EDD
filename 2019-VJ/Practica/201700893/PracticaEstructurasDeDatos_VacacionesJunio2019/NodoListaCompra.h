/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoListaCompra.h
 * Author: USER
 *
 * Created on 10 de junio de 2019, 08:25 PM
 */

#ifndef NODOLISTACOMPRA_H
#define NODOLISTACOMPRA_H
#include "Cliente.h"

class NodoListaCompra {
public:
    NodoListaCompra();
    NodoListaCompra* siguiente;
    NodoListaCompra* anterior;
    Cliente* getCliente();
    void setCliente(Cliente* client);
    void setSiguinte(NodoListaCompra* next);
    NodoListaCompra* getSiguiente();
    void setAnterior(NodoListaCompra* previous);
    NodoListaCompra* getAnterior();
private:
    Cliente* cliente;
};

#endif /* NODOLISTACOMPRA_H */

