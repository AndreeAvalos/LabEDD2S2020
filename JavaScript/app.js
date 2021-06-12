// var express = require('express');
// var app = require('./routes');
// var http = require('http');
//
// app.use(express.json());
// app.use(express.urlencoded({ extended: false }));
// app.locals.policiesList = {};
// app.locals.automaticPDF = {};
//
//
// var port = 3000;
// app.set('port',port);
//
// var server = http.createServer(app);
//
// server.listen(port);
// server.on('error', onError);
// server.on('listening', onListening);
//
// function normalizePort(val) {
//     var port = parseInt(val, 10);
//
//     if (isNaN(port)) {
//         return val;
//     }
//
//     if (port >= 0) {
//         return port;
//     }
//
//     return false;
// }
//
// function onError(error) {
//     if (error.syscall !== 'listen') {
//         throw error;
//     }
//
//     var bind = typeof port === 'string'
//         ? 'Pipe ' + port
//         : 'Port ' + port;
//
//     switch (error.code) {
//         case 'EACCES':
//             console.error(bind + ' requiere mas permisos');
//             process.exit(1);
//             break;
//         case 'EADDRINUSE':
//             console.error(bind + ' esta en uso');
//             process.exit(1);
//             break;
//         default:
//             throw error;
//     }
// }
//
// function onListening() {
//     var addr = server.address();
//     var bind = typeof addr === 'string'
//         ? 'pipe ' + addr
//         : 'port ' + addr.port;
//
//     console.log("Servidor: ",bind);
// }
//
// let array = [1,2,3,4,5,6,7,8,9,10,11]
//
//
// var busqueda = require('./structure/busquedas');
//
// var indice = busqueda.busqueda_secuencial(array, 0, 9);
//
// if(indice != -1){
//     console.log("El valor en la busqueda secuencial en la posicion:", indice, "es de:",array[indice]);
// }else{
//     console.log("No se encontro el valor en el arreglo por busqueda secuencial");
// }
// indice = busqueda.busqueda_binaria(array,11,0,array.length);
//
// console.log("----------")
// if(indice != -1){
//     console.log("El valor en la busqueda binaria en la posicion:", indice, "es de:",array[indice]);
// }else{
//     console.log("No se encontro el valor en el arreglo por busqueda binaria");
// }

// var ordenamiento = require('./structure/ordenamiento')
//
// var array = [3, 5, 1, 4, 2, 6]
//
//
// var result = ordenamiento.ordenamiento_burbuja(array);
//
// console.log("Desordenado", array);
// console.log("Ordenado", result);

//
// var Matriz = require('./structure/matriz');
//
// let matriz = new Matriz();
//
// matriz.insertar(0,0,0);
// matriz.insertar(1,1,0);
// matriz.insertar(2,1,1);
// matriz.insertar(3,2,1);
// matriz.insertar(4,2,2);
// matriz.insertar(5,2,3);
// matriz.insertar(6,2,4);
// matriz.insertar(7,2,5);
// matriz.insertar(8,3,1);
// matriz.insertar(9,5,3);
// matriz.insertar(10,5,5);
//
//
// matriz.imprimir_horizontal();
// console.log("----------------------");
// matriz.imprimir_vertical();

// var AVL = require('./structure/avl');
//
// var avl = new AVL();
//
// avl.insertar(1);
// avl.insertar(2);
// avl.insertar(3);
// avl.insertar(4);
// avl.insertar(5);
// avl.insertar(6);
// avl.insertar(7);
// avl.insertar(8);
// avl.insertar(9);
// avl.insertar(10);
// avl.insertar(11);
// avl.preOrden();
//
// console.log("---ABB----");
// var ABB = require('./structure/abb');
//
// var abb = new ABB();
//
// abb.insertar(1);
// abb.insertar(2);
// abb.insertar(3);
// abb.insertar(4);
// abb.insertar(5);
// abb.insertar(6);
// abb.insertar(7);
// abb.insertar(8);
// abb.insertar(9);
// abb.insertar(10);
// abb.insertar(11);
// abb.preOrden();

const arbolB = require('./structure/arbolb')
let b = new arbolB(5);

b.insertar(10);
b.insertar(11);
b.insertar(12);
b.insertar(13);
b.insertar(14);
b.insertar(15);
b.insertar(16);
b.insertar(17);

b.print();

