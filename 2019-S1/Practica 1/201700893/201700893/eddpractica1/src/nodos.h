#ifndef NODOS_H
#define NODOS_H
#include <string>
//--------Inicio Usuarios--------//
	struct Usuario{
        std::string identificador;
        std::string nombre;
        std::string correo;
        std::string fecha;
    };
    class NodoUsuario{
        public:
            Usuario userx;
            NodoUsuario*siguiente;
            NodoUsuario(Usuario u);
            NodoUsuario(Usuario u, NodoUsuario* nu);//ns hace referencia al siguiente nodo
            Usuario datos();
            NodoUsuario*SiguienteUsuario();
            void setUsuarioSiguiente(NodoUsuario* next);
    };
//---------Fin Usuarios---------//

//--------Inicio Recursos--------//
    struct Recurso{
		std::string dominio;
		std::string contenido;
	};
	class NodoRecurso{
		public:
			Recurso resource;
			NodoRecurso* siguiente;
			NodoRecurso(Recurso r);
			NodoRecurso(Recurso r, NodoRecurso*nr);
			Recurso datos();
			NodoRecurso* SiguienteRecurso();
			void setSiguienteRecurso(NodoRecurso* next);
	};
//---------Fin Recursos---------//

//--------Inicio Servicios--------//
	struct Servicio{
		std::string identificador_sesion;
		std::string identificador_usuario;
	};
	class NodoServicio{
		public:
			Servicio service;
			NodoServicio* siguiente;
			NodoServicio(Servicio s);
			NodoServicio(Servicio s, NodoServicio* ns);
			Servicio datos();
			NodoServicio* SiguienteServicio();
			void setSiguienteServicio(NodoServicio* next);
	};
//---------Fin Servicios---------//
#endif