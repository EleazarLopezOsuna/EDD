/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Capa.h
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:41 PM
 */

#ifndef CAPA_H
#define CAPA_H
#include <string>
#include "MatrizDispersa.h"

using namespace std;

class Capa
{
public:
    Capa();

    void setNombre(int nombre);
    int getNombre();
    MatrizDispersa* matriz;

private:
    int Nombre;
};

#endif /* CAPA_H */

