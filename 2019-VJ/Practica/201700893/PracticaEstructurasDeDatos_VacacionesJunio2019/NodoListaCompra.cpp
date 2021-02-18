/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoListaCompra.cpp
 * Author: USER
 * 
 * Created on 10 de junio de 2019, 08:25 PM
 */

#include "NodoListaCompra.h"

NodoListaCompra::NodoListaCompra() {
    siguiente = nullptr;
    anterior = nullptr;
}

void NodoListaCompra::setCliente(Cliente* client){
    cliente = client;
}

void NodoListaCompra::setSiguinte(NodoListaCompra* next){
    siguiente = next;
}

void NodoListaCompra::setAnterior(NodoListaCompra* previous){
    anterior = previous;
}

Cliente* NodoListaCompra::getCliente(){
    return cliente;
}

NodoListaCompra* NodoListaCompra::getSiguiente(){
    return siguiente;
}

NodoListaCompra* NodoListaCompra::getAnterior(){
    return anterior;
}

