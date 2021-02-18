#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H
#include <list>
#include <string>
#include "nodos.h"
#include <iostream>
#include <array>

//--------Inicio Usuarios--------//
	class ListaUsuario{
	public:
    	NodoUsuario*buscar(std::string u);
	public:
    	NodoUsuario* primero;
    	NodoUsuario* ultimo;
    	ListaUsuario();
    	std::string insertarUsuario(Usuario u, int contador, NodoRecurso* recurso);
    	void OrdenarUsuario();
    	Usuario getUsuario(std::string identificador);
    	std::list<Usuario>linealizar();
	};
//---------Fin Usuarios---------//

//--------Inicio Recursos--------//
	class ColaRecurso{
	public:
		NodoRecurso*buscar(std::string r);
	public:
		NodoRecurso* primero;
		NodoRecurso* ultimo;
		ColaRecurso();
		void insertarRecurso(Recurso r);
		Recurso getRecurso(std::string dominio);
		std::list<Recurso>linealizar();
	};
//---------Fin Recursos---------//

//--------Inicio Servicio--------//
	class PilaServicio{
	public:
		NodoServicio*buscar(std::string s);
	public:
		NodoServicio* primero;
		PilaServicio();
		void insertarServicio(Servicio s);
		Servicio getServicio(std::string identificador_sesion);
		std::list<Servicio>linealizar();
	};
//---------Fin Servicio---------//
#endif