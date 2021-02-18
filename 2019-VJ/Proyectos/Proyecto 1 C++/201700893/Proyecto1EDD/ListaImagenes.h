/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Lista.h
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:38 PM
 */

#ifndef LISTAIMAGENES_H
#define LISTAIMAGENES_H
#include <string>
#include <iostream>
#include "Imagen.h"
#include "NodoImagen.h"

using namespace std;

class ListaImagenes
{
public:

    NodoImagen* head;
    NodoImagen* tail;
    ListaImagenes();
    void ordenarLista(int tipo);
    bool isEmpty();
    string insertarOrdenado(Imagen* imagen);
    string insertarOrdenado1(Imagen* imagen);
    string printImagenes();
    string printImagenes(string nombreUsuario);
    string printImagenesCapas();
    string eliminarDato(int codigoImagen);
    int getCantidadImagenes();
    Imagen* buscar(int codigo);
    string recorrer();
    string graficaImagenArbol(int codigo);
    string Top5();
private:
    int cantidadImagenes;
};

#endif /* LISTAIMAGENES_H */

