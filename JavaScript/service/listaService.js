const Lista = require('../structure/simpleList');

const lst = new Lista();

module.exports = {
    add,
    print
}

function add(dato) {
    return new Promise(function (resolve, reject) {
        lst.add(dato.dato);
        console.log("Su fecha de ingreso fue", dato.fecha )
        resolve({status: 1, message: "OK", data: ""})
    })
}
function print(){
    return new Promise(function (resolve){
        let val = lst.print();
        resolve({status: 1, message: "OK", data: val})
    })
}
