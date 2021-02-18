#include "estructura.h"
#include <string.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

//Inicio Metodos Arbol Catedratico
std::string ArbolCatedratico::recorrer(){
	NodoCatedratico* r = raiz;
	std::string cabecera = "digraph structs { \n node [shape=record];\n";
	std::string pie = "}";
	std::string codigo = preOrden(r,"Raiz");
	std::string insertar = cabecera + codigo + pie;
	int n = insertar.length();
	char frase[n+1];
	strcpy(frase, insertar.c_str());
	FILE *fichero;
	fichero = fopen("arbol.dot","wt");
	if(fichero != NULL){
		fwrite(&frase, strlen(frase), 1, fichero);
		fclose(fichero);
		system("dot -Tpng arbol.dot -o /home/jared/Catedraticos.png");
		return codigo;
	}else{
		return "ERROR";
	}
}
std::string ArbolCatedratico::preOrden(NodoCatedratico* r, std::string hijo){
	if(r!=NULL){
		//Obtiene los datos de la raiz
		std::string raiz = r -> datos().codigo + " " + r -> datos().nombre; 
		std::string codr = r -> datos().codigo;
		std::string cadenaRaiz = "";
		//Genera el string del hijo izquierdo
		std::string izquierdo = "";
		std::string codi = "";
		std::string cadenaIzquierdo = "";
		//Genera el string del hijo derecho
		std::string derecho = "";
		std::string codd = "";
		std::string cadenaDerecho = "";

		cadenaRaiz = codr+" [shape=record,label = \"<f0> |<f1> "+raiz+"|<f2>\"];\n";
		if(r -> hijoI() != NULL){
			//Obtiene los datos del hijo izquierdo
			NodoCatedratico* iz = r -> hijoI();
			std::string codi = iz -> datos().codigo;
			cadenaIzquierdo = codr+":f0 -> "+codi+":f1;\n";
		}
		if(r -> hijoD() != NULL){
			//Obtiene los datos del hijo derecho
			NodoCatedratico* de = r -> hijoD();
			std::string codd = de -> datos().codigo;
			cadenaDerecho = codr+":f2 -> "+codd+":f1;\n";
		}
		//Se genera la cadena para enviar a graphviz
		std::string cadena =  cadenaRaiz + cadenaIzquierdo + cadenaDerecho;
		return cadena + preOrden(r -> hijoI(), "I") +preOrden(r -> hijoD(),"D");
	}else{
		return "";
	}
}

ArbolCatedratico::ArbolCatedratico(){
	raiz = NULL;
}

std::string ArbolCatedratico::insertarCatedratico(Catedratico cate){
	std::string retorno = "Catedratico insertado";
	NodoCatedratico* nuevo;
	nuevo = new NodoCatedratico(cate);
	if(raiz != NULL){
		NodoCatedratico* auxiliar = raiz;
		NodoCatedratico* padre;
		while(true){
			padre = auxiliar;
			std::string codigo1 = nuevo -> datos().codigo;
			std::string codigo2 = auxiliar -> datos().codigo;
			if(codigo1.compare(codigo2) < 0){
				auxiliar = auxiliar -> hijoI();
				if(auxiliar == NULL){
					padre -> setHijoI(nuevo);
					return retorno;
				}
			}else{
				auxiliar = auxiliar -> hijoD();
				if(auxiliar == NULL){
					padre -> setHijoD(nuevo);
					return retorno;
				}
			}
		}
	}else{
		raiz = nuevo;
		return retorno;
	}
}
//Fin Metodos Arbol Catedratico


//Inicio Metodos Lista Circular Curso
ListaCursos::ListaCursos(){
	cabeza = NULL;
	cola = NULL;
}

std::string ListaCursos::insertarCurso(Curso cur, ArbolCatedratico ac){
	std::string retorno = "";
	NodoCatedratico* cate;
	NodoCurso* nuevo;
	nuevo = new NodoCurso(cur);
	cate = buscar(nuevo -> datos().catedratico, ac);
	if(cate != NULL){
		nuevo -> setCatedratico(cate);
		if(cabeza != NULL){
			nuevo -> setSiguiente(cabeza);
			cabeza = nuevo;
			cola -> setSiguiente(cabeza);
		}else{
			cabeza = nuevo;
			nuevo -> setSiguiente(cabeza);
			cola = nuevo;
		}
		retorno = "Curso insertado";
	}else{
		retorno = "Curso no insertado, Falta Catedratico";
	}
	return retorno;
}

