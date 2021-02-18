/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/*
 * File:   main.cpp
 * Author: USER
 *
 * Created on 17 de junio de 2019, 03:16 PM
 */

#include "Capa.h"
#include "ListaImagenes.h"
#include "Imagen.h"
#include "Usuario.h"
#include "ListaCapas.h"
#include "ArbolABB.h"
#include "ArbolAVL.h"
#include "MatrizDispersa.h"
#include <fstream>
#include <cstring>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string pathCapas, pathImagenes, pathUsuarios;

//Estructuras
ArbolABB* ABB = new ArbolABB();//Capas
ArbolAVL* AVL = new ArbolAVL();//Usuarios
ListaImagenes* LI = new ListaImagenes();//Imagenes


void ProcesarArchivos(string path, int tipo)
{
    string line;
    ifstream myfile(path);
    switch (tipo)
    {
    //Capas
    case 0:
        if (myfile.is_open())
        {
            Capa* capa;
            MatrizDispersa* matrizD;
            while (getline(myfile, line))
            {
                int posicionX;
                int posicionY;
                string colorHEX;
                char linea[line.size() + 1];
                strcpy(linea,line.c_str());
                char* point;
                string strI = "{";
                size_t found = line.find(strI);
                //Encontro una nueva Capa
                if(found != string::npos)
                {
                    point = strtok(linea, "{");
                    while(point != NULL)
                    {
                        capa = new Capa();
                        matrizD = new MatrizDispersa();
                        string s(point);
                        int idCapa = stoi(s);
                        capa -> setNombre(idCapa);
                        break;
                    }
                }
                string strPC = ";";
                found = line.find(strPC);
                if(found != string::npos)
                {
                    point = strtok(linea, ";");
                    while(point != NULL)
                    {
                        string strC = ",";
                        string s(point);
                        found = s.find(strC);
                        if(found != string::npos)
                        {
                            char* punto = strtok(point, ",");
                            int contador = 0;
                            while(punto != NULL)
                            {
                                string st(punto);
                                switch(contador)
                                {
                                case 0:
                                    posicionX = stoi(st);
                                    break;
                                case 1:
                                    posicionY = stoi(st);
                                    break;
                                case 2:
                                    colorHEX = st;
                                    break;
                                }
                                contador++;
                                punto = strtok(NULL, ",");
                            }
                        }
                        matrizD -> agregar(posicionY, posicionX, colorHEX);
                        point = strtok(NULL, ";");
                    }
                }
                found = line.find("}");
                if(found == 0)
                {
                    if(matrizD != nullptr)
                    {
                        capa -> matriz = matrizD;
                        ABB -> insertarNodo(capa);
                    }
                }
            }
            myfile.close();
        }
        break;
    //Imagenes
    case 1:
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                Imagen* imagen = new Imagen();
                ListaCapas* LC = new ListaCapas();
                char linea[line.size() + 1];
                strcpy(linea,line.c_str());
                char* point;
                string strI = "}";
                size_t found = line.find(strI);
                //Encontro una nueva Imagen
                if(found != string::npos)
                {
                    point = strtok(linea, "}");
                    while(point != NULL)
                    {
                        string s(point);
                        found = s.find("{");
                        if(found != string::npos)
                        {
                            char* punto = strtok(point,"{");
                            int contador = 0;
                            while(punto != NULL)
                            {
                                string codi(punto);
                                if(!contador)
                                {
                                    imagen -> setIdImagen(stoi(codi));
                                }
                                else
                                {
                                    found = codi.find(",");
                                    if(found != string::npos)
                                    {
                                        char* p = strtok(punto, ",");
                                        while(p != NULL)
                                        {
                                            string cap(p);
                                            Capa* capa = ABB -> existe(ABB -> root, stoi(cap));
                                            if(capa != nullptr)
                                            {
                                                LC -> insertarCabeza(capa);
                                            }
                                            p = strtok(NULL, ",");
                                        }
                                    }
                                    else
                                    {
                                        Capa* capa = ABB -> existe(ABB -> root, stoi(codi));
                                        if(capa != nullptr)
                                        {
                                            LC -> insertarCabeza(capa);
                                        }
                                    }
                                }
                                contador++;
                                punto = strtok(NULL, "{");
                            }
                        }
                        point = strtok(NULL, "}");
                    }
                }
                imagen -> setListaCapas(LC);
                LI -> insertarOrdenado(imagen);
            }
            myfile.close();
        }
        break;
    //Usuarios
    case 2:
        if (myfile.is_open())
        {
            while (getline(myfile, line))
            {
                Usuario* usuario = new Usuario();
                ListaImagenes* LLI = new ListaImagenes();
                char linea[line.size() + 1];
                strcpy(linea,line.c_str());
                char* point;
                string strI = ";";
                size_t found = line.find(strI);
                //Encontro un nuevo Usuario
                if(found != string::npos)
                {
                    point = strtok(linea, ";");
                    while(point != NULL)
                    {
                        string s(point);
                        found = s.find(":");
                        if(found != string::npos)
                        {
                            char* punto = strtok(point,":");
                            int contador = 0;
                            while(punto != NULL)
                            {
                                string codi(punto);
                                if(!contador)
                                {
                                    usuario -> setNombreUsuario(codi);
                                }
                                else
                                {
                                    found = codi.find(",");
                                    if(found != string::npos)
                                    {
                                        char* p = strtok(punto, ",");
                                        while(p != NULL)
                                        {
                                            string cap(p);
                                            Imagen* imagen = LI -> buscar(stoi(cap));
                                            if(imagen != nullptr)
                                            {
                                                LLI -> insertarOrdenado(imagen);
                                            }
                                            p = strtok(NULL, ",");
                                        }
                                    }
                                    else
                                    {
                                        char* as = strtok(punto, ",");
                                        if(as)
                                        {
                                            string n(as);
                                            Imagen* imagen = LI -> buscar(stoi(n));
                                            if(imagen != nullptr)
                                            {
                                                LLI -> insertarOrdenado(imagen);
                                            }
                                        }
                                    }
                                }
                                contador++;
                                punto = strtok(NULL, ":");
                            }
                        }
                        point = strtok(NULL, ";");
                    }
                }
                usuario -> setListaImagenes(LLI);
                AVL -> insertar(usuario);
            }
            myfile.close();
        }
        break;
    default:
        break;
    }
}


