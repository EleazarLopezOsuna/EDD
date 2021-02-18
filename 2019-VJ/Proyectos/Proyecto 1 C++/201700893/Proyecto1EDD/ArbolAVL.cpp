/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ArbolAVL.cpp
 * Author: USER
 *
 * Created on 19 de junio de 2019, 10:13 AM
 */

#include "ArbolAVL.h"
#include "Usuario.h"

ArbolAVL::ArbolAVL()
{
    root = nullptr;
    niveles = new ListaUsuario();
    TopU = new ListaUsuario();
}

int ArbolAVL::maximo(int valor1, int valor2)
{
    if (valor1 > valor2)
        return valor1;
    return valor2;
}

int ArbolAVL::altura()
{
    if (root == nullptr)
        return 0;
    return root -> altura;
}

bool ArbolAVL::isEmpty()
{
    return (root == nullptr) ? false : true;
}

bool ArbolAVL::ingresado(string nombre)
{
    return ingresado(root, nombre);
}

bool ArbolAVL::ingresado(NodoAVL* raiz, string nombre)
{
    if (raiz == nullptr)
        return false;
    if (nombre < (raiz -> getUsuario() -> getNombreUsuario()))
        return ingresado(raiz -> hijoIzquierdo, nombre);
    else if(nombre == (raiz -> getUsuario() -> getNombreUsuario()))
        return true;
    else
        return ingresado(raiz -> hijoDerecho, nombre);
    return true;
}

void ArbolAVL::obtenerFE(NodoAVL* nodo)
{
    int alturaIzquierda = (nodo -> hijoIzquierdo == nullptr) ? -1 : nodo -> hijoIzquierdo -> altura;
    int alturaDerecha = (nodo -> hijoDerecho == nullptr) ? -1 : nodo -> hijoDerecho -> altura;
    nodo -> setAltura(1 + maximo(alturaIzquierda, alturaDerecha));
    nodo -> setFactorEquilibrio(alturaDerecha - alturaIzquierda);
}

NodoAVL* ArbolAVL::rotacionSimpleIzquierda(NodoAVL* nodo)
{
    NodoAVL* temp = nodo -> hijoIzquierdo;
    nodo -> hijoIzquierdo = temp -> hijoDerecho;
    temp -> hijoDerecho = nodo;
    obtenerFE(nodo);
    obtenerFE(temp);
    return temp;
}

NodoAVL* ArbolAVL::rotacionSimpleDerecha(NodoAVL* nodo)
{
    NodoAVL* temp = nodo -> hijoDerecho;
    nodo -> hijoDerecho = temp -> hijoIzquierdo;
    temp -> hijoIzquierdo = nodo;
    obtenerFE(nodo);
    obtenerFE(temp);
    return temp;
}

NodoAVL* ArbolAVL::rotacionDobleIzquierda(NodoAVL* nodo)
{
    nodo -> hijoIzquierdo = rotacionSimpleDerecha(nodo -> hijoIzquierdo);
    return rotacionSimpleIzquierda(nodo);;
}

NodoAVL* ArbolAVL::rotacionDobleDerecha(NodoAVL* nodo)
{
    nodo -> hijoDerecho = rotacionSimpleIzquierda(nodo -> hijoDerecho);
    return rotacionSimpleDerecha(nodo);
}

NodoAVL* ArbolAVL::balancear(NodoAVL* raiz)
{
    if (raiz -> getFactorEquilibrio() == -2)
        if (raiz -> hijoIzquierdo -> getFactorEquilibrio() <= 0)
            return rotacionSimpleIzquierda(raiz);
        else
            return rotacionDobleIzquierda(raiz);
    else if (raiz -> getFactorEquilibrio() == 2)
        if (raiz -> hijoDerecho -> getFactorEquilibrio() >= 0)
            return rotacionSimpleDerecha(raiz);
        else
            return rotacionDobleDerecha(raiz);
    return raiz;
}

NodoAVL* ArbolAVL::insertarBalanceado(NodoAVL* raiz, NodoAVL* nuevo)
{
    if (raiz == nullptr)
        return nuevo;
    //Hace la insercion como si fuera un ABB
    if ((nuevo -> getUsuario() -> getNombreUsuario()) < (raiz -> getUsuario() ->getNombreUsuario()))
        raiz -> hijoIzquierdo = insertarBalanceado(raiz -> hijoIzquierdo, nuevo);
    else
        raiz -> hijoDerecho = insertarBalanceado(raiz -> hijoDerecho, nuevo);
    //Recalcula los factores de equilibrio y alturas
    obtenerFE(raiz);
    //Balancea segun los factores de equilibrio
    return balancear(raiz);
}

