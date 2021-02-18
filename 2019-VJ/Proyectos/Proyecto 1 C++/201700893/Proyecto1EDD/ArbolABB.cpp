/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArbolABB.cpp
 * Author: USER
 *
 * Created on 18 de junio de 2019, 08:43 PM
 */

#include "ArbolABB.h"

ArbolABB::ArbolABB()
{
    root = nullptr;
    capaHoja = new ListaCapas();
}

bool ArbolABB::existe(NodoABB* raiz, Capa* capa)
{
    if(!raiz)
        return false;
    int idRaiz = raiz -> getCapa() -> getNombre();
    int idNuevo = capa -> getNombre();
    return (idNuevo == idRaiz) ? true : (idNuevo < idRaiz) ? existe(raiz -> hijoIzquierdo, capa) : existe(raiz -> hijoDerecho, capa);
}

Capa* ArbolABB::existe(NodoABB* raiz, int idNuevo)
{
    if(!raiz)
        return nullptr;
    int idRaiz = raiz -> getCapa() -> getNombre();
    return (idNuevo == idRaiz) ? raiz -> getCapa() : (idNuevo < idRaiz) ? existe(raiz -> hijoIzquierdo, idNuevo) : existe(raiz -> hijoDerecho, idNuevo);
}

string ArbolABB::insertarNodo(Capa* capa)
{
    NodoABB* nuevo = new NodoABB(capa);
    if(root == nullptr)
    {
        root = nuevo;
        return "Ingresado";
    }
    else if(!existe(root, capa))
    {
        NodoABB* temp = root;
        NodoABB* raiz;
        while(true)
        {
            raiz = temp;
            int codigoNuevo = capa -> getNombre();
            int codigoPadre = temp -> getCapa() -> getNombre();
            if(codigoNuevo < codigoPadre)
            {
                //Verifica si el nodo es hoja para el futuro reporte
                if((temp -> hijoDerecho != nullptr) || (temp -> hijoIzquierdo != nullptr))
                    temp -> setEsHoja(false);
                temp = temp -> hijoIzquierdo;
                if(temp == nullptr)
                {
                    raiz -> hijoIzquierdo = nuevo;
                    return "Ingresado";
                }
            }
            else
            {
                temp = temp -> hijoDerecho;
                if(temp == nullptr)
                {
                    raiz -> hijoDerecho = nuevo;
                    return "Ingresado";
                }
            }
        }
        return "Insertado";
    }
    else
        return "Dato Duplicado";
}

string ArbolABB::preOrdenGrafica(NodoABB* nodo)
{
    if(nodo != nullptr)
    {
        string nodoRaiz = "Nodo_" + to_string(nodo -> getCapa() -> getNombre()) +
                          "[label = \"<f0>|<f1>" + to_string(nodo -> getCapa() -> getNombre()) + "|<f2>\"; group = 1; fillcolor = darkseagreen2; style = filled]\n";
        string apuntador = "";
        if(nodo -> hijoIzquierdo != nullptr)
        {
            apuntador += "Nodo_" + to_string(nodo -> getCapa() -> getNombre()) + ":f0 -> "
                         "Nodo_" + to_string(nodo -> hijoIzquierdo -> getCapa() -> getNombre()) + ":f1\n";
        }
        if(nodo -> hijoDerecho != nullptr)
        {
            apuntador += "Nodo_" + to_string(nodo -> getCapa() -> getNombre()) + ":f2 -> "
                         "Nodo_" + to_string(nodo -> hijoDerecho -> getCapa() -> getNombre()) + ":f1\n";
        }
        string retorno = nodoRaiz + apuntador;
        return retorno + preOrdenGrafica(nodo -> hijoIzquierdo) + preOrdenGrafica(nodo -> hijoDerecho);
        ;
    }
    return "";
}

string ArbolABB::preOrden(NodoABB* nodo)
{
    string retorno = "";
    if(nodo != nullptr)
    {
        retorno = " " + to_string(nodo -> getCapa() -> getNombre());
        return retorno + preOrden(nodo -> hijoIzquierdo) + preOrden(nodo -> hijoDerecho);
    }
    return retorno;
}

