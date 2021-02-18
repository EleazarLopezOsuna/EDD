/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: USER
 *
 * Created on 8 de junio de 2019, 11:41 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <ctime>
#include <random>
#include <sstream>
#include <fstream>
#include "Carreta.h"
#include "Cliente.h"
#include "Caja.h"
#include "PilaCarretas.h"
#include "ColaClientes.h"
#include "ListaCajas.h"
#include "ListaClientes.h"
#include <windows.h>

using namespace std;

/*
 * Declaracion de variables Globales
 */
int numeroClientes_Esperando = 0;
int numeroCarretasPila_1 = 0;
int numeroCarretasPila_2 = 0;
int numeroClientes_Comprando = 0;
int numeroClientes_Pagando = 0;
int numeroCajas = 0;
string numerosClientes = "";
int contadorCarretas = 1;
int contadorPasos = 0;

/*
 * Instancias de las Estructuras
 */
PilaCarretas* pila1 = new PilaCarretas();
PilaCarretas* pila2 = new PilaCarretas();
ColaClientes* colaClienteEspera = new ColaClientes();
ColaClientes* colaClientesPagando = new ColaClientes();
ListaCajas* listaCajas = new ListaCajas();
ListaClientes* listaClientes = new ListaClientes();

/*
 * Metodos de Creacion de Recursos
 */
void agregarCarretas(int numeroCarretas, int numeroPila) {
    for (int i = 0; i < numeroCarretas; i++) {
        Carreta* basket = new Carreta();
        basket -> setNumeroCarreta(contadorCarretas);
        if (numeroPila == 1) {
            cout << pila1->HeadInsertion(contadorCarretas, numeroPila) << endl;
        } else {
            cout << pila2->HeadInsertion(contadorCarretas, numeroPila) << endl;
        }
        contadorCarretas++;
    }
}

void agregarClientes(int numeroClientes, int opcionCliente) {
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> nume(1, 999999);
    std::uniform_int_distribution<uint32_t> pil(1, 2);
    int numeroCliente = 0;
    int numeroCarreta = 0;
    switch (opcionCliente) {
            //Clientes Esperando
        case 0:
            for (int i = 1; i <= numeroClientes; i++) {
                while (true) {
                    numeroCliente = nume(generator);
                    string num = to_string(numeroCliente);
                    if (numerosClientes.find(num) == std::string::npos) {
                        numerosClientes += " " + num;
                        break;
                    }
                }
                Cliente* client = new Cliente();
                client -> setCodigoCliente(numeroCliente);
                NodoPilaCarretas* carreta = new NodoPilaCarretas();
                client ->setCarreta(carreta -> getCarreta());
                cout << colaClienteEspera -> TailInsertion(client, 1) << endl;
                ;
            }
            break;
            //Clientes Comprando
        case 1:
            for (int i = 1; i <= numeroClientes; i++) {
                while (true) {
                    numeroCliente = nume(generator);
                    string num = to_string(numeroCliente);
                    if (numerosClientes.find(num) == std::string::npos) {
                        numerosClientes += " " + num;
                        break;
                    }
                }
                Cliente* client = new Cliente();
                client -> setCodigoCliente(numeroCliente);
                numeroCarreta = pil(generator);
                NodoPilaCarretas* carreta;
                if (numeroCarreta == 1) {
                    if (!pila1 -> isEmpty()) {
                        carreta = pila1 -> HeadDelete();
                    } else {
                        carreta = pila2 -> HeadDelete();
                    }
                } else {
                    if (!pila2 -> isEmpty()) {
                        carreta = pila2 -> HeadDelete();
                    } else {
                        carreta = pila1 -> HeadDelete();
                    }
                }
                client -> setCarreta(carreta -> getCarreta());
                cout << listaClientes -> TailInsertion(client) << endl;
            }
            break;
            //Clientes Pagando
        case 2:
            for (int i = 1; i <= numeroClientes; i++) {
                while (true) {
                    numeroCliente = nume(generator);
                    string num = to_string(numeroCliente);
                    if (numerosClientes.find(num) == std::string::npos) {
                        numerosClientes += " " + num;
                        break;
                    }
                }
                Cliente* client = new Cliente();
                client -> setCodigoCliente(numeroCliente);
                numeroCarreta = pil(generator);
                NodoPilaCarretas* carreta;
                if (numeroCarreta == 1) {
                    if (!pila1 -> isEmpty()) {
                        carreta = pila1 -> HeadDelete();
                    } else {
                        carreta = pila2 -> HeadDelete();
                    }
                } else {
                    if (!pila2 -> isEmpty()) {
                        carreta = pila2 -> HeadDelete();
                    } else {
                        carreta = pila1 -> HeadDelete();
                    }
                }
                client -> setCarreta(carreta -> getCarreta());
                cout << colaClientesPagando -> TailInsertion(client, 2) << endl;
            }
            break;
        default:
            break;
    }
}

void agregarCajas() {
    for (int i = 1; i <= numeroCajas; i++) {
        Caja* till = new Caja();
        till -> setCodigo(i);
        till -> setEstadoCaja(false);
        cout << listaCajas -> TailInsertion(till) << endl;
    }
}

