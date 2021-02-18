/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoListaCajas.h
 * Author: USER
 *
 * Created on 10 de junio de 2019, 06:39 PM
 */

#ifndef NODOLISTACAJAS_H
#define NODOLISTACAJAS_H
#include "Caja.h"

class NodoListaCajas {
public:
    NodoListaCajas();
    NodoListaCajas* siguiente;
    NodoListaCajas* anterior;
    void setCaja(Caja* check);
    Caja* getCaja();
    void setAnterior(NodoListaCajas* previous);
    NodoListaCajas* getAnterior();
    void setSiguinte(NodoListaCajas* next);
    NodoListaCajas* getSiguiente();
private:
    Caja* check;
};

#endif /* NODOLISTACAJAS_H */

