package com.jared.edd.estructuras;

import com.jared.edd.nodos.NodoGrafo;
import com.jared.edd.nodos.NodoDestino;
import com.jared.edd.test;
import com.jared.edd.models.Destino;
import com.jared.edd.models.Ruta;;

public class GrafoRuta {

	private NodoGrafo primero;
	private NodoGrafo ultimo;
    
    public GrafoRuta(){
        primero = null;
        ultimo = null;
    }
    
    //Busca si el Grafo cuenta con el Id del pais
    public Boolean buscar(int id) {
    	NodoGrafo temp = primero;
    	while(temp != null) {
    		if(temp.getDato().getId() == id)
    			return true;
    		temp = temp.getSiguiente();
    	}
    	return false;
    }
    
    //Inserta un nuevo nodo dentro del Grafo
    public String insertarRuta(Ruta ruta) {
    	String retorno = "";
    	if(ruta.getId_paisLlegada() != ruta.getId_paisSalida()) {
    		NodoGrafo temp = primero;//Seteamos el NodoGrafo para recorrer
        	while(temp != null) {
        		if(temp.getDato().getId() == ruta.getId_paisSalida()) {//Busca el Nodo que requerimos
        			break;//Finaliza el while cuando encuentra el nodo
        		}
        		temp = temp.getSiguiente();
        	}
        	if(temp != null) {//Encontro el nodo del Grafo con el Id de salida
        		if(buscar(ruta.getId_paisLlegada())) {
        			if(temp.getRuta() != null) {//La lista no esta Vacia
            			if(!temp.getRuta().buscar(ruta)) {//Busca la ruta dentro de la Lista
            				temp.getRuta().insertar(ruta);//No encontro la ruta dentro de la Lista, procede a Insertar la ruta
            			}else {
            				retorno = "ERROR: Ruta duplicada";
            			}
            		}else {//La lista esta vacia
            			ListaRuta lr = new ListaRuta();//Se crea una nueva Lista
            			lr.insertar(ruta);//Se añade la ruta a la Lista
            			temp.setRuta(lr);//Agregamos la Lista al Nodo
            		}
        			if(retorno == "") {//Verifica si no hubo ningun Error
        				int pS = ruta.getId_paisLlegada();
        				int pL = ruta.getId_paisSalida();
        				int pC = ruta.getCosto();
        				int pT = ruta.getTiempo();
        				Ruta rutaRetorno = new Ruta(pS,pL,pC,pT);
        				insertarRutaRetorno(rutaRetorno);
        				retorno = "Ingresado";
        			}
        		}else {//No encontro el nodo del Grafo con el Id de llegada
        			retorno = "ERROR: Pais de Llegada no Ingresado";
        		}
        	}else {//No encontro el nodo del Grafo con el Id de salida
        		retorno = "ERROR: Pais de Origen no Ingresado";
        	}
    	}else {
    		retorno = "ERROR: El Pais de Origen no puede ser igual al Pais de Llegada";
    	}
    	return retorno;
    }
    
    public void insertar(Destino destino) {
    	NodoGrafo nuevo = new NodoGrafo(destino);
        if(!empty()) {
        	if(!buscar(destino.getId())) {
        		ultimo.setSiguiente(nuevo);
            	ultimo = ultimo.getSiguiente();
        	}
        }else {
        	primero = ultimo = nuevo;
        }
    }
    
    public void insertarRutaRetorno(Ruta ruta) {
    	NodoGrafo temp = primero;//Seteamos el NodoGrafo para recorrer
    	while(temp != null) {
    		if(temp.getDato().getId() == ruta.getId_paisSalida()) {//Busca el Nodo que requerimos
    			break;//Finaliza el while cuando encuentra el nodo
    		}
    		temp = temp.getSiguiente();
    	}
    	if(temp.getRuta() == null) {//La lista esta vacia
    		ListaRuta lr = new ListaRuta();//Se crea una nueva Lista
			lr.insertar(ruta);//Se añade la ruta a la Lista
			temp.setRuta(lr);//Agregamos la Lista al Nodo
    	}else {//La lista no esta Vacia
    		temp.getRuta().insertar(ruta);//No encontro la ruta dentro de la Lista, procede a Insertar la ruta
    	}
    }
    
  //Verifica si el Grafo esta vacio
    public Boolean empty() {
    	if(primero == null) {
    		return true;
    	}
    	return false;
    }
    
    //Recorre el Grafo para Graficarlo
    public String recorrerGrafo() {
    	String resultado = "";
    	NodoGrafo temp = primero;
		String ingresados = "";
    	while(temp != null) {
    		if(temp.getRuta() != null) {
    			String temporal = temp.getRuta().recorrer();
        		String nombrePais = temp.getDato().getPais();
        		String apuntador = "";
        		if(temporal != "") {
        			String codigoPaises[]  = temporal.split(",");
            		for(int i = 1; i < codigoPaises.length; i++) {
            			int cod = Integer.parseInt(codigoPaises[i]);
            			String re = buscarNombre(cod);
            			if(re != "") {
            				String a = nombrePais+re;
            				String b = re+nombrePais;
            				if(ingresados.contains(a) || ingresados.contains(b)) {
            					
            				}else {
            					int tiempo = temp.getRuta().obtenerTiempo(temp.getDato().getId(), cod);
            					int costo = temp.getRuta().obtenerCosto(temp.getDato().getId(), cod);
            					apuntador = "\"" + nombrePais + "\"" + "->" + "\"" + re + "\"" + "[label = \"\\E \\n Tiempo: " + tiempo + "\\n Costo: " + costo + "\", fontsize=\"10\", labeldistance = \"4.0\"];\n";
            					ingresados += a + ",";
            					ingresados += b + ",";
            				}
            			}else {
            				apuntador = "";
            			}
            			resultado += apuntador;
            		}
        		}
    		}
    		temp = temp.getSiguiente();
    	}
    	return resultado;
    }
    
    public String buscarNombre(int id) {
    	NodoDestino temp = test.destinito.primero;
    	while(temp != null) {
    		if(temp.getDato().getId() == id)
    			return temp.getDato().getPais();
    		temp = temp.getSiguiente();
    	}
    	return "";
    }
    
}
