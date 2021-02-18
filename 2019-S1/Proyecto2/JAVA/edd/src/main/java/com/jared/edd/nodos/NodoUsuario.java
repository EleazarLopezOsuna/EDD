package com.jared.edd.nodos;

import com.jared.edd.models.Usuario;

public class NodoUsuario {
    public Usuario dato;
    public NodoUsuario hijoIzquierdo;
    public NodoUsuario hijoDerecho;
    public int factorEquilibrio;
    
    public NodoUsuario(Usuario usuario){
        this.dato = usuario;
        hijoIzquierdo = null;
        hijoDerecho = null;
        factorEquilibrio = 0;
    }

    public Usuario getDato() {
        return dato;
    }

    public void setDato(Usuario dato) {
        this.dato = dato;
    }

    public NodoUsuario getHijoIzquierdo() {
        return hijoIzquierdo;
    }

    public void setHijoIzquierdo(NodoUsuario hijoIzquierdo) {
        this.hijoIzquierdo = hijoIzquierdo;
    }

    public NodoUsuario getHijoDerecho() {
        return hijoDerecho;
    }

    public void setHijoDerecho(NodoUsuario hijoDerecho) {
        this.hijoDerecho = hijoDerecho;
    }

    public int getFactorEquilibrio() {
        return factorEquilibrio;
    }

    public void setFactorEquilibrio(int factorEquilibrio) {
        this.factorEquilibrio = factorEquilibrio;
    }
    
}
