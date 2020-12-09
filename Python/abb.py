class nodo:
    def __init__(self, val):
        self.valor = val
        self.izq = self.der = None

class abb:
    def __init__(self):
        self.raiz = None

    def add(self, valor):
        self.raiz = self.__add(valor, self.raiz)
    
    def __add(self, valor, raiz):
        if raiz == None:
            return  nodo(valor)
        else:
            if valor > raiz.valor:
                raiz.der = self.__add(valor, raiz.der)
            else:
                raiz.izq = self.__add(valor, raiz.izq)
        return raiz
    
    def pre_orden(self):
        self.__pre(self.raiz)
    def __pre(self, raiz):
        if raiz:
            print("Valor:", raiz.valor)
            self.__pre(raiz.izq)
            self.__pre(raiz.der)

    def in_orden(self):
        self.__in(self.raiz)
    def __in(self,raiz):
        if raiz:
            self.__in(raiz.izq)
            print("Valor:", raiz.valor)
            self.__in(raiz.der)
    def post_orden(self):
        self.__post(self.raiz)
    def __post(self, raiz):
        if raiz:
            self.__post(raiz.izq)
            self.__post(raiz.der)
            print("Valor:", raiz.valor)

arbol_binario = abb()
arbol_binario.add(10)
arbol_binario.add(11)
arbol_binario.add(7)
arbol_binario.add(67)
arbol_binario.add(8)
arbol_binario.add(51)
arbol_binario.add(2)
arbol_binario.add(3)

print("Recorrido Pre-Orden")
arbol_binario.pre_orden()
print("Recorrido In-Orden")
arbol_binario.in_orden()
print("Recorrido Post-Orden")
arbol_binario.post_orden()