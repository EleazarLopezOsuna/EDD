#ifndef NODO_H
#define NODO_H
#include <string>

struct Catedratico{
	std::string codigo;
	std::string nombre;
};

class NodoCatedratico{
	public:
		Catedratico cate;
		NodoCatedratico* hijoIzquierdo;
		NodoCatedratico* hijoDerecho;
		NodoCatedratico(Catedratico cate);
		NodoCatedratico(Catedratico cate, NodoCatedratico* hijoDerecho, NodoCatedratico* hijoIzquierdo);
		Catedratico datos();
		NodoCatedratico* hijoI();
		NodoCatedratico* hijoD();
		void setHijoI(NodoCatedratico* hijoIz);
		void setHijoD(NodoCatedratico* hijoDe);
};

struct Curso{
	std::string codigo;
	std::string nombre;
	std::string catedratico;
};

class NodoCurso{
	public:
		Curso cur;
		NodoCurso* siguiente;
		NodoCatedratico* catedratico;
		NodoCurso(Curso cur);
		NodoCurso(Curso cur, NodoCurso* siguiente, NodoCatedratico* catedratico);
		Curso datos();
		NodoCurso* getSiguiente();
		NodoCatedratico* getCatedratico();
		void setSiguiente(NodoCurso* siguiente);
		void setCatedratico(NodoCatedratico* catedratico);
};

struct Salon{
	std::string edificio;
	std::string salon;
	std::string capacidad;
};

class NodoSalon{
	public:
		Salon sal;
		NodoSalon* siguiente;
		NodoSalon* anterior;
		NodoSalon(Salon sal);
		NodoSalon(Salon sal, NodoSalon* siguiente, NodoSalon* anterior);
		Salon datos();
		NodoSalon* getSiguiente();
		NodoSalon* getAnterior();
		void setSiguiente(NodoSalon* sal);
		void setAnterior(NodoSalon* sal);
};

struct Hora{
	std::string horaInicio;
	std::string horaFinal;
	std::string dia;
};

class NodoHora{
	public:
		Hora hor;
		NodoHora* siguiente;
		NodoHora* anterior;
		NodoHora(Hora h);
		NodoHora(Hora h, NodoHora* siguiente, NodoHora* anterior);
		Hora datos();
		NodoHora* getSiguiente();
		NodoHora* getAnterior();
		void setSiguiente(NodoHora* h);
		void setAnterior(NodoHora* h);
};

struct Matriz{
	std::string nombreDia;
};

class NodoMatriz{
	public:
		Matriz mat;
		NodoMatriz* siguiente;
		NodoMatriz(Matriz mat);

};

struct Dia{
	std::string nombreDia;
};

class NodoDia{
	public:
		Dia di;
		NodoDia* siguiente;
		NodoMatriz* matriz;
		NodoDia(Dia di);
		NodoDia(Dia di, NodoDia* siguiente, NodoMatriz* matriz);
		Dia datos();
		NodoDia* getSiguiente();
		NodoMatriz* getMatriz();
		void setSiguiente(NodoDia* dia);
		void setMatriz(NodoMatriz* matriz);
};

struct Asignacion{
	std::string dia;
	std::string cod_curso;
	std::string cod_catedratico;
	std::string horaInicio;
	std::string horaFinal;
	std::string edificio;
	std::string salon;
};

class NodoAsignacion{
	public:
		Asignacion ass;
		NodoDia* di_ass;
		NodoCurso* cu_ass;
		NodoCatedratico* ca_ass;
		NodoHora* ho_ass;
		NodoSalon* sa_ass;
		NodoAsignacion* si_ass;
		NodoAsignacion(Asignacion ass, NodoDia* di_ass, NodoCurso* cu_ass, NodoCatedratico* ca_ass, NodoHora* ho_ass, NodoSalon* sa_ass);
		NodoAsignacion(Asignacion ass, NodoDia* di_ass, NodoCurso* cu_ass, NodoCatedratico* ca_ass, NodoHora* ho_ass, NodoSalon* sa_ass, NodoAsignacion* si_ass);
		Asignacion datos();
		NodoDia* getDia();
		NodoCurso* getCurso();
		NodoCatedratico* getCatedratico();
		NodoHora* getHora();
		NodoSalon* getSalon();
		NodoAsignacion* getSiguiente();
		void setDia(NodoDia* di_ass);
		void setCurso(NodoCurso* cu_ass);
		void setCatedratico(NodoCatedratico* ca_ass);
		void setHora(NodoHora* ho_ass);
		void setSalon(NodoSalon* sa_ass);
		void setSiguiente(NodoAsignacion* si_ass);
};

#endif