/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Imagen.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:44 PM
 */

#include "Imagen.h"

Imagen::Imagen()
{
    idImagen = 0;
    listaCapas = nullptr;
}

void Imagen::setIdImagen(int id)
{
    idImagen = id;
}

void Imagen::setListaCapas(ListaCapas* lista)
{
    listaCapas = lista;
}

int Imagen::getIdImagen()
{
    return idImagen;
}

ListaCapas* Imagen::getListaCapas()
{
    return listaCapas;
}

string Imagen::printImagen()
{
    string cabecera = "digraph{\nnode[shape = record; width = 1; height = 1]\n";
    string pie = "}";
    string nodosPintados = "";
    string nodosBlancos = "";
    string retorno = "";
    int ejeX = 0;
    int ejeY = 0;
    NodoCapa* temp = getListaCapas() -> head;
    while(temp != nullptr)
    {
        ejeX = ((temp -> getCapa() -> matriz -> numeroEjeX) > ejeX) ? temp -> getCapa() -> matriz -> numeroEjeX : ejeX;
        ejeY = ((temp -> getCapa() -> matriz -> numeroEjeY) > ejeY) ? temp -> getCapa() -> matriz -> numeroEjeY : ejeY;
        nodosPintados += temp -> getCapa() -> matriz -> imprimirImagen();
        temp = temp -> siguiente;
    }
    for(int i = ejeX - 1; i >= 0; i--)
    {
        for(int j = ejeY - 1; j >= 0; j--)
        {
            nodosBlancos += "C" + to_string(i) + "F" + to_string(j) + "[pos = \"" + to_string(i) + ",-" + to_string(j) +
                            "!\"; color = \"#FFFFFF\"; label = \"\"]\n";
        }
    }
    retorno = cabecera + nodosBlancos + nodosPintados + pie;
    return retorno;
}


