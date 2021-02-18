package com.jared.edd.recursos;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import com.jared.edd.test;
import com.jared.edd.models.Reservacion;

@Path("/Vuelos")
public class Vuelos {

	@POST
	@Path("/Ingresar")
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarDestino(Reservacion reservacion) {
		Reservacion[] reser = new Reservacion[1];
		Reservacion r = new Reservacion(reservacion.costo, reservacion.tiempo, reservacion.nombre, reservacion.codigos);
		reser[0] = r;
		test.tablita.funcionHash(reser);
		return "Insertado";
	}
	
	@GET
	@Path("/Recorrer")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerRutas() {
		File file = new File("graficaTablaHash.dot");
		try {
			if(!file.exists()) {
				file.createNewFile();
			}
			String path = "C:\\Users\\USER\\Desktop\\FrontEndProyecto1\\archivos\\assets\\images\\big\\TablaHash.png";
			PrintWriter pw = new PrintWriter(file);
			String cabecera = "digraph structs { \n graph [pad=\"0.212,0.055\" bgcolor=azure3] \n rankdir = LR \n node[shape= record] \n";
			String pie = "}";
			String contenido = cabecera + test.tablita.recorrer() + pie;
			pw.println(contenido);
			pw.close();
			@SuppressWarnings("unused")
			Process p = Runtime.getRuntime().exec("cmd /c dot -Tpng graficaTablaHash.dot -o" + path);
			return "1";
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
}