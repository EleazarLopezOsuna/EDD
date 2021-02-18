/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   Lista.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 06:38 PM
 */

#include "ListaImagenes.h"

ListaImagenes::ListaImagenes()
{
    head = nullptr;
    tail = nullptr;
    cantidadImagenes = 0;
}

int ListaImagenes::getCantidadImagenes()
{
    return cantidadImagenes;
}

bool ListaImagenes::isEmpty()
{
    if (head == nullptr)
        return true;
    return false;
}

Imagen* ListaImagenes::buscar(int codigo)
{
    NodoImagen* temp = head;
    if(!head)
        return nullptr;
    do
    {
        if(codigo == temp -> getImagen() -> getIdImagen())
        {
            return temp -> getImagen();
        }
        temp = temp -> siguiente;
    }
    while (temp != head);
    return nullptr;
}

void ListaImagenes::ordenarLista(int tipo)
{
    NodoImagen* primero = head;
    do
    {
        NodoImagen* segundo = primero -> siguiente;
        do
        {
            if(tipo)
            {
                int capasPrimero, capasSegundo;
                capasPrimero = primero -> getImagen() -> getListaCapas() -> getNumeroCapas();
                capasSegundo = segundo -> getImagen() -> getListaCapas() -> getNumeroCapas();
                if(capasPrimero < capasSegundo)
                {
                    Imagen* temp = primero -> getImagen();
                    primero -> setImagen(segundo -> getImagen());
                    segundo -> setImagen(temp);
                }
            }
            else
            {
                int codigoPrimero, codigoSegundo;
                codigoPrimero = primero -> getImagen() -> getIdImagen();
                codigoSegundo = segundo -> getImagen() -> getIdImagen();
                if (codigoPrimero > codigoSegundo)
                {
                    Imagen* temp = primero -> getImagen();
                    primero -> setImagen(segundo -> getImagen());
                    segundo -> setImagen(temp);
                }
            }
            segundo = segundo -> siguiente;
        }
        while (segundo != head);
        primero = primero -> siguiente;
    }
    while (primero != head -> anterior);
}

string ListaImagenes::insertarOrdenado(Imagen* imagen)
{
    NodoImagen* nuevo = new NodoImagen();
    nuevo -> setImagen(imagen);
    if (head == nullptr)
    {
        nuevo -> siguiente = nuevo;
        nuevo -> anterior = nuevo;
        head = nuevo;
        tail = nuevo;
    }
    else
    {
        if(!buscar(imagen -> getIdImagen()))
        {
            nuevo -> anterior = tail;
            tail -> siguiente = nuevo;
            head -> anterior = nuevo;
            nuevo -> siguiente = head;
            head = nuevo;
            ordenarLista(0);
        }
        else
        {
            return "Imagen Duplicada";
        }
    }
    cantidadImagenes++;
    return "Imagen " + to_string(imagen -> getIdImagen()) + " Insertada";
}

string ListaImagenes::printImagenes()
{
    string retorno = "";
    NodoImagen* temp = head;
    if (!isEmpty())
    {
        do
        {
            string codigoA = to_string(temp -> getImagen() -> getIdImagen());
            string codigoP = to_string(temp -> anterior -> getImagen() -> getIdImagen());
            string codigoN = to_string(temp -> siguiente -> getImagen() -> getIdImagen());
            retorno += "Imagen_" + codigoA + "[label = \"" + codigoA + "\"; fillcolor = crimson; style = filled]\n";
            retorno += "Imagen_" + codigoA + " -> " + "Imagen_" + codigoP + "\n";
            retorno += "Imagen_" + codigoA + " -> " + "Imagen_" + codigoN + "\n";
            temp = temp -> siguiente;
        }
        while (temp != head);
    }
    else
    {
        retorno = "Lista Vacia";
    }
    return retorno;
}

