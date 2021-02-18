/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Carreta.h
 * Author: USER
 *
 * Created on 8 de junio de 2019, 11:55 PM
 */

#ifndef CARRETA_H
#define CARRETA_H

class Carreta {
public:
    Carreta();
    int getNumeroCarreta();
    void setNumeroCarreta(int numCarreta);
    int getNumeroPila();
    void setNumeroPila(int numPila);
private:
    int numeroCarreta = 0;
    int numeroPila = 0;
};

#endif /* CARRETA_H */