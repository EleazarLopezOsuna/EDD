package com.jared.edd.estructuras;

import com.jared.edd.models.*;
import com.jared.edd.*;

public class ArbolB {
	public Rama raiz;

	public ArbolB() {
		raiz = null;
	}

	class Rama {

		NodoB primero;
		int cuenta;
		boolean hoja;

		public Rama(NodoB primero) {
			this.primero = primero;
			this.cuenta = 1;
			this.hoja = true;
		}

		public Rama() {
			primero = null;
			cuenta = 0;
			hoja = true;
		}

		public NodoB getPrimero() {
			return primero;
		}

		public void setPrimero(NodoB primero) {
			this.primero = primero;
		}

		public int getCuenta() {
			return cuenta;
		}

		public void setCuenta(int cuenta) {
			this.cuenta = cuenta;
		}

		public boolean esHoja() {
			return hoja;
		}

		public void setHoja(boolean hoja) {
			this.hoja = hoja;
		}

		void insertar(NodoB nuevo) {
			NodoB aux = primero;
			do {
				if (primero != null) {
					if (nuevo.destino.id < aux.destino.id) {
						if (aux == primero) {
							primero.anterior = nuevo;
							nuevo.izquierda = primero.derecha;
							nuevo.siguiente = primero;
							primero = nuevo;
							break;
						} else {
							nuevo.anterior = aux.anterior;
							nuevo.siguiente = aux;
							aux.anterior.siguiente = nuevo;
							aux.anterior.derecha = nuevo.izquierda;
							aux.anterior = nuevo;
							aux.izquierda = nuevo.derecha;
							break;
						}
					} else if (aux.siguiente == null) {
						aux.siguiente = nuevo;
						aux.derecha = nuevo.izquierda;
						nuevo.anterior = aux;
						nuevo.siguiente = null;
						break;
					}
				} else {
					primero = nuevo;
					break;
				}
				aux = aux.siguiente;
			} while (aux != null);
			setCuenta(getCuenta() + 1);
		}
	}

	class NodoB {

		Destino destino;
		NodoB anterior, siguiente;
		Rama izquierda, derecha;

		public NodoB(Destino destino) {
			this.destino = destino;
			this.siguiente = null;
			this.anterior = null;
			this.izquierda = null;
			this.derecha = null;
		}

		public Destino getDestino() {
			return destino;
		}

		public void setDestino(Destino destino) {
			this.destino = destino;
		}

		public NodoB getAnterior() {
			return anterior;
		}

		public void setAnterior(NodoB anterior) {
			this.anterior = anterior;
		}

		public NodoB getSiguiente() {
			return siguiente;
		}

		public void setSiguiente(NodoB siguiente) {
			this.siguiente = siguiente;
		}

		public Rama getIzquierda() {
			return izquierda;
		}

		public void setIzquierda(Rama izquierda) {
			this.izquierda = izquierda;
		}

		public Rama getDerecha() {
			return derecha;
		}

		public void setDerecha(Rama derecha) {
			this.derecha = derecha;
		}

	}

	boolean estaVacio() {
		return (raiz == null);
	}

	public void insertar(Destino destino) {
		NodoB nodo = new NodoB(destino);
		if (estaVacio()) {
			raiz = new Rama();
			raiz.insertar(nodo);
		} else {
			Object obj = inserta(nodo, raiz);
			if (obj instanceof NodoB) {
				raiz = new Rama();
				raiz.insertar((NodoB) obj);
				raiz.setHoja(false);
			}
		}
	}

	public Object dividir(Rama rama) {
		NodoB aux = rama.primero;
		NodoB aux1 = rama.primero;
		for (int i = 0; i < 2; i++) {
			aux = aux.siguiente;
		}
		Rama izq = new Rama(aux1);
		izq.setCuenta(2);
		aux1.siguiente.siguiente = null;
		aux1.siguiente.derecha = aux.izquierda;
		Rama der = new Rama(aux.siguiente);
		der.setCuenta(2);
		aux.siguiente.anterior = null;
		aux.izquierda = izq;
		aux.derecha = der;
		aux.siguiente = null;
		aux.anterior = null;
		if (rama.esHoja()) {

		} else {
			der.setHoja(false);
			izq.setHoja(false);
		}
		return aux;
	}

	private Object inserta(NodoB nodo, Rama rama) {
		if (rama.esHoja()) {
			rama.insertar(nodo);
			if (rama.getCuenta() == 5) {
				return dividir(rama);
			} else {
				return rama;
			}
		} else {
			NodoB temp = rama.getPrimero();
			do {
				if (nodo.getDestino().getId() == temp.getDestino().getId()) {
					return rama;
				} else if (nodo.getDestino().getId() < temp.getDestino().getId()) {
					Object obj = inserta(nodo, temp.getIzquierda());
					if (obj instanceof NodoB) {
						rama.insertar((NodoB) obj);
						if (rama.getCuenta() == 5) {
							return dividir(rama);
						}
					}
					return rama;
				} else if (temp.getSiguiente() == null) {
					Object obj = inserta(nodo, temp.getDerecha());
					if (obj instanceof NodoB) {
						rama.insertar((NodoB) obj);
						if (rama.getCuenta() == 5) {
							return dividir(rama);
						}
					}
					return rama;
				}
				temp = temp.getSiguiente();
			} while (temp != null);
		}
		return rama;
	}

