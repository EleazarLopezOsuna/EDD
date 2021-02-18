function httpPost1(url,obj,callback){
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("POST",url,true);
    xmlHttp.setRequestHeader('Content-Type','application/json');
    xmlHttp.onreadystatechange = function(){
        if(xmlHttp.readyState == 4 && xmlHttp.status == 200)
            callback(xmlHttp.responseText);
    }
    xmlHttp.send(obj);
}

function httpGet(url){
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("GET",url,true);
    xmlHttp.setRequestHeader('Content-Type','application/json');
    xmlHttp.onreadystatechange = function(){
        if(xmlHttp.readyState == 4 && xmlHttp.status == 200)
            callback(xmlHttp.responseText);
    }
    xmlHttp.send();
}

function httpPost(url,obj){
    var xmlHttp = new XMLHttpRequest();
    xmlHttp.open("POST",url,false);
    xmlHttp.setRequestHeader('Content-Type','application/json');
    xmlHttp.onreadystatechange = function(){
        if(xmlHttp.readyState == 4 && xmlHttp.status == 200)
            callback(xmlHttp.responseText);
    }
    xmlHttp.send(obj);
}