/*
 * Graficar
 */
string graficar() {
    int num = 12345;
    string filename;
    filename = "C:\\Users\\USER\\Desktop\\Calificacion\\imagenPaso_" + to_string(contadorPasos) + ".dot";
    ofstream out(filename.c_str());
    string cadena;
    string cuerpoPila1, cuerpoPila2, cuerpoEspera, cuerpoPagando, cuerpoCajas, cuerpoComprando;
    cuerpoPila1 = pila1 -> print(1);
    cuerpoPila2 = pila2 -> print(2);
    cuerpoEspera = colaClienteEspera -> print("espera");
    cuerpoPagando = colaClientesPagando -> print("pago");
    cuerpoComprando = listaClientes -> print();
    cuerpoCajas = listaCajas -> print();
    cadena += "digraph{\nnode[shape = record; style = filled; color = lightblue];\ngraph[bgcolor=coral];\n";
    cadena += cuerpoEspera + cuerpoPagando + cuerpoPila1 + cuerpoPila2 + cuerpoCajas + cuerpoComprando;
    cadena += "\n}";

    ofstream myfile;
    myfile.open(filename);
    myfile << cadena;

    string comando = "dot -Tpng " + filename + " -o C:\\Users\\USER\\Desktop\\Calificacion\\imagenPaso_" + to_string(contadorPasos) + ".png";
    system(comando.c_str());
    comando = "start C:\\Users\\USER\\Desktop\\Calificacion\\imagenPaso_" + to_string(contadorPasos) + ".png";
    system(comando.c_str());

    return "Graficando...\n";
}

/*
 * Realizar Paso
 */
void performStep() {
    std::mt19937 generator;
    generator.seed(std::time(0));
    std::uniform_int_distribution<uint32_t> pil(1, 2);
    int opcion = 1;
    int clientesNuevos = 0;
    while (true) {
        cout << "******************************" << endl;
        cout << "************ MENU ************" << endl;
        cout << "******************************" << endl;
        cout << "Ingrese Opcion" << endl;
        cout << "1. Generar Grafica" << endl;
        cout << "2. Agregar Clientes" << endl;
        cout << "3. Ejecutar Paso" << endl;
        cout << "4. Terminar Simulacion" << endl;
        cin >> opcion;
        NodoListaCompra* salidaCompra;
        NodoColaClientes* salidaCola;
        NodoPilaCarretas* salidaCarreta;
        Caja* cajaVacia;
        Cliente* salidaCliente;
        int numeroDeCarreta = 0;
        switch (opcion) {
            case 1:
                //Graficar
                cout << endl;
                cout << "******************************" << endl;
                cout << "******GENERANDO  GRAFICA******" << endl;
                cout << "******************************" << endl;
                cout << endl;
                cout << graficar();
                break;
            case 2:
                cout << "Ingrese Cantidad de Clientes" << endl;
                cin >> clientesNuevos;
                if (clientesNuevos) {
                    agregarClientes(clientesNuevos, 0);
                }
                break;
            case 3:
                contadorPasos++;
                cout << endl;
                cout << "******************************" << endl;
                cout << "*******EJECUTANDO  PASO*******" << endl;
                cout << "******************************" << endl;
                cout << endl;
                /* Paso numero 1: Llamar al metodo atenderCliente() en todas las cajas existentes
                 * Si se cumple que numeroClientesAtendidos == numeroClientes entonces 
                 * Sacar Cliente y Entregar Carreta
                 */
                for (int i = 1; i <= numeroCajas; i++) {
                    Cliente* cliente = listaCajas -> atenderClientes(i);
                    //Pregunta si se sacó algun cliente
                    if (cliente != nullptr) {
                        std::mt19937 generator;
                        generator.seed(time(0));
                        std::uniform_int_distribution<uint32_t> numCarreta(1, 2);
                        int numeroCarreta = numCarreta(generator);
                        Carreta* carretaSaliente = cliente -> getCarreta();
                        int nCarreta = carretaSaliente -> getNumeroCarreta();
                        if (numeroCarreta == 1) {
                            pila1-> HeadInsertion(nCarreta, 1);
                        } else {
                            pila2 -> HeadInsertion(nCarreta, 2);
                        }
                        cout << endl;
                    }
                }
                /* Paso numero 2: Verificar si existe una caja disponible
                 * Si la caja está vacia entonces sacar a un cliente de la Cola de pago
                 * e ingresar dicho cliente a una Caja. Resetear el contador numeroClientesAtendidos
                 */
                cajaVacia = listaCajas -> obtenerCajaVacia();
                if ((cajaVacia != nullptr) && (colaClientesPagando -> head != nullptr)) {
                    salidaCola = colaClientesPagando -> HeadDelete("pago");
                    cajaVacia -> setCliente(salidaCola -> getCliente());
                    cajaVacia -> setEstadoCaja(true);
                    cout << endl;
                }
                /* Paso numero 3: Generar numero al azar en ListaClientes::Delete()
                 * Si el numero generado es menor al tamaño de la Lista entonces 
                 * sacar Cliente en la posicion indicada e ingresarlo en la cola de Pago
                 */
                salidaCompra = listaClientes -> Delete();
                if (salidaCompra != nullptr) {
                    colaClientesPagando -> TailInsertion(salidaCompra -> getCliente(), 2);
                    cout << endl;
                }
                /* Paso numero 4: Comprobar si hay Clientes en la cola de Espera (de carreta)
                 * Si existe por lo menos un Cliente entonces comprobar disponibilidad de Carretas
                 * Si hay carretas disponibles tomar una (al azar). Remover la carreta de la Pila 
                 * Correspondiente y agregarla al Cliente. El Cliente debe ser añadido 
                 * A la lista de Compra
                 */
                if ((colaClienteEspera -> head != nullptr) && ((pila1 -> head != nullptr) || (pila2 -> head != nullptr))) {
                    salidaCola = colaClienteEspera -> HeadDelete("espera");
                    if (salidaCola != nullptr) {
                        numeroDeCarreta = pil(generator);
                        while (true) {
                            if (numeroDeCarreta == 1) {
                                if (pila1 -> head != nullptr) {
                                    salidaCarreta = pila1 -> HeadDelete();
                                } else {
                                    salidaCarreta = pila2 -> HeadDelete();
                                }
                                cout << endl;
                            } else {
                                if (pila2 -> head != nullptr) {
                                    salidaCarreta = pila2 -> HeadDelete();
                                } else {
                                    salidaCarreta = pila1 -> HeadDelete();
                                }
                                cout << endl;
                            }
                            if (salidaCarreta != nullptr)
                                break;
                        }
                        salidaCliente = salidaCola -> getCliente();
                        salidaCliente -> setCarreta(salidaCarreta -> getCarreta());
                        listaClientes -> TailInsertion(salidaCliente);
                        cout << endl;
                    }
                }

                break;
            case 4:
                exit(0);
                break;
            default:
                performStep();
                break;
        }
    }
}