	public String obtenerNodo(Rama r, int numero) {
		NodoB n = r.getPrimero();
		for (int i = 0; i < numero; i++) {
			if (n != null) {
				n = n.siguiente;
			}
		}
		if (n == null) {
			return "Vacio";
		}
		return String.valueOf(n.getDestino().getPais());
	}
	
	public int obtenerCodigo(Rama r, int numero) {
		NodoB n = r.getPrimero();
		for (int i = 0; i < numero; i++) {
			if (n != null) {
				n = n.siguiente;
			}
		}
		return n.getDestino().getId();
	}
	// Cuenta = 1; index = 1
	// Cuenta = 2; index = 3
	// Cuenta = 3; index = 5
	// Cuenta = 4; index = 7
	public String inOrden(Rama r) {
		String resultado = "";
		String nodo = "";
		NodoB n = r.getPrimero();
		if (r != null) {
			switch (r.cuenta) {
			case 1:
				nodo = "Nodo" + r.getPrimero().destino.pais + "[label = \"<F0>" + "|<F1>" + obtenerCodigo(r, 0) + " \\ " + obtenerNodo(r, 0) + "|<F2>"
						+ "\"; style = filled, fillcolor = lawngreen];\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F1> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,0)) + ";\n";
				break;
			case 2:
				nodo = "Nodo" + r.getPrimero().destino.pais + "[label = \"<F0>" + "|<F1>" + obtenerCodigo(r, 0) + " \\ " + obtenerNodo(r, 0) + "|<F2>"
						+ "|<F3>"+ obtenerCodigo(r, 1) + " \\ "  + obtenerNodo(r, 1) + "|<F4>" + "\"; style = filled, fillcolor = lawngreen];\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F1> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,0)) + ";\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F3> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,1)) + ";\n";
				break;
			case 3:
				nodo = "Nodo" + r.getPrimero().destino.pais + "[label = \"<F0>" + "|<F1>"+ obtenerCodigo(r, 0) + " \\ "  + obtenerNodo(r, 0) + "|<F2>"
						+ "|<F3>"+ obtenerCodigo(r, 1) + " \\ "  + obtenerNodo(r, 1) + "|<F4>" + "|<F5>" + obtenerCodigo(r, 2) + " \\ "  + obtenerNodo(r, 2) + "|<F6>" + "\"; style = filled, fillcolor = lawngreen];\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F1> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,0)) + ";\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F3> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,1)) + ";\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F5> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,2)) + ";\n";
				break;
			case 4:
				nodo = "Nodo" + r.getPrimero().destino.pais + "[label = \"<F0>" + "|<F1>" + obtenerCodigo(r, 0) + " \\ " + obtenerNodo(r, 0) + "|<F2>"
						+ "|<F3>" + obtenerCodigo(r, 1) + " \\ " + obtenerNodo(r, 1) + "|<F4>" + "|<F5>" + obtenerCodigo(r, 2) + " \\ " + obtenerNodo(r, 2) + "|<F6>" + "|<F7>"
						+ obtenerCodigo(r, 3) + " \\ " + obtenerNodo(r, 3) + "|<F8>" + "\"; style = filled, fillcolor = lawngreen];\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F1> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,0)) + ";\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F3> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,1)) + ";\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F5> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,2)) + ";\n";
				resultado += "Nodo" + r.getPrimero().destino.pais + ":<F7> -> F_"
						+ test.matrisita.buscarPosicion(obtenerCodigo(r,3)) + ";\n";
				break;
			}
		}
		resultado += nodo;
		int contador = 0;
		while (n != null) {
			if (n == r.getPrimero()) {
				if (n.izquierda != null) {
					resultado += "Nodo" + r.getPrimero().destino.pais + ":<F0> -> Nodo"
							+ n.izquierda.getPrimero().destino.pais + ":<F" + n.derecha.cuenta + ">;\n";
					resultado += inOrden(n.izquierda);
				}
				if (n.derecha != null) {
					resultado += "Nodo" + r.getPrimero().destino.pais + ":<F2> -> Nodo"
							+ n.derecha.getPrimero().destino.pais + ":<F" + n.derecha.cuenta + ">;\n";
					resultado += inOrden(n.derecha);
				}
			} else {
				if (n.derecha != null) {
					switch (contador) {
					case 1:
						resultado += "Nodo" + r.getPrimero().destino.pais + ":<F4> -> Nodo"
								+ n.derecha.getPrimero().destino.pais + ":<F" + n.derecha.cuenta + ">;\n";
						break;
					case 2:
						resultado += "Nodo" + r.getPrimero().destino.pais + ":<F6> -> Nodo"
								+ n.derecha.getPrimero().destino.pais + ":<F" + n.derecha.cuenta + ">;\n";
						break;
					case 3:
						resultado += "Nodo" + r.getPrimero().destino.pais + ":<F8> -> Nodo"
								+ n.derecha.getPrimero().destino.pais + ":<F" + n.derecha.cuenta + ">;\n";
						break;
					}
					resultado += inOrden(n.derecha);
				}
			}
			n = n.siguiente;
			contador++;
		}
		return resultado;
	}
}