string ListaImagenes::printImagenes(string nombreUsuario)
{
    string retorno = "";
    NodoImagen* temp = head;
    if (!isEmpty())
    {
        do
        {
            string codigoA = to_string(temp -> getImagen() -> getIdImagen());
            string codigoP = to_string(temp -> anterior -> getImagen() -> getIdImagen());
            string codigoN = to_string(temp -> siguiente -> getImagen() -> getIdImagen());
            retorno += "Imagen_" + codigoA + nombreUsuario + "[label = \"" + codigoA + "\"; style = filled; fillcolor = skyblue]\n";
            retorno += "Imagen_" + codigoA + nombreUsuario + " -> " + "Imagen_" + codigoP + nombreUsuario + "\n";
            retorno += "Imagen_" + codigoA + nombreUsuario + " -> " + "Imagen_" + codigoN + nombreUsuario + "\n";
            temp = temp -> siguiente;
        }
        while (temp != head);
    }
    else
    {
        retorno = "Lista Vacia";
    }
    return retorno;
}

string ListaImagenes::printImagenesCapas()
{
    string retorno = "digraph{\nnode[shape = record]\n";
    string ranki = "{rank = same";
    NodoImagen* temp = head;
    int contador = 1;
    if (!isEmpty())
    {
        do
        {
            string codigoA = to_string(temp -> getImagen() -> getIdImagen());
            string codigoP = to_string(temp -> anterior -> getImagen() -> getIdImagen());
            string codigoN = to_string(temp -> siguiente -> getImagen() -> getIdImagen());
            if(temp == head)
            {
                retorno += "Imagen_" + codigoA + "[label = \"" + codigoA + "\" ; fillcolor = crimson; style = filled; group = " +
                           to_string(contador) + "]\n";
            }
            else if(temp == tail)
            {
                retorno += "Imagen_" + codigoA + "[label = \"" + codigoA + "\" ; fillcolor = crimson; style = filled; group = " +
                           to_string(contador) + "]\n";
            }
            else
            {
                retorno += "Imagen_" + codigoA + "[label = \"" + codigoA + "\" ; fillcolor = crimson; style = filled; group = " +
                           to_string(contador) + "]\n";
            }
            retorno += "Imagen_" + codigoA + " -> " + "Imagen_" + codigoN + "\n";
            retorno += "Imagen_" + codigoA + " -> " + "Imagen_" + codigoP + "\n";
            if(temp -> getImagen() -> getListaCapas() -> head != nullptr)
            {
                string nombreCapaHead = to_string(temp -> getImagen() -> getListaCapas() -> head -> getCapa() -> getNombre());
                retorno += temp -> getImagen() -> getListaCapas() -> printImagenesCapas(temp -> getImagen() -> getIdImagen(), contador);
                retorno += "Imagen_" + codigoA + " -> " + "Capa_" + nombreCapaHead + "_" + codigoA + "\n";
            }
            ranki += "; Imagen_" + codigoA;
            temp = temp -> anterior;
            contador++;
        }
        while (temp != head);
    }
    else
    {
        retorno = "Lista Vacia";
    }
    ranki += "}\n";
    retorno += ranki + "}";
    return retorno;
}

string ListaImagenes::eliminarDato(int codigoImagen)
{
    if (!isEmpty())
    {
        NodoImagen* temp = head;
        do
        {
            if ((temp -> getImagen() -> getIdImagen()) == codigoImagen)
            {
                if (head == tail)
                {
                    head = nullptr;
                    tail = nullptr;
                    return "Imagen " + to_string(codigoImagen) + " Eliminada";
                }
                if (temp == head)
                {
                    head = temp -> siguiente;
                    tail -> siguiente = head;
                }
                else if (temp == tail)
                {
                    NodoImagen* tempAnt = temp -> anterior;
                    tempAnt -> siguiente = head;
                    tail = tempAnt;
                    head -> anterior = tail;
                }
                else
                {
                    NodoImagen* tempAnterior = temp -> anterior;
                    NodoImagen* tempSiguiente = temp -> siguiente;
                    tempAnterior -> siguiente = tempSiguiente;
                    tempSiguiente -> anterior = tempAnterior;
                    return "Imagen " + to_string(codigoImagen) + " Insertada";
                }
            }
            temp = temp -> siguiente;
        }
        while (temp != head);
        return "Dato no encontrado";
    }
    else
    {
        return "Lista Vacia";
    }
}