void MenuUsuarios()
{
    int opcion = 0;
    int numeroImagenes = 0;
    int codigoImagen = 0;
    int opcionModificarEliminar = 0;
    int codigoModificarEliminar = 0;
    string nombreUsuario = "";
    Usuario* user;
    ListaImagenes* LII;
    Imagen* img;
    while (opcion != 4)
    {
        cout << "***********************" << endl;
        cout << "*****Menu Usuarios*****" << endl;
        cout << "***********************" << endl;
        cout << "1. Agregar" << endl;
        cout << "2. Eliminar" << endl;
        cout << "3. Modificar" << endl;
        cout << "4. Regresar" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            while (nombreUsuario == "")
            {
                cout << "Ingresar Nombre del Usuario" << endl;
                cin >> nombreUsuario;
            }
            user = new Usuario();
            user -> setNombreUsuario(nombreUsuario);
            LII = new ListaImagenes();
            user -> setListaImagenes(LII);
            cout << "Ingresar Numero de Imagenes" << endl;
            cin >> numeroImagenes;
            if (numeroImagenes)
            {
                cout << "Imagenes Disponibles: " << endl;
                cout << LI -> recorrer() << endl;
                cout << "Seleccione " + to_string(numeroImagenes) << endl;
                for (int i = 0; i < numeroImagenes; i++)
                {
                    do
                    {
                        cout << "Imagen numero: " + to_string(i) << endl;
                        cin >> codigoImagen;
                        Imagen* im = new Imagen();
                        im -> setIdImagen(codigoImagen);
                        if(im)
                        {
                            LII -> insertarOrdenado(im);
                            break;
                        }
                    }
                    while (true);
                }
            }
            AVL -> insertar(user);
            break;
        case 2:
            cout << "Ingresar Nombre del Usuario" << endl;
            cin >> nombreUsuario;
            (AVL -> eliminar(nombreUsuario)) ? cout << "Usuario Eliminado" << endl : cout << "Usuario no existe" << endl;
            break;
        case 3:
            cout << "Ingresar Nombre del Usuario" << endl;
            cin >> nombreUsuario;
            user = AVL -> obtenerUsuario(AVL -> root, nombreUsuario);
            if(user != nullptr)
            {
                LII = user -> getListaImagenes();
                cout << "Seleccione una Opcion" << endl;
                cout << "1. Eliminar Imagen" << endl;
                cout << "2. Agregar Imagen" << endl;
                cout << "3. Regresar" << endl;
                cin >> opcionModificarEliminar;
                switch (opcionModificarEliminar)
                {
                case 1:
                    cout << LII -> recorrer() << endl;
                    cout << "Seleccione la Imagen que desea eliminar" << endl;
                    cin >> codigoModificarEliminar;
                    LII -> eliminarDato(codigoModificarEliminar);
                    break;
                case 2:
                    cout << LI -> recorrer() << endl;
                    cout << "Seleccione la Imagen que desea agregar" << endl;
                    cin >> codigoModificarEliminar;
                    img = LII -> buscar(codigoModificarEliminar);
                    if(img != nullptr)
                    {
                        cout << "Imagen ya pertenece al Usuario" << endl;
                    }
                    else
                    {
                        img = LI -> buscar(codigoModificarEliminar);
                        if(img != nullptr)
                        {
                            LII -> insertarOrdenado(img);
                        }
                        else
                        {
                            cout << "Imagen no existe" << endl;
                        }
                    }
                    break;
                }
            }
            else
            {
                cout << "El usuario no existe" << endl;
            }
            break;
        case 4:
            break;
        default:
            break;
        }
    }
}

