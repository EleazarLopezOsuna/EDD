//POST
const p_IngresarUsuario = "http://localhost:8080/edd/webapi/Usuarios/Ingresar";
const p_IngresarPais = "http://localhost:8080/edd/webapi/Destinos/Ingresar";
const p_IngresarRuta = "http://localhost:8080/edd/webapi/Rutas/Ingresar";
const p_IngresarTabla = "http://localhost:8080/edd/webapi/Vuelos/Ingresar";
const p_IngresarFactura = "http://localhost:8080/edd/webapi/Facturas/Ingresar";
const p_Login = "http://localhost:8080/edd/webapi/Login/Ingresar";


//GET
const p_RecorrerUsuario = "http://localhost:8080/edd/webapi/Usuarios/Recorrer";
const p_BuscarUsuario = "http://localhost:8080/edd/webapi/Usuarios/Buscar/"; //Falta agregar el codigo
const p_RecorrerPais = "http://localhost:8080/edd/webapi/Destinos/Recorrer";
const p_BuscarPais = "http://localhost:8080/edd/webapi/Destinos/Buscar/"; //Falta agregar el codigo
const p_RecorrerRuta = "http://localhost:8080/edd/webapi/Rutas/Recorrer";
const p_RecorrerTabla = "http://localhost:8080/edd/webapi/Vuelos/Recorrer";
const p_RecorrerFactura = "http://localhost:8080/edd/webapi/Facturas/Recorrer";
const p_GraficarRutaCorta = "http://localhost:8080/edd/webapi/Rutas/ObtenerRutas/";//Falta agregar los codigos
/*
*   Falta agregar /n1/n2/n3/n4
*   n1 = opcion para elegir ruta corta o completa, Corta = 0, Completa = 1
*   n2 = codigo Salida
*   n3 = codigo llegada
*   n4 = opcion para elegir que ruta tomar, Tiempo = 0, Costo = 1
*/
const p_IngresarRutaNombre = "http://localhost:8080/edd/webapi/Rutas/IngresarNombre";
/*
* Falta agregar /s1/s2/n1/n2
*   s1 = nombre pais salida
*   s2 = nombre pais llegada
*   n1 = costo
*   n2 = tiempo
*/