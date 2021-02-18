/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   MatrizDispersa.cpp
 * Author: USER
 *
 * Created on 20 de junio de 2019, 02:06 PM
 */

#include "MatrizDispersa.h"

MatrizDispersa::MatrizDispersa()
{
    numeroEjeX = 0;
    numeroEjeY = 0;
    root = new NodoCabecera();
}

string MatrizDispersa::agregar(int ejeX, int ejeY, string color)
{
    NodoContenido* nuevo = new NodoContenido();
    nuevo -> setColor(color);
    nuevo -> coordenadaX = ejeX;
    nuevo -> coordenadaY = ejeY;
    /* temp = root no va adentro del for para que sea mas eficiente
     * entonces se recorre una sola vez todo el contenido
     * ejemplo: teniendo la siguiente lista
     * 1 -> 2 -> 3 -> nullptr
     * deseo agregar hasta el nodo 6
     * Primera iteracion:
     *      temp = 0, temp = 1, temp = 2, temp = 3, temp = 4
     * Segunda iteracion:
     *      temp = 4, temp = 5
     * Tercera iteracion:
     *      temp = 5, temp = 6
     *
     * Si temp = root estuviera dentro del for
     * Primera iteracion:
     *      temp = 0, temp = 1, temp = 2, temp = 3, temp = 4
     * Segunda iteracion:
     *      temp = 0, temp = 1, temp = 2, temp = 3, temp = 4, temp = 5
     * Tercera iteracion:
     *      temp = 0, temp = 1, temp = 2, temp = 3, temp = 4, temp = 5, temp = 6
     *
     * Total de iteraciones con temp = root afuera = 6
     * Total de iteraciones con temp = root adentro = 15
     */
    NodoCabecera* temp = root;
    for (int i = numeroEjeX; i <= ejeX; i++)
    {
        numeroEjeX++;
        NodoCabecera* nuevo = new NodoCabecera();
        nuevo -> numeroCabecera = i;
        while (temp != nullptr)
        {
            if (temp -> derecha == nullptr)
            {
                temp -> derecha = nuevo;
                temp = temp -> derecha;
                break;
            }
            temp = temp -> derecha;
        }
    }
    temp = root;
    for (int i = numeroEjeY; i <= ejeY; i++)
    {
        numeroEjeY++;
        NodoCabecera* nuevo = new NodoCabecera();
        nuevo -> numeroCabecera = i;
        while (temp != nullptr)
        {
            if (temp -> abajo == nullptr)
            {
                temp -> abajo = nuevo;
                temp = temp -> abajo;
                break;
            }
            temp = temp -> abajo;
        }
    }
    //Despues de ingresar las filas y columnas necesarias
    temp = root;
    NodoContenido* tempContenido;
    //Recorrer las cabeceras de Columna
    while (temp != nullptr)
    {
        int cabeceraActual = temp -> numeroCabecera;
        if (cabeceraActual == ejeX)
        {
            tempContenido = temp -> contenido;
            if (tempContenido == nullptr)
            {
                temp -> contenido = nuevo;
            }
            else
            {
                while (tempContenido != nullptr)
                {
                    if (tempContenido -> coordenadaY > nuevo -> coordenadaY)
                    {
                        if (tempContenido == temp -> contenido)
                        {
                            //Es cabeza
                            nuevo -> abajo = tempContenido;
                            tempContenido -> arriba = nuevo;
                            temp -> contenido = nuevo;
                        }
                        else
                        {
                            nuevo -> abajo = tempContenido;
                            NodoContenido* tmp = tempContenido -> arriba;
                            tmp -> abajo = nuevo;
                            nuevo -> arriba = tmp;
                            tempContenido -> arriba = nuevo;
                        }
                        break;
                    }
                    else
                    {
                        if (tempContenido -> abajo == nullptr)
                        {
                            nuevo -> arriba = tempContenido;
                            tempContenido -> abajo = nuevo;
                            break;
                        }
                    }
                    tempContenido = tempContenido -> abajo;
                }
            }
            break;
        }
        temp = temp -> derecha;
    }
    temp = root;
    //Recorrer las cabeceras de Fila
    while (temp != nullptr)
    {
        int cabeceraActual = temp -> numeroCabecera;
        if (cabeceraActual == ejeY)
        {
            tempContenido = temp -> contenido;
            if (tempContenido == nullptr)
            {
                temp -> contenido = nuevo;
            }
            else
            {
                while (tempContenido != nullptr)
                {
                    if (tempContenido -> coordenadaX > nuevo -> coordenadaX)
                    {
                        if (tempContenido == temp -> contenido)
                        {
                            //Es cabeza
                            nuevo -> siguiente = tempContenido;
                            tempContenido -> anterior = nuevo;
                            temp -> contenido = nuevo;
                        }
                        else
                        {
                            nuevo -> siguiente = tempContenido;
                            NodoContenido* tmp = tempContenido -> anterior;
                            tmp -> siguiente = nuevo;
                            nuevo -> anterior = tmp;
                            tempContenido -> anterior = nuevo;
                        }
                        break;
                    }
                    else
                    {
                        if (tempContenido -> siguiente == nullptr)
                        {
                            nuevo -> anterior = tempContenido;
                            tempContenido -> siguiente = nuevo;
                            break;
                        }
                    }
                    tempContenido = tempContenido -> siguiente;
                }
            }
            break;
        }
        temp = temp -> abajo;
    }
    return "Ingresado";
}