NodoCatedratico* ListaCursos::buscar(std::string codCur, ArbolCatedratico ac){
	NodoCatedratico* cab;
	if(ac.raiz != NULL){
		cab = ac.raiz;
		while(cab -> datos().codigo != codCur){
			if(cab -> datos().codigo.compare(codCur) > 0){
				cab = cab -> hijoI();
			}else{
				cab = cab -> hijoD();
			}
			if(cab == NULL){
				return cab;
			}
		}
	}else{
		cab = NULL;
	}
	return cab;
}

std::string ListaCursos::linealizar(ArbolCatedratico ac, ListaCursos lc){
	NodoCatedratico* raiz = ac.raiz;
	NodoCurso* cabeza = lc.cabeza;
	std::string arbol = ac.preOrden(raiz,"Raiz");
	std::string lista = "";
	std::string rank = "{ rank=same";
	do{
		std::string codCur = "";
		std::string nombre = "";
		std::string codCat = "";
		std::string nodo = "";
		std::string codSig = "";
		std::string apuntadorCat = "";
		std::string apuntadorCur = "";
		std::string cadena = "";
		codCur = cabeza -> datos().codigo;
		nombre = cabeza -> datos().nombre;
		codCat = cabeza -> datos().catedratico;
		codSig = cabeza -> getSiguiente() -> datos().codigo;
		rank += " " +codCur;
		nodo = codCur+" [shape=record,label = \"<f0> |<f1> "+codCur +" " + nombre +"|<f2>\"];\n";
		apuntadorCat = codCur+":f0 -> "+codCat+":f1;\n";
		apuntadorCur = codCur+":f2 -> "+codSig+":f0;\n";
		cadena = nodo + apuntadorCat + apuntadorCur;
		lista += cadena;
		cabeza = cabeza -> getSiguiente();
	}while(cabeza != lc.cabeza);

	std::string cabecera = "digraph G { \n node [shape=record];\n";
	std::string pie = "}\n";
	std::string insertar = cabecera + rank + "}" + arbol + lista + pie;
	int n = insertar.length();
	char frase[n+1];
	strcpy(frase, insertar.c_str());
	FILE *fichero;
	fichero = fopen("lista.dot","wt");
	if(fichero != NULL){
		fwrite(&frase, strlen(frase), 1, fichero);
		fclose(fichero);
		system("dot -Tpng lista.dot -o /home/jared/Cursos.png");
	}else{

	}
	return lista;
}
//Fin Metodos Lista Circular Curso

//Inicio Metodos Lista Simple Dia
ListaDia::ListaDia(){
	cabeza = NULL;
}
std::string ListaDia::insertarDia(Dia d){
	NodoDia* nuevo;
	nuevo = new NodoDia(d);
	std::string dia = nuevo -> datos().nombreDia;
	if(cabeza != NULL){
		if(buscarDia(dia) == false){
			nuevo -> setSiguiente(cabeza);
			cabeza = nuevo;
		}else{
			return "ERROR: El dia ya fue ingresado";
		}
	}else{
		cabeza = nuevo;
	}
	return "Dia ingresado";
}
bool ListaDia::buscarDia(std::string dia){
	std::string diaIterado;
	NodoDia* iterador = cabeza;
	if(dia == "sabado" || dia == "domingo"){
		return false;
	}else{
		while(iterador != NULL){
			diaIterado = iterador -> datos().nombreDia;
			if(diaIterado.compare(dia) == 0)
				return true;
			iterador = iterador -> getSiguiente();
		}
	}
	return false;
}
//Fin Metodos Lista Simple Dia

//Inicio Metodos Lista Doblemente Enlazada Salon
ListaSalon::ListaSalon(){
	cabeza = NULL;
}
std::string ListaSalon::insertarSalon(Salon s){
	NodoSalon* nuevo;
	nuevo = new NodoSalon(s);
	if(buscarSalon(nuevo -> datos().edificio, nuevo -> datos().salon)){
		if(cabeza != NULL){
			nuevo -> setSiguiente(cabeza);
			cabeza -> setAnterior(nuevo);
			cabeza = nuevo;
		}else{
			cabeza = nuevo;
		}
		return "Salon ingresado";
	}else{
		return "Error: Salon Ya ingresado";
	}
}

bool ListaSalon::buscarSalon(std::string e, std::string s){
	std::string edificio;
	std::string salon;
	NodoSalon* temp = cabeza;
	while(temp != NULL){
		edificio = temp -> datos().edificio;
		salon = temp -> datos().salon;
		if(edificio.compare(e) == 0 && salon.compare(s) == 0)
			return false;
		temp = temp -> getSiguiente();
	}
	return true;
}

