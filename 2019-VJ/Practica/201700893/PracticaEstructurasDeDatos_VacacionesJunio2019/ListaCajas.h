/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCajas.h
 * Author: USER
 *
 * Created on 10 de junio de 2019, 06:42 PM
 */

#ifndef LISTACAJAS_H
#define LISTACAJAS_H
#include "NodoListaCajas.h"
#include <string>

using namespace std;

class ListaCajas {
public:
    NodoListaCajas* head;
    ListaCajas();
    bool isEmpty();
    string print();
    string TailInsertion(Caja* caja);
    Cliente* atenderClientes(int numero);
    Caja* obtenerCajaVacia();
    
private:

};

#endif /* LISTACAJAS_H */

