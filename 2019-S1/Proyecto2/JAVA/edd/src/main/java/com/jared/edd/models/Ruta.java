package com.jared.edd.models;

public class Ruta {

	public int id_paisSalida;
	public int id_paisLlegada;
	public int costo;
	public int tiempo;
	
	public Ruta() {
		
	}
	
	public Ruta(int id_paisSalida, int id_paisLlegada, int costo, int tiempo) {
		this.id_paisSalida = id_paisSalida;
		this.id_paisLlegada = id_paisLlegada;
		this.costo = costo;
		this.tiempo = tiempo;
	}

	public int getId_paisSalida() {
		return id_paisSalida;
	}

	public void setId_paisSalida(int id_paisSalida) {
		this.id_paisSalida = id_paisSalida;
	}

	public int getId_paisLlegada() {
		return id_paisLlegada;
	}

	public void setId_paisLlegada(int id_paisLlegada) {
		this.id_paisLlegada = id_paisLlegada;
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
	
	
}
