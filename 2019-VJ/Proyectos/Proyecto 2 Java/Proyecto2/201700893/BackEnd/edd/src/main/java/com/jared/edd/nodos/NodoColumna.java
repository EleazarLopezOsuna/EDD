package com.jared.edd.nodos;

public class NodoColumna {
	public int numColumna;
    public NodoColumna siguiente;
    public NodoC abajo;
    public int index = 0;

    public NodoColumna(int numColumna) {
        this.numColumna = numColumna;
        siguiente = null;
        abajo = null;
        index = 0;
    }
}
