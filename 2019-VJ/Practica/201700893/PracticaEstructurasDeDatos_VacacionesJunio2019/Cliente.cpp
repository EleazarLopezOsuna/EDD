/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.cpp
 * Author: USER
 * 
 * Created on 9 de junio de 2019, 12:25 AM
 */

#include "Cliente.h"

Cliente::Cliente() {
    codigoCliente = 0;
    carreta = new Carreta();
}

void Cliente::setCodigoCliente(int codCliente){
    codigoCliente = codCliente;
}

int Cliente::getCodigoCliente(){
    return codigoCliente;
}

Carreta* Cliente::getCarreta(){
    return carreta;
}

void Cliente::setCarreta(Carreta* basket){
    carreta = basket;
}