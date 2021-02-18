package com.jared.edd.otros;

import com.jared.edd.nodos.NodoB;

public class Split {
    public NodoB mPuntero;
    public Generico mLlave;
    public Object mDato;

    public Split(NodoB pPuntero, Generico pLlave, Object pDato) {
        this.mPuntero = pPuntero;
        this.mLlave = pLlave;
        this.mDato = pDato;
    }

    public void setPuntero(NodoB mPuntero) {
        this.mPuntero = mPuntero;
    }

    public NodoB getPuntero() {
        return mPuntero;
    }

    public void setLlave(Generico mLlave) {
        this.mLlave = mLlave;
    }

    public Generico getLlave() {
        return mLlave;
    }

    public void setDato(Object mDato) {
        this.mDato = mDato;
    }

    public Object getDato() {
        return mDato;
    }
}