bool ArbolAVL::insertar(Usuario* user)
{
    NodoAVL* nuevo = new NodoAVL(user);
    nuevo -> setUsuario(user);
    if (!ingresado(root, user -> getNombreUsuario()))
    {
        root = insertarBalanceado(root, nuevo);
        return true;
    }
    return false;
}

bool ArbolAVL::eliminar(string nombre)
{
    if (ingresado(root, nombre))
    {
        root = eliminar(root, nombre);
        return true;
    }
    return false;
}

NodoAVL* ArbolAVL::eliminar(NodoAVL* raiz, string nombre)
{
    if (raiz == nullptr)
        return nullptr;
    //Hace la Busqueda como un ABB
    if (nombre < raiz -> getUsuario() -> getNombreUsuario())
        raiz -> hijoIzquierdo = eliminar(raiz -> hijoIzquierdo, nombre);
    else if (nombre > raiz -> getUsuario() -> getNombreUsuario())
        raiz -> hijoDerecho = eliminar(raiz -> hijoDerecho, nombre);
    //Match entre valor Buscado y valor Obtenido
    else
        //Si no tiene hijo Izquierdo
        if (raiz -> hijoIzquierdo == nullptr)
            return raiz -> hijoDerecho;
    //Si no tiene hijo Derecho
        else if (raiz -> hijoDerecho == nullptr)
            return raiz -> hijoIzquierdo;
        else
            //Si tiene subArboles en ambos hijos
            //Comprueba que altura de hijo es mayor. Para eliminar por ese lado
            if ((raiz -> hijoIzquierdo -> altura) > (raiz -> hijoDerecho -> altura))
            {
                NodoAVL* temp = raiz -> hijoIzquierdo;
                //Predecesor
                while (temp -> hijoDerecho != nullptr)
                    temp = temp -> hijoDerecho;
                raiz -> setUsuario(temp -> getUsuario());
                raiz -> hijoIzquierdo = eliminar(raiz -> hijoIzquierdo, temp -> getUsuario() -> getNombreUsuario());
            }
            else
            {
                NodoAVL* temp = raiz -> hijoDerecho;
                //Sucesor
                while (temp -> hijoIzquierdo != nullptr)
                    temp = temp -> hijoIzquierdo;
                raiz -> setUsuario(temp -> getUsuario());
                raiz -> hijoDerecho = eliminar(raiz -> hijoDerecho, temp -> getUsuario() -> getNombreUsuario());
            }
    obtenerFE(raiz);
    return balancear(raiz);
}

string ArbolAVL::preOrdenGrafica(NodoAVL* nodo)
{
    if (nodo != nullptr)
    {
        string nodoRaiz = "Nodo_" + nodo -> getUsuario() -> getNombreUsuario() +
                          "[label = \"<f0>|<f1>" + nodo -> getUsuario() -> getNombreUsuario() + "|<f2>\"; group = 1; fillcolor = darkseagreen2; style = filled]\n";
        string apuntador = "";
        if (nodo -> hijoIzquierdo != nullptr)
        {
            apuntador += "Nodo_" + nodo -> getUsuario() -> getNombreUsuario() + ":f0 -> "
                         "Nodo_" + nodo -> hijoIzquierdo -> getUsuario() -> getNombreUsuario() + ":f1\n";
        }
        if (nodo -> hijoDerecho != nullptr)
        {
            apuntador += "Nodo_" + nodo -> getUsuario() -> getNombreUsuario() + ":f2 -> "
                         "Nodo_" + nodo -> hijoDerecho -> getUsuario() -> getNombreUsuario() + ":f1\n";
        }
        string retorno = nodoRaiz + apuntador;
        return retorno + preOrdenGrafica(nodo -> hijoIzquierdo) + preOrdenGrafica(nodo -> hijoDerecho);
    }
    return "";
}

Usuario* ArbolAVL::obtenerUsuario(NodoAVL* raiz, string nombre)
{
    if(raiz == nullptr)
        return nullptr;
    string nom = raiz -> getUsuario() -> getNombreUsuario();
    if(nom == nombre)
    {
        return raiz -> getUsuario();
    }
    else if(nombre < nom)
    {
        return obtenerUsuario(raiz -> hijoIzquierdo, nombre);
    }
    else
    {
        return obtenerUsuario(raiz -> hijoDerecho, nombre);
    }
}

