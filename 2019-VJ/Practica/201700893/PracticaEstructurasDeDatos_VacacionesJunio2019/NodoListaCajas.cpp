/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoListaCajas.cpp
 * Author: USER
 * 
 * Created on 10 de junio de 2019, 06:40 PM
 */

#include "NodoListaCajas.h"

NodoListaCajas::NodoListaCajas() {
    siguiente = nullptr;
    anterior = nullptr;
}

void NodoListaCajas::setCaja(Caja* caj){
    check = caj;
}

void NodoListaCajas::setSiguinte(NodoListaCajas* next){
    siguiente = next;
}

void NodoListaCajas::setAnterior(NodoListaCajas* previous){
    anterior = previous;
}

Caja* NodoListaCajas::getCaja(){
    return check;
}

NodoListaCajas* NodoListaCajas::getSiguiente(){
    return siguiente;
}

NodoListaCajas* NodoListaCajas::getAnterior(){
    return anterior;
}

