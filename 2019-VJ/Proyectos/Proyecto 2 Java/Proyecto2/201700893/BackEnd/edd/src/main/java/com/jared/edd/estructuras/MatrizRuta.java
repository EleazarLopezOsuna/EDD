package com.jared.edd.estructuras;

import com.jared.edd.nodos.NodoC;
import com.jared.edd.nodos.NodoColumna;
import com.jared.edd.nodos.NodoFila;

import com.jared.edd.models.Ruta;

public class MatrizRuta {
	NodoFila primeroFila;
	NodoColumna primeroColumna;
	public Lista lista = new Lista();
	public ListaInt listaInt = new ListaInt();
	//public ArrayList<ArrayList<Integer>> ruta = new ArrayList<ArrayList<Integer>>();

	public String agregarCabecera(int numFila, String pais) {
		if (primeroFila == null) {
			primeroFila = new NodoFila(numFila, pais);
			primeroColumna = new NodoColumna(numFila);
			primeroFila.index = 0;
			primeroColumna.index = 0;
			return "Ingresado";
		} else {
			if (!encontrarCabecera(numFila)) {
				NodoFila tempF = primeroFila;
				NodoColumna tempC = primeroColumna;
				NodoFila nuevoF = new NodoFila(numFila, pais);
				NodoColumna nuevoC = new NodoColumna(numFila);
				if (tempF.numFila > numFila) {
					nuevoF.siguiente = tempF;
					primeroFila = nuevoF;
					nuevoC.siguiente = tempC;
					primeroColumna = nuevoC;
					indexar();
					return "Ingresado";
				}
				while (tempF.siguiente != null) {
					if (tempF.siguiente.numFila > numFila) {
						nuevoF.siguiente = tempF.siguiente;
						tempF.siguiente = nuevoF;
						nuevoC.siguiente = tempC.siguiente;
						tempC.siguiente = nuevoC;
						indexar();
						return "Ingresado";
					}
					tempF = tempF.siguiente;
					tempC = tempC.siguiente;
				}
				tempF.siguiente = nuevoF;
				tempC.siguiente = nuevoC;
				indexar();
				return "Ingresado";
			} else {
				return "Codigo Duplicado";
			}
		}
	}

	public boolean encontrarCabecera(int dato) {
		NodoFila temp = primeroFila;
		while (temp != null) {
			if (temp.numFila == dato) {
				return true;
			}
			temp = temp.siguiente;
		}
		return false;
	}

	public void agregarRuta(Ruta ruta) {
		NodoColumna tempColumna = primeroColumna;
		NodoFila tempFila = primeroFila;

		int columna = ruta.id_paisSalida;
		int fila = ruta.id_paisLlegada;

		NodoC nuevo = new NodoC(ruta);

		while (tempColumna != null) {
			if (tempColumna.numColumna == columna) {
				NodoC temp = tempColumna.abajo;
				if (temp == null) {
					tempColumna.abajo = nuevo;
				} else {
					if (temp.ruta.id_paisLlegada > ruta.id_paisLlegada) {
						nuevo.abajo = temp;
						tempColumna.abajo = nuevo;
						break;
					}
					int a = 0;
					while (temp.abajo != null) {
						if (temp.abajo.ruta.id_paisLlegada > ruta.id_paisLlegada) {
							nuevo.abajo = temp.abajo;
							temp.abajo = nuevo;
							a = 1;
							break;
						}
						temp = temp.abajo;
					}
					if (a == 0) {
						temp.abajo = nuevo;
					}

				}
				break;
			}
			tempColumna = tempColumna.siguiente;
		}
		while (tempFila != null) {
			if (tempFila.numFila == fila) {
				NodoC temp = tempFila.derecha;
				if (temp == null) {
					tempFila.derecha = nuevo;
				} else {
					int a = 0;
					if (temp.ruta.id_paisSalida > ruta.id_paisSalida) {
						nuevo.derecha = temp;
						tempFila.derecha = nuevo;
						break;
					}
					while (temp.derecha != null) {
						if (temp.derecha.ruta.id_paisSalida > ruta.id_paisSalida) {
							nuevo.derecha = temp.derecha;
							temp.derecha = nuevo;
							a = 1;
							break;
						}
						temp = temp.derecha;
					}
					if (a == 0) {
						temp.derecha = nuevo;
					}
				}
				break;
			}
			tempFila = tempFila.siguiente;
		}
	}

