/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PilaCarretas.cpp
 * Author: USER
 * 
 * Created on 9 de junio de 2019, 11:58 AM
 */

#include "PilaCarretas.h"
#include <iostream>

PilaCarretas::PilaCarretas() {
    head = nullptr;
}

/*
 * Metodo que devuelve True si la estructura está vacia
 * de lo contrario devuelve False
 */
bool PilaCarretas::isEmpty(){
    if(head == nullptr)
        return true;
    return false;
}

/*
 * Metodo usado para imprimir la estructura
 */
string PilaCarretas::print(int numero){
    NodoPilaCarretas* temp = head;
    string cadena = "";
    if(!isEmpty()){
        while(temp != nullptr){
            if(temp == head){
                cadena += "carretaINICIAL_" + to_string(numero) + 
                        "[label = \"Pila: " + to_string(numero) + "\"];\n";
                cadena += "carretaINICIAL_" + to_string(numero) + " -> carreta_" + 
                        to_string(temp -> getCarreta() -> getNumeroCarreta()) + "[style=invis]\n";
            }
            string nodo = "carreta_" + to_string(temp -> getCarreta() -> getNumeroCarreta()) +
                    "[label = \"Carreta Numero: " + to_string(temp -> getCarreta() -> getNumeroCarreta()) + "\"];\n";
            cadena += nodo;
            string apuntador = "";
            if(temp -> siguiente != nullptr){
                apuntador = "carreta_" + to_string(temp -> getCarreta() -> getNumeroCarreta()) + 
                     " -> carreta_" + to_string(temp -> getSiguiente() -> getCarreta() -> getNumeroCarreta()) + ";\n";
            }
            cadena += apuntador;
            temp = temp -> siguiente;
        }
    }else{
        cadena += "carretaINICIAL_" + to_string(numero) + 
                        "[label = \"Pila Carreta: " + to_string(numero) + "\"];\n";
    }
    return cadena;
}

/*
 * Metodo para insertar un nuevo nodo al inicio de la estructura
 * Utilizar este metodo para Pilas
 */
string PilaCarretas::HeadInsertion(int cartNumber, int stackNumber){
    NodoPilaCarretas* newCart = new NodoPilaCarretas();
    Carreta* cart = new Carreta();
    cart -> setNumeroCarreta(cartNumber);
    cart -> setNumeroPila(stackNumber);
    newCart -> setCarreta(cart);
    NodoPilaCarretas* temp = head;
    newCart -> siguiente = temp;
    head = newCart;
    return "Carreta: " + to_string(cartNumber) + 
            " Ingreso a la Pila: " + to_string(stackNumber);
}

/*
 * Metodo para eliminar un nodo al inicio de la estructura
 */
NodoPilaCarretas* PilaCarretas::HeadDelete(){
    NodoPilaCarretas* temp = new NodoPilaCarretas();
    if(!isEmpty()){
        NodoPilaCarretas* temp2 = head;
        temp = head -> siguiente;
        head = temp;
        cout << "\nCarreta: " + to_string(temp2 -> getCarreta() -> getNumeroCarreta()) + 
                " Salio de la Pila: " + to_string(temp2 -> getCarreta() -> getNumeroPila()) + "\n";
        return temp2;
    }
    return nullptr;
}