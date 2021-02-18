package com.jared.edd.otros;

public class LlaveCadena extends Generico {
    public LlaveCadena(String pValor) {
        mLlave = pValor;
    }    
    private String mLlave = null;    

    public Object getKey() {
        return mLlave;
    }
    
    public boolean igualA(Generico pObjeto) {
        return mLlave.equals(pObjeto.getKey());
    }

    public boolean menorQue(Generico pObjeto) {
        return mLlave.compareTo((String)pObjeto.getKey()) < 0;
    }
    
    public boolean mayorQue(Generico pObjeto) {
        return mLlave.compareTo((String)pObjeto.getKey()) > 0;
    }
    
    public boolean menorOIgualQue(Generico pObjeto) {
        return mLlave.compareTo((String)pObjeto.getKey()) <= 0;
    }
    
    public boolean mayorOIgualQue(Generico pObjeto) {
        return mLlave.compareTo((String)pObjeto.getKey()) >= 0;
    }
    
    public Generico minKey() {
        return new LlaveCadena("");
    }
}
