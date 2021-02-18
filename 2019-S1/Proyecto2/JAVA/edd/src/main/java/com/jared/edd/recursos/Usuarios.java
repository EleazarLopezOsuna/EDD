package com.jared.edd.recursos;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import com.jared.edd.test;
import com.jared.edd.models.Usuario;

@Path("/Usuarios")
public class Usuarios {
	
	
	@POST
	@Path("/Ingresar")
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarUsuario(Usuario user) {
		String retorno = "Error: Usuario Duplicado";
		test.arbolito.insertar(user);
			retorno = "Ingresado";
			return retorno;
	}
	
	@GET
	@Path("/Buscar/{id}")
	@Produces(MediaType.APPLICATION_JSON)
	public String buscarUsuario(@PathParam("id")int id) {
		return test.arbolito.buscarUsuario(id).nombre;
	}
	
	@GET
	@Path("/Recorrer")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerUsuario() {
		File file = new File("graficaArbolUsuario.dot");
		try {
			if(!file.exists()) {
				file.createNewFile();
			}
			PrintWriter pw = new PrintWriter(file);
			String cabecera = "digraph structs { \n graph [pad=\"0.212,0.055\" bgcolor=azure3] \n node [shape=record,style = filled, fillcolor = darksalmon];\n";
			String pie = "}";
			String contenido = cabecera + test.arbolito.preOrden(test.arbolito.obtenerRaiz()) + pie;
			pw.println(contenido);
			pw.close();
			String path = "C:\\Users\\USER\\Desktop\\FrontEndProyecto1\\archivos\\assets\\images\\big\\ArbolUsuario.png";
			@SuppressWarnings("unused")
			Process p = Runtime.getRuntime().exec("cmd /c dot -Tpng graficaArbolUsuario.dot -o" + path);
			return "1";
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
}