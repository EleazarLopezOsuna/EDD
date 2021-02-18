package com.jared.edd.estructuras;

import com.jared.edd.models.Ruta;
import com.jared.edd.nodos.NodoRuta;

public class ListaRuta {

public NodoRuta primero;
public NodoRuta ultimo;
    
    public ListaRuta(){
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
    public Boolean insertar(Ruta ruta){
    	NodoRuta nuevo = new NodoRuta(ruta);
        if(!empty()) {
        	if(!buscar(ruta)) {
        		ultimo.setSiguiente(nuevo);
            	ultimo = ultimo.getSiguiente();
        	}
        	return true;
        }else {
        	primero = ultimo = nuevo;
        	return true;
        }
    }
    
    //Buscar
    public Boolean buscar(Ruta ruta) {
    	NodoRuta temp = primero;
    	while(temp != null) {
    		if(temp.getDato().getId_paisSalida() == ruta.id_paisSalida && temp.getDato().getId_paisLlegada() == ruta.id_paisLlegada)
    			return true;
    		temp = temp.getSiguiente();
    	}
    	return false;
    }
    
  //Eliminar
    public Boolean eliminar(int llegada, int salida) {
    	if(!empty()) {
    		if(primero == ultimo && llegada == primero.getDato().getId_paisLlegada()
    				&& salida == primero.getDato().getId_paisSalida()) {
    			primero = ultimo = null;
    			return true;
    		}else if(llegada == primero.getDato().getId_paisLlegada()
    				&& salida == primero.getDato().getId_paisSalida()) {
    			primero = primero.getSiguiente();
    			return true;
    		}else {
    			NodoRuta prev, temp;
    			prev = primero;
    			temp = primero.siguiente;
    			while(temp != null && temp.getDato().getId_paisLlegada() != llegada
    					&& temp.getDato().getId_paisSalida() != salida) {
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
    
    //Recorrer
    public String recorrer() {
    	NodoRuta temp = primero;
    	String respuesta = "";
    	while(temp != null) {
    		respuesta = respuesta + ","+ temp.getDato().getId_paisLlegada();
    		temp = temp.getSiguiente();
    	}
    	return respuesta;
    }
    
    public int obtenerTiempo(int salida, int llegada) {
    	NodoRuta temp = primero;
    	while(temp != null) {
    		if((salida == temp.getDato().getId_paisSalida()) && (llegada == temp.getDato().getId_paisLlegada()))
    			return temp.getDato().getTiempo();
    		temp = temp.getSiguiente();
    	}
    	return 0;
    }
    
    public int obtenerCosto(int salida, int llegada) {
    	NodoRuta temp = primero;
    	while(temp != null) {
    		if((salida == temp.getDato().getId_paisSalida()) && (llegada == temp.getDato().getId_paisLlegada()))
    			return temp.getDato().getCosto();
    		temp = temp.getSiguiente();
    	}
    	return 0;
    }
}
