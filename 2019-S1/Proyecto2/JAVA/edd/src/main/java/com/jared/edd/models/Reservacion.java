package com.jared.edd.models;

import java.util.ArrayList;
import java.util.Random;

import com.jared.edd.test;

public class Reservacion {
    public int costo;
    public int tiempo;
    public int reservacion;
    public String nombre;
    public ArrayList<String[]> vuelo = new ArrayList<String[]>();
    public String codigos;
    
    public Reservacion() {}
    
    public Reservacion(int costo, int tiempo, String nombre, String codigos){
        Random random = new Random();
        int nRandom = random.nextInt(999);
        String numero = "" + nRandom + costo + tiempo;
        int numeroInt = Integer.parseInt(numero);
        this.reservacion = numeroInt;
        this.costo = costo;
        this.tiempo = tiempo;
        this.nombre = nombre;
        String[] cod = codigos.split(",");
        for(int i = 0; i < cod.length; i++) {
            String hola[] = new String[2];
        	int nCod = Integer.parseInt(cod[i]);
        	Destino destino = test.destinito.buscarD(nCod);
        	hola[0] = destino.getPais();
        	hola[1] = String.valueOf(destino.getId());
            vuelo.add(hola);
        }
    }
    
    public int getCosto() {
        return costo;
    }

    public void setCosto(int costo) {
        this.costo = costo;
    }

    public int getTiempo() {
        return tiempo;
    }

    public void setTiempo(int tiempo) {
        this.tiempo = tiempo;
    }

    public int getReservacion() {
        return reservacion;
    }

    public void setReservacion(int reservacion) {
        this.reservacion = reservacion;
    }

    public String getNombre() {
        return nombre;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public ArrayList<String[]> getVuelo() {
        return vuelo;
    }

    public void setVuelo(ArrayList<String[]> vuelo) {
        this.vuelo = vuelo;
    }
    
    
}
