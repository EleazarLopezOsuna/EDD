package com.jared.edd.recursos;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import javax.ws.rs.GET;
import javax.ws.rs.Path;
import javax.ws.rs.Produces;
import javax.ws.rs.core.MediaType;
import javax.ws.rs.PathParam;

import com.jared.edd.test;
import com.jared.edd.models.Ruta;
import com.jared.edd.models.Destino;
import com.jared.edd.estructuras.Lista;
import com.jared.edd.estructuras.ListaInt;

@Path("/Rutas")
public class Rutas {
	
	@GET
	@Path("/Eliminar/{idS}/{idL}")
	@Produces(MediaType.APPLICATION_JSON)
	public String eliminarRuta(@PathParam("idS") int pS,@PathParam("idL") int pL) throws Throwable {
		test.matrisita.eliminar(pS, pL);
		return "";
	}
	
	@GET
	@Path("/Editar/{idS}/{idL}/{Co}/{Ti}")
	@Produces(MediaType.APPLICATION_JSON)
	public String editarRuta(@PathParam("idS") int pS,@PathParam("idL") int pL,@PathParam("Co") int costo,@PathParam("Ti") int tiempo) {
		test.matrisita.editar(pS, pL, costo, tiempo);
		return "";
	}
	
	@GET
	@Path("/IngresarNombre/{idS}/{idL}/{Co}/{Ti}/{Pi}")
	@Produces(MediaType.APPLICATION_JSON)
	public String ingresarRutaNombre(@PathParam("idS") int pS,@PathParam("idL") int pL,@PathParam("Co") int costo,@PathParam("Ti") int tiempo, @PathParam("Pi") String nPil) {
		int paisS = test.destinito.buscarCodigo(pS);
		int paisL = test.destinito.buscarCodigo(pL);
		System.out.println(paisS);
		System.out.println(paisL);
		Ruta ruta = new Ruta(paisS,paisL,costo,tiempo,nPil);
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
		ListaInt ingresados = new ListaInt();
        ingresados.insertar(salida);
        test.matrisita.lista = new Lista();
        test.matrisita.rutaCorta(salida, llegada);
        int index = 0;
        int peso = 999999999;
        for (int i = 0; i < test.matrisita.lista.size(); i++) {
            int pesoTemp = 0;
            for (int j = 0; j < test.matrisita.lista.get(i).size() - 1; j++) {
                pesoTemp += test.matrisita.buscarTC(test.matrisita.lista.get(i).get(j), test.matrisita.lista.get(i).get(j + 1), tipo);
            }
            if (pesoTemp < peso) {
                peso = pesoTemp;
                index = i;
            }
        }
        for (int i = 0; i < test.matrisita.lista.get(index).size(); i++) {
        	if(i == test.matrisita.lista.get(index).size() - 1){
        		int id = test.matrisita.lista.get(index).get(i);
        		Destino destino = test.destinito.buscarD(id);
        		retorno += destino.pais + "\n";
        	}else{
        		int id = test.matrisita.lista.get(index).get(i);
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
		ListaInt ingresados = new ListaInt();
        ingresados.insertar(salida);
        test.matrisita.lista = new Lista();
        test.matrisita.rutaCorta(salida, llegada);
        int index = 0;
        int peso = 999999999;
        String codigoPaises = "";
        String tipoGraph = "";
        String tipoImg = "";
        if(grafica == 0) {//Grafica y devuelve la ruta corta
        	tipoGraph = "C:\\Users\\USER\\Desktop\\Cali\\graficaRutaCorta.dot";
        	tipoImg = "C:\\Users\\USER\\Desktop\\Cali\\RutaCorta.png";
        	for (int i = 0; i < test.matrisita.lista.size(); i++) {
                int pesoTemp = 0;
                for (int j = 0; j < test.matrisita.lista.get(i).size() - 1; j++) {
                    pesoTemp += test.matrisita.buscarTC(test.matrisita.lista.get(i).get(j), test.matrisita.lista.get(i).get(j + 1), tipo);
                }
                if (pesoTemp < peso) {
                    peso = pesoTemp;
                    index = i;
                }
            }
            for (int i = 0; i < test.matrisita.lista.get(index).size(); i++) {
            	if(i == test.matrisita.lista.get(index).size() - 1){
            		int id = test.matrisita.lista.get(index).get(i);
            		Destino destino = test.destinito.buscarD(id);
            		retorno += "\"" + destino.pais + "\"" + "\n";
            		codigoPaises += destino.pais;
            	}else{
            		int id = test.matrisita.lista.get(index).get(i);
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
    			String path = "C:\\Users\\USER\\Desktop\\Cali\\";
    			@SuppressWarnings("unused")
    			Process p1 = Runtime.getRuntime().exec("cmd /c dot -Tpng " + tipoGraph + " -o " + path + tipoImg);
            }catch(IOException e) {
    			e.printStackTrace();
    			return "0";
    		}
        }else if(grafica == 1){//Grafica y devuelve todas las rutas
        	tipoGraph = "C:\\\\Users\\USER\\Desktop\\Cali\\graficaRutaCompleta.dot";
        	tipoImg = "C:\\Users\\USER\\Desktop\\Cali\\RutaCompleta.png";
        	for (int j = 0; j < test.matrisita.lista.size(); j++) {
        		int costo = 0;
        		int tiempo = 0;
                for(int i = 0; i < test.matrisita.lista.get(j).size(); i++) {
                	if(i == test.matrisita.lista.get(j).size() - 1){
                		int id = test.matrisita.lista.get(j).get(i);
                		Destino destino = test.destinito.buscarD(id);
                		if(!retorno.contains(destino.pais)) {
                			retorno += "\"" + destino.pais + "\"" + "\n";
                		}
                		codigoPaises += destino.pais + ":" + id;
                	}else{ 
                		costo += test.matrisita.buscarTC(test.matrisita.lista.get(j).get(i), test.matrisita.lista.get(j).get(i + 1), 1);
                    	tiempo += test.matrisita.buscarTC(test.matrisita.lista.get(j).get(i), test.matrisita.lista.get(j).get(i + 1), 0);
                        int id = test.matrisita.lista.get(j).get(i);
                		Destino destino = test.destinito.buscarD(id);
                		if(!retorno.contains(destino.pais)) {
                			retorno += "\"" + destino.pais + "\"" + "->";
                		}
                		codigoPaises += destino.pais + ":" + id + ",";
                    }
            	}
                if(j != test.matrisita.lista.get(j).size() - 1) {
                	codigoPaises += "-" + costo + "," + tiempo + ";";
                }else {
                	codigoPaises += "-" + costo + "," + tiempo;
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
    			String path = "C:\\Users\\USER\\Desktop\\Cali\\";
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
	@Path("/Recorre")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerRutas() {
		File file2 = new File("C:\\Users\\USER\\Desktop\\Cali\\graficaMatrizRuta.dot");
		try {
			if(!file2.exists()) {
				file2.createNewFile();
			}
			PrintWriter pw2 = new PrintWriter(file2);
			String contenido2 = "digraph{node[shape=record;width = 1.1; height = 0.8]" + test.matrisita.mostrarCabeceras1() + test.matrisita.completar() + "}";
			pw2.println(contenido2);
			pw2.close();
			String path = "C:\\Users\\USER\\Desktop\\Cali\\";
			@SuppressWarnings("unused")
			Process p2 = Runtime.getRuntime().exec("cmd /c dot -Tpng C:\\Users\\USER\\Desktop\\Cali\\graficaMatrizRuta.dot -o" + path + "MatrizRuta.png");
			return contenido2;
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
	
	@GET
	@Path("/Recorrerr")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerrRutas() {
		File file1 = new File("C:\\Users\\USER\\Desktop\\Cali\\graficaGrafoRuta.dot");
		File file2 = new File("C:\\Users\\USER\\Desktop\\Cali\\graficaMatrizRuta.dot");
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
			String path = "C:\\Users\\USER\\Desktop\\Cali\\";
			@SuppressWarnings("unused")
			Process p1 = Runtime.getRuntime().exec("cmd /c dot -Tpng C:\\Users\\USER\\Desktop\\Cali\\graficaGrafoRuta.dot -o" + path + "GrafoRuta.png");
			@SuppressWarnings("unused")
			Process p2 = Runtime.getRuntime().exec("cmd /c neato -Tpng C:\\Users\\USER\\Desktop\\Cali\\graficaMatrizRuta.dot -o" + path + "MatrizRuta.png");
			return contenido2;
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
	
	@GET
	@Path("/Graficar/{paises}")
	@Produces(MediaType.APPLICATION_JSON)
	public String recorrerRuta(@PathParam("paises") String contenido) {
		File file1 = new File("C:\\Users\\USER\\Desktop\\Cali\\ruta.dot");
		try {
			if(!file1.exists()) {
				file1.createNewFile();
			}
			PrintWriter pw1 = new PrintWriter(file1);
			String cabecera1 = "digraph structs { \n edge[arrowhead = none] \n graph [pad=\"0.212,0.055\" bgcolor=azure3] \n node[style = filled, fillcolor = darksalmon]; \n";
			String pie1 = "}";
			String contenidox = contenido.replace(",", "->").replace(";","");
			String contenido1 = cabecera1 + contenidox + pie1;
			pw1.println(contenido1);
			pw1.close();
			String path = "C:\\Users\\USER\\Desktop\\Cali\\";
			@SuppressWarnings("unused")
			Process p1 = Runtime.getRuntime().exec("cmd /c dot -Tpng C:\\Users\\USER\\Desktop\\Cali\\ruta.dot -o" + path + "ruta.png");
			return "1";
		}catch(IOException e) {
			e.printStackTrace();
			return "0";
		}
	}
}
