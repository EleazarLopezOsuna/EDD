#ifndef ESTRUCTURA_H
#define ESTRUCTURA_H
#include <string>
#include <list>
#include "nodo.h"
#include <iostream>
#include <array>

class ArbolCatedratico{
	public:
		std::string recorrer();														//CORRECTO
		std::string preOrden(NodoCatedratico* r, std::string hijo);					//CORRECTO
	public:
		NodoCatedratico* raiz;
		ArbolCatedratico();															//CORRECTO
		std::string insertarCatedratico(Catedratico c);								//CORRECTO
};

class ListaCursos{
	public:
		std::string recorrer();														//PENDIENDTE  N
		std::string linealizar(ArbolCatedratico ac, ListaCursos lc);				//CORRECTO
		NodoCatedratico* buscar(std::string codigo, ArbolCatedratico ac);			//CORRECTO
	public:
		NodoCurso* cabeza;
		NodoCurso* cola;
		ListaCursos();																//CORRECTO
		std::string insertarCurso(Curso c, ArbolCatedratico ac);					//CORRECTO
};

class ListaDia{
	public:
		std::string insertarDia(Dia d);												//CORRECTO
		bool buscarDia(std::string dia);											//CORRECTO
	public:
		NodoDia* cabeza;
		ListaDia();																	//CORRECTO
};

class ListaSalon{
	public:
		std::string insertarSalon(Salon s);											//CORRECTO
		std::list<std::string> buscarSalon(std::string edificio);					//CORRECTO
		std::string buscarSalon();													//CORRECTO
		bool buscarSalon(std::string edificio, std::string salon);					//CORRECTO
	public:
		NodoSalon* cabeza;
		ListaSalon();																//CORRECTO
};

class ListaHora{
	public:
		std::string insertarHora(Hora h);											//CORRECTO
		bool buscarHora(std::string horaI, std::string horaF);						//CORRECTO
		std::string recorrerHora(std::string dia);									//CORRECTO
	public:
		NodoHora* cabeza;
		ListaHora();																//CORRECTO
};

class ListaAsignacion{
	public:
		std::string insertarAsignacion(Asignacion ass, ListaDia ld, ListaCursos lc, ArbolCatedratico ac, ListaHora lh, ListaSalon ls);
		std::string recorrerAsignacion(std::string dia);
	public:
		NodoAsignacion* cabeza;
		ListaAsignacion();
};

#endif