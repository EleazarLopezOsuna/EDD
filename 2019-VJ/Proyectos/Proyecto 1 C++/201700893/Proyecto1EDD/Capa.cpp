/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Capa.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:41 PM
 */

#include "Capa.h"

Capa::Capa()
{
    Nombre = 0;
    matriz = nullptr;
}

void Capa::setNombre(int nombre)
{
    Nombre = nombre;
}

int Capa::getNombre()
{
    return Nombre;
}