void MenuReportes()
{
    Imagen* img;
    int codigoModificarEliminar;
    cout << "***********************" << endl;
    cout << "**Top5 Imagenes-Capas**" << endl;
    cout << "***********************" << endl;
    cout << endl;
    cout << LI -> Top5() << endl;
    cout << endl;
    cout << "**************************" << endl;
    cout << "**Top5 Usuarios-Imagenes**" << endl;
    cout << "**************************" << endl;
    AVL -> Top5(AVL -> root);
    cout << endl;
    cout << AVL -> TopU -> recorrer() << endl;
    cout << endl;
    cout << "***********************" << endl;
    cout << "******Capas  Hoja******" << endl;
    cout << "***********************" << endl;
    ABB -> capaHoja = new ListaCapas();
    ABB -> capasHoja(ABB -> root);
    cout << endl;
    cout << ABB -> capaHoja -> print() << endl;
    cout << endl;
    cout << "***********************" << endl;
    cout << "****Capas  PreOrden****" << endl;
    cout << "***********************" << endl;
    cout << "Seleccione la Imagen que desea agregar" << endl;
    cin >> codigoModificarEliminar;
    img = LI -> buscar(codigoModificarEliminar);
    if(img != nullptr)
    {
        cout << endl;
        ABB -> capasPreOrden(ABB -> root, img -> getListaCapas());
        cout << endl;
        cout << endl;
    }
    else
    {
        cout << "Imagen no existe" << endl;
    }
    cout << "***********************" << endl;
    cout << "*****Capas InOrden*****" << endl;
    cout << "***********************" << endl;
    cout << "Seleccione la Imagen que desea agregar" << endl;
    cin >> codigoModificarEliminar;
    img = LI -> buscar(codigoModificarEliminar);
    if(img != nullptr)
    {
        cout << endl;
        ABB -> capasInOrden(ABB -> root, img -> getListaCapas());
        cout << endl;
        cout << endl;
    }
    else
    {
        cout << "Imagen no existe" << endl;
    }
    cout << "***********************" << endl;
    cout << "****Capas PostOrden****" << endl;
    cout << "***********************" << endl;
    cout << "Seleccione la Imagen que desea agregar" << endl;
    cin >> codigoModificarEliminar;
    img = LI -> buscar(codigoModificarEliminar);
    if(img != nullptr)
    {
        cout << endl;
        ABB -> capasPostOrden(ABB -> root, img -> getListaCapas());
        cout << endl;
        cout << endl;
    }
    else
    {
        cout << "Imagen no existe" << endl;
    }
    cout << "***********************" << endl;
    cout << "***Capas Profundidad***" << endl;
    cout << "***********************" << endl;
    cout << endl;
    cout << ABB -> profundidad(ABB -> root, 0) + 1 << endl;
    cout << endl;

    cout << "***********************" << endl;
    cout << "***Usuarios PreOrden***" << endl;
    cout << "***********************" << endl;
    cout << endl;
    cout << AVL -> preOrden(AVL -> root) << endl;
    cout << endl;
    cout << "***********************" << endl;
    cout << "***Usuarios  InOrden***" << endl;
    cout << "***********************" << endl;
    cout << endl;
    cout << AVL -> inOrden(AVL -> root) << endl;
    cout << endl;
    cout << "***********************" << endl;
    cout << "**Usuarios  PostOrden**" << endl;
    cout << "***********************" << endl;
    cout << endl;
    cout << AVL -> postOrden(AVL -> root) << endl;
    cout << endl;
    cout << "***********************" << endl;
    cout << "***Usuarios  Niveles***" << endl;
    cout << "***********************" << endl;
    AVL -> niveles -> head = nullptr;
    AVL -> recorrerNiveles(AVL -> root, 1);
    cout << endl;
    cout << AVL -> niveles -> recorrer() << endl;
    cout << endl;

}

