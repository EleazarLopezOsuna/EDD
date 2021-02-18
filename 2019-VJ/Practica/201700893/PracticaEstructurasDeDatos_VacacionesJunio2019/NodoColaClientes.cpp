/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NodoPilaClientes.cpp
 * Author: USER
 * 
 * Created on 9 de junio de 2019, 02:23 PM
 */

#include "NodoColaClientes.h"

NodoColaClientes::NodoColaClientes() {
    siguiente = nullptr;
}

void NodoColaClientes::setCliente(Cliente* client){
    cliente = client;
}

void NodoColaClientes::setSiguinte(NodoColaClientes* next){
    siguiente = next;
}

Cliente* NodoColaClientes::getCliente(){
    return cliente;
}

NodoColaClientes* NodoColaClientes::getSiguiente(){
    return siguiente;
}

