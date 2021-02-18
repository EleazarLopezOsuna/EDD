/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Usuario.h
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:36 PM
 */

#ifndef USUARIO_H
#define USUARIO_H
#include "ListaImagenes.h"
#include <string>

using namespace std;

class Usuario
{
public:

    Usuario();
    void setListaImagenes(ListaImagenes* imagenes);
    void setNombreUsuario(string nombre);

    string getNombreUsuario();
    ListaImagenes* getListaImagenes();
    void setNivel(int n);
    int getNivel();

private:
    string nombreUsuario;
    ListaImagenes* listaImagenes;
    int nivel;
};

#endif /* USUARIO_H */

