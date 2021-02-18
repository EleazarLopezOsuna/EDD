/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaClientes.cpp
 * Author: USER
 * 
 * Created on 9 de junio de 2019, 02:27 PM
 */

#include "ColaClientes.h"
#include <iostream>
#include <string>

using namespace std;

ColaClientes::ColaClientes() {
    head = nullptr;
}

/*
 * Metodo que devuelve True si la estructura está vacia
 * de lo contrario devuelve False
 */
bool ColaClientes::isEmpty(){
    if(head == nullptr)
        return true;
    return false;
}

/*
 * Metodo usado para imprimir la estructura
 */
string ColaClientes::print(string tipo){
    NodoColaClientes* temp = head;
    string cadena = "";
    if(!isEmpty()){
        while(temp != nullptr){
            string nodo;
            if(tipo == "espera"){
                nodo = "cliente_" + tipo + "_" + to_string(temp -> getCliente() -> getCodigoCliente()) +
                    "[label = \"Cliente: " + to_string(temp -> getCliente() -> getCodigoCliente()) + "\"];\n";
            }else{
                nodo = "cliente_" + tipo + "_" + to_string(temp -> getCliente() -> getCodigoCliente()) +
                    "[label = \"Cliente: " + to_string(temp -> getCliente() -> getCodigoCliente())
                        + "\\nCarreta: " + to_string(temp -> getCliente() -> getCarreta() -> getNumeroCarreta()) + "\"];\n";
            }
            if(temp == head){
                cadena += "cliente_" + tipo + "[label = \"Cola de " + tipo + "\"];\n";
                cadena += "cliente_" + tipo + " -> cliente_" + tipo + 
                        "_" + to_string(temp -> getCliente() -> getCodigoCliente()) + "[style=invis]\n";
            }
            cadena += nodo;
            string apuntador = "";
            if(temp -> siguiente != nullptr){
                apuntador = "cliente_" + tipo + "_" + to_string(temp -> getCliente() -> getCodigoCliente()) + 
                     " -> cliente_" + tipo + "_" + to_string(temp -> getSiguiente() -> getCliente() -> getCodigoCliente()) + ";\n";
            }
            cadena += apuntador;
            temp = temp -> siguiente;
        }
    }else{
        cadena += "cliente_" + tipo + "[label = \"Cola de " + tipo + "\"];\n";
    }
    return cadena;
}

/*
 * Metodo para insertar un nuevo nodo al final de la estructura
 * Utilizar este metodo para Colas
 */
string ColaClientes::TailInsertion(Cliente* cliente, int tipo){
    NodoColaClientes* newClient = new NodoColaClientes();
    newClient -> setCliente(cliente);
    NodoColaClientes* temp = head;
    if(temp != nullptr){
        while(temp != nullptr){
            if(temp -> siguiente == nullptr){
                temp -> siguiente = newClient;
                break;
            }
            temp = temp -> siguiente;
        }
    }else{
        head = newClient;
    }
    if(tipo == 1){
        return "Cliente: " + to_string(newClient -> getCliente() -> getCodigoCliente()) + 
                        " Entro a la Cola de espera";
    }else{
        return "Cliente: " + to_string(newClient -> getCliente() -> getCodigoCliente()) + 
                        " Entro a la Cola de pago" +
                        " Con la Carreta: " + to_string(newClient -> getCliente() -> getCarreta() -> getNumeroCarreta());
    }
    return "BUG2";
}

/*
 * Metodo para eliminar un nodo al inicio de la estructura
 */
NodoColaClientes* ColaClientes::HeadDelete(string tipo){
    NodoColaClientes* temp = new NodoColaClientes();
    NodoColaClientes* temp2 = temp;
    if(!isEmpty()){
        temp = head;
        temp2 = head -> siguiente;
        head = temp2;
        if(tipo == "espera"){
            cout << "Cliente: " + to_string(temp -> getCliente() -> getCodigoCliente()) + 
                " Salio de la Cola de " + tipo;
        }else{
            cout << "Cliente: " + to_string(temp -> getCliente() -> getCodigoCliente()) + 
                " Salio de la Cola de " + tipo + 
                " Con la Carreta: " + to_string(temp -> getCliente() -> getCarreta() -> getNumeroCarreta());
        }
        return temp;
    }
    return nullptr;
}