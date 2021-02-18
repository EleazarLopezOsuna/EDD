package com.jared.edd.estructuras;

import com.jared.edd.models.Destino;
import com.jared.edd.nodos.NodoDestino;

public class ListaDestino {

public NodoDestino primero;
public NodoDestino ultimo;
    
    public ListaDestino(){
        primero = null;
        ultimo = null;
    }
    
    //Empty
    public Boolean empty() {
    	if(primero == null) {
    		return true;
    	}
    	return false;
    }
    
    //Insertar
    public Boolean insertar(Destino destino){
        NodoDestino nuevo = new NodoDestino(destino);
        if(!empty()) {
        	if(!buscar(destino.getId())) {
        		ultimo.setSiguiente(nuevo);
            	ultimo = ultimo.getSiguiente();
            	return true;
        	}else {
        		return false;
        	}
        }else {
        	primero = ultimo = nuevo;
        	return true;
        }
    }
    
    //Buscar
    public Boolean buscar(int id) {
    	NodoDestino temp = primero;
    	while(temp != null) {
    		if(temp.getDato().getId() == id)
    			return true;
    		temp = temp.getSiguiente();
    	}
    	return false;
    }
    
    //Retornar Destino
    public Destino buscarD(int id) {
    	NodoDestino temp = primero;
    	while(temp != null) {
    		if(temp.getDato().getId() == id)
    			return temp.dato;
    		temp = temp.getSiguiente();
    	}
    	return null;
    }
    
    //Recorrer
    public String recorrer() {
    	NodoDestino temp = primero;
    	String respuesta = "";
    	while(temp != null) {
    		respuesta = respuesta + " , "+ temp.getDato().getPais();
    		temp = temp.getSiguiente();
    	}
    	return respuesta;
    }
    
    //Buscar por Nombre
    public int buscarCodigo(int nombre) {
    	NodoDestino temp = primero;
    	int respuesta = 0;
    	while(temp != null) {
    		if(temp.dato.id == nombre) {
    			return temp.dato.id;
    		}
    		temp = temp.getSiguiente();
    	}
    	return respuesta;
    }
    
  //Buscar por Nombre
    public int buscarCodigo(String nombre) {
    	NodoDestino temp = primero;
    	int respuesta = 0;
    	while(temp != null) {
    		if(temp.dato.pais.equals(nombre)) {
    			return temp.dato.id;
    		}
    		temp = temp.getSiguiente();
    	}
    	return respuesta;
    }
    
    //Eliminar
    public Boolean eliminar(int id) {
    	if(!empty()) {
    		if(primero == ultimo && id == primero.getDato().getId()) {
    			primero = ultimo = null;
    			return true;
    		}else if(id == primero.getDato().getId()) {
    			primero = primero.getSiguiente();
    			return true;
    		}else {
    			NodoDestino prev, temp;
    			prev = primero;
    			temp = primero.siguiente;
    			while(temp != null && temp.getDato().getId() != id) {
    				prev = prev.getSiguiente();
    				temp = temp.getSiguiente();
    			}
    			if(temp != null) {
    				prev.setSiguiente(temp.getSiguiente());
    				if(temp == ultimo) {
    					ultimo = prev;
    				}
    				return true;
    			}
    		}
    	}
    	return false;
    }
    
    public Boolean contiene(int id) {
    	if(!empty()) {
    		NodoDestino temp = primero;
    		while(temp != null) {
    			if(temp.getDato().getId() == id)
    				return true;
    			temp = temp.getSiguiente();
    		}
    	}
    	return false;
    }
}