void graficar(string path, string cadena, string comandoDot, string comandoAbrir)
{
    ofstream out(path.c_str());
    ofstream myFile;
    myFile.open(path);
    myFile << cadena;
    myFile.close();
    system(comandoDot.c_str());
    system(comandoAbrir.c_str());
}

void GenerarImagenes()
{
    int opcion = 0;
    int opcionImagen = 0;
    Capa* capa;
    Imagen* img;
    Usuario* us;
    ListaImagenes* LII;
    string opNombre = "";
    string path = "";
    string comandoDot = "";
    string cadena = "";
    string comandoAbrir = "";
    while(opcion != 4)
    {
        cout << "***********************" << endl;
        cout << "*****Menu Graficas*****" << endl;
        cout << "***********************" << endl;
        cout << "1. Por Capa" << endl;
        cout << "2. Por Imagen" << endl;
        cout << "3. Por Usuario" << endl;
        cout << "4. Regresar" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            cout << ABB -> preOrden(ABB -> root) << endl;
            cout << "Seleccione una capa" << endl;
            cin >> opcionImagen;
            capa = ABB -> existe(ABB -> root, opcionImagen);
            if(capa)
            {
                path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Capa.neato";
                cadena = capa -> matriz -> imprimirColor();
                comandoDot = "neato -Tpng C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Capa.neato -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Capa.png";
                comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Capa.png";
                graficar(path, cadena, comandoDot, comandoAbrir);
            }
            else
            {
                cout << "La capa no existe" << endl;
            }
            break;
        case 2:
            cout << LI -> recorrer() << endl;
            cout << "Seleccione una Imagen" << endl;
            cin >> opcionImagen;
            img = LI -> buscar(opcionImagen);
            if(img)
            {
                path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Imagen.neato";
                cadena = img -> printImagen();
                comandoDot = "neato -Tpng C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Imagen.neato -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Imagen.png";
                comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\Imagen.png";
                graficar(path, cadena, comandoDot, comandoAbrir);
            }
            else
            {
                cout << "La imagen no existe" << endl;
            }
            break;
        case 3:
            cout << AVL -> preOrden(AVL -> root) << endl;
            cout << "Seleccione un Usuario" << endl;
            cin >> opNombre;
            us = AVL -> obtenerUsuario(AVL -> root, opNombre);
            if(us)
            {
                LII = us -> getListaImagenes();
                cout << LII -> recorrer() << endl;
                cout << "Seleccione una Imagen" << endl;
                cin >> opcionImagen;
                img = LII -> buscar(opcionImagen);
                if(img)
                {
                    path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ImagenUsuario.neato";
                    cadena = img -> printImagen();
                    comandoDot = "neato -Tpng C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ImagenUsuario.neato -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ImagenUsuario.png";
                    comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ImagenUsuario.png";
                    graficar(path, cadena, comandoDot, comandoAbrir);
                }
                else
                {
                    cout << "La imagen no existe" << endl;
                }
            }
            else
            {
                cout << "El usuario no existe" << endl;
            }
            break;
        case 4:
            break;
        default:
            break;
        }
    }
}

