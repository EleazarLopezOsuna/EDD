/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaCarretas.h
 * Author: USER
 *
 * Created on 9 de junio de 2019, 11:58 AM
 */

#ifndef PILACARRETAS_H
#define PILACARRETAS_H
#include "NodoPilaCarretas.h"
#include <string>

using namespace std;

class PilaCarretas {
public:
    NodoPilaCarretas* head;
    PilaCarretas();
    bool isEmpty();
    string print(int numero);
    string HeadInsertion(int cartNumber, int stackNumber);
    NodoPilaCarretas* HeadDelete();
    
private:
};

#endif /* PILACARRETAS_H */

