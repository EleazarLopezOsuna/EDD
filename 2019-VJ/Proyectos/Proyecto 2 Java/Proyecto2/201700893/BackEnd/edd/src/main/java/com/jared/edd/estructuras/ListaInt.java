package com.jared.edd.estructuras;

public class ListaInt {

	public class Nodo {

		public Nodo siguiente;
		public int codigo;

		public Nodo(int codigo) {
			this.codigo = codigo;
		}

		public Nodo getSiguiente() {
			return siguiente;
		}

		public void setSiguiente(Nodo siguiente) {
			this.siguiente = siguiente;
		}

		public int getCodigo() {
			return codigo;
		}

		public void setCodigo(int codigo) {
			this.codigo = codigo;
		}
	}

	public Nodo primero;

	public ListaInt() {
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
	public Boolean insertar(int codigo) {
		Nodo nuevo = new Nodo(codigo);
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

	public Boolean contiene(int codigo) {
		if (!empty()) {
			Nodo temp = primero;
			while (temp != null) {
				if (temp.getCodigo() == codigo)
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

	public int get(int index) {
		Nodo temp = primero;
		for (int i = 0; i < index; i++) {
			temp = temp.getSiguiente();
		}
		return temp.getCodigo();
	}

}
