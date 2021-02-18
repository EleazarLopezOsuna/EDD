package com.jared.edd.nodos;

import com.jared.edd.models.Ruta;

public class NodoRuta {

	public Ruta dato;
	public NodoRuta siguiente;
	
	public NodoRuta(Ruta ruta) {
		this.dato = ruta;
		siguiente = null;
	}

	public Ruta getDato() {
		return dato;
	}

	public void setDato(Ruta dato) {
		this.dato = dato;
	}

	public NodoRuta getSiguiente() {
		return siguiente;
	}

	public void setSiguiente(NodoRuta siguiente) {
		this.siguiente = siguiente;
	}
	
}
