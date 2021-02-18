/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Cliente.h
 * Author: USER
 *
 * Created on 9 de junio de 2019, 12:25 AM
 */

#ifndef CLIENTE_H
#define CLIENTE_H
#include "Carreta.h"

class Cliente {
public:
    Cliente();
    int getCodigoCliente();
    void setCodigoCliente(int codCliente);
    Carreta* getCarreta();
    void setCarreta(Carreta* basket);
private:
    int codigoCliente;
    Carreta* carreta;
};

#endif /* CLIENTE_H */