void GraficarEstructuras()
{
    string cabeceraMatriz = "digraph{\nnode[shape = record; width = 1; height = 1]\n";
    string cabeceraOtros = "digraph{\nnode[shape = record;]\n";
    int opcion = 0;
    int codigo = 0;
    string path, comandoDot, comandoAbrir;
    Capa* capa;
    Imagen* img;
    while(opcion != 9)
    {
        cout << "***********************" << endl;
        cout << "***Menu  Estructuras***" << endl;
        cout << "***********************" << endl;
        cout << "1. Arbol Usuarios" << endl;
        cout << "2. Arbol Usuarios-Imagenes" << endl;
        cout << "3. Arbol Capas" << endl;
        cout << "4. Arbol Capas-Espejo" << endl;
        cout << "5. Lista Imagenes" << endl;
        cout << "6. Lista Imagenes-Capas" << endl;
        cout << "7. Imagen-Capas-Arbol" << endl;
        cout << "8. Capa Logica" << endl;
        cout << "9. Salir" << endl;
        cin >> opcion;
        switch(opcion)
        {
        case 1:
            cabeceraOtros += AVL -> preOrdenGrafica(AVL -> root) + "\n}";
            path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolUsuarios.dot";
            comandoDot = "dot -Tpng C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolUsuarios.dot -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolUsuarios.png";
            comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolUsuarios.png";
            graficar(path, cabeceraOtros, comandoDot, comandoAbrir);
            cabeceraOtros = "digraph{\nnode[shape = record;]\n";
            break;
        case 2:
            cabeceraOtros += AVL -> graficaArbolLista(AVL -> root) + "\n}";
            path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolUsuariosImagenes.dot";
            comandoDot = "dot -Tpng " + path + " -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolUsuariosImagenes.png";
            comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolUsuariosImagenes.png";
            graficar(path, cabeceraOtros, comandoDot, comandoAbrir);
            cabeceraOtros = "digraph{\nnode[shape = record;]\n";
            break;
        case 3:
            cabeceraOtros += ABB -> preOrdenGrafica(ABB -> root) + "\n}";
            path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolCapas.dot";
            comandoDot = "dot -Tpng " + path + " -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolCapas.png";
            comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolCapas.png";
            graficar(path, cabeceraOtros, comandoDot, comandoAbrir);
            cabeceraOtros = "digraph{\nnode[shape = record;]\n";
            break;
        case 4:
            cabeceraOtros += ABB -> graficaEspejo(ABB -> root) + "\n}";
            path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolCapasEspejo.dot";
            comandoDot = "dot -Tpng " + path + " -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolCapasEspejo.png";
            comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ArbolCapasEspejo.png";
            graficar(path, cabeceraOtros, comandoDot, comandoAbrir);
            cabeceraOtros = "digraph{\nnode[shape = record;]\n";
            break;
        case 5:
            cabeceraOtros += LI -> printImagenes() + "\n}";
            path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ListaImagenes.dot";
            comandoDot = "dot -Tpng " + path + " -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ListaImagenes.png";
            comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ListaImagenes.png";
            graficar(path, cabeceraOtros, comandoDot, comandoAbrir);
            cabeceraOtros = "digraph{\nnode[shape = record;]\n";
            break;
        case 6:
            cabeceraOtros = LI -> printImagenesCapas();
            path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ListaImagenesCapas.dot";
            comandoDot = "dot -Tpng " + path + " -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ListaImagenesCapas.png";
            comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ListaImagenesCapas.png";
            graficar(path, cabeceraOtros, comandoDot, comandoAbrir);
            cabeceraOtros = "digraph{\nnode[shape = record;]\n";
            break;
        case 7:
            cout << LI -> recorrer() << endl;
            cout << "Seleccione una Imagen" << endl;
            cin >> codigo;
            img = LI -> buscar(codigo);
            if(img)
            {
                cabeceraOtros += LI -> graficaImagenArbol(codigo);
                cabeceraOtros += ABB -> preOrdenGrafica(ABB -> root) + "\n}";
                path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ImagenCapasArbol.dot";
                comandoDot = "dot -Tpng " + path + " -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ImagenCapasArbol.png";
                comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\ImagenCapasArbol.png";
                graficar(path, cabeceraOtros, comandoDot, comandoAbrir);
                cabeceraOtros = "digraph{\nnode[shape = record;]\n";
            }
            else
            {
                cout << "La imagen no existe" << endl;
            }
            break;
        case 8:
            cout << ABB -> preOrden(ABB -> root) << endl;
            cout << "Seleccione una capa" << endl;
            cin >> codigo;
            capa = ABB -> existe(ABB -> root, codigo);
            if(capa)
            {
                cabeceraMatriz = capa -> matriz -> imprimirLogico();
                path = "C:\\Users\\USER\\Desktop\\Archivos\\Salida\\CapaLogica.neato";
                comandoDot = "neato -Tpng " + path + " -o C:\\Users\\USER\\Desktop\\Archivos\\Salida\\CapaLogica.png";
                comandoAbrir = "start C:\\Users\\USER\\Desktop\\Archivos\\Salida\\CapaLogica.png";
                graficar(path, cabeceraMatriz, comandoDot, comandoAbrir);
            }
            else
            {
                cout << "La capa no existe" << endl;
            }
            break;
        case 9:
            break;
        default:
            break;
        }
    }
}

