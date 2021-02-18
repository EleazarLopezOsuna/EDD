package com.jared.edd.otros;

public class InfoGestion extends Generico {

    private Integer mLlave = null;
    private String fecha = null;
    private String hora = null;
    private Double costo = null;
    private String NombreUs = null;
    private Integer CodigoUs = null;
    private String Descrip = null;

    public InfoGestion(int pValor) {
        mLlave = pValor;
    }

    public InfoGestion(Integer Codigo, String Fecha, String Hora, Double Costo, String Nombre, int Cod_Usuario, String Descripcion) {
        mLlave = Codigo;
        fecha = Fecha;
        hora = Hora;
        costo = Costo;
        NombreUs = Nombre;
        CodigoUs = Cod_Usuario;
        Descrip = Descripcion;
    }

    public Object getKey() {
        return mLlave;
    }

    public Object getName() {
        return NombreUs;
    }

    public Object getFecha() {
        return fecha;
    }

    public Object getHora() {
        return hora;
    }

    public Object getCosto() {
        return costo;
    }

    public Object getCodigo() {
        return CodigoUs;
    }

    public Object getDesc() {
        return Descrip;
    }

    public void SetName(String n) {
        NombreUs = n;
    }

    public boolean igualA(Generico pObjeto) {
        return mLlave.equals(pObjeto.getKey());
    }

    public boolean menorQue(Generico pObjeto) {
        return mLlave.compareTo((Integer) pObjeto.getKey()) < 0;
    }

    public boolean mayorQue(Generico pObjeto) {
        return mLlave.compareTo((Integer) pObjeto.getKey()) > 0;
    }

    public boolean menorOIgualQue(Generico pObjeto) {
        return mLlave.compareTo((Integer) pObjeto.getKey()) <= 0;
    }

    public boolean mayorOIgualQue(Generico pObjeto) {
        return mLlave.compareTo((Integer) pObjeto.getKey()) >= 0;
    }

    public Generico minKey() {
        return new InfoGestion(Integer.MIN_VALUE);
    }

}
