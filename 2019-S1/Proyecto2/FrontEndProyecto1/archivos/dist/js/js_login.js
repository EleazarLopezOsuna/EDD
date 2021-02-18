function ini_sesion(){
    httpPost1(p_Login,getValueForm("loginform"),function(response){
        var result = JSON.parse(response);
        if(result == true){
            window.location.href = "http://192.168.0.11:8081/index.html";
        }else{
            window.alert("ERROR, datos erroneos");
        }
    });
}

function cre_sesion(){
    httpPost1(p_IngresarUsuario,getValueForm("crearform"),function(response){
        var result = JSON.parse(response);
        if(result.result == "Ingresado"){
            window.location.href = "http://192.168.0.11:8081/index.html";
        }else{
            window.alert("ERROR, usuario duplicado");
        }
    });
}

function cre_ruta(){
    var r = "";
    var form = document.getElementById("rutaform");
    var elements = form.querySelectorAll( "input" );
    for(var i = 0; i < elements.length; ++i){
        var element = elements[i];
        var name = element.name;
        var value = element.value;
        if(name){
            r += "/" + value;
        }
    }
    console.log(p_IngresarRutaNombre+r);
    httpGet(p_IngresarRutaNombre+r);
}