string ArbolABB::inOrden(NodoABB* nodo)
{
    string retorno = "";
    if(nodo != nullptr)
    {
        retorno = " " + to_string(nodo -> getCapa() -> getNombre());
        return inOrden(nodo -> hijoIzquierdo) + retorno + inOrden(nodo -> hijoDerecho);
    }
    return retorno;
}

string ArbolABB::postOrden(NodoABB* nodo)
{
    string retorno = "";
    if(nodo != nullptr)
    {
        retorno = " " + to_string(nodo -> getCapa() -> getNombre());
        return postOrden(nodo -> hijoIzquierdo) + postOrden(nodo -> hijoDerecho) + retorno;
    }
    return retorno;
}

string ArbolABB::graficaEspejo(NodoABB* nodo)
{
    if(nodo != nullptr)
    {
        string nodoRaiz = "Nodo_" + to_string(nodo -> getCapa() -> getNombre()) +
                          "[label = \"<f0>|<f1>" + to_string(nodo -> getCapa() -> getNombre()) + "|<f2>\"; group = 1; fillcolor = darkseagreen2; style = filled]\n";
        string apuntador = "";
        if(nodo -> hijoIzquierdo != nullptr)
        {
            apuntador += "Nodo_" + to_string(nodo -> getCapa() -> getNombre()) + ":f2 -> "
                         "Nodo_" + to_string(nodo -> hijoIzquierdo -> getCapa() -> getNombre()) + ":f1\n";
        }
        if(nodo -> hijoDerecho != nullptr)
        {
            apuntador += "Nodo_" + to_string(nodo -> getCapa() -> getNombre()) + ":f0 -> "
                         "Nodo_" + to_string(nodo -> hijoDerecho -> getCapa() -> getNombre()) + ":f1\n";
        }
        string retorno = nodoRaiz + apuntador;
        return retorno + graficaEspejo(nodo -> hijoDerecho) + graficaEspejo(nodo -> hijoIzquierdo);
        ;
    }
    return "";
}

void ArbolABB::capasHoja(NodoABB* raiz)
{
    if(raiz)
    {
        if(raiz -> hijoIzquierdo == nullptr && raiz -> hijoDerecho == nullptr)
        {
            capaHoja -> insertarCabeza(raiz -> getCapa());
        }
        capasHoja(raiz -> hijoIzquierdo);
        capasHoja(raiz -> hijoDerecho);
    }
}

int ArbolABB::profundidad(NodoABB* raiz, int p)
{
    if(raiz)
    {
        int iz = profundidad(raiz -> hijoIzquierdo, p + 1);
        int der = profundidad(raiz -> hijoDerecho, p + 1);
        if(iz > der)
        {
            return iz;
        }
        else
        {
            return der;
        }
    }
    return p - 1;
}

void ArbolABB::capasPreOrden(NodoABB* nodo, ListaCapas* lista)
{
    if(nodo != nullptr)
    {
        if(lista -> existe(nodo -> getCapa() -> getNombre()))
        {
            cout << " " + to_string(nodo -> getCapa() -> getNombre());
        }
        capasPreOrden(nodo -> hijoIzquierdo, lista);
        capasPreOrden(nodo -> hijoDerecho, lista);
    }
}

void ArbolABB::capasInOrden(NodoABB* nodo, ListaCapas* lista)
{
    if(nodo != nullptr)
    {
        capasInOrden(nodo -> hijoIzquierdo, lista);
        if(lista -> existe(nodo -> getCapa() -> getNombre()))
        {
            cout << " " + to_string(nodo -> getCapa() -> getNombre());
        }
        capasInOrden(nodo -> hijoDerecho, lista);
    }
}

void ArbolABB::capasPostOrden(NodoABB* nodo, ListaCapas* lista)
{
    if(nodo != nullptr)
    {
        capasPostOrden(nodo -> hijoIzquierdo, lista);
        capasPostOrden(nodo -> hijoDerecho, lista);
        if(lista -> existe(nodo -> getCapa() -> getNombre()))
        {
            cout << " " + to_string(nodo -> getCapa() -> getNombre());
        }
    }
}
