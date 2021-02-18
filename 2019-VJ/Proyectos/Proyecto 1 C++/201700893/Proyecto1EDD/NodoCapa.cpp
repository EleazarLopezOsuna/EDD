/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoCapa.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 07:45 PM
 */

#include "NodoCapa.h"

NodoCapa::NodoCapa()
{
    siguiente = nullptr;
    anterior = nullptr;
}

Capa* NodoCapa::getCapa()
{
    return capa;
}

void NodoCapa::setCapa(Capa* layer)
{
    capa = layer;
}

