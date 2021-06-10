function ordenamiento_burbuja(array) {
    var arreglo = array.slice();

    for (var i = (arreglo.length - 1); i >= 0; i--) {
        for (var j = 0; j < i; j++) {
            if(arreglo[j]> arreglo[j+1]){
                var temp = arreglo[j];
                arreglo[j] = arreglo[j+1]
                arreglo[j+1] = temp;
            }
        }
    }
    return arreglo;
}

module.exports={
    ordenamiento_burbuja
}
