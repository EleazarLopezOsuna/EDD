function ini_sesion(){
    httpPost(p_login,getValueForm("loginform"),function(response){
        var result = JSON.parse(response);
        if(result.result == 'true'){
            window.location.href = "http://192.168.0.10:8080/index.html";
        }else{
        }
    });
}