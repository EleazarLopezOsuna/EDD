/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaCarretas.h
 * Author: USER
 *
 * Created on 9 de junio de 2019, 11:30 AM
 */

#ifndef NODOPILACARRETAS_H
#define NODOPILACARRETAS_H
#include "Carreta.h"

class NodoPilaCarretas {
public:
    NodoPilaCarretas();
    NodoPilaCarretas* siguiente;
    void setCarreta(Carreta* cart);
    Carreta* getCarreta();
    void setSiguinte(NodoPilaCarretas* next);
    NodoPilaCarretas* getSiguiente();
    
private:
    Carreta* carreta;
};

#endif /* NODOPILACARRETAS_H */