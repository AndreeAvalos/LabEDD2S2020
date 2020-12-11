import Binarios

class Nodo:
    def __init__(self, valor):
        self.valor = valor
        self.altura = 0
        self.izq = self.der = None
    
class AVL:
    def __init__(self):
        self.raiz = None
    
    def MAX(self, val1, val2):
        if val1>val2:
            return val1
        else:
            return val2

    def insertar(self, valor):
        self.raiz = self.__insertar(valor, self.raiz)
    
    def __insertar(self, valor, raiz):
        if raiz == None:
            return Nodo(valor)
        else:
            if valor < raiz.valor:
                raiz.izq = self.__insertar(valor, raiz.izq)
                if(self.Altura(raiz.der) - self.Altura(raiz.izq) == -2):
                    if valor < raiz.izq.valor:
                        raiz = self.RI(raiz)
                    else:
                        raiz = self.RDI(raiz)
            elif valor > raiz.valor:
                raiz.der = self.__insertar(valor, raiz.der)
                if(self.Altura(raiz.der)- self.Altura(raiz.izq) == 2):
                    if valor > raiz.der.valor:
                        raiz = self.RD(raiz)
                    else:
                        raiz = self.RDD(raiz)
            else:
                raiz.valor = valor
        
        raiz.altura = self.MAX(self.Altura(raiz.izq), self.Altura(raiz.der))+1
        return raiz

    def Altura(self, nodo):
        if nodo != None:
            return nodo.altura
        return -1

    def RI(self, nodo):
        aux = nodo.izq
        nodo.izq = aux.der
        aux.der = nodo
        nodo.altura = self.MAX(self.Altura(nodo.der), self.Altura(nodo.izq))+1
        aux.altura = self.MAX(self.Altura(aux.izq), nodo.altura)+1
        return aux
    
    def RD(self, nodo):
        aux = nodo.der
        nodo.der = aux.izq
        aux.izq = nodo
        nodo.altura = self.MAX(self.Altura(nodo.der), self.Altura(nodo.izq))+1
        aux.altura = self.MAX(self.Altura(aux.der), nodo.altura)+1
        return aux

    def RDI(self, nodo):
        nodo.izq = self.RD(nodo.izq)
        return self.RI(nodo)
    
    def RDD(self, nodo):
        nodo.der = self.RI(nodo.der)
        return self.RD(nodo)

    def print(self):
        self.__in(self.raiz)
    
    def __in(self, nodo):
        if nodo:
            self.__in(nodo.izq)
            print("Valor:", nodo.valor)
            self.__in(nodo.der)


avl = AVL()
avl.insertar(1)
avl.insertar(2)
avl.insertar(3)
avl.insertar(4)
avl.insertar(5)
avl.insertar(6)
avl.insertar(7)

tablas = {"tabla1":"avl-clase6"}

Binarios.commit(tablas, "bd1")

temp = Binarios.rollback("bd1")

print(temp["tabla1"])
tabla1 = Binarios.rollback(temp["tabla1"])
print(tabla1[1])
tabla1[1].print()          