int main(int argc, char** argv) {
    do {
        cout << "Ingrese Cantidad de Clientes esperando Carreta" << endl;
        cin >> numeroClientes_Esperando;
        cout << "Ingrese Cantidad de Clientes Comprando" << endl;
        cin >> numeroClientes_Comprando;
        cout << "Ingrese Cantidad de Clientes Pagando" << endl;
        cin >> numeroClientes_Pagando;
    } while ((numeroClientes_Esperando + numeroClientes_Comprando + numeroClientes_Pagando) < 0);
    do {
        cout << "Ingrese Cantidad de Carretas para la Pila 1" << endl;
        cin >> numeroCarretasPila_1;
        cout << "Ingrese Cantidad de Carretas para la Pila 2" << endl;
        cin >> numeroCarretasPila_2;
    } while ((numeroCarretasPila_1 + numeroCarretasPila_2) <= (numeroClientes_Comprando + numeroClientes_Pagando));
    do {
        cout << "Ingrese Cantidad de Cajas" << endl;
        cin >> numeroCajas;
    } while (numeroCajas <= 0);

    cout << endl;
    cout << "*****************************" << endl;
    cout << "***INFORMACION DEL SISTEMA***" << endl;
    cout << "*****************************" << endl;
    cout << endl;
    cout << "Numero de Clientes Esperando: " + to_string(numeroClientes_Esperando) << endl;
    cout << "Numero de Clientes Comprando: " + to_string(numeroClientes_Comprando) << endl;
    cout << "Numero de Clientes Pagando: " + to_string(numeroClientes_Pagando) << endl;
    cout << "Numero de Carretas Pila 1: " + to_string(numeroCarretasPila_1) << endl;
    cout << "Numero de Carretas Pila 2: " + to_string(numeroCarretasPila_2) << endl;
    cout << "Numero de Cajas: " + to_string(numeroCajas) << endl;

    cout << endl;
    cout << "******************************" << endl;
    cout << "****EJECUTANDO  SIMULACION****" << endl;
    cout << "******************************" << endl;
    cout << endl;


    //Añadir Carretas
    cout << endl;
    cout << "******************************" << endl;
    cout << "******AGREGANDO CARRETAS******" << endl;
    cout << "******************************" << endl;
    cout << endl;
    agregarCarretas(numeroCarretasPila_1, 1);
    agregarCarretas(numeroCarretasPila_2, 2);

    //Añadir Clientes
    cout << endl;
    cout << "******************************" << endl;
    cout << "******AGREGANDO CLIENTES******" << endl;
    cout << "******************************" << endl;
    cout << endl;
    if (numeroClientes_Esperando) {
        agregarClientes(numeroClientes_Esperando, 0);
    }
    if (numeroClientes_Comprando) {
        agregarClientes(numeroClientes_Comprando, 1);
    }
    if (numeroClientes_Pagando) {
        agregarClientes(numeroClientes_Pagando, 2);
    }

    //Añadir Cajas
    cout << endl;
    cout << "******************************" << endl;
    cout << "*******AGREGANDO  CAJAS*******" << endl;
    cout << "******************************" << endl;
    cout << endl;
    agregarCajas();

    //Inicio de la Simulacion
    performStep();

    return 0;
}