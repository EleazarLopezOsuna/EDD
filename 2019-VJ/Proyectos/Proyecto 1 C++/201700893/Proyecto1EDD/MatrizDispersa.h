/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MatrizDispersa.h
 * Author: USER
 *
 * Created on 20 de junio de 2019, 02:06 PM
 */

#ifndef MATRIZDISPERSA_H
#define MATRIZDISPERSA_H
#include "NodoCabecera.h"
#include <string>
#include <iostream>

using namespace std;

class MatrizDispersa
{
public:
    NodoCabecera* root;
    MatrizDispersa();
    string agregar(int ejeX, int ejeY, string color);

    string recorrerEjeX();
    string recorrerEjeY();

    string pintarEjeX();
    string pintarEjeY();
    string pintarBlancos();

    string imprimirLogico();
    string imprimirColor();
    string imprimirImagen();

    int numeroEjeX;
    int numeroEjeY;

private:
};

#endif /* MATRIZDISPERSA_H */

