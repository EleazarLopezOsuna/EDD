package com.jared.edd.recursos;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

import javax.ws.rs.Consumes;
import javax.ws.rs.GET;
import javax.ws.rs.POST;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.PathParam;

import com.jared.edd.test;
import com.jared.edd.models.Ruta;
import com.jared.edd.models.Destino;

@Path("/Rutas")
public class Rutas {
	@POST
	@Path("/Ingresar")
	@Consumes(MediaType.APPLICATION_JSON)
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarRuta(Ruta ruta) {
		String retorno = test.rutitas.insertarRuta(ruta);
		if(retorno.equals("Ingresado")) {
			test.matrisita.agregarRuta(ruta);
			test.matrisita.agregarRuta(test.matrisita.inversorRuta(ruta));
		}
		return retorno;
	}
	
	@GET
	@Path("/IngresarNombre/{idS}/{idL}/{Co}/{Ti}")
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarRutaNombre(@PathParam("idS") String pS,@PathParam("idL") String pL,@PathParam("Co") int costo,@PathParam("Ti") int tiempo) {
		int paisS = test.destinito.buscarCodigo(pS);
		int paisL = test.destinito.buscarCodigo(pL);
		Ruta ruta = new Ruta(paisS,paisL,costo,tiempo);
		String retorno = test.rutitas.insertarRuta(ruta);
		if(retorno.equals("Ingresado")) {
			test.matrisita.agregarRuta(ruta);
			test.matrisita.agregarRuta(test.matrisita.inversorRuta(ruta));
		}
		return retorno;
	}
	
	@GET
	@Path("/BuscarRutaCorta/{salida}/{llegada}/{tipo}")
	@Produces(MediaType.APPLICATION_JSON)
	public String buscarRuta(@PathParam("salida") int salida, @PathParam("llegada") int llegada, @PathParam("tipo") int tipo) {
		String retorno = "";
		ArrayList<Integer> ingresados = new ArrayList<Integer>();
        ingresados.add(salida);
        test.matrisita.ruta = new ArrayList<ArrayList<Integer>>();
        test.matrisita.rutaCorta(salida, llegada);
        int index = 0;
        int peso = 999999999;
        for (int i = 0; i < test.matrisita.ruta.size(); i++) {
            int pesoTemp = 0;
            for (int j = 0; j < test.matrisita.ruta.get(i).size() - 1; j++) {
                pesoTemp += test.matrisita.buscarTC(test.matrisita.ruta.get(i).get(j), test.matrisita.ruta.get(i).get(j + 1), tipo);
            }
            if (pesoTemp < peso) {
                peso = pesoTemp;
                index = i;
            }
        }
        for (int i = 0; i < test.matrisita.ruta.get(index).size(); i++) {
        	if(i == test.matrisita.ruta.get(index).size() - 1){
        		int id = test.matrisita.ruta.get(index).get(i);
        		Destino destino = test.destinito.buscarD(id);
        		retorno += destino.pais + "\n";
        	}else{
        		int id = test.matrisita.ruta.get(index).get(i);
        		Destino destino = test.destinito.buscarD(id);
        		retorno += destino.pais + ",";
            }
            
        }
		return retorno;
	}
	
