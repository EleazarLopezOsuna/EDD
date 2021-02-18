#include "estructuras.h"
#include <string.h>
#include "iostream"
#include <algorithm>

//--------Inicio Usuarios--------//
	NodoUsuario* ListaUsuario::buscar(std::string n){
    	NodoUsuario* temp = primero; //temp hace referencia a un nodo temporal, el cual puede ser modificado sin afectar el original
    	NodoUsuario* p = primero;
    	do{
        	if(temp -> datos().identificador==n){
            	return temp; //retorna temp cuando hace match con el usuario
        	}
        	temp = temp -> SiguienteUsuario();
    }while(temp!=p);
    return NULL; //retorna NULL si el usuario buscado no hace match
	}

	ListaUsuario::ListaUsuario(){
	    primero = NULL;
	    ultimo = NULL;
	}

	Usuario ListaUsuario::getUsuario(std::string identificador){
	    Usuario resultado = {"",""};
	    NodoUsuario* buscador = buscar(identificador);
	    if(buscador!=NULL){
	        return buscador -> datos();//retorna el usuario
	    }
	    return resultado;//retorna nulo
	}
	
	std::string ListaUsuario::insertarUsuario(Usuario n, int contador, NodoRecurso* recurso){
	    NodoUsuario* nuevo;
	    NodoRecurso* temp = recurso;
	    int num = 0;
	    std::string identificador = n.identificador;
	    std::string dominio = "";
	    if(recurso != NULL){
	    	do{
	    		if(num == (contador-1)){
	    			dominio = temp -> datos().dominio;
	    		}
	    		num++;
	    		temp = temp -> siguiente;
	    	}while(temp != recurso && num < contador);
	    	n.identificador = identificador+"."+dominio;
	    	nuevo = new NodoUsuario(n);
	    	if(primero != NULL){	
	    	    ultimo -> siguiente = nuevo;
	    	    nuevo -> siguiente = primero;
	    	    ultimo = nuevo;
	    	}else{
	    	    primero = nuevo;
	    	    nuevo -> siguiente = primero;
	    	    ultimo = nuevo;
    		}
	
	    	NodoUsuario* recorredor1 = primero;
       		do{
	    	   	NodoUsuario* recorredor2 = recorredor1 -> siguiente;
	    	   	do{
	    			std::string nombre1 = recorredor1 -> datos().nombre;
	   				std::string nombre2 = recorredor2 -> datos().nombre;
	    	   		if(nombre1.compare(nombre2) < 0){
	    	   			Usuario aux = recorredor1 -> datos();
	     	  			recorredor1 -> userx = recorredor2 -> userx;
	    	   			recorredor2 -> userx = aux;
	    	   		}
	    	   		recorredor2 = recorredor2 -> siguiente;
	    	   	}while(recorredor2 != recorredor1);
	    	   	recorredor1 = recorredor1 -> siguiente;
	    	}while(recorredor1 != primero);
	    	return "Usuario Registrado";
	    }else{
	    	return "ERROR: ingrese un recurso";
	    }
	}

	std::list<Usuario> ListaUsuario::linealizar(){
	    std::list<Usuario> lista;
 	    NodoUsuario* temp = primero;
 		if(temp != NULL){
 			do{
 	       		lista.push_back(temp->datos());
 	       		temp = temp->SiguienteUsuario();
 	   		}while(temp!=primero);
 	    }
  	  return lista;
	}
//---------Fin Usuarios---------//

//---------Inicio Recursos---------//
	NodoRecurso* ColaRecurso::buscar(std::string r){
		NodoRecurso* temp = primero;
		while(temp != NULL){
			if(temp -> datos().dominio == r){
				return temp;
			}
			temp = temp -> SiguienteRecurso();
		}
		return NULL;
	}

	ColaRecurso::ColaRecurso(){
		primero = NULL;
		ultimo = NULL;
	}

	Recurso ColaRecurso::getRecurso(std::string dominio){
		Recurso resultado = {"",""};
		NodoRecurso* buscador = buscar(dominio);
		if(buscador!=NULL){
			return buscador -> datos();
		}
		return resultado;
	}

	void ColaRecurso::insertarRecurso(Recurso r){
		NodoRecurso* nuevo;
		nuevo = new NodoRecurso(r);
		if(primero != NULL){
	        ultimo -> siguiente = nuevo;
	        nuevo -> siguiente = primero;
	        ultimo = nuevo;
	    }else{
	        primero = nuevo;
	        nuevo -> siguiente = primero;
	        ultimo = nuevo;
    	}
	}

	std::list<Recurso> ColaRecurso::linealizar(){
		std::list<Recurso> lista;
		NodoRecurso* temp = primero;
		if(temp != NULL){
			do{
				lista.push_back(temp -> datos());
				temp = temp -> SiguienteRecurso();
			}while(temp != primero);
		}
		return lista;
	}
//---------Fin Recursos---------//

//--------Inicio Servicios--------//
	NodoServicio* PilaServicio::buscar(std::string s){
		NodoServicio* temp = primero;
		while(temp != NULL){
			if(temp -> datos().identificador_sesion == s){
				return temp;
			}
			temp = temp -> SiguienteServicio();
		}
		return NULL;
	}

	PilaServicio::PilaServicio(){
		primero = NULL;
	}

	Servicio PilaServicio::getServicio(std::string identificador_sesion){
		Servicio resultado = {"",""};
		NodoServicio* buscador = buscar(identificador_sesion);
		if(buscador!=NULL){
			return buscador -> datos();
		}
		return resultado;
	}

	void PilaServicio::insertarServicio(Servicio s){
		NodoServicio* nuevo;
		nuevo = new NodoServicio(s);
		nuevo -> siguiente = primero;
		primero = nuevo;
	}

	std::list<Servicio> PilaServicio::linealizar(){
		std::list<Servicio> lista;
		NodoServicio* temp = primero;
		if(temp != NULL){
			while(temp != NULL){
				lista.push_back(temp -> datos());
				temp = temp -> SiguienteServicio();
			}
		}
		return lista;
	}
//--------Fin Servicios--------//