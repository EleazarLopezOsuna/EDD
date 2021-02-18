/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Imagen.h
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:44 PM
 */

#ifndef IMAGEN_H
#define IMAGEN_H
#include "ListaCapas.h"

class Imagen
{
public:

    Imagen();
    void setIdImagen(int id);
    void setListaCapas(ListaCapas* lista);

    int getIdImagen();
    ListaCapas* getListaCapas();
    string printImagen();

private:

    int idImagen;
    ListaCapas* listaCapas;
};

#endif /* IMAGEN_H */

