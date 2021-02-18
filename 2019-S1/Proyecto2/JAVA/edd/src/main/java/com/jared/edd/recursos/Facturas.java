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
import com.jared.edd.models.Factura;
import com.jared.edd.otros.InfoGestion;

@Path("/Facturas")
public class Facturas {
	@POST
	@Path("/Ingresar")
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarRuta(Factura factura) {
		int key = factura.key;
		String fecha = factura.fecha;
		String hora = factura.hora;
		Double costo = factura.costo;
		String nombre = factura.nombre;
		int codigo = factura.codigo;
		String descripcion = factura.descripcion;
		test.arbolitoB.insert(new InfoGestion(key,fecha,hora,costo,nombre,codigo,descripcion), "Dummy " + test.arbolitoB.contador);
		test.arbolitoB.contador++;
		return "Error";
	}
	
	@GET
	@Path("/Recorrer")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerRutas() {
		File file = new File("graficaArbolFactura.dot");
		try {
			if(!file.exists()) {
				file.createNewFile();
			}
			PrintWriter pw = new PrintWriter(file);
			String contenido = test.arbolitoB.toDot();
			pw.println(contenido);
			pw.close();
			String path = "C:\\Users\\USER\\Desktop\\FrontEndProyecto1\\archivos\\assets\\images\\big\\ArbolFactura.png";
			@SuppressWarnings("unused")
			Process p = Runtime.getRuntime().exec("cmd /c dot -Tpng graficaArbolFactura.dot -o" + path);
			return "1";
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
}