string MatrizDispersa::recorrerEjeX()
{
    if (root == nullptr)
        return "Matriz Vacia";
    else
    {
        NodoCabecera* temp = root;
        string retorno = "";
        string nodo = "";
        string apuntador = "";
        while (temp != nullptr)
        {
            if (temp -> numeroCabecera != -1)
            {
                nodo = "C_" + to_string(temp -> numeroCabecera) + "[label = \"" + to_string(temp -> numeroCabecera) +
                       "\"; pos = \"" + to_string(temp -> numeroCabecera) + ",1!\"; fillcolor = crimson; style = filled]\n";
                if (temp -> derecha != nullptr)
                {
                    retorno += "C_" + to_string(temp -> numeroCabecera) + " -> C_" +
                               to_string(temp -> derecha -> numeroCabecera) + "\n";
                    retorno += "C_" + to_string(temp -> derecha -> numeroCabecera) + " -> C_" +
                               to_string(temp -> numeroCabecera) + "\n";
                }
            }
            retorno += nodo;
            NodoContenido* cont = temp -> contenido;
            if (cont != nullptr)
            {
                int ejeX = cont -> coordenadaX;
                int ejeY = cont -> coordenadaY;
                apuntador = "C_" + to_string(temp -> numeroCabecera) + " -> C" + to_string(ejeX) + "F" + to_string(ejeY) + "\n";
                apuntador += "C" + to_string(ejeX) + "F" + to_string(ejeY) + " -> C_" + to_string(temp -> numeroCabecera) + "\n";
                retorno += apuntador;
            }
            while (cont != nullptr)
            {
                //Creo el NodoContenido y apunto hacia abajo
                int ejeX = cont -> coordenadaX;
                int ejeY = cont -> coordenadaY;
                nodo = "C" + to_string(ejeX) + "F" + to_string(ejeY) +
                       "[label = \"" + cont -> getColor() +
                       "\"; pos = \"" + to_string(ejeX) + ",-" + to_string(ejeY) + "!\"; fillcolor = lightblue; style = filled]\n";
                if (cont -> abajo != nullptr)
                {
                    int ejeX1 = cont -> abajo -> coordenadaX;
                    int ejeY1 = cont -> abajo -> coordenadaY;
                    apuntador = "C" + to_string(ejeX) + "F" + to_string(ejeY) + " -> " +
                                "C" + to_string(ejeX1) + "F" + to_string(ejeY1) + "\n";
                    apuntador += "C" + to_string(ejeX1) + "F" + to_string(ejeY1) + " -> " +
                                 "C" + to_string(ejeX) + "F" + to_string(ejeY) + "\n";
                    retorno += apuntador;
                }
                retorno += nodo;
                cont = cont -> abajo;
            }
            temp = temp -> derecha;
        }
        return retorno;
    }
}

