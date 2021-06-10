function busqueda_secuencial(array, pivote, dato) {
    if (pivote < array.length) {
        if (array[pivote] == dato) {
            return pivote;
        }
        return busqueda_secuencial(array, pivote + 1, dato);
    }
    return -1;
}

function busqueda_binaria(array, dato, izq, der) {
    if (izq > der) {
        return -1;
    }
    var medio = parseInt((izq + der) / 2);
    var valor_medio = array[medio];

    if (valor_medio == dato) return medio;

    if (valor_medio > dato) {
        der = medio - 1;
    } else {
        izq = medio + 1;
    }
    return busqueda_binaria(array, dato, izq, der);
}

module.exports = {
    busqueda_secuencial,
    busqueda_binaria
}
