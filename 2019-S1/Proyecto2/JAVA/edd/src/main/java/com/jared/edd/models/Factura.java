package com.jared.edd.models;

public class Factura {

    public int key;
    public String fecha;
    public String hora;
    public Double costo;
    public String nombre;
    public int codigo;
    public String descripcion;

    public Factura() {

    }

    public Factura(int key, String fecha, String hora, Double costo, String nombre, int codigo, String descripcion) {
        this.key = key;
        this.fecha = fecha;
        this.hora = hora;
        this.nombre = nombre;
        this.codigo = codigo;
        this.descripcion = descripcion;
    }

    public int getId_Factura() {
        return key;
    }

    public void setId_Factura(int id_Factura) {
        this.key = id_Factura;
    }

    public String getFecha() {
        return fecha;
    }

    public void setFecha(String fecha) {
        this.fecha = fecha;
    }

    public String getHora() {
        return hora;
    }

    public void setHora(String hora) {
        this.hora = hora;
    }

    public Double getCosto() {
        return costo;
    }

    public void setCosto(Double costo) {
        this.costo = costo;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public int getCodigo() {
        return codigo;
    }

    public void setCodigo(int codigo) {
        this.codigo = codigo;
    }

    public String getDescripcion() {
        return descripcion;
    }

    public void setDescripcion(String descripcion) {
        this.descripcion = descripcion;
    }

    
}
