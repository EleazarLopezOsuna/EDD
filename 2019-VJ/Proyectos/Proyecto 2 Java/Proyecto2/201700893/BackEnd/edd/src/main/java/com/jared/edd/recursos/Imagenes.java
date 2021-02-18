package com.jared.edd.recursos;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.util.Base64;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.core.MediaType;

@Path("/Imagenes")
public class Imagenes {
	@GET
	@Path("/Grafo")
	@Consumes(MediaType.APPLICATION_JSON)
	public String grafo() {
		String base64Image = "";
		String path = "C:\\Users\\USER\\Desktop\\Cali\\GrafoRuta.png";
		File file = new File(path);
		try {
			FileInputStream imageInFile = new FileInputStream(file);
			byte imageData[] = new byte[(int) file.length()];
			imageInFile.read(imageData);
			base64Image = Base64.getEncoder().encodeToString(imageData);
			imageInFile.close();
		}catch(FileNotFoundException e) {
			
		}catch(IOException ioe) {
			
		}
		return base64Image;
	}
	
	@GET
	@Path("/Tabla")
	@Consumes(MediaType.APPLICATION_JSON)
	public String tabla() {
		String base64Image = "";
		String path = "C:\\Users\\USER\\Desktop\\Cali\\TablaHash.png";
		File file = new File(path);
		try {
			FileInputStream imageInFile = new FileInputStream(file);
			byte imageData[] = new byte[(int) file.length()];
			imageInFile.read(imageData);
			base64Image = Base64.getEncoder().encodeToString(imageData);
			imageInFile.close();
		}catch(FileNotFoundException e) {
			
		}catch(IOException ioe) {
			
		}
		return base64Image;
	}
}