void Menu()
{
    int opcion = 0;
    while (opcion != 5)
    {
        cout << "***********************" << endl;
        cout << "****Menu  Principal****" << endl;
        cout << "***********************" << endl;
        cout << "1. Menu de Usuarios" << endl;
        cout << "2. Menu de Reportes" << endl;
        cout << "3. Generar Imagenes" << endl;
        cout << "4. Generar Grafica de Estructuras" << endl;
        cout << "5. Salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            MenuUsuarios();
            break;
        case 2:
            MenuReportes();
            break;
        case 3:
            GenerarImagenes();
            break;
        case 4:
            GraficarEstructuras();
            break;
        case 5:
            exit(0);
            break;
        default:
            break;
        }
    }
}

void CargaArchivos()
{
    cout << "***********************" << endl;
    cout << "***Carga de Archivos***" << endl;
    cout << "***********************" << endl;
    cout << "Ingrese Archivo de Capas" << endl;
    cin >> pathCapas;
    ProcesarArchivos(pathCapas, 0);
    cout << "Ingrese Archivo de Imagenes" << endl;
    cin >> pathImagenes;
    ProcesarArchivos(pathImagenes, 1);
    cout << "Ingrese Archivo de Usuarios" << endl;
    cin >> pathUsuarios;
    ProcesarArchivos(pathUsuarios, 2);
    Menu();
}

int main(int argc, char** argv)
{
    CargaArchivos();
    return 0;
}
