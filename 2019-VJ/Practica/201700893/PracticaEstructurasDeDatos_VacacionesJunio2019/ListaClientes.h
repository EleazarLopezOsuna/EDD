/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaClientes.h
 * Author: USER
 *
 * Created on 10 de junio de 2019, 08:51 PM
 */

#ifndef LISTACLIENTES_H
#define LISTACLIENTES_H
#include <string>
#include "Cliente.h"
#include "NodoListaCompra.h"

using namespace std;

class ListaClientes {
public:
    NodoListaCompra* head;
    NodoListaCompra* tail;
    ListaClientes();
    bool isEmpty();
    string print();
    string TailInsertion(Cliente* cliente);
    NodoListaCompra* Delete();
    
private:
    int contador = 0;
};

#endif /* LISTACLIENTES_H */

