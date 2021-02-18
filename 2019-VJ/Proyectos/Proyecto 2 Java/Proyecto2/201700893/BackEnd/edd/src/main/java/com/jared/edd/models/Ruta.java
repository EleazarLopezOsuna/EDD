package com.jared.edd.models;

public class Ruta {

	public int id_paisSalida;
	public int id_paisLlegada;
	public int costo;
	public int tiempo;
	public String piloto;

	public Ruta() {

	}

	public static String partirPalabra(String palabra) {
		String retorno = "";
		for (int i = 0; i < palabra.length(); i++) {
			int caracter = palabra.charAt(i);
			retorno += codificar(caracter);
		}
		return retorno;
	}

	public static String codificar(int entrada) {
		int llave = 11;
		int nuevoCaracter = entrada ^ llave;
		char caracter = (char) nuevoCaracter;
		String retorno = String.valueOf(caracter);
		return retorno;
	}

	public Ruta(int id_paisSalida, int id_paisLlegada, int costo, int tiempo, String piloto) {
		this.id_paisSalida = id_paisSalida;
		this.id_paisLlegada = id_paisLlegada;
		this.costo = costo;
		this.tiempo = tiempo;
		this.piloto = partirPalabra(piloto);
	}

	public String getPiloto() {
		return partirPalabra(piloto);
	}

	public void setPiloto(String piloto) {
		this.piloto = partirPalabra(piloto);
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
