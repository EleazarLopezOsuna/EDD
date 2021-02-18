/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoContenido.h
 * Author: USER
 *
 * Created on 20 de junio de 2019, 01:37 PM
 */

#ifndef NODOCONTENIDO_H
#define NODOCONTENIDO_H
#include <string>

using namespace std;

class NodoContenido
{
public:

    NodoContenido* siguiente;
    NodoContenido* anterior;
    NodoContenido* arriba;
    NodoContenido* abajo;
    NodoContenido();
    string getColor();
    void setColor(string casilla);
    int coordenadaX;
    int coordenadaY;

private:
    string color;
};

#endif /* NODOCONTENIDO_H */

