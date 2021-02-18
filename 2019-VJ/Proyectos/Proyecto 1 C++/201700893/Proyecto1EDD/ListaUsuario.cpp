#include "ListaUsuario.h"

ListaUsuario::ListaUsuario()
{
    head = nullptr;
    cantidad = 0;
}

bool ListaUsuario::isEmpty()
{
    if (head == nullptr)
        return true;
    return false;
}

int ListaUsuario::getCantidad()
{
    return cantidad;
}

void ListaUsuario::setCantidad(int c)
{
    cantidad = c;
}

void ListaUsuario::ordenarLista(int tipo)
{
    NodoUsuario* tmp = head;
    while (tmp -> siguiente != nullptr)
    {
        NodoUsuario* segundo = tmp -> siguiente;
        while (segundo != nullptr)
        {
            //Ordenar para el Top
            if(!tipo)
            {
                string capasPrimero, capasSegundo;
                capasPrimero = tmp -> getUsuario() -> getNombreUsuario();
                capasSegundo = segundo -> getUsuario() -> getNombreUsuario();
                if(capasPrimero < capasSegundo)
                {
                    Usuario* temp = tmp -> getUsuario();
                    tmp -> setUsuario(segundo -> getUsuario());
                    segundo -> setUsuario(temp);
                }
            }
            //Ordenar por niveles
            else
            {
                int capasPrimero, capasSegundo;
                capasPrimero = tmp -> getUsuario() -> getNivel();
                capasSegundo = segundo -> getUsuario() -> getNivel();
                if(capasPrimero < capasSegundo)
                {
                    Usuario* temp = tmp -> getUsuario();
                    tmp -> setUsuario(segundo -> getUsuario());
                    segundo -> setUsuario(temp);
                }
            }
            segundo = segundo -> siguiente;
        }
        tmp = tmp -> siguiente;
    }
}

void ListaUsuario::eliminarCabeza()
{
    if (!isEmpty())
    {
        if(head -> siguiente)
        {
            NodoUsuario* temp = head -> siguiente;
            head = temp;
        }
        else
        {
            head = nullptr;
        }
    }
}

string ListaUsuario::recorrer()
{
    string retorno = "";
    NodoUsuario* temp = head;
    if(temp)
    {
        while (temp != nullptr)
        {
            if(temp -> siguiente != nullptr)
                retorno =  " " + temp -> getUsuario() -> getNombreUsuario() + retorno;
            else
                retorno = temp -> getUsuario() -> getNombreUsuario() + retorno;
            temp = temp -> siguiente;
        }
    }
    return retorno;
}

string ListaUsuario::Top5()
{
    string retorno = "";
    return retorno;
}

//Tipo 1 ordenar List
void ListaUsuario::insertarOrdenado(Usuario* user)
{
    NodoUsuario* nuevo = new NodoUsuario();
    nuevo -> setUsuario(user);
    if (head == nullptr)
    {
        head = nuevo;
    }
    else
    {
        nuevo -> siguiente = head;
        head = nuevo;
        ordenarLista(user -> getNivel());
    }
    setCantidad(getCantidad() + 1);
}
