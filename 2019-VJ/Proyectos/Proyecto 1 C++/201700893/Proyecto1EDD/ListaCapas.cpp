/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ListaCapas.cpp
 * Author: USER
 *
 * Created on 18 de junio de 2019, 03:41 PM
 */

#include "ListaCapas.h"

ListaCapas::ListaCapas()
{
    head = nullptr;
    numeroCapas = 0;
}

int ListaCapas::getNumeroCapas()
{
    return numeroCapas;
}

string ListaCapas::insertarCabeza(Capa* capa)
{
    NodoCapa* nuevo = new NodoCapa();
    nuevo -> setCapa(capa);
    if(head != nullptr)
    {
        NodoCapa* temp = head;
        while(temp -> siguiente != nullptr)
            temp = temp -> siguiente;
        temp -> siguiente = nuevo;
        numeroCapas++;
        return "Capa insertada";
    }
    else
    {
        head = nuevo;
        numeroCapas++;
        return "Capa insertada";
    }
    return "No se pudo insertar";
}

string ListaCapas::printCapas()
{
    string retorno = "";
    if(head != nullptr)
    {
        NodoCapa* temp = head;
        while(temp != nullptr)
        {
            string nombreCapaT = to_string(temp -> getCapa() -> getNombre());
            string nodo = "Capa_" + nombreCapaT + "[label = \"" + nombreCapaT + "\" ;fillcolor = crimson; style = filled]\n";
            if(temp -> siguiente != nullptr)
            {
                string nombreCapaT2 = to_string(temp -> siguiente -> getCapa() -> getNombre());
                string apuntador = "Capa_" + nombreCapaT + " -> " + "Capa_" + nombreCapaT2 + "\n";
                retorno += apuntador;
            }
            retorno += nodo;
            temp = temp -> siguiente;
        }
        return retorno;
    }
    retorno = "";
    return retorno;
}

string ListaCapas::printImagenesCapas(int codigoImagen, int codigoGrupo)
{
    string retorno = "";
    if(head != nullptr)
    {
        NodoCapa* temp = head;
        while(temp != nullptr)
        {
            string nombreCapaT = to_string(temp -> getCapa() -> getNombre());
            string nodo = "Capa_" + nombreCapaT + "_" + to_string(codigoImagen) + "[label = \"" + nombreCapaT + "\" ; fillcolor = lightblue; style = filled; group = " +
                          to_string(codigoGrupo) + "]\n";
            if(temp -> siguiente != nullptr)
            {
                string nombreCapaT2 = to_string(temp -> siguiente -> getCapa() -> getNombre());
                string apuntador = "Capa_" + nombreCapaT + "_" + to_string(codigoImagen) + " -> " +
                                   "Capa_" + nombreCapaT2 + "_" + to_string(codigoImagen) + "\n";
                retorno += apuntador;
            }
            retorno += nodo;
            temp = temp -> siguiente;
        }
        return retorno;
    }
    retorno = "";
    return retorno;
}

string ListaCapas::eliminarDato(string nombreCapa)
{
    if(head != nullptr)
    {
        NodoCapa* temp = head;
        NodoCapa* ant = nullptr;
        while(temp != nullptr)
        {
            string nombreCapaT = to_string(temp -> getCapa() -> getNombre());
            if(!nombreCapaT.compare(nombreCapa))
            {
                if(temp == head)
                {
                    head = temp -> siguiente;
                    return "Dato Eliminado";
                }
                ant -> siguiente = temp -> siguiente;
                return "Dato Eliminado";
            }
            ant = temp;
            temp = temp -> siguiente;
        }
        return "No se encontro el Dato";
    }
    return "Lista Vacia";
}

string ListaCapas::printCapaArbol()
{
    string retorno = "";
    if(head != nullptr)
    {
        NodoCapa* temp = head;
        while(temp != nullptr)
        {
            string nombreCapaT = to_string(temp -> getCapa() -> getNombre());
            string nodo = "Capa_L" + nombreCapaT + "[label = \"" + nombreCapaT + "\" ; fillcolor = crimson; style = filled; group = 0]\n";
            string apuntador = "";
            if(temp -> siguiente != nullptr)
            {
                string nombreCapaT2 = to_string(temp -> siguiente -> getCapa() -> getNombre());
                apuntador = "Capa_L" + nombreCapaT + " -> " + "Capa_L" + nombreCapaT2 + "\n";
                retorno += apuntador;
            }
            apuntador = "Capa_L" + nombreCapaT + " -> " + "Nodo_" + nombreCapaT + ":f1\n";
            retorno += nodo;
            retorno += apuntador;
            temp = temp -> siguiente;
        }
        return retorno;
    }
    retorno = "";
    return retorno;
}

string ListaCapas::print()
{
    string retorno = "";
    if(head != nullptr)
    {
        NodoCapa* temp = head;
        while(temp != nullptr)
        {
            string nombreCapaT = to_string(temp -> getCapa() -> getNombre());
            retorno += " " + nombreCapaT;
            temp = temp -> siguiente;
        }
        return retorno;
    }
    retorno = "";
    return retorno;
}

bool ListaCapas::existe(int codigo)
{
    if(head != nullptr)
    {
        NodoCapa* temp = head;
        while(temp != nullptr)
        {
            if(temp -> getCapa() -> getNombre() == codigo){
                return true;
            }
            temp = temp -> siguiente;
        }
        return false;
    }
    return false;
}
