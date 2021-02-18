package com.jared.edd.recursos;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.PathParam;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;

import com.jared.edd.test;
import com.jared.edd.models.Destino;

@Path("/Destinos")
public class Destinos {

	@POST
	@Path("/Ingresar")
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarDestino(Destino destino) {
		if(test.destinito.insertar(destino)) {
			test.rutitas.insertar(destino);
			test.matrisita.agregarCabecera(destino.id, destino.pais);
			return "Insertado";
		}
		return "ERROR";
	}
	
	@GET
	@Path("/Buscar/{id}")
	@Produces(MediaType.APPLICATION_JSON)
	public String buscar(@PathParam("id")int id) {
		if(test.destinito.buscar(id)) {
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
}
