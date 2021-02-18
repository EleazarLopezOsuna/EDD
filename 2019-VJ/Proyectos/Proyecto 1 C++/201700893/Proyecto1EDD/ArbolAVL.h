/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArbolAVL.h
 * Author: USER
 *
 * Created on 19 de junio de 2019, 10:13 AM
 */

#ifndef ARBOLAVL_H
#define ARBOLAVL_H
#include "NodoAVL.h"
#include "ListaImagenes.h"
#include "ListaUsuario.h"

class ArbolAVL
{
public:

    NodoAVL* root;
    ArbolAVL();

    //Metodos USUARIO
    Usuario* obtenerUsuario(NodoAVL* raiz, string nombre);

    //Metodos INT
    int maximo(int valor1, int valor2);
    int altura();

    //Metodos BOOL
    bool isEmpty();
    bool ingresado(string name);
    bool ingresado(NodoAVL* nodo, string name);
    bool insertar(Usuario* user);
    bool eliminar(string nombre);

    //Metodos VOID
    void obtenerFE(NodoAVL* nodo);
    void recorrerNiveles(NodoAVL* nodo, int nivel);

    //Metodos STRING
    string preOrdenGrafica(NodoAVL* nodo);
    string preOrden(NodoAVL* nodo);
    string inOrden(NodoAVL* nodo);
    string postOrden(NodoAVL* nodo);
    string graficaArbolLista(NodoAVL* nodo);
    string Top5(NodoAVL* raiz);

    //Metodos NODOAVL
    NodoAVL* rotacionSimpleIzquierda(NodoAVL* nodo);
    NodoAVL* rotacionSimpleDerecha(NodoAVL* nodo);
    NodoAVL* rotacionDobleIzquierda(NodoAVL* nodo);
    NodoAVL* rotacionDobleDerecha(NodoAVL* nodo);
    NodoAVL* balancear(NodoAVL* raiz);
    NodoAVL* insertarBalanceado(NodoAVL* raiz, NodoAVL* nuevo);
    NodoAVL* eliminar(NodoAVL* raiz, string nombre);

    ListaImagenes* Top;
    ListaUsuario* niveles;
    ListaUsuario* TopU;

private:
};

#endif /* ARBOLAVL_H */

