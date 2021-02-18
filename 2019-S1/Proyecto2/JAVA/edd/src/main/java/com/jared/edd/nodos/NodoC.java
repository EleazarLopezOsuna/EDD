package com.jared.edd.nodos;
import com.jared.edd.models.Ruta;

public class NodoC {
	public NodoC derecha;
    public NodoC izquierda;
    public NodoC arriba;
    public NodoC abajo;

    public Ruta ruta;

    public NodoC(Ruta ruta) {
        this.ruta = ruta;
        derecha = null;
        izquierda = null;
        arriba = null;
        abajo = null;
    }
}
