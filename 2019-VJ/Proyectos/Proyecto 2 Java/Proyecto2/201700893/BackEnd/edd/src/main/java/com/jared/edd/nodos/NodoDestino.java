package com.jared.edd.nodos;

import com.jared.edd.models.Destino;

public class NodoDestino {

	public Destino dato;
    public NodoDestino siguiente;
    
    public NodoDestino(Destino destino){
        this.dato = destino;
        siguiente = null;
    }

    public Destino getDato() {
        return dato;
    }

    public void setDato(Destino dato) {
        this.dato = dato;
    }

    public NodoDestino getSiguiente() {
        return siguiente;
    }

    public void setSiguiente(NodoDestino siguiente) {
        this.siguiente = siguiente;
    }
    
}
