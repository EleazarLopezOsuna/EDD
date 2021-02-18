/*var http = require('http');
var server = http.createServer(function (request, response){
    response.writeHead(200, {"Content-type": "text/plain"});
    response.end("Hello World\n");
});

server.listen(7000);*/
const express = require('express');
const app     = express();

app.use(express.static('archivos'));
app.listen(7000);