package com.jared.edd.estructuras;

public class Lista {

	public class Nodo {

		public Nodo siguiente;
		public ListaInt lista;

		public Nodo(ListaInt lista) {
			this.lista = lista;
		}

		public Nodo getSiguiente() {
			return siguiente;
		}

		public void setSiguiente(Nodo siguiente) {
			this.siguiente = siguiente;
		}

		public ListaInt getLista() {
			return lista;
		}

		public void setLista(ListaInt lista) {
			this.lista = lista;
		}
	}

	public Nodo primero;

	public Lista() {
		primero = null;
	}

	// Empty
	public Boolean empty() {
		if (primero == null) {
			return true;
		}
		return false;
	}

	// Insertar
	public Boolean insertar(ListaInt lista) {
		Nodo nuevo = new Nodo(lista);
		if (!empty()) {
			Nodo temp = primero;
			while (temp != null) {
				if (temp.siguiente == null) {
					temp.siguiente = nuevo;
					break;
				}
				temp = temp.siguiente;
			}
			return true;
		} else {
			primero = nuevo;
			return true;
		}
	}

	public Boolean contiene(ListaInt l) {
		if (!empty()) {
			Nodo temp = primero;
			while (temp != null) {
				if (temp.getLista() == l)
					return true;
				temp = temp.getSiguiente();
			}
		}
		return false;
	}

	public int size() {
		int contador = 0;
		Nodo temp = primero;
		while (temp != null) {
			contador++;
			temp = temp.getSiguiente();
		}
		return contador;
	}

	public ListaInt get(int index) {
		Nodo temp = primero;
		for (int i = 0; i < index; i++) {
			temp = temp.getSiguiente();
		}
		return temp.getLista();
	}
}
