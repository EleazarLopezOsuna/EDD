package com.jared.edd.estructuras;

import java.util.Arrays;
import com.jared.edd.models.Reservacion;

public class TablaHash {
	private int size;
    private int ingresados;
    private Reservacion tabla[];

    public TablaHash() {
        this.size = 7;
        tabla = new Reservacion[size];
        Arrays.fill(tabla, null);
        this.ingresados = 0;
    }

    public Reservacion[] getTabla() {
        return tabla;
    }

    public void setTabla(Reservacion[] tabla) {
        this.tabla = tabla;
    }

    public int getIngresados() {
        return ingresados;
    }

    public void setIngresados(int ingresados) {
        this.ingresados = ingresados;
    }

    public int getSize() {
        return size;
    }

    public void setSize(int size) {
        this.size = size;
    }

    public void cambiarSize() {
        int temp = size + 1;
        while (true) {
            if (esPrimo(temp)) {
                break;
            } else {
                temp++;
            }
        }
        size = temp;
        Reservacion tabTemp[] = tabla;
        tabla = new Reservacion[size];
        ingresados = 0;
        for (int i = 0; i < tabTemp.length; i++) {
            if (tabTemp[i] != null) {
                insertar(tabTemp[i]);
            }
        }
    }

    private boolean esPrimo(int numero) {
        int contadorDivisores = 0;
        for (int i = numero; i > 0; i--) {
            if (numero % i == 0) {
                contadorDivisores++;
            }
        }
        return (contadorDivisores == 2);
    }

    public void insertar(Reservacion reservacion) {
        if (ingresados < (size / 2)) {
            int llave = reservacion.getNombreCliente().charAt(0)
                    + reservacion.getNombreCliente().charAt(1) + reservacion.getNombreCliente().charAt(2);
            int index = llave % size;
            if (tabla[index] != null) {
                redireccionar(reservacion, index, 0);
            } else {
                tabla[index] = reservacion;
                ingresados++;
            }
        } else {
            cambiarSize();
            insertar(reservacion);
        }
    }

    private void redireccionar(Reservacion reservacion, int index, int iteracion) {
        int newIndex = index + (iteracion + 1) * (iteracion + 1);
        if (newIndex <= size) {
            if (tabla[newIndex - 1] == null) {
                tabla[newIndex - 1] = reservacion;
                ingresados++;
            } else {
                redireccionar(reservacion, index, iteracion + 1);
            }
        } else {
            while (newIndex > size) {
                newIndex -= size;
            }
            if (tabla[newIndex] == null) {
                tabla[newIndex] = reservacion;
                ingresados++;
            } else {
                redireccionar(reservacion, index, iteracion + 1);
            }
        }
    }
    
    public void eliminar(String nombre) {
        for(int i = 0; i < tabla.length; i++) {
        	if(tabla[i] != null) {
        		if(tabla[i].getNombreCliente().equals(nombre)) {
        			tabla[i] = null;
        		}
        	}
        }
    }

    public String recorrer() {
        String retorno = "digraph{\nnode[shape=record];\nrankdir=LR;\n";
        String rank = "{rank = same; ";
        for (int i = 0; i < tabla.length; i++) {
            String nodo = "";
            String apuntador = "";
            if (tabla[i] != null) {
                nodo = "HashIndex" + i + "[label = \"" + tabla[i].getNombreCliente() + " \\n"+ 
                        tabla[i].getPlanVuelo() + "\"];\n";
            }else{
                nodo = "HashIndex" + i + "[label = \"\"];\n";
            }
            if(i + 1 == tabla.length){
                apuntador = "";
            }else{
                apuntador = "HashIndex" + i + " -> HashIndex" + (i+1) + ";\n";
            }
            retorno += nodo;
            retorno += apuntador;
            rank += "HashIndex" + i + "; ";
        }
        rank += "}\n";
        retorno += rank;
        retorno += "}";
        return retorno;
    }

    public Reservacion buscar(String nombreUsuario) {
        int llave = nombreUsuario.charAt(0)
                + nombreUsuario.charAt(1) + nombreUsuario.charAt(2);
        int index = llave % size;
        if (tabla[index] != null) {
            if (tabla[index].getNombreCliente().compareTo(nombreUsuario) == 0) {
                return tabla[index];
            } else {
                int iteracion = 0;
                int visitado = 0;
                String visitados = "";
                while (true) {
                    int newIndex = index + (iteracion + 1) * (iteracion + 1);
                    if (visitado <= size) {
                        if (newIndex <= size) {
                            if (tabla[newIndex - 1] != null) {
                                if (tabla[newIndex - 1].getNombreCliente().compareTo(nombreUsuario) == 0) {
                                    return tabla[newIndex - 1];
                                } else {
                                    if (!visitados.contains(String.valueOf(newIndex))) {
                                        visitados += newIndex + ";";
                                        visitado++;
                                    }
                                }
                            } else {
                                if (!visitados.contains(String.valueOf(newIndex))) {
                                    visitados += newIndex + ";";
                                    visitado++;
                                }
                            }
                        } else {
                            while (newIndex > size) {
                                newIndex -= size;
                            }
                            if (tabla[newIndex] != null) {
                                if (tabla[newIndex].getNombreCliente().compareTo(nombreUsuario) == 0) {
                                    return tabla[newIndex];
                                } else {
                                    if (!visitados.contains(String.valueOf(newIndex))) {
                                        visitados += newIndex + ";";
                                        visitado++;
                                    }
                                }
                            } else {
                                if (!visitados.contains(String.valueOf(newIndex))) {
                                    visitados += newIndex + ";";
                                    visitado++;
                                }
                            }
                        }
                    } else {
                        break;
                    }
                    iteracion++;
                }
            }
        }
        return null;
    }
}
