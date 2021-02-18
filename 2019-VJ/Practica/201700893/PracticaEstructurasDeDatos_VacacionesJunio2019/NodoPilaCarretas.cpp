/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaCarretas.cpp
 * Author: USER
 * 
 * Created on 9 de junio de 2019, 11:30 AM
 */

#include "NodoPilaCarretas.h"

NodoPilaCarretas::NodoPilaCarretas() {
    siguiente = nullptr;
}

void NodoPilaCarretas::setCarreta(Carreta* cart){
    carreta = cart;
}

void NodoPilaCarretas::setSiguinte(NodoPilaCarretas* next){
    siguiente = next;
}

Carreta* NodoPilaCarretas::getCarreta(){
    return carreta;
}

NodoPilaCarretas* NodoPilaCarretas::getSiguiente(){
    return siguiente;
}