std::list<std::string> ListaSalon::buscarSalon(std::string e){
	std::list<std::string> lista;
	NodoSalon* temp = cabeza;
	if(temp != NULL){
		while(temp != NULL){
			if(temp -> datos().edificio.compare(e) == 0)
				lista.push_back(temp -> datos().salon);
			temp = temp -> getSiguiente();
		}
	}
	return lista;
}
std::string ListaSalon::buscarSalon(){
	std::string lista;
	std::string codigo_salon;
	std::string codigo_edificio;
	std::string edif;
	NodoSalon* temp = cabeza;	
	if(temp != NULL){
		while(temp != NULL){
			codigo_salon = temp -> datos().salon;
			codigo_edificio = temp -> datos().edificio;
			std::size_t found = edif.find(codigo_edificio);
			if(found==std::string::npos){
				lista += codigo_salon+" [shape=record,label = \""+codigo_salon+"\"];\n";
				edif += codigo_edificio+";";
			}
			lista += codigo_edificio+"->"+codigo_salon+";\n";	
			temp = temp -> getSiguiente();
		}
	}
	return lista;
}
//Fin Metodos Lista Doblemente Enlazada Salon

//Inicio Metodos Lista Doblemente Enlazada Hora
ListaHora::ListaHora(){
	cabeza = NULL;
}

std::string ListaHora::insertarHora(Hora h){
	NodoHora* nuevo;
	nuevo = new NodoHora(h);
	if(buscarHora(nuevo -> datos().horaInicio, nuevo -> datos().horaFinal)){
		if(cabeza != NULL){
			nuevo -> setSiguiente(cabeza);
			cabeza -> setAnterior(nuevo);
			cabeza = nuevo;
		}else{
			cabeza = nuevo;
		}
		return "Hora ingresada";
	}else{
		return "Error: Hora Ya ingresada";
	}
}

bool ListaHora::buscarHora(std::string hI, std::string hF){
	std::string horaI;
	std::string horaF;
	NodoHora* temp = cabeza;
	while(temp != NULL){
		horaI = temp -> datos().horaInicio;
		horaF = temp -> datos().horaFinal;
		if(horaI.compare(hI) == 0 && horaF.compare(hF) == 0)
			return false;
		temp = temp -> getSiguiente();
	}
	return true;
}
std::string ListaHora::recorrerHora(std::string dia){	
	NodoHora* temp = cabeza;
	std::string cadena;
	std::string hora;
	std::string hora2;
	while(temp != NULL){
		if(dia.compare(temp -> datos().dia) == 0){
			hora = temp -> datos().horaInicio;
			cadena += hora+" [shape=record,label = \""+hora+"\"];\n";
			if((temp -> getSiguiente())!=NULL){
				hora2 = temp -> getSiguiente() -> datos().horaInicio;
				cadena += hora+"->"+hora2+";\n";
			}
		}
		temp = temp -> getSiguiente();
	}
	return cadena;
}
//Fin Metodos Lista Doblemente Enlazada Hora

//Inicio Metodos Lista Doblemente Enlazada Hora
ListaAsignacion::ListaAsignacion(){
	cabeza = NULL;
}

