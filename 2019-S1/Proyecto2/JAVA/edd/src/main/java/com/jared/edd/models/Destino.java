package com.jared.edd.models;

public class Destino {

	public int id;
    public String pais;
    
    public Destino() {
    	
    }
    
    public Destino(int id, String pais){
        this.id = id;
        this.pais = pais;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getPais() {
        return pais;
    }

    public void setPais(String pais) {
        this.pais = pais;
    }
    
}
