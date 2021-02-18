/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ListaCajas.cpp
 * Author: USER
 * 
 * Created on 10 de junio de 2019, 06:42 PM
 */

#include "ListaCajas.h"
#include <iostream>
#include <string>

using namespace std;

ListaCajas::ListaCajas() {
    head = nullptr;
}

/*
 * Metodo que devuelve True si la estructura está vacia
 * de lo contrario devuelve False
 */
bool ListaCajas::isEmpty(){
    if(head == nullptr)
        return true;
    return false;
}

/*
 * Metodo usado para imprimir la estructura
 */
string ListaCajas::print(){
    NodoListaCajas* temp = head;
    if(!isEmpty()){
        string cadena = "";
        string estado  = "";
        while(temp != nullptr){
            string codigoCaja = to_string(temp -> getCaja() -> getCodigo());
            string codigoCliente = to_string(temp -> getCaja() -> getCliente() -> getCodigoCliente());
            string codigoCarreta = to_string(temp -> getCaja() -> getCliente() -> getCarreta() -> getNumeroCarreta());
            if(temp -> getCaja() -> getEstadoCaja()){
                estado = "Ocupada";
            }else{
                estado = "Vacia";
            }
            if(temp == head){
                cadena += "cajaINICIAL[label = \"Lista de Cajas\"];\n";
                cadena += "cajaINICIAL -> caja_" + codigoCaja + "[style=invis]\n";
            }
            string nodo = "caja_" + codigoCaja + "[label = \"Caja: " + codigoCaja + 
                    "\\nCliente: " + codigoCliente + "\\nCarreta: " + codigoCarreta +
                    "\\nEstado: " + estado + "\\nTurnos: " + to_string(temp -> getCaja() -> getNumeroClientes()) +
                    "\\nTurno Actual: " + to_string(temp -> getCaja() -> getNumeroClientesAtendidos()) + "\"];\n";
            string apuntador = "\n";
            if(temp -> siguiente != nullptr){
                apuntador += "caja_" + codigoCaja + " -> caja_" + to_string(temp -> getSiguiente() -> getCaja() -> getCodigo()) + ";\n";
            }
            if(temp -> anterior != nullptr){
                apuntador += "caja_" + codigoCaja + " -> caja_" + to_string(temp -> getAnterior() -> getCaja() -> getCodigo()) + ";\n";
            }
            cadena += nodo;
            cadena += apuntador;
            temp = temp -> siguiente;
        }
        return cadena;
    }else{
        return "";
    }
}

/*
 * Metodo para insertar un nuevo nodo al final de la estructura
 * Utilizar este metodo para Colas
 */
string ListaCajas::TailInsertion(Caja* caja){
    NodoListaCajas* newCaja = new NodoListaCajas();
    newCaja -> setCaja(caja);
    NodoListaCajas* temp = head;
    string estado;
    if(temp != nullptr){
        while(temp != nullptr){
            if(temp -> siguiente == nullptr){
                newCaja -> anterior = temp;
                temp -> siguiente = newCaja;
                if(temp -> getCaja() -> getEstadoCaja()){
                    estado = "Ocupada";
                }else{
                    estado = "Vacia";
                }
                return "Caja: " + to_string(newCaja -> getCaja() -> getCodigo()) + 
                        " Estado: " + estado + " Turnos: " + to_string(newCaja -> getCaja() -> getNumeroClientes());
            }
            temp = temp -> siguiente;
        }
    }else{
        if(newCaja -> getCaja() -> getEstadoCaja()){
            estado = "Ocupada";
        }else{
            estado = "Vacia";
        }
        head = newCaja;
        return "Caja: " + to_string(newCaja -> getCaja() -> getCodigo()) + 
                        " Estado: " + estado + " Turnos: " + to_string(newCaja -> getCaja() -> getNumeroClientes());
    }
    return "BUG1";
}

Cliente* ListaCajas::atenderClientes(int numero){
    NodoListaCajas* temp = head;
    if(!isEmpty()){
        while(temp != nullptr){
            if(temp -> getCaja() -> getCodigo() == numero && (temp -> getCaja() -> getEstadoCaja())){
                if(temp -> getCaja() -> getNumeroClientes() > temp -> getCaja() -> getNumeroClientesAtendidos()){
                    temp -> getCaja() -> atenderCliente();
                    return nullptr;
                }else{
                    Cliente* aux = temp -> getCaja() -> getCliente();
                    temp -> getCaja() -> setCliente(new Cliente());
                    temp -> getCaja() -> setEstadoCaja(false);
                    temp -> getCaja() -> setNumeroClientesAtendidos();
                    int numeroCliente = aux -> getCodigoCliente();
                    int numeroCarreta = aux -> getCarreta() -> getNumeroCarreta();
                    cout << "El Cliente: " + to_string(numeroCliente) + 
                            " Salio de la Caja: " + to_string(numero) + 
                            " Con la Carreta: " + to_string(numeroCarreta) << endl;
                    return aux;
                }
            }
            temp = temp -> siguiente;
        }
    }
    return nullptr;
}

Caja* ListaCajas::obtenerCajaVacia(){
    NodoListaCajas* temp = head;
    if(!isEmpty()){
        while(temp != nullptr){
            if(!(temp -> getCaja() -> getEstadoCaja())){
                return temp -> getCaja();
            }
            temp = temp -> siguiente;
        }
    }
    return nullptr;
}

