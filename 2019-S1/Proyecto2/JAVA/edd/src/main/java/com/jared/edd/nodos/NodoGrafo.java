package com.jared.edd.nodos;

import com.jared.edd.models.Destino;
import com.jared.edd.estructuras.ListaRuta;

public class NodoGrafo {

	public Destino dato;
	public NodoGrafo siguiente;
	public ListaRuta ruta;
	
	public NodoGrafo(Destino destino) {
		this.dato = destino;
		siguiente = null;
		ruta = null;
	}

	public Destino getDato() {
		return dato;
	}

	public void setDato(Destino dato) {
		this.dato = dato;
	}

	public NodoGrafo getSiguiente() {
		return siguiente;
	}

	public void setSiguiente(NodoGrafo siguiente) {
		this.siguiente = siguiente;
	}
	
	public ListaRuta getRuta() {
		return ruta;
	}

	public void setRuta(ListaRuta ruta) {
		this.ruta = ruta;
	}
	
}
