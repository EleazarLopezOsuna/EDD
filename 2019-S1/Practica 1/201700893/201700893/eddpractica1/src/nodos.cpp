#include "nodos.h"
//--------Inicio Usuarios--------//
	//Entra al siguiente metodo si la lista esta vacia
	NodoUsuario::NodoUsuario(Usuario u){
	    userx = u;
	    siguiente = 0;
	}
	//Entra al siguiente metodo si la lista ya contiene por lo menos 1 elemento
	NodoUsuario::NodoUsuario(Usuario u, NodoUsuario*us){
	    userx = u;
	    siguiente = us;
	}
	//El siguiente metodo retorna los el usuario que posee el nodo
	Usuario NodoUsuario::datos(){
	    return userx;
	}
	//El siguiente metodo retorna el nodo siguiente
	NodoUsuario* NodoUsuario::SiguienteUsuario(){
    return siguiente;
	}
	//El siguiente metodo se encarga de poner el siguiente a un nodo
	void NodoUsuario::setUsuarioSiguiente(NodoUsuario* next){
 	   siguiente = next;
	}
//---------Fin Usuarios---------//

//--------Inicio Recursos--------//
	NodoRecurso::NodoRecurso(Recurso r){
		resource = r;
		siguiente = 0;
	}

	NodoRecurso::NodoRecurso(Recurso r, NodoRecurso* nr){
		resource = r;
		siguiente = nr;
	}

	Recurso NodoRecurso::datos(){
		return resource;
	}

	NodoRecurso* NodoRecurso::SiguienteRecurso(){
		return siguiente;
	}

	void NodoRecurso::setSiguienteRecurso(NodoRecurso* next){
		siguiente = next;
	}
//---------Fin Recursos---------//

//--------Inicio Servicios--------//
	NodoServicio::NodoServicio(Servicio s){
		service = s;
		siguiente = 0;
	}

	NodoServicio::NodoServicio(Servicio s, NodoServicio* ns){
		service = s;
		siguiente = ns;
	}

	Servicio NodoServicio::datos(){
		return service;
	}

	NodoServicio* NodoServicio::SiguienteServicio(){
		return siguiente;
	}

	void NodoServicio::setSiguienteServicio(NodoServicio* next){
		siguiente = next;
	}
//---------Fin Servicios---------//