/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Usuario.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:36 PM
 */

#include "Usuario.h"

Usuario::Usuario()
{
    listaImagenes = nullptr;
    nombreUsuario = "";
}

void Usuario::setListaImagenes(ListaImagenes* imagenes)
{
    listaImagenes = imagenes;
}

void Usuario::setNombreUsuario(string nombre)
{
    nombreUsuario = nombre;
}

void Usuario::setNivel(int n)
{
    nivel = n;
}

ListaImagenes* Usuario::getListaImagenes()
{
    return listaImagenes;
}

string Usuario::getNombreUsuario()
{
    return nombreUsuario;
}

int Usuario::getNivel()
{
    return nivel;
}
