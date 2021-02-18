#include "nodo.h"
//Inicio Arbol Catedratico
NodoCatedratico::NodoCatedratico(Catedratico c){
	cate = c;
	hijoIzquierdo = 0;
	hijoDerecho = 0;
}
NodoCatedratico::NodoCatedratico(Catedratico c, NodoCatedratico* hijoI, NodoCatedratico* hijoD){
	cate = c;
	hijoIzquierdo = hijoI;
	hijoDerecho = hijoD;
}
Catedratico NodoCatedratico::datos(){
	return cate;
}
NodoCatedratico* NodoCatedratico::hijoI(){
	return hijoIzquierdo;
}
NodoCatedratico* NodoCatedratico::hijoD(){
	return hijoDerecho;
}
void NodoCatedratico::setHijoI(NodoCatedratico* hijoIz){
	hijoIzquierdo = hijoIz;
}
void NodoCatedratico::setHijoD(NodoCatedratico* hijoDe){
	hijoDerecho = hijoDe;
}
//Fin Arbol Catedratico

//Inicio Lista Simple Curso
NodoCurso::NodoCurso(Curso c){
	cur = c;
	siguiente = 0;
	catedratico = 0;
}
NodoCurso::NodoCurso(Curso c, NodoCurso* sig, NodoCatedratico* cat){
	cur = c;
	siguiente = sig;
	catedratico = cat;
}
Curso NodoCurso::datos(){
	return cur;
}
NodoCurso* NodoCurso::getSiguiente(){
	return siguiente;
}
NodoCatedratico* NodoCurso::getCatedratico(){
	return catedratico;
}
void NodoCurso::setSiguiente(NodoCurso* sig){
	siguiente = sig;
}
void NodoCurso::setCatedratico(NodoCatedratico* cat){
	catedratico = cat;
}
//Fin Lista Simple Curso

//Inicio Lista Simple Dia
NodoDia::NodoDia(Dia d){
	di = d;
	siguiente = 0;
	matriz = 0;
}
NodoDia::NodoDia(Dia d, NodoDia* sig, NodoMatriz* mat){
	di = d;
	siguiente = sig;
	matriz = mat;
}
Dia NodoDia::datos(){
	return di;
}
NodoDia* NodoDia::getSiguiente(){
	return siguiente;
}
NodoMatriz* NodoDia::getMatriz(){
	return matriz;
}
void NodoDia::setSiguiente(NodoDia* sig){
	siguiente = sig;
}
void NodoDia::setMatriz(NodoMatriz* mat){
	matriz = mat;
}
//Fin Lista Simple Dia

//Inicio Matriz
NodoMatriz::NodoMatriz(Matriz mat){

}
//Fin Matriz

//Inicio Salon
NodoSalon::NodoSalon(Salon s){
	sal = s;
	siguiente = 0;
	anterior = 0;
}
NodoSalon::NodoSalon(Salon s, NodoSalon* sig, NodoSalon* ant){
	sal = s;
	siguiente = sig;
	anterior = ant;
}
Salon NodoSalon::datos(){
	return sal;
}
NodoSalon* NodoSalon::getSiguiente(){
	return siguiente;
}
NodoSalon* NodoSalon::getAnterior(){
	return anterior;
}
void NodoSalon::setSiguiente(NodoSalon* sig){
	siguiente = sig;
}
void NodoSalon::setAnterior(NodoSalon* ant){
	anterior = ant;
}
//Fin Salon

//Inicio Hora
NodoHora::NodoHora(Hora h){
	hor = h;
	siguiente = 0;
	anterior = 0;
}
NodoHora::NodoHora(Hora h, NodoHora* sig, NodoHora* ant){
	hor = h;
	siguiente = sig;
	anterior = ant;
}
Hora NodoHora::datos(){
	return hor;
}
NodoHora* NodoHora::getSiguiente(){
	return siguiente;
}
NodoHora* NodoHora::getAnterior(){
	return anterior;
}
void NodoHora::setSiguiente(NodoHora* sig){
	siguiente = sig;
}
void NodoHora::setAnterior(NodoHora* ant){
	anterior = ant;
}
//Fin Hora

//Inicio Asignacion
NodoAsignacion::NodoAsignacion(Asignacion a, NodoDia* di_a, NodoCurso* cu_a, NodoCatedratico* ca_a, NodoHora* ho_a, NodoSalon* sa_a){
	ass = a;
	di_ass = di_a;
	cu_ass = cu_a;
	ca_ass = ca_a;
	sa_ass = sa_a;
	ho_ass = ho_a;
	si_ass = 0;
}
NodoAsignacion::NodoAsignacion(Asignacion a, NodoDia* di_a, NodoCurso* cu_a, NodoCatedratico* ca_a, NodoHora* ho_a, NodoSalon* sa_a, NodoAsignacion* si_a){
	ass = a;
	di_ass = di_a;
	cu_ass = cu_a;
	ca_ass = ca_a;
	sa_ass = sa_a;
	ho_ass = ho_a;
	si_ass = si_a;
}
Asignacion NodoAsignacion::datos(){
	return ass;
}
NodoDia* NodoAsignacion::getDia(){
	return di_ass;
}
void NodoAsignacion::setDia(NodoDia* di_a){
	di_ass = di_a;
}
NodoCurso* NodoAsignacion::getCurso(){
	return cu_ass;
}
void NodoAsignacion::setCurso(NodoCurso* cu_a){
	cu_ass = cu_a;
}
NodoCatedratico* NodoAsignacion::getCatedratico(){
	return ca_ass;
}
void NodoAsignacion::setCatedratico(NodoCatedratico* ca_a){
	ca_ass = ca_a;
}
NodoHora* NodoAsignacion::getHora(){
	return ho_ass;
}
void NodoAsignacion::setHora(NodoHora* ho_a){
	ho_ass = ho_a;
}
NodoAsignacion* NodoAsignacion::getSiguiente(){
	return si_ass;
}
void NodoAsignacion::setSiguiente(NodoAsignacion* si_a){
	si_ass = si_a;
}
//Fin Asignacion