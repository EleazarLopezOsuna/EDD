/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArbolABB.h
 * Author: USER
 *
 * Created on 18 de junio de 2019, 08:43 PM
 */

#ifndef ARBOLABB_H
#define ARBOLABB_H
#include "NodoABB.h"
#include <iostream>
#include <string>
#include "ListaCapas.h"

using namespace std;

class ArbolABB
{
public:
    ArbolABB();
    NodoABB* root;

    string insertarNodo(Capa* capa);

    string preOrdenGrafica(NodoABB* nodo);
    string preOrden(NodoABB* nodo);
    string inOrden(NodoABB* nodo);
    string postOrden(NodoABB* nodo);
    string graficaEspejo(NodoABB* nodo);
    void capasHoja(NodoABB* nodo);

    bool existe(NodoABB* raiz, Capa* capa);
    Capa* existe(NodoABB* raiz, int idNuevo);
    int profundidad(NodoABB* raiz, int p);
    void capasPreOrden(NodoABB* nodo, ListaCapas* lista);
    void capasInOrden(NodoABB* nodo, ListaCapas* lista);
    void capasPostOrden(NodoABB* nodo, ListaCapas* lista);

    ListaCapas* capaHoja;

private:

};

#endif /* ARBOLABB_H */

