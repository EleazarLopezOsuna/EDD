/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoContenido.cpp
 * Author: USER
 *
 * Created on 20 de junio de 2019, 01:37 PM
 */

#include "NodoContenido.h"

NodoContenido::NodoContenido()
{
    siguiente = nullptr;
    anterior = nullptr;
    arriba = nullptr;
    abajo = nullptr;
    color = "#FFFFFF";
    coordenadaX = 0;
    coordenadaY = 0;
}

string NodoContenido::getColor()
{
    return color;
}

void NodoContenido::setColor(string casilla)
{
    color = casilla;
}
