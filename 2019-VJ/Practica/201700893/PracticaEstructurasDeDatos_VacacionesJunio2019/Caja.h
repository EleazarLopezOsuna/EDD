/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Caja.h
 * Author: USER
 *
 * Created on 9 de junio de 2019, 01:05 AM
 */

#ifndef CAJA_H
#define CAJA_H
#include "Cliente.h"

class Caja {
public:
    Caja();
    
    int getCodigo();
    int getNumeroClientes();
    bool getEstadoCaja();
    int getNumeroClientesAtendidos();
    Cliente* getCliente();
    
    void setCodigo(int cod);
    void setNumeroClientes(int numClientes);
    void setEstadoCaja(bool estCaja);
    void setCliente(Cliente* client);
    void atenderCliente();
    void setNumeroClientesAtendidos();
    
private:
    int codigo;
    int numeroClientes;
    bool estadoCaja;
    Cliente* cliente;
    int numeroClientesAtendidos;
};

#endif /* CAJA_H */