package com.jared.edd.recursos;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import com.jared.edd.test;
import com.jared.edd.models.Destino;

@Path("/Destinos")
public class Destinos {

	@GET
	@Path("/Ingresar/{id}/{pais}")
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarDestino(@PathParam("id") int id,@PathParam("pais") String pais) {
		Destino destino = new Destino();
		destino.setId(id);
		destino.setPais(pais);
		if (test.destinito.insertar(destino)) {
			test.rutitas.insertar(destino);
			test.matrisita.agregarCabecera(destino.id, destino.pais);
			test.arbolito.insertar(destino);
			return "Insertado";
		}
		return "ERROR";
	}

	@GET
	@Path("/Buscar/{id}")
	@Produces(MediaType.APPLICATION_JSON)
	public String buscar(@PathParam("id") int id) {
		if (test.destinito.buscar(id)) {
			return "Encontrado";
		}
		return "No Encontrado";
	}

	@GET
	@Path("/Recorrer")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrer() {
		return test.destinito.recorrer();
	}

	@GET
	@Path("/Nombre/{pais}")
	@Produces(MediaType.APPLICATION_JSON)
	public String buscarN(@PathParam("pais") String pais) {
		return String.valueOf(test.destinito.buscarCodigo(pais));
	}

	@GET
	@Path("/Graficar/Arbol")
	@Produces(MediaType.APPLICATION_JSON)
	public String GraficarArbol() {
		String retorno = "digraph{node[shape=record]" + test.arbolito.inOrden(test.arbolito.raiz) + "}";
		File file = new File("C:\\Users\\USER\\Desktop\\Cali\\Arbol.dot");
		try {
			if (!file.exists()) {
				file.createNewFile();
			}
			String path = "C:\\Users\\USER\\Desktop\\Cali\\Arbol.png";
			PrintWriter pw = new PrintWriter(file);
			pw.println(retorno);
			pw.close();
			@SuppressWarnings("unused")
			Process p = Runtime.getRuntime()
					.exec("cmd /c dot -Tpng C:\\Users\\USER\\Desktop\\Cali\\Arbol.dot -o" + path);
			return "1";
		} catch (IOException e) {
			e.printStackTrace();
			return "0";
		}
	}

	@GET
	@Path("/Graficar/ArbolMatriz")
	@Produces(MediaType.APPLICATION_JSON)
	public String GraficarArbolMatriz() {
		String cabezaArbol = "subgraph Arbolito{\n";
		cabezaArbol += test.arbolito.inOrden(test.arbolito.raiz);
		cabezaArbol += "\n}\n";
		String cabezaMatriz = "subgraph Matricita{\n";
		cabezaMatriz = test.matrisita.mostrarCabeceras1() + test.matrisita.completar();
		cabezaMatriz += "\n}\n";
		String retorno = "";
		retorno += "digraph{\nnode[shape=record; width = 0.9; heiht = 0.8]\n";
		retorno += cabezaArbol + cabezaMatriz + "}";

		File file = new File("C:\\Users\\USER\\Desktop\\Cali\\graficaArbolMatriz.dot");
		try {
			if (!file.exists()) {
				file.createNewFile();
			}
			String path = "C:\\Users\\USER\\Desktop\\Cali\\ArbolMatriz.png";
			PrintWriter pw = new PrintWriter(file);
			pw.println(retorno);
			pw.close();
			@SuppressWarnings("unused")
			Process p = Runtime.getRuntime()
					.exec("cmd /c dot -Tpng C:\\Users\\USER\\Desktop\\Cali\\graficaArbolMatriz.dot -o" + path);
			return "1";
		} catch (IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
}
