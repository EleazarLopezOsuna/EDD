/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caja.cpp
 * Author: USER
 * 
 * Created on 9 de junio de 2019, 01:05 AM
 */

#include "Caja.h"
#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <random>

Caja::Caja() {
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> nume(1,10);
    codigo = 0;
    numeroClientes = nume(generator);
    estadoCaja = false;
    cliente = new Cliente();
    numeroClientesAtendidos = 0;
}

int Caja::getCodigo(){
    return codigo;
}

int Caja::getNumeroClientes(){
    return numeroClientes;
}

bool Caja::getEstadoCaja(){
    return estadoCaja;
}

Cliente* Caja::getCliente(){
    return cliente;
}

int Caja::getNumeroClientesAtendidos(){
    return numeroClientesAtendidos;
}


void Caja::setCodigo(int cod){
    codigo = cod;
}

void Caja::setEstadoCaja(bool estCaja){
    estadoCaja = estCaja;
}

void Caja::setNumeroClientes(int numClientes){
    numeroClientes = numClientes;
}

void Caja::setCliente(Cliente* client){
    cliente = client;
}

void Caja::setNumeroClientesAtendidos(){
    numeroClientesAtendidos = 0;
}

void Caja::atenderCliente(){
    numeroClientesAtendidos++;
}