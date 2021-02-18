package com.jared.edd.models;

public class Reservacion {
	private long numeroReservacion;
    private String nombreCliente;
    private double costo;
    private float tiempo;
    private String planVuelo;
    
    public Reservacion() {
        this.numeroReservacion = 0;
        this.nombreCliente = "";
        this.costo = 0;
        this.tiempo = 0;
        this.planVuelo = null;
    }

    public Reservacion(long numeroReservacion, String nombreCliente, double costo, float tiempo, String planVuelo) {
        this.numeroReservacion = numeroReservacion;
        this.nombreCliente = nombreCliente;
        this.costo = costo;
        this.tiempo = tiempo;
        this.planVuelo = planVuelo;
    }

    public long getNumeroReservacion() {
        return numeroReservacion;
    }

    public void setNumeroReservacion(long numeroReservacion) {
        this.numeroReservacion = numeroReservacion;
    }

    public String getNombreCliente() {
        return nombreCliente;
    }

    public void setNombreCliente(String nombreCliente) {
        this.nombreCliente = nombreCliente;
    }

    public double getCosto() {
        return costo;
    }

    public void setCosto(double costo) {
        this.costo = costo;
    }

    public float getTiempo() {
        return tiempo;
    }

    public void setTiempo(float tiempo) {
        this.tiempo = tiempo;
    }

    public String getPlanVuelo() {
        return planVuelo;
    }

    public void setPlanVuelo(String planVuelo) {
        this.planVuelo = planVuelo;
    }
}
