package com.jared.edd.models;

public class Destino {

	public int id;
	public int index;
    public String pais;
    
    public Destino() {
    	this.id = 0;
    	this.index = 0;
    	this.pais = "";
    }
    
    public Destino(int id, String pais){
        this.id = id;
        this.pais = pais;
        this.index = 0;
    }

    public int getId() {
        return id;
    }
    
    public int getIndex() {
    	return index;
    }
    
    public void setIndex(int index) {
    	this.index = index;
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
