package com.jared.edd.estructuras;

import com.jared.edd.models.Usuario;
import com.jared.edd.nodos.NodoUsuario;

public class ArbolUsuario {
    public NodoUsuario raiz;
    
    public ArbolUsuario(){
        raiz = null;
    }
    
    //Insertar
    public void insertar(Usuario user){
        NodoUsuario nuevo = new NodoUsuario(user);
        if(raiz == null){
            raiz = nuevo;
        }else{
        	
            raiz = insertarBal(nuevo, raiz);
        }
    }
    
    //Obtener Raiz
    public NodoUsuario obtenerRaiz(){
        return raiz;
    }
    
    //Buscar Usario
    public Usuario buscarUsuario(int id) {
    	NodoUsuario r = raiz;
    	if(raiz == null){
            return null;
        }else if(r.getDato().id == id){
            return r.getDato();
        }else if(r.getDato().id < id){
            return buscarUsuario(id, r.hijoDerecho);
        }else{
            return buscarUsuario(id, r.hijoIzquierdo);
        }
    }
    
    public Usuario buscarUsuario(int id, NodoUsuario r) {
    	if(raiz == null){
            return null;
        }else if(r.getDato().id == id){
            return r.getDato();
        }else if(r.getDato().id < id){
            return buscarUsuario(id, r.hijoDerecho);    
        }else{
            return buscarUsuario(id, r.hijoIzquierdo);
        }
    }
    
    //Insertar Balanceado
    public NodoUsuario insertarBal(NodoUsuario nuevo, NodoUsuario sub){
        NodoUsuario padre = sub;
        if(nuevo.getDato().getId() < sub.getDato().getId()){
            if(sub.hijoIzquierdo == null){
                sub.hijoIzquierdo = nuevo;
            }else{
                sub.hijoIzquierdo = insertarBal(nuevo, sub.hijoIzquierdo);
                //Comprobamos DesBalance
                if((obtenerFE(sub.hijoIzquierdo)- obtenerFE(sub.hijoDerecho) == 2)){
                    if(nuevo.getDato().getId() < sub.hijoIzquierdo.getDato().getId()){
                        padre = rotacionIzquierda(sub);
                    }else{
                        padre = rotacionDobleIzquierda(sub);
                    }
                }
            }
        }else if(nuevo.getDato().getId() > sub.getDato().getId()){
            if(sub.hijoDerecho == null){
                sub.hijoDerecho = nuevo;
            }else{
                sub.hijoDerecho = insertarBal(nuevo, sub.hijoDerecho);
                //Comprobamos DesBalance
                if((obtenerFE(sub.hijoDerecho)- obtenerFE(sub.hijoIzquierdo) == 2)){
                    if(nuevo.getDato().getId() > sub.hijoDerecho.getDato().getId()){
                        padre = rotacionDerecha(sub);
                    }else{
                        padre = rotacionDobleDerecha(sub);
                    }
                }
            }
        }else{//Usuario Duplicado
            System.out.println("Error: Usuario ya registrado");
        }
        //Actualizando FE
        if((sub.hijoIzquierdo == null) && (sub.hijoDerecho != null)){
            sub.factorEquilibrio = sub.hijoDerecho.factorEquilibrio + 1;
        }else if((sub.hijoDerecho == null) && (sub.hijoIzquierdo != null)){
            sub.factorEquilibrio = sub.hijoIzquierdo.factorEquilibrio + 1;
        }else{
            sub.factorEquilibrio = Math.max(obtenerFE(sub.hijoIzquierdo), obtenerFE(sub.hijoDerecho)) + 1;
        }
        return padre;
    }
    
    //Buscar
    public NodoUsuario buscar(int id, NodoUsuario r){
        if(raiz == null){
            return null;
        }else if(r.getDato().getId() == id){
            return r;
        }else if(r.getDato().getId() < id){
            return buscar(id, r.hijoDerecho);
        }else{
            return buscar(id, r.hijoIzquierdo);
        }
    }
    
    //Obtener FE (Factor de Equilibrio)
    public int obtenerFE(NodoUsuario nu){
        if(nu == null){
            return -1;
        }else{
            return nu.factorEquilibrio;
        }
    }
    
    //Rotacion Simple Izquierda
    public NodoUsuario rotacionIzquierda(NodoUsuario nu){
        NodoUsuario temp = nu.hijoIzquierdo;
        nu.hijoIzquierdo = temp.hijoDerecho;
        temp.hijoDerecho = nu;
        nu.factorEquilibrio = Math.max(obtenerFE(nu.hijoIzquierdo), obtenerFE(nu.hijoDerecho)) + 1;
        temp.factorEquilibrio = Math.max(obtenerFE(temp.hijoIzquierdo), obtenerFE(temp.hijoDerecho)) + 1;
        return temp;
    }
    
    //Rotacion Simple Derecha
    public NodoUsuario rotacionDerecha(NodoUsuario nu){
        NodoUsuario temp = nu.hijoDerecho;
        nu.hijoDerecho = temp.hijoIzquierdo;
        temp.hijoIzquierdo= nu;
        nu.factorEquilibrio = Math.max(obtenerFE(nu.hijoIzquierdo), obtenerFE(nu.hijoDerecho)) + 1;
        temp.factorEquilibrio = Math.max(obtenerFE(temp.hijoIzquierdo), obtenerFE(temp.hijoDerecho)) + 1;
        return temp;
    }
    
    //Rotacion Doble Izquierda
    public NodoUsuario rotacionDobleIzquierda(NodoUsuario nu){
        NodoUsuario temp;
        nu.hijoIzquierdo = rotacionDerecha(nu.hijoIzquierdo);
        temp = rotacionIzquierda(nu);
        return temp;
    }
    
    //Rotacion Doble Derecha
    public NodoUsuario rotacionDobleDerecha(NodoUsuario nu){
        NodoUsuario temp;
        nu.hijoDerecho = rotacionIzquierda(nu.hijoDerecho);
        temp = rotacionDerecha(nu);
        return temp;
    }
    
    
    
    //Recorrer
    public String preOrden(NodoUsuario r){
    	
    		
    	
        if(r != null){
        	//Raiz
        	String raizId = String.valueOf(r.getDato().getId());
        	String raizName = r.getDato().getNombre();
        	String cadenaRaiz = "";
        	
        	//Variables para almacenar los valores para los apuntadores
        	String hijoIzId = "";
        	String cadenahijoIz = "";
        	String hijoDeId = "";
        	String cadenahijoDe = "";
        	
        	//Setear Nodo Principal
        	cadenaRaiz = raizId + " [shape=record,label = \"<f0> |<f1> " + raizId + " " + raizName + "|<f2>\"];\n";
        	
        	//Setear apuntador a Hijo Izquierdo si existe
        	if(r.getHijoIzquierdo() != null) {
        		//Obtiene los datos del hijo izquierdo
      			NodoUsuario hijoIz = r.getHijoIzquierdo();
      			hijoIzId = String.valueOf(hijoIz.getDato().getId());
      			cadenahijoIz = raizId + ":f0 -> " + hijoIzId + ":f1;\n";
        	}
        	
        	//Setear apuntador a Hijo Derecho si existe
        	if(r.getHijoDerecho() != null) {
        		//Obtiene los datos del hijo derecho
        		NodoUsuario hijoDe = r.getHijoDerecho();
            	hijoDeId = String.valueOf(hijoDe.getDato().getId());
      			cadenahijoDe = raizId + ":f2 -> " + hijoDeId + ":f1;\n";
        	}
        	
        	//Se genera la cadena para enviar a graphviz
      		String cadena =  cadenaRaiz + cadenahijoIz + cadenahijoDe;
      		return cadena + preOrden(r.hijoIzquierdo) +preOrden(r.hijoDerecho);
        }else {
        	return "";
        }
    }
}