string ListaImagenes::recorrer()
{
    string retorno = "";
    NodoImagen* temp = head;
    if(temp)
    {
        do
        {
            if(temp -> siguiente != head)
                retorno += to_string(temp -> getImagen() -> getIdImagen()) + ", ";
            else
                retorno += to_string(temp -> getImagen() -> getIdImagen());
            temp = temp -> siguiente;
        }
        while (temp != head);
    }
    return retorno;
}

string ListaImagenes::graficaImagenArbol(int codigo)
{
    string retorno = "";
    NodoImagen* temp = head;
    do
    {
        if(codigo == temp -> getImagen() -> getIdImagen())
        {
            retorno += "Imagen_" + to_string(codigo) + "[label = \"" + to_string(codigo) + "\" ; group = 0; fillcolor = lightblue; style = filled]\n";
            if(temp -> getImagen() -> getListaCapas() -> head != nullptr)
            {
                string nombreCapaHead = to_string(temp -> getImagen() -> getListaCapas() -> head -> getCapa() -> getNombre());
                retorno += temp -> getImagen() -> getListaCapas() -> printCapaArbol();
                retorno += "Imagen_" + to_string(codigo) + " -> " + "Capa_L" + nombreCapaHead  + "\n";
            }
        }
        temp = temp -> siguiente;
    }
    while(temp != head);
    return retorno;
}

string ListaImagenes::Top5()
{
    string retorno = "";
    ListaImagenes* listaNueva = new ListaImagenes();
    NodoImagen* temp = head;
    int contador = 5;
    do
    {
        if(contador)
        {
            listaNueva -> insertarOrdenado1(temp -> getImagen());
            contador--;
        }
        else
        {
            int a = temp -> getImagen() -> getListaCapas() -> getNumeroCapas();
            int b = listaNueva -> head -> getImagen() -> getListaCapas() -> getNumeroCapas();
            if(a > b)
            {
                listaNueva -> eliminarDato(listaNueva -> head -> getImagen() -> getIdImagen());
                listaNueva -> insertarOrdenado1(temp -> getImagen());
            }
        }
        temp = temp -> siguiente;
    }
    while(temp != head);
    NodoImagen* tmp = listaNueva -> head;
    if(tmp)
    {
        do
        {
            if(tmp -> siguiente != head)
                retorno += "Imagen: " + to_string(tmp -> getImagen() -> getIdImagen()) +
                           " Capas: " + to_string(tmp -> getImagen() -> getListaCapas() -> getNumeroCapas()) + "\n";
            else
                retorno += "Imagen: " + to_string(tmp -> getImagen() -> getIdImagen()) +
                           " Capas: " + to_string(tmp -> getImagen() -> getListaCapas() -> getNumeroCapas());
            tmp = tmp -> siguiente;
        }
        while (tmp != listaNueva -> head);
    }
    return retorno;
}

string ListaImagenes::insertarOrdenado1(Imagen* imagen)
{
    NodoImagen* nuevo = new NodoImagen();
    nuevo -> setImagen(imagen);
    if (head == nullptr)
    {
        nuevo -> siguiente = nuevo;
        nuevo -> anterior = nuevo;
        head = nuevo;
        tail = nuevo;
    }
    else
    {
        if(!buscar(imagen -> getIdImagen()))
        {
            nuevo -> anterior = tail;
            tail -> siguiente = nuevo;
            head -> anterior = nuevo;
            nuevo -> siguiente = head;
            head = nuevo;
            ordenarLista(1);
        }
        else
        {
            return "Imagen Duplicada";
        }
    }
    cantidadImagenes++;
    return "Imagen " + to_string(imagen -> getIdImagen()) + " Insertada";
}
