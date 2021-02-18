/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carreta.cpp
 * Author: USER
 * 
 * Created on 8 de junio de 2019, 11:55 PM
 */

#include "Carreta.h"

Carreta::Carreta() {
    numeroCarreta = 0;
}

int Carreta::getNumeroCarreta(){
    return numeroCarreta;
}

int Carreta::getNumeroPila(){
    return numeroPila;
}

void Carreta::setNumeroCarreta(int numCarreta){
    numeroCarreta = numCarreta;
}

void Carreta::setNumeroPila(int numPila){
    numeroPila = numPila;
}