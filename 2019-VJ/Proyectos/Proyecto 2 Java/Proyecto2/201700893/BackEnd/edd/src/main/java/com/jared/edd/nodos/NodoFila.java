package com.jared.edd.nodos;

public class NodoFila {
	public int numFila;
    public NodoFila siguiente;
    public NodoC derecha;
    public int index;
    public String pais = "";

    public NodoFila(int numFila, String pais) {
        this.numFila = numFila;
        this.pais = pais;
        siguiente = null;
        derecha = null;
        index = 0;
    }
}
