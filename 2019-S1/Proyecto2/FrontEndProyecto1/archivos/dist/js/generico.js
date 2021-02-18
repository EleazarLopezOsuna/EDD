function toJSONString(form){
    var obj = {};
    var elements = form.querySelectorAll( "input" );
    for(var i = 0; i < elements.length; ++i){
        var element = elements[i];
        var name = element.name;
        var value = element.value;
        if(name){
            obj[ name ] = value;
        }
    }
    return JSON.stringify( obj );
}

function getValueForm(id_form){
    var form = document.getElementById(id_form);
    var json = toJSONString(form);
    return json;
}