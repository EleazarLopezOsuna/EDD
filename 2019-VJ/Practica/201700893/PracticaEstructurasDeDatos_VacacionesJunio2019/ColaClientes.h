/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaClientes.h
 * Author: USER
 *
 * Created on 9 de junio de 2019, 02:27 PM
 */

#ifndef COLACLIENTES_H
#define COLACLIENTES_H
#include "NodoColaClientes.h"
#include <string>

using namespace std;

class ColaClientes {
public:
    NodoColaClientes* head;
    ColaClientes();
    bool isEmpty();
    string print(string tipo);
    string TailInsertion(Cliente* cliente, int tipo);
    NodoColaClientes* HeadDelete(string tipo);
    
private:

};

#endif /* COLACLIENTES_H */

