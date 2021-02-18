/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaClientes.cpp
 * Author: USER
 * 
 * Created on 10 de junio de 2019, 08:51 PM
 */

#include "ListaClientes.h"
#include "Carreta.h"
#include "NodoListaCompra.h"
#include <iostream>
#include <string>
#include <ctime>
#include <random>

using namespace std;

ListaClientes::ListaClientes() {
    head = nullptr;
    tail = nullptr;
}

/*
 * Metodo que devuelve True si la estructura está vacia
 * de lo contrario devuelve False
 */
bool ListaClientes::isEmpty() {
    if (head == nullptr)
        return true;
    return false;
}

/*
 * Metodo usado para imprimir la estructura
 */
string ListaClientes::print() {
    if (!isEmpty()) {
        NodoListaCompra* temp = head;
        string cadena = "";
        do {
            string codigoCliente = to_string(temp -> getCliente() -> getCodigoCliente());
            string codigoClienteA = "";
            string codigoClienteS = "";
            string codigoCarreta = to_string(temp -> getCliente() -> getCarreta() -> getNumeroCarreta());
            string nodo = "clienteCompra_" + codigoCliente + "[label = \"Cliente: " + codigoCliente + "\\nCarreta: " + codigoCarreta + "\"];\n";
            string apuntadorS = "";
            string apuntadorA = "";
            if(temp == head){
                cadena += "listaClientes[label = \"Lista de Compra\"];\n";
                cadena += "listaClientes -> clienteCompra_" + codigoCliente + "[style=invis]\n";
            }
            codigoClienteA = to_string(temp -> getAnterior() -> getCliente() -> getCodigoCliente());
            codigoClienteS = to_string(temp -> getSiguiente() -> getCliente() -> getCodigoCliente());
            apuntadorS = "clienteCompra_" + codigoCliente + "-> clienteCompra_" + codigoClienteS + ";\n";
            apuntadorA = "clienteCompra_" + codigoCliente + "-> clienteCompra_" + codigoClienteA + ";\n";
            cadena += nodo;
            cadena += apuntadorS;
            cadena += apuntadorA;
            temp = temp -> siguiente;
        } while (temp != head);
        return cadena;
    } else {
        return "listaClientes[label = \"Lista de Compra\"];\n";
    }
}

/*
 * Metodo para insertar un nuevo nodo al final de la estructura
 * Utilizar este metodo para Colas
 */
string ListaClientes::TailInsertion(Cliente* cliente) {
    NodoListaCompra* newCliente = new NodoListaCompra();
    newCliente -> setCliente(cliente);
    NodoListaCompra* temp = head;
    contador++;
    if (head != nullptr) {
        tail -> siguiente = newCliente;
        newCliente -> anterior = tail;
        newCliente -> siguiente = head;
        tail = newCliente;
        head -> anterior = tail;
        return "Cliente: " + to_string(newCliente -> getCliente() -> getCodigoCliente()) + " Entro a la lista de compra" +
                " Con Carreta: " + to_string(newCliente -> getCliente() -> getCarreta() -> getNumeroCarreta());
    } else {
        head = newCliente;
        tail = newCliente;
        head -> siguiente = head;
        head -> anterior = tail;
        return "Cliente: " + to_string(newCliente -> getCliente() -> getCodigoCliente()) + " Entro a la lista de compra" +
                " Con Carreta: " + to_string(newCliente -> getCliente() -> getCarreta() -> getNumeroCarreta());
    }
    return "BUG3";
}

NodoListaCompra* ListaClientes::Delete() {
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> nume(0, 99);
    int index = nume(generator);
    if (contador != 0) {
        if (index <= contador) {
            NodoListaCompra* temp = head;
            while (index--) {
                temp = temp -> siguiente;
            }
            NodoListaCompra* ant = temp -> anterior;
            NodoListaCompra* sig = temp -> siguiente;
            if (temp == head) {
                head = sig;
                head -> anterior = tail;
                ant -> siguiente = head;
            } else if (temp == tail) {
                tail = ant;
                tail -> siguiente = head;
                sig -> anterior = tail;
            } else {
                ant -> siguiente = sig;
                sig -> anterior = ant;
            }
            cout << "Cliente Sale de la Lista de Compras: " + to_string(temp -> getCliente() -> getCodigoCliente()) << endl;
            contador--;
            if(contador == 0){
                head = nullptr;
                tail = nullptr;
            }
            return temp;
        }
    }
    return nullptr;
}