	@GET
	@Path("/ObtenerRutas/{grafica}/{salida}/{llegada}/{tipo}/")
	@Produces(MediaType.APPLICATION_JSON)
	public String graficarRutaCorta(@PathParam("salida") int salida, @PathParam("llegada") int llegada, 
			@PathParam("tipo") int tipo, @PathParam("grafica") int grafica) {
		String retorno = "";
		ArrayList<Integer> ingresados = new ArrayList<Integer>();
        ingresados.add(salida);
        test.matrisita.ruta = new ArrayList<ArrayList<Integer>>();
        test.matrisita.rutaCorta(salida, llegada);
        int index = 0;
        int peso = 999999999;
        String codigoPaises = "";
        String tipoGraph = "";
        String tipoImg = "";
        if(grafica == 0) {//Grafica y devuelve la ruta corta
        	tipoGraph = "graficaRutaCorta.dot";
        	tipoImg = "RutaCorta.png";
        	for (int i = 0; i < test.matrisita.ruta.size(); i++) {
                int pesoTemp = 0;
                for (int j = 0; j < test.matrisita.ruta.get(i).size() - 1; j++) {
                    pesoTemp += test.matrisita.buscarTC(test.matrisita.ruta.get(i).get(j), test.matrisita.ruta.get(i).get(j + 1), tipo);
                }
                if (pesoTemp < peso) {
                    peso = pesoTemp;
                    index = i;
                }
            }
            for (int i = 0; i < test.matrisita.ruta.get(index).size(); i++) {
            	if(i == test.matrisita.ruta.get(index).size() - 1){
            		int id = test.matrisita.ruta.get(index).get(i);
            		Destino destino = test.destinito.buscarD(id);
            		retorno += "\"" + destino.pais + "\"" + "\n";
            		codigoPaises += destino.pais;
            	}else{
            		int id = test.matrisita.ruta.get(index).get(i);
            		Destino destino = test.destinito.buscarD(id);
            		retorno += "\"" + destino.pais + "\"" + "->";
            		codigoPaises += destino.pais + ",";
                }
                
            }
            File file1 = new File(tipoGraph);
            String cabecera1 = "digraph structs { \n edge[arrowhead = none] \n graph [pad=\"0.212,0.055\" bgcolor=azure3] \n node[style = filled, fillcolor = darksalmon]; \n";
            String pie1 = "}";
            String contenido = cabecera1 + retorno + pie1;
            try {
    			if(!file1.exists()) {
    				file1.createNewFile();
    			}
    			PrintWriter pw1 = new PrintWriter(file1);
    			pw1.println(contenido);
    			pw1.close();
    			String path = "C:\\Users\\USER\\Desktop\\FrontEndProyecto1\\archivos\\assets\\images\\big\\";
    			@SuppressWarnings("unused")
    			Process p1 = Runtime.getRuntime().exec("cmd /c dot -Tpng " + tipoGraph + " -o " + path + tipoImg);
            }catch(IOException e) {
    			e.printStackTrace();
    			return "0";
    		}
        }else if(grafica == 1){//Grafica y devuelve todas las rutas
        	tipoGraph = "graficaRutaCompleta.dot";
        	tipoImg = "RutaCompleta.png";
        	for (int j = 0; j < test.matrisita.ruta.size(); j++) {
            	for(int i = 0; i < test.matrisita.ruta.get(j).size(); i++) {
            		if(i == test.matrisita.ruta.get(j).size() - 1){
                		int id = test.matrisita.ruta.get(j).get(i);
                		Destino destino = test.destinito.buscarD(id);
                		if(!retorno.contains(destino.pais)) {
                			retorno += "\"" + destino.pais + "\"" + "\n";
                		}
                		codigoPaises += destino.pais;
                	}else{
                		int id = test.matrisita.ruta.get(j).get(i);
                		Destino destino = test.destinito.buscarD(id);
                		if(!retorno.contains(destino.pais)) {
                			retorno += "\"" + destino.pais + "\"" + "->";
                		}
                		codigoPaises += destino.pais + ",";
                    }
            	}
                if(j != test.matrisita.ruta.get(j).size() - 1) {
                	codigoPaises += ";";
                }
            }
        	File file1 = new File(tipoGraph);
            String cabecera1 = "digraph structs { \n edge[arrowhead = none] \n graph [pad=\"0.212,0.055\" bgcolor=azure3] \n node[style = filled, fillcolor = darksalmon]; \n";
            String pie1 = "}";
            String contenido = cabecera1 + retorno + pie1;
            try {
    			if(!file1.exists()) {
    				file1.createNewFile();
    			}
    			PrintWriter pw1 = new PrintWriter(file1);
    			pw1.println(contenido);
    			pw1.close();
    			String path = "C:\\Users\\USER\\Desktop\\FrontEndProyecto1\\archivos\\assets\\images\\big\\";
    			@SuppressWarnings("unused")
    			Process p1 = Runtime.getRuntime().exec("cmd /c dot -Tpng " + tipoGraph + " -o " + path + tipoImg);
            }catch(IOException e) {
    			e.printStackTrace();
    			return "0";
    		}
        }
        return codigoPaises;
	}
	
	@GET
	@Path("/Recorrer")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerRutas() {
		File file1 = new File("graficaGrafoRuta.dot");
		File file2 = new File("graficaMatrizRuta.dot");
		try {
			if(!file1.exists()) {
				file1.createNewFile();
			}
			if(!file2.exists()) {
				file2.createNewFile();
			}
			PrintWriter pw1 = new PrintWriter(file1);
			PrintWriter pw2 = new PrintWriter(file2);
			String cabecera1 = "digraph structs { \n edge[arrowhead = none] \n graph [pad=\"0.212,0.055\" bgcolor=azure3] \n node[style = filled, fillcolor = darksalmon]; \n";
			String cabecera2 = "digraph structs { \n node[shape = record]; \n graph [pad=\"0.212,0.055\" bgcolor=azure3] \n";
			String pie1 = "}";
			String pie2 = "}";
			String contenido1 = cabecera1 + test.rutitas.recorrerGrafo() + pie1;
			String contenido2 = cabecera2 + test.matrisita.mostrarCabeceras() + test.matrisita.mostrarFila() +
					test.matrisita.mostrarColumna() + pie2;
			pw1.println(contenido1);
			pw1.close();
			pw2.println(contenido2);
			pw2.close();
			String path = "C:\\Users\\USER\\Desktop\\FrontEndProyecto1\\archivos\\assets\\images\\big\\";
			@SuppressWarnings("unused")
			Process p1 = Runtime.getRuntime().exec("cmd /c dot -Tpng graficaGrafoRuta.dot -o" + path + "GrafoRuta.png");
			@SuppressWarnings("unused")
			Process p2 = Runtime.getRuntime().exec("cmd /c neato -Tpng graficaMatrizRuta.dot -o" + path + "MatrizRuta.png");
			return "1";
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
}