std::string ListaAsignacion::insertarAsignacion(Asignacion ass, ListaDia ld, ListaCursos lc, ArbolCatedratico ac, ListaHora lh, ListaSalon ls){
	std::string dia = ass.dia;
	std::string cod_curso = ass.cod_curso;
	std::string cod_catedratico = ass.cod_catedratico;
	std::string horaInicio = ass.horaInicio;
	std::string horaFinal = ass.horaFinal;
	std::string edificio = ass.edificio;
	std::string salon = ass.salon;
	NodoAsignacion* nuevo;
	std::string ingreso = "Ingresado";
	NodoDia* di_a = ld.cabeza;
	while(di_a != NULL){
		std::string temp = di_a -> datos().nombreDia;
		if(temp.compare(dia) == 0)
			break;
		di_a = di_a -> getSiguiente();
	}
	NodoCurso* cu_a = lc.cabeza;
	while(cu_a != NULL){
		std::string temp = cu_a -> datos().codigo;
		if(temp.compare(cod_curso) == 0)
			break;
		cu_a = cu_a -> getSiguiente();
	}
	NodoCatedratico* ca_a = ac.raiz;
	while(ca_a -> datos().codigo != cod_curso){
		if(ca_a -> datos().codigo.compare(cod_curso) > 0){
			ca_a = ca_a -> hijoI();
		}else{
			ca_a = ca_a -> hijoD();
		}
		if(ca_a == NULL){
			break;
		}
	}
	NodoHora* ho_a = lh.cabeza;
	while(ho_a != NULL){
		std::string horaI = ho_a -> datos().horaInicio;
		std::string horaF = ho_a -> datos().horaFinal;
		if(horaI.compare(horaInicio) == 0 && horaF.compare(horaFinal) == 0)
			break;
		ho_a = ho_a -> getSiguiente();
	}
	NodoSalon* sa_a = ls.cabeza;
	while(sa_a != NULL){
		std::string codigo_salon = sa_a -> datos().salon;
		std::string codigo_edificio = sa_a -> datos().edificio;
		if(codigo_salon.compare(salon) == 0 && codigo_edificio.compare(edificio) == 0)
			break;
		sa_a = sa_a -> getSiguiente();
	}


	nuevo = new NodoAsignacion(ass, di_a, cu_a, ca_a, ho_a, sa_a);
	if(cabeza != NULL){
			nuevo -> setSiguiente(cabeza);
			cabeza = nuevo;
	}else{
		cabeza = nuevo;
	}
	return ingreso;
}
std::string ListaAsignacion::recorrerAsignacion(std::string dia){	
	std::string cadena;
	NodoAsignacion* temp = cabeza;
	NodoAsignacion* temp2 = temp -> getSiguiente();
	std::string dia;
	std::string catedratico;
	std::string curso;
	std::string horaInicio;
	std::string horaFinal;
	std::string edificio;
	std::string salon;
	std::string fdia;
	std::string fcatedratico;
	std::string fcurso;
	std::string fhoraInicio;
	std::string fhoraFinal;
	std::string fedificio;
	std::string fsalon;
	NodoDia* n_dia;
	NodoCurso* n_curso;
	NodoCatedratico* n_catedratico;
	NodoHora* n_hora;
	NodoSalon* n_salon;
	NodoDia* fn_dia;
	NodoCurso* fn_curso;
	NodoCatedratico* fn_catedratico;
	NodoHora* fn_hora;
	NodoSalon* fn_salon;
	while(temp != NULL){
		if(dia.compare(temp -> datos().dia) == 0){
			n_dia = temp -> getDia();
			n_curso = temp -> getCurso();
			n_catedratico = temp -> getCatedratico();
			n_hora = temp -> getHora();
			n_salon = temp -> getSalon();
			//Variables Actuales
			dia = n_dia -> datos().dia;
			catedratico = n_catedratico -> datos().nombre;
			curso = n_curso -> datos().nombre;
			horaInicio = n_hora -> datos().horaInicio;
			horaFinal = n_hora -> datos().horaFinal;
			edificio = n_salon -> datos().edificio;
			salon = n_salon -> datos().salon;
			//Creacion de Nodos Actuales
			cadena += dia+" [shape=record,label = \""+dia+"\"];\n";
			cadena += catedratico+" [shape=record,label = \""+catedratico+"\"];\n";
			cadena += curso+" [shape=record,label = \""+curso+"\"];\n";
			cadena += horaInicio+" [shape=record,label = \""+horaInicio+"\"];\n";
			cadena += horaFinal+" [shape=record,label = \""+horaFinal+"\"];\n";
			cadena += edificio+" [shape=record,label = \""+edificio+"\"];\n";
			cadena += salon+" [shape=record,label = \""+salon+"\"];\n";		
			//Variables Futuras
			if(temp2 != NULL){
				fn_dia = temp2 -> getDia();
				fn_curso = temp2 -> getCurso();
				fn_catedratico = temp2 -> getCatedratico();
				fn_hora = temp2 -> getHora();
				fn_salon = temp2 -> getSalon();
				fdia = fn_dia -> datos().dia;
				fcatedratico = fn_catedratico -> datos().nombre;
				fcurso = fn_curso -> datos().nombre;
				fhoraInicio = fn_hora -> datos().horaInicio;
				fhoraFinal = fn_hora -> datos().horaFinal;
				fedificio = fn_salon -> datos().edificio;
				fsalon = fn_salon -> datos().salon;
				temp2 = temp2 -> getSiguiente();
				//Apuntadores
				cadena += horaInicio+"->"+fhoraInicio";\n";
				cadena += salon+"->"+nodoext";\n";
				cadena += nodoext+"->"+fnodoext";\n";
				cadena += salon+"->"+fsalon";\n";
			}
			cadena += horaInicio+"->"+nodoext";\n";
			
		}
		temp = temp -> getSiguiente();
	}
	return cadena;
}
//Fin Metodos Lista Doblemente Enlazada Hora