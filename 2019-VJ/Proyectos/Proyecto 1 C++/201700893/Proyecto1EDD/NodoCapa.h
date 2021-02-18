/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   NodoCapa.h
 * Author: USER
 *
 * Created on 17 de junio de 2019, 07:45 PM
 */

#ifndef NODOCAPA_H
#define NODOCAPA_H
#include "Capa.h"

class NodoCapa
{
public:

    NodoCapa();

    NodoCapa* siguiente;
    NodoCapa* anterior;

    void setCapa(Capa* layer);
    Capa* getCapa();

private:
    Capa* capa;
};

#endif /* NODOCAPA_H */