string ArbolAVL::preOrden(NodoAVL* nodo)
{
    string retorno = "";
    if(nodo != nullptr)
    {
        retorno = " " + nodo -> getUsuario() -> getNombreUsuario();
        return retorno + preOrden(nodo -> hijoIzquierdo) + preOrden(nodo -> hijoDerecho);
    }
    return retorno;
}

string ArbolAVL::graficaArbolLista(NodoAVL* nodo)
{
    if (nodo != nullptr)
    {
        string nodoRaiz = "Nodo_" + nodo -> getUsuario() -> getNombreUsuario() +
                          "[label = \"<f0>|<f1>" + nodo -> getUsuario() -> getNombreUsuario() + "|<f2>\"; group = 1;" +
                          "fillcolor = crimson; style = filled]\n";
        string apuntador = "";
        if(nodo -> getUsuario() -> getListaImagenes() -> head != nullptr)
        {
            apuntador += "Nodo_" + nodo -> getUsuario() -> getNombreUsuario() + ":f1 -> Imagen_" +
                         to_string(nodo -> getUsuario() -> getListaImagenes() -> head -> getImagen() -> getIdImagen()) +
                         nodo -> getUsuario() -> getNombreUsuario() + "\n";
            apuntador += nodo -> getUsuario() -> getListaImagenes() -> printImagenes(nodo -> getUsuario() -> getNombreUsuario()) + "\n";
        }
        if (nodo -> hijoIzquierdo != nullptr)
        {
            apuntador += "Nodo_" + nodo -> getUsuario() -> getNombreUsuario() + ":f0 -> "
                         "Nodo_" + nodo -> hijoIzquierdo -> getUsuario() -> getNombreUsuario() + ":f1\n";
        }
        if (nodo -> hijoDerecho != nullptr)
        {
            apuntador += "Nodo_" + nodo -> getUsuario() -> getNombreUsuario() + ":f2 -> "
                         "Nodo_" + nodo -> hijoDerecho -> getUsuario() -> getNombreUsuario() + ":f1\n";
        }
        string retorno = nodoRaiz + apuntador;
        return retorno + graficaArbolLista(nodo -> hijoIzquierdo) + graficaArbolLista(nodo -> hijoDerecho);
    }
    return "";
}

string ArbolAVL::Top5(NodoAVL* raiz)
{
    Usuario* user = new Usuario();
    if(raiz)
    {
        if(TopU -> getCantidad() != 5)
        {
            user = raiz -> getUsuario();
            user -> setNivel(0);
            TopU -> insertarOrdenado(user);
        }
        else
        {
            if(TopU -> head -> getUsuario() -> getListaImagenes() -> getCantidadImagenes() < raiz -> getUsuario() -> getListaImagenes() -> getCantidadImagenes())
            {
                TopU -> eliminarCabeza();
                TopU -> insertarOrdenado(raiz -> getUsuario());
            }
        }
        Top5(raiz -> hijoIzquierdo);
        Top5(raiz -> hijoDerecho);
    }
    return "";
}

string ArbolAVL::inOrden(NodoAVL* nodo)
{
    string retorno = "";
    if(nodo != nullptr)
    {
        retorno = " " + nodo -> getUsuario() -> getNombreUsuario();
        return  preOrden(nodo -> hijoIzquierdo) + retorno + preOrden(nodo -> hijoDerecho);
    }
    return retorno;
}

string ArbolAVL::postOrden(NodoAVL* nodo)
{
    string retorno = "";
    if(nodo != nullptr)
    {
        retorno = " " + nodo -> getUsuario() -> getNombreUsuario();
        return preOrden(nodo -> hijoIzquierdo) + preOrden(nodo -> hijoDerecho) + retorno;
    }
    return retorno;
}

void ArbolAVL::recorrerNiveles(NodoAVL* raiz, int nivel)
{
    if(raiz)
    {
        Usuario* user = raiz -> getUsuario();
        user -> setNivel(nivel);
        niveles -> insertarOrdenado(user);
        recorrerNiveles(raiz -> hijoIzquierdo, nivel + 1);
        recorrerNiveles(raiz -> hijoDerecho, nivel + 1);
    }
}
