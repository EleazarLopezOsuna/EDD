/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoCabecera.h
 * Author: USER
 *
 * Created on 20 de junio de 2019, 01:37 PM
 */

#ifndef NODOCABECERA_H
#define NODOCABECERA_H
#include "NodoContenido.h"

class NodoCabecera
{
public:

    NodoCabecera* derecha;
    NodoCabecera* abajo;
    NodoContenido* contenido;
    int numeroCabecera;
    NodoCabecera();

private:

};

#endif /* NODOCABECERA_H */

