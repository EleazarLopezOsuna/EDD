/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoImagen.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 07:47 PM
 */

#include "NodoImagen.h"

NodoImagen::NodoImagen()
{
    siguiente = nullptr;
    anterior = nullptr;
}

Imagen* NodoImagen::getImagen()
{
    return imagen;
}

void NodoImagen::setImagen(Imagen* image)
{
    imagen = image;
}

