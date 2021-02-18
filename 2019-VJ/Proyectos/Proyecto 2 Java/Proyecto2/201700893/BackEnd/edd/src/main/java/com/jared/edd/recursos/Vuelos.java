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
import com.jared.edd.models.Reservacion;

@Path("/Vuelos")
public class Vuelos {
	
	@GET
	@Path("/InsertarT/{numero}/{cliente}/{costo}/{tiempo}/{plan}")
	@Produces(MediaType.APPLICATION_JSON)
	public String insertarTabla(@PathParam("numero") long num, @PathParam("cliente") String cli,
			@PathParam("costo") double cos, @PathParam("tiempo") float tie, @PathParam("plan") String pla) {
		Reservacion reservacion = new Reservacion(num,cli,cos,tie,pla);
		test.tablita.insertar(reservacion);
		return "";
	}
	
	@GET
	@Path("/Eliminar/{nombre}")
	@Produces(MediaType.APPLICATION_JSON)
	public void eliminar(@PathParam("nombre") String nombre) {
		test.tablita.eliminar(nombre);
	}
		
	@GET
	@Path("/Recorrer")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerRutas() {
		File file = new File("C:\\Users\\USER\\Desktop\\Cali\\graficaTablaHash.dot");
		try {
			if(!file.exists()) {
				file.createNewFile();
			}
			String path = "C:\\Users\\USER\\Desktop\\Cali\\TablaHash.png";
			PrintWriter pw = new PrintWriter(file);
			String contenido = test.tablita.recorrer();
			pw.println(contenido);
			pw.close();
			@SuppressWarnings("unused")
			Process p = Runtime.getRuntime().exec("cmd /c dot -Tpng C:\\Users\\USER\\Desktop\\Cali\\graficaTablaHash.dot -o" + path);
			return contenido;
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
	
	
}