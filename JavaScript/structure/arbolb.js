class Nodo {
    constructor(valor) {
        this.valor = valor;
        this.anterior = null;
        this.siguiente = null;
        this.derecho = null;
        this.izquierdo = null;
    }
}

class Rama {
    constructor() {
        this.contador = 0;//contador de elementos insertados
        this.hoja = true;//Si es hoja el nodo que vamos a insertar
        this.raiz = null;//El inicio de la lista
    }

    insertar(nodo) {
        if (this.raiz == null) {
            this.raiz = nodo;
            this.contador++;
        } else {
            let temp = this.raiz;
            do {
                if (nodo.valor <= temp.valor) {
                    this.contador++;
                    if (temp == this.raiz) {
                        this.raiz.anterior = nodo;
                        this.raiz.izquierdo = nodo.derecho;
                        this.raiz = nodo;
                        break;
                    } else {
                        nodo.anterior = temp.anterior;
                        nodo.siguiente = temp;
                        temp.anterior.siguiente = nodo;
                        temp.anterior.derecho = nodo.izquierdo;
                        temp.anterior = nodo;
                        temp.izquierdo = nodo.derecho;
                        break;
                    }
                } else if (temp.siguiente == null) {
                    this.contador++;
                    temp.siguiente = nodo;
                    temp.derecho = nodo.izquierdo;
                    nodo.anterior = temp;
                    nodo.siguiente = null;
                    break;
                }
                temp = temp.siguiente;
            }
            while (temp != null);
        }
    }

    print() {
        let result = "";
        let temp = this.raiz;
        let contador = 0;
        while (temp != null) {
            if (contador == 0) {
                result = temp.valor;
            } else {
                result += "|" + temp.valor;
            }
            temp = temp.siguiente;
        }
        return result;
    }
}

class ARBOLB {
    constructor(orden) {

        this.raiz = null;
        this.orden = orden;
    }

    insertar(valor) {
        let nodo = new Nodo(valor);
        if (this.raiz == null) {
            this.raiz = new Rama();
            this.raiz.insertar(nodo);
            return;
        } else {
            let temp = this.add(nodo, this.raiz);
            if (temp instanceof Nodo) {
                this.raiz = new Rama();
                this.raiz.insertar(temp);
                this.raiz.hoja = false;
            }

        }
    }

    add(nodo, rama) {
        if (rama.hoja) {
            rama.insertar(nodo);
            if (rama.contador == this.orden) {
                return this.dividirRama(rama);
            } else {
                return rama;
            }
        } else {
            let temp = rama.raiz;
            do {
                if (nodo.valor == temp.valor) {
                    return rama;
                } else if (nodo.valor < temp.valor) {
                    let aux = this.add(nodo, temp.izquierdo);
                    if (aux instanceof Nodo) {
                        rama.insertar(aux);
                        if (rama.contador == this.orden) {
                            return this.dividirRama(rama);
                        }
                    }
                    return rama

                } else if (temp.siguiente == null) {
                    let aux = this.add(nodo, temp.derecho);
                    if (aux instanceof Nodo) {
                        rama.insertar(aux);
                        if (rama.contador == this.orden) return this.dividirRama(rama);

                    }
                    return rama
                }
                temp = temp.siguiente;
            } while (temp != null);
        }
        return rama;
    }

    dividirRama(rama) {
        let derecha = new Rama();
        let izquierda = new Rama();
        let medio = null;
        let temp = rama.raiz;

        let inicio = 1;
        let valorMedio = parseInt(this.orden / 2) + 1;
        let final = this.orden;
        for (let i = 1; i < this.orden + 1; i++, temp = temp.siguiente) {
            let nodo = new Nodo(temp.valor);
            nodo.izquierdo = temp.izquierdo;
            nodo.derecho = temp.derecho;

            if (nodo.derecho != null && nodo.izquierdo != null) {
                izquierda.hoja = false;
                derecha.hoja = false;
            }

            if (i >= inicio && i < valorMedio) {
                izquierda.insertar(nodo);
            } else if (i == valorMedio) {
                medio = nodo;
            } else if (i <= final && i > valorMedio) {
                derecha.insertar(nodo);
            }
        }

        medio.izquierdo = izquierda;
        medio.derecho = derecha;
        return medio;
    }
}

module.exports = ARBOLB;
// export default ARBOLB;
