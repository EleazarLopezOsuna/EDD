package com.jared.edd.recursos;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import com.jared.edd.test;
import com.jared.edd.models.Usuario;

@Path("/Login")
public class Login {

	@POST
	@Path("/Ingresar")
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public String login(Usuario usuario) {
		String retorno = "false";
		if(usuario.id == 201700893 && usuario.nombre.equals("admin")) {
			retorno = "true";
		}else {
			Usuario user = test.arbolito.buscarUsuario(usuario.id);
			if(user != null) {
				if(user.nombre.equals(usuario.nombre))
					retorno = "true";
				else
					retorno = "false";
			}else {
				retorno = "usuario no existe";
			}
		}
		return retorno;
	}
	
	@GET
	@Path("/IngresarA/{id}/{nombre}")
	@Consumes(MediaType.APPLICATION_JSON)
	public String loginA(@PathParam("id")int identificador, @PathParam("nombre") String nombre) {
		String retorno = "false";
		if(identificador == 201700893 && nombre.equals("admin")) {
			retorno = "true";
		}else {
			Usuario user = test.arbolito.buscarUsuario(identificador);
			if(user != null) {
				if(user.nombre.equals(nombre))
					retorno = "true";
				else
					retorno = "false";
			}else {
				retorno = "usuario no existe";
			}
		}
		return retorno;
	}
}