	public String mostrarCabeceras() {
		NodoFila temp = primeroFila;
		String apuntadorFila = "";
		String apuntadorColumna = "";
		String retorno = "";
		while (temp != null) {
			String headerFila = "\"F_" + temp.index + "\"[label = \"" + temp.pais + "\" ,pos=\"0,-" + temp.index
					+ "!\",style = filled, fillcolor = darksalmon]";
			String headerColumna = "\"C_" + temp.index + "\"[label = \"" + temp.numFila + "\" ,pos=\"" + temp.index
					+ ",0!\",style = filled, fillcolor = darksalmon]";
			apuntadorFila += "\"F_" + temp.index + "\"";
			apuntadorColumna += "\"C_" + temp.index + "\"";
			if (temp.siguiente != null) {
				apuntadorFila += "->";
				apuntadorColumna += "->";
			}
			retorno += headerFila + "\n";
			retorno += headerColumna + "\n";
			temp = temp.siguiente;
		}
		temp = primeroFila;
		retorno += "\"Matriz\"[label = \"Matriz\", pos = \"0,0!\",style = filled, fillcolor = crimson]\n\"Matriz\"->\"F_1\"\n\"Matriz\"->\"C_1\""
				+ "\n";
		retorno += apuntadorFila + "\n";
		retorno += apuntadorColumna + "\n";
		return retorno;
	}

	public String mostrarCabeceras1() {
		NodoFila temp = primeroFila;
		String apuntadorFila = "";
		String apuntadorColumna = "";
		String retorno = "";
		String rank = "{rank = same; Matriz; ";
		while (temp != null) {
			String headerFila = "\"F_" + temp.index + "\"[label = \"" + temp.pais
					+ "\" ,style = filled, fillcolor = darksalmon]";
			rank += "F_" + temp.index + "; ";
			String headerColumna = "\"C_" + temp.index + "\"[label = \"" + temp.numFila
					+ "\" ,style = filled, fillcolor = darksalmon]";
			apuntadorFila += "\"F_" + temp.index + "\"";
			apuntadorColumna += "\"C_" + temp.index + "\"";
			if (temp.siguiente != null) {
				apuntadorFila += "->";
				apuntadorColumna += "->";
			}
			retorno += headerFila + "\n";
			retorno += headerColumna + "\n";
			temp = temp.siguiente;
		}
		temp = primeroFila;
		retorno += "\"Matriz\"[label = \"Matriz\"style = filled, fillcolor = crimson]\n\"Matriz\"->\"F_1\"\n\"Matriz\"->\"C_1\""
				+ "\n";
		retorno += apuntadorFila + "\n";
		retorno += apuntadorColumna + "\n";
		rank += "};\n";
		retorno += rank;
		return retorno;
	}

	public String completar() {
		String retorno = "";
		for (int i = 1; i <= contarCabecera(); i++) {
			String rank = "{rank = same; C_" + i + "; ";
			for (int j = 0; j < contarCabecera(); j++) {
				rank += "N_" + i + "_" + j + "; ";
				retorno += "N_" + i + "_" + j + "[label = \"\"];\n";
				if (i != contarCabecera()) {
					retorno += "N_" + i + "_" + j + " -> N_" + (i + 1) + "_" + j + ";\n";
				}
				if (j == 0) {
					retorno += "N_" + i + "_" + 0 + " -> N_" + i + "_" + 1 + ";\n";
				} else if(j != contarCabecera() - 1){
					retorno += "N_" + i + "_" + j + " -> N_" + i + "_" + (j + 1) + ";\n";
				}
			}
			rank += "}\n";
			retorno += rank;
		}
		retorno += llenar();
		return retorno;
	}
	
	public String llenar() {
		NodoFila tempFila = primeroFila;
		String headerContenido = "";
		String retorno = "";
		while (tempFila != null) {
			NodoC tempContenido = tempFila.derecha;
			while (tempContenido != null) {
				String Costo = "Costo: " + tempContenido.ruta.getCosto();
				String Tiempo = "Tiempo: " + tempContenido.ruta.getTiempo();
				String piloto = "Piloto: " + tempContenido.ruta.getPiloto();
				String Contenido = Costo + "\\n" + Tiempo + "\\n" + piloto;
				int fila = buscarPosicion(tempContenido.ruta.getId_paisLlegada());
				int columna = buscarPosicion(tempContenido.ruta.getId_paisSalida());
				String Nodo = "\"N_" + fila + "_" + (columna - 1) + "\"[label = \""
						+ Contenido + "\", fontsize = \"10\",style = filled, fillcolor = cornflowerblue]";
				retorno += Nodo + "\n";
				tempContenido = tempContenido.derecha;
			}
			tempFila = tempFila.siguiente;
		}
		retorno += headerContenido + "\n";
		return retorno;
	}

	public String mostrarFila() {
		NodoFila tempFila = primeroFila;
		String headerContenido = "";
		String retorno = "";
		while (tempFila != null) {
			NodoC tempContenido = tempFila.derecha;
			NodoC tempC = tempContenido;
			while (tempContenido != null) {
				String Costo = "Costo: " + tempContenido.ruta.getCosto();
				String Tiempo = "Tiempo: " + tempContenido.ruta.getTiempo();
				String Contenido = Costo + "\\n" + Tiempo;
				int fila = buscarPosicion(tempContenido.ruta.getId_paisLlegada());
				int columna = buscarPosicion(tempContenido.ruta.getId_paisSalida());

				String Nodo = "\"N_" + tempContenido.ruta.getId_paisSalida() + "_"
						+ tempContenido.ruta.getId_paisLlegada() + "\"[label = \"" + Contenido + "\" ,pos=\"" + columna
						+ ",-" + fila + "!\", fontsize = \"10\",style = filled, fillcolor = cornflowerblue]";
				retorno += Nodo + "\n";

				if (tempContenido.derecha != null) {
					headerContenido += "\"N_" + tempContenido.ruta.getId_paisSalida() + "_"
							+ tempContenido.ruta.getId_paisLlegada() + "\"->";
				} else {
					headerContenido += "\"N_" + tempContenido.ruta.getId_paisSalida() + "_"
							+ tempContenido.ruta.getId_paisLlegada() + "\"\n";
				}
				tempContenido = tempContenido.derecha;
			}
			if (tempC != null) {
				int f = buscarPosicion(tempC.ruta.getId_paisLlegada());
				headerContenido += "\"F_" + f + "\"->" + "\"N_" + tempC.ruta.getId_paisSalida() + "_"
						+ tempC.ruta.getId_paisLlegada() + "\"\n";
			}
			tempFila = tempFila.siguiente;
		}
		retorno += headerContenido + "\n";
		return retorno;
	}

	public String mostrarColumna() {
		NodoColumna tempColumna = primeroColumna;
		String headerContenido = "";
		String retorno = "";
		while (tempColumna != null) {
			NodoC tempContenido = tempColumna.abajo;
			NodoC tempC = tempContenido;
			while (tempContenido != null) {
				if (tempContenido.abajo != null) {
					headerContenido += "\"N_" + tempContenido.ruta.getId_paisSalida() + "_"
							+ tempContenido.ruta.getId_paisLlegada() + "\"->";
				} else {
					headerContenido += "\"N_" + tempContenido.ruta.getId_paisSalida() + "_"
							+ tempContenido.ruta.getId_paisLlegada() + "\"\n";
				}
				tempContenido = tempContenido.abajo;
			}
			if (tempC != null) {
				int f = buscarPosicion(tempC.ruta.getId_paisSalida());
				headerContenido += "\"C_" + f + "\"->" + "\"N_" + tempC.ruta.getId_paisSalida() + "_"
						+ tempC.ruta.getId_paisLlegada() + "\"\n";
			}
			tempColumna = tempColumna.siguiente;
		}
		retorno += headerContenido + "\n";
		return retorno;
	}

	public int contarCabecera() {
		int contador = 0;
		NodoFila temp = primeroFila;
		while (temp != null) {
			contador++;
			temp = temp.siguiente;
		}
		return contador;
	}

	void indexar() {
		int index = 1;
		NodoFila tempF = primeroFila;
		NodoColumna tempC = primeroColumna;
		while (tempF != null) {
			tempF.index = index;
			tempC.index = index;
			index++;
			tempF = tempF.siguiente;
			tempC = tempC.siguiente;
		}
	}

	int buscarPosicion(int codigo) {
		NodoFila temp = primeroFila;
		while (temp != null) {
			if (temp.numFila == codigo) {
				return temp.index;
			}
			temp = temp.siguiente;
		}
		return -1;
	}

	void mostrarLista() {
		NodoFila tempCol = primeroFila;
		NodoC tempCon = tempCol.derecha;
		System.out.println(tempCon.ruta.costo);
	}

	public Ruta inversorRuta(Ruta ruta) {
		Ruta nueva = null;
		int salida = ruta.id_paisLlegada;
		int llegada = ruta.id_paisSalida;
		int costo = ruta.costo;
		int tiempo = ruta.tiempo;
		String piloto = ruta.piloto;
		nueva = new Ruta(salida, llegada, costo, tiempo, piloto);
		return nueva;
	}

	public int rutaCorta(int salida, int llegada) {
		NodoColumna tempF = primeroColumna; // Creamos el apuntador de la Fila
		int buscando = salida;
		while (tempF != null) {
			if (tempF.numColumna == salida) {
				
				
				ListaInt temp = new ListaInt();
				ListaInt temp1 = new ListaInt();
				ListaInt temp2 = new ListaInt();
				ListaInt temp3 = new ListaInt();
				ListaInt temp4 = new ListaInt();
				if (!temp.contiene(buscando)) {
					temp.insertar(buscando);
					temp2.insertar(buscando);
					temp3.insertar(buscando);
					temp4.insertar(buscando);
				}
				NodoC tempC = tempF.abajo;
				while (tempC != null) {
					int cLlegada = tempC.ruta.id_paisLlegada;
					if (cLlegada == llegada) {
						temp.insertar(cLlegada);
						lista.insertar(temp);
						temp = new ListaInt();
						temp.insertar(buscando);
					} else {
						NodoColumna tempF2 = retornarColumna(tempC.ruta.id_paisLlegada);
						NodoC tempC2 = tempF2.abajo;
						cLlegada = tempC.ruta.id_paisLlegada;
						if (cLlegada == llegada) {
							if (!temp1.contiene(cLlegada) && !temp1.contiene(tempC2.ruta.id_paisSalida)) {
								temp1.insertar(tempC.ruta.id_paisSalida);
								temp1.insertar(cLlegada);
								if (!lista.contiene(temp1)) {
									lista.insertar(temp1);
									temp1 = new ListaInt();
									temp1.insertar(buscando);
								}
							}
						} else {
							while (tempC2 != null) {
								tempF2 = retornarColumna(tempC2.ruta.id_paisLlegada);
								NodoC tempC3 = tempF2.abajo;
								cLlegada = tempC2.ruta.id_paisLlegada;
								if (cLlegada == llegada) {
									if (!temp2.contiene(cLlegada) && !temp2.contiene(tempC2.ruta.id_paisSalida)) {
										temp2.insertar(tempC2.ruta.id_paisSalida);
										temp2.insertar(cLlegada);
										if (!lista.contiene(temp2)) {
											lista.insertar(temp2);
											temp2 = new ListaInt();
											temp2.insertar(buscando);
										}
									}
								} else {
									while (tempC3 != null) {
										tempF2 = retornarColumna(tempC3.ruta.id_paisLlegada);
										NodoC tempC4 = tempF2.abajo;
										cLlegada = tempC3.ruta.id_paisLlegada;
										if (cLlegada == llegada) {
											if (!temp3.contiene(cLlegada) && !temp3.contiene(tempC2.ruta.id_paisSalida)
													&& !temp3.contiene(tempC3.ruta.id_paisSalida)) {
												temp3.insertar(tempC2.ruta.id_paisSalida);
												temp3.insertar(tempC3.ruta.id_paisSalida);
												temp3.insertar(cLlegada);
												if (!lista.contiene(temp3)) {
													lista.insertar(temp3);
													temp3 = new ListaInt();
													temp3.insertar(buscando);
												}
											}
										} else {
											while (tempC4 != null) {
												tempF2 = retornarColumna(tempC3.ruta.id_paisLlegada);
												cLlegada = tempC4.ruta.id_paisLlegada;
												if (cLlegada == llegada) {
													if (!temp4.contiene(cLlegada)
															&& !temp4.contiene(tempC2.ruta.id_paisSalida)
															&& !temp4.contiene(tempC3.ruta.id_paisSalida)
															&& !temp4.contiene(tempC4.ruta.id_paisSalida)) {
														temp4.insertar(tempC2.ruta.id_paisSalida);
														temp4.insertar(tempC3.ruta.id_paisSalida);
														temp4.insertar(tempC4.ruta.id_paisSalida);
														temp4.insertar(cLlegada);
														if (!lista.contiene(temp4)) {
															lista.insertar(temp4);
															temp4 = new ListaInt();
															temp4.insertar(buscando);
														}
													}
												}
												tempC4 = tempC4.abajo;
											}
										}
										tempC3 = tempC3.abajo;
									}
								}
								tempC2 = tempC2.abajo;
							}
						}
					}
					tempC = tempC.abajo;
				}
				
				
				
				
				/*ArrayList<Integer> temp = new ArrayList<Integer>();
				ArrayList<Integer> temp1 = new ArrayList<Integer>();
				ArrayList<Integer> temp2 = new ArrayList<Integer>();
				ArrayList<Integer> temp3 = new ArrayList<Integer>();
				ArrayList<Integer> temp4 = new ArrayList<Integer>();
				if (!temp.contains(buscando)) {
					temp.add(buscando);
					temp2.add(buscando);
					temp3.add(buscando);
					temp4.add(buscando);
				}
				NodoC tempC = tempF.abajo;
				while (tempC != null) {
					int cLlegada = tempC.ruta.id_paisLlegada;
					if (cLlegada == llegada) {
						temp.add(cLlegada);
						ruta.add(temp);
						temp = new ArrayList<Integer>();
						temp.add(buscando);
					} else {
						NodoColumna tempF2 = retornarColumna(tempC.ruta.id_paisLlegada);
						NodoC tempC2 = tempF2.abajo;
						cLlegada = tempC.ruta.id_paisLlegada;
						if (cLlegada == llegada) {
							if (!temp1.contains(cLlegada) && !temp1.contains(tempC2.ruta.id_paisSalida)) {
								temp1.add(tempC.ruta.id_paisSalida);
								temp1.add(cLlegada);
								if (!ruta.contains(temp1)) {
									ruta.add(temp1);
									temp1 = new ArrayList<Integer>();
									temp1.add(buscando);
								}
							}
						} else {
							while (tempC2 != null) {
								tempF2 = retornarColumna(tempC2.ruta.id_paisLlegada);
								NodoC tempC3 = tempF2.abajo;
								cLlegada = tempC2.ruta.id_paisLlegada;
								if (cLlegada == llegada) {
									if (!temp2.contains(cLlegada) && !temp2.contains(tempC2.ruta.id_paisSalida)) {
										temp2.add(tempC2.ruta.id_paisSalida);
										temp2.add(cLlegada);
										if (!ruta.contains(temp2)) {
											ruta.add(temp2);
											temp2 = new ArrayList<Integer>();
											temp2.add(buscando);
										}
									}
								} else {
									while (tempC3 != null) {
										tempF2 = retornarColumna(tempC3.ruta.id_paisLlegada);
										NodoC tempC4 = tempF2.abajo;
										cLlegada = tempC3.ruta.id_paisLlegada;
										if (cLlegada == llegada) {
											if (!temp3.contains(cLlegada) && !temp3.contains(tempC2.ruta.id_paisSalida)
													&& !temp3.contains(tempC3.ruta.id_paisSalida)) {
												temp3.add(tempC2.ruta.id_paisSalida);
												temp3.add(tempC3.ruta.id_paisSalida);
												temp3.add(cLlegada);
												if (!ruta.contains(temp3)) {
													ruta.add(temp3);
													temp3 = new ArrayList<Integer>();
													temp3.add(buscando);
												}
											}
										} else {
											while (tempC4 != null) {
												tempF2 = retornarColumna(tempC3.ruta.id_paisLlegada);
												cLlegada = tempC4.ruta.id_paisLlegada;
												if (cLlegada == llegada) {
													if (!temp4.contains(cLlegada)
															&& !temp4.contains(tempC2.ruta.id_paisSalida)
															&& !temp4.contains(tempC3.ruta.id_paisSalida)
															&& !temp4.contains(tempC4.ruta.id_paisSalida)) {
														temp4.add(tempC2.ruta.id_paisSalida);
														temp4.add(tempC3.ruta.id_paisSalida);
														temp4.add(tempC4.ruta.id_paisSalida);
														temp4.add(cLlegada);
														if (!ruta.contains(temp4)) {
															ruta.add(temp4);
															temp4 = new ArrayList<Integer>();
															temp4.add(buscando);
														}
													}
												}
												tempC4 = tempC4.abajo;
											}
										}
										tempC3 = tempC3.abajo;
									}
								}
								tempC2 = tempC2.abajo;
							}
						}
					}
					tempC = tempC.abajo;
				}*/
			}
			tempF = tempF.siguiente;
		}
		return 0;
	}

	NodoColumna retornarColumna(int codigo) {
		NodoColumna temp = primeroColumna;
		while (temp != null) {
			if (temp.numColumna == codigo) {
				return temp;
			}
			temp = temp.siguiente;
		}
		return temp;
	}

	public int buscarTC(int salida, int llegada, int opcion) {
		NodoColumna temp = primeroColumna;
		while (temp != null) {
			if (temp.numColumna == salida) {
				NodoC tempC = temp.abajo;
				while (tempC != null) {
					if (tempC.ruta.id_paisSalida == salida && tempC.ruta.id_paisLlegada == llegada) {
						if (opcion == 0) {
							return tempC.ruta.tiempo;
						} else {
							return tempC.ruta.costo;
						}
					}
					tempC = tempC.abajo;
				}
			}
			temp = temp.siguiente;
		}
		return 0;
	}

	public String editar(int codigoSalida, int  codigoLlegada, int costo, int tiempo) {
		NodoFila tempFila = primeroFila;
		while (tempFila != null) {
			NodoC tempContenido = tempFila.derecha;
			while (tempContenido != null) {
				if(tempContenido.ruta.id_paisSalida == codigoSalida && tempContenido.ruta.id_paisLlegada == codigoLlegada) {
					tempContenido.ruta.setCosto(costo);
					tempContenido.ruta.setTiempo(tiempo);
					editar2(codigoLlegada, codigoSalida, costo, tiempo);
					break;
				}
				tempContenido = tempContenido.derecha;
			}
			tempFila = tempFila.siguiente;
		}
		return "";
	}
	
	public String editar2(int codigoSalida, int  codigoLlegada, int costo, int tiempo) {
		NodoFila tempFila = primeroFila;
		while (tempFila != null) {
			NodoC tempContenido = tempFila.derecha;
			while (tempContenido != null) {
				if(tempContenido.ruta.id_paisSalida == codigoSalida && tempContenido.ruta.id_paisLlegada == codigoLlegada) {
					tempContenido.ruta.setCosto(costo);
					tempContenido.ruta.setTiempo(tiempo);
					break;
				}
				tempContenido = tempContenido.derecha;
			}
			tempFila = tempFila.siguiente;
		}
		return "";
	}

	public String eliminar(int codigoSalida, int  codigoLlegada) {
		NodoColumna tempColumna = primeroColumna;
		NodoFila tempFila = primeroFila;

		int columna = codigoSalida;
		int fila = codigoLlegada;

		while (tempColumna != null) {
			if (tempColumna.numColumna == columna) {
				NodoC temp = tempColumna.abajo;
				NodoC tempC = temp;
				while(temp != null) {
					if(temp.ruta.id_paisSalida == codigoSalida && temp.ruta.id_paisLlegada == codigoLlegada) {
						tempC.abajo = temp.abajo;
						temp = null;
						System.out.println("ELIMINADO");
						break;
					}
					tempC = temp;
					temp = temp.abajo;
				}
				break;
			}
			tempColumna = tempColumna.siguiente;
		}
		while (tempFila != null) {
			if (tempFila.numFila == fila) {
				NodoC temp = tempFila.derecha;
				NodoC tempC = temp;
				while(temp != null) {
					if(temp.ruta.id_paisSalida == codigoSalida && temp.ruta.id_paisLlegada == codigoLlegada) {
						tempC.derecha = temp.derecha;
						temp = null;
						System.out.println("ELIMINADO");
						break;
					}
					tempC = temp;
					temp = temp.derecha;
				}
				break;
			}
			tempFila = tempFila.siguiente;
		}
		return "";
	}
}
