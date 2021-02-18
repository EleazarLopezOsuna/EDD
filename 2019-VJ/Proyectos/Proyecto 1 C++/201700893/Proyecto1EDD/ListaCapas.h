/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   ListaCapas.h
 * Author: USER
 *
 * Created on 18 de junio de 2019, 03:41 PM
 */

#ifndef LISTACAPAS_H
#define LISTACAPAS_H
#include "Capa.h"
#include "NodoCapa.h"

class ListaCapas
{
public:

    NodoCapa* head;
    ListaCapas();
    string insertarCabeza(Capa* capa);
    string printCapas();
    string print();
    string printImagenesCapas(int codigoImagen, int codigoGrupo);
    string eliminarDato(string nombreCapa);
    string printCapaArbol();
    int getNumeroCapas();
    bool existe(int codigo);

private:
    int numeroCapas;
};


#endif /* LISTACAPAS_H */

