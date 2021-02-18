package com.jared.edd.nodos;

import com.jared.edd.otros.*;

public class NodoB {
	public int mK;
    public int mB;
    public Generico[] mLlaves;
    public Object[] mDatos;
    public NodoB[] mPunteros;

    public String getDotName() {
        return "Nodo" + this.hashCode();
    }

    public String toDot() {
        StringBuilder b = new StringBuilder();
        b.append(getDotName());
        b.append("[label=\"<P0>");
        for (int i = 0; i < mB; i++) {
            b.append("|").append(mLlaves[i].getKey()).append("    ").append(mLlaves[i].getName().toString());
            b.append("|<P").append(i + 1).append(">");
        }
        b.append("\"];\n");
        for (int i = 0; i <= mB; i++) {
            if (mPunteros[i] != null) {
                b.append(mPunteros[i].toDot());
                b.append(getDotName()).append(":P").append(i).append(" -> ").append(mPunteros[i].getDotName()).append(";\n");
            }
        }
        return b.toString();
    }

    public NodoB(int pK) {
        this.mK = pK;
        mB = 0;
        mLlaves = new Generico[2 * pK + 1];
        mDatos = new Object[2 * pK + 1];
        mPunteros = new NodoB[(2 * pK) + 2];
    }

    public NodoB(int pK, Generico pLlave, Object pDato) {
        this(pK);
        mB = 1;
        mLlaves[0] = pLlave;
        mDatos[0] = pDato;
    }

    public void setK(int mK) {
        this.mK = mK;
    }

    public int getK() {
        return mK;
    }
}