string MatrizDispersa::recorrerEjeY()
{
    if (root == nullptr)
        return "Matriz Vacia";
    else
    {
        NodoCabecera* temp = root;
        string retorno = "";
        string nodo = "";
        string apuntador = "";
        while (temp != nullptr)
        {
            if (temp -> numeroCabecera != -1)
            {
                nodo = "F_" + to_string(temp -> numeroCabecera) + "[label = \"" + to_string(temp -> numeroCabecera) +
                       "\"; pos = \"-1,-" + to_string(temp -> numeroCabecera) + "!\"; fillcolor = crimson; style = filled]\n";
                if (temp -> abajo != nullptr)
                {
                    retorno += "F_" + to_string(temp -> numeroCabecera) + " -> F_" +
                               to_string(temp -> abajo -> numeroCabecera) + "\n";
                    retorno += "F_" + to_string(temp -> abajo -> numeroCabecera) + " -> F_" +
                               to_string(temp -> numeroCabecera) + "\n";
                }
            }
            retorno += nodo;
            NodoContenido* cont = temp -> contenido;
            if (cont != nullptr)
            {
                int ejeX = cont -> coordenadaX;
                int ejeY = cont -> coordenadaY;
                if (temp -> numeroCabecera != -1)
                {
                    apuntador = "F_" + to_string(temp -> numeroCabecera) + " -> C" + to_string(ejeX) + "F" + to_string(ejeY) + "\n";
                    apuntador += "C" + to_string(ejeX) + "F" + to_string(ejeY) + " -> F_" + to_string(temp -> numeroCabecera) + "\n";
                }
                else
                {
                    apuntador = "F_A -> C" + to_string(ejeX) + "F" + to_string(ejeY) + "\n";
                    apuntador += "C" + to_string(ejeX) + "F" + to_string(ejeY) + " -> F_A";
                }
                retorno += apuntador;
            }
            while (cont != nullptr)
            {
                //Tomo el NodoContenido ya creado y apunto a la derecha
                int ejeX = cont -> coordenadaX;
                int ejeY = cont -> coordenadaY;
                if (cont -> siguiente != nullptr)
                {
                    int ejeX1 = cont -> siguiente -> coordenadaX;
                    int ejeY1 = cont -> siguiente -> coordenadaY;
                    apuntador = "C" + to_string(ejeX) + "F" + to_string(ejeY) + " -> " +
                                "C" + to_string(ejeX1) + "F" + to_string(ejeY1) + "\n";
                    apuntador += "C" + to_string(ejeX1) + "F" + to_string(ejeY1) + " -> " +
                                 "C" + to_string(ejeX) + "F" + to_string(ejeY) + "\n";
                    retorno += apuntador;
                }
                cont = cont -> siguiente;
            }
            temp = temp -> abajo;
        }
        return retorno;
    }
}

string MatrizDispersa::imprimirLogico()
{
    string retorno = "";
    retorno += "digraph{\nnode[shape = record; fontsize = 10]\n";
    retorno += "MATRIZ[label = \"By: JLopez\"; pos = \"-1,1!\"]\nMATRIZ -> C_0\nMATRIZ -> F_0\n";
    retorno += recorrerEjeX();
    retorno += recorrerEjeY();
    retorno += "}";
    return retorno;
}

string MatrizDispersa::pintarEjeX()
{
    if (root == nullptr)
        return "A[style = filled; color = \"#000000\"; pos = \"0,0!\"]";
    else
    {
        NodoCabecera* temp = root;
        string retorno = "";
        string nodo = "";
        string apuntador = "";
        while (temp != nullptr)
        {
            NodoContenido* cont = temp -> contenido;
            while (cont != nullptr)
            {
                //Creo el NodoContenido y apunto hacia abajo
                int ejeX = cont -> coordenadaX;
                int ejeY = cont -> coordenadaY;
                nodo = "C" + to_string(ejeX) + "F" + to_string(ejeY) +
                       "[style = filled; color = \"" + cont -> getColor() + "\" ;pos = \"" +
                       to_string(ejeX) + ",-" + to_string(ejeY) + "!\"]\n";
                retorno += nodo;
                cont = cont -> abajo;
            }
            temp = temp -> derecha;
        }
        return retorno;
    }
}

string MatrizDispersa::pintarEjeY()
{
    if (root == nullptr)
        return "A[style = filled; color = \"#000000\"; pos = \"0,0!\"]";
    else
    {
        NodoCabecera* temp = root;
        string retorno = "";
        string nodo = "";
        string apuntador = "";
        while (temp != nullptr)
        {
            NodoContenido* cont = temp -> contenido;
            while (cont != nullptr)
            {
                //Creo el NodoContenido y apunto hacia abajo
                int ejeX = cont -> coordenadaX;
                int ejeY = cont -> coordenadaY;
                nodo = "C" + to_string(ejeX) + "F" + to_string(ejeY) +
                       "[style = filled; color = \"" + cont -> getColor() + "\" ;pos = \"" +
                       to_string(ejeX) + ",-" + to_string(ejeY) + "!\"]\n";
                retorno += nodo;
                cont = cont -> siguiente;
            }
            temp = temp -> derecha;
        }
        return retorno;
    }
}

string MatrizDispersa::pintarBlancos()
{
    string retorno = "";
    for(int i = numeroEjeX - 1; i >= 0; i--)
    {
        for(int j = numeroEjeY - 1; j >= 0; j--)
        {
            retorno += "C" + to_string(i) + "F" + to_string(j) + "[pos = \"" + to_string(i) + ",-" + to_string(j) +
                       "!\"; color = \"#FFFFFF\"; label = \"\"]\n";
        }
    }
    return retorno;
}

string MatrizDispersa::imprimirColor()
{
    string retorno = "";
    retorno += "digraph{\nnode[shape = record; width = 1; height = 1]\n";
    retorno += pintarBlancos();
    retorno += pintarEjeX();
    retorno += pintarEjeY();
    retorno += "}";
    return retorno;
}

string MatrizDispersa::imprimirImagen()
{
    string retorno = "";
    retorno += pintarEjeX();
    retorno += pintarEjeY();
    return retorno;
}
