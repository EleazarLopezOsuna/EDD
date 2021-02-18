package com.jared.edd.estructuras;

import java.util.Arrays;
import com.jared.edd.models.Reservacion;

public class TablaHash {
	public Reservacion[] arreglo;
    public int size = 44;
    public int contador;

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public TablaHash(int size) {
        this.size = size;
        arreglo = new Reservacion[size];
        Arrays.fill(arreglo, null);
    }

    public void funcionHash(Reservacion[] recibe) {
        for (Reservacion temp : recibe) {
            int contadorx = recibe.length;
            while (true) {
                float porcentajeLleno = (contadorx) * 100 / size;
                if (porcentajeLleno > 50) {
                    size = siguientePrimo(size);
                    arreglo = new Reservacion[size];
                } else {
                    break;
                }
            }
            if (temp != null) {
                int codReservacion = temp.reservacion % (size - 1);
                Reservacion[] envia = arreglo;
                while (envia[codReservacion] != null) {
                    codReservacion++;
                    codReservacion %= size;
                }
                envia[codReservacion] = temp;
            }
        }
    }

    public String recorrer() {
        int incremento = 0;
        String rankTabla = "{rank = same;";
        String rankLista = "{rank = same;";
        String apuntadorTabla = "";
        String nodoTabla = "";
        String apuntadorTablaLista = "";
        String nodoLista = "";
        String retorno = "";
        int primero = -1;
        for (int i = 0; i < 1; i++) {
            incremento += size;
            for (int j = incremento - size; j < incremento; j++) {
                if (arreglo[j] != null) {
                    primero++;
                    String nodoActualTabla = "\"N_" + arreglo[j].reservacion + "\"";
                    nodoTabla += nodoActualTabla + "[label = \"" + "Cliente: " + arreglo[j].nombre + " Reservacion: " + arreglo[j].reservacion + "\",style = filled, fillcolor = darksalmon]" + "\n";
                    rankTabla += nodoActualTabla + ";";
                    if (primero == 0) {
                        apuntadorTabla += nodoActualTabla;
                    } else {
                        apuntadorTabla += " -> " + nodoActualTabla;
                    }
                    String nodoActualLista = "\"S_" + arreglo[j].reservacion + "\"";
                    String contenido = "";
                    for(int k = 0; k < arreglo[j].vuelo.size(); k++) {
                    	String[] actual = arreglo[j].vuelo.get(k);
                    	if(k == (arreglo[j].vuelo.size() - 1)) {
                    		String c = " Pais: " + actual[0];
                    		String id = " Codigo: " + actual[1];
                    		contenido += c + id;
                    	}else {
                    		String c = " Pais: " + actual[0];
                    		String id = " Codigo: " + actual[1];
                    		contenido += c + id + " | ";
                    	}
                    }
                    rankLista += nodoActualLista + ";";
                    apuntadorTablaLista += nodoActualTabla + " -> " + nodoActualLista + "\n";
                    nodoLista += nodoActualLista + "[label = \"" + contenido + "\",style = filled, fillcolor = cornflowerblue]" + "\n";
                }
            }
        }
        rankLista += "}";
        rankTabla += "} \n";
        retorno += nodoTabla + nodoLista + apuntadorTabla + apuntadorTablaLista + rankTabla + rankLista;
        return retorno;
    }

    public int siguientePrimo(int primoInicial) {
        while (!false) {
            int divisores = 0;
            primoInicial++;
            for (int i = 1; i <= primoInicial; i++) {
                if (primoInicial % i == 0) {
                    divisores++;
                }
            }
            if (divisores == 2) {
                return primoInicial + 1;
            }
        }
    }
}
