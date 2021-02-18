/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoImagen.h
 * Author: USER
 *
 * Created on 17 de junio de 2019, 07:47 PM
 */

#ifndef NODOIMAGEN_H
#define NODOIMAGEN_H
#include "Imagen.h"

class NodoImagen
{
public:

    NodoImagen();

    NodoImagen* siguiente;
    NodoImagen* anterior;

    void setImagen(Imagen* image);
    Imagen* getImagen();

private:
    Imagen* imagen;
};

#endif /* NODOIMAGEN_H */

