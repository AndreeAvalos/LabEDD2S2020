import abb as abb2

class nodo:
    def __init__(self, indice,valor):
        self.diccionario = valor
        self.index = indice
        self.izquierdo = self.derecho = None        

class abb:
    def __init__(self):
        self.raiz = None

    def add(self, index, tupla):
        self.raiz = self.__add(index, tupla, self.raiz)

    def __add(self, index, tupla, raiz):
        if raiz == None:
            return nodo(index, tupla)
        else:
            if index == raiz.index:
                for key in tupla:
                    raiz.diccionario[key] = tupla[key]
            elif index > raiz.index:
                raiz.derecho = self.__add(index, tupla, raiz.derecho)
            else:
                raiz.izquierdo = self.__add(index, tupla, raiz.izquierdo)
        return raiz
    
    def pre_orden(self):
        self.__pre(self.raiz)
    
    def __pre(self, raiz):
        if raiz:
            print("Indice:", raiz.index, "Diccionario:", raiz.diccionario)
            self.__pre(raiz.izquierdo)
            self.__pre(raiz.derecho)

    def in_orden(self):
        self.__in(self.raiz)
    def __in(self, raiz):
        if raiz: 
            self.__in(raiz.izquierdo)
            print("Indice:", raiz.index, "Diccionario:", raiz.diccionario)
            self.__in(raiz.derecho)

    def post_orden(self):
        self.__post(self.raiz)
    def __post(self, raiz):
        if raiz: 
            self.__post(raiz.izquierdo)
            self.__post(raiz.derecho)
            print("Indice:", raiz.index, "Diccionario:", raiz.diccionario)


'''dic = {1:"hola", 2:"que tal", 3:"clase 4"}
busqueda = abb()
busqueda.add(10,dic)
busqueda.add(10,{5:"nuevo dato"})
busqueda.add(11,{1:"nuevo indice"})
busqueda.add(6, {1: "Indice menor"})
print("Pre-Orden")
busqueda.pre_orden()
print("In-Orden")
busqueda.in_orden()
print("Post-Orden")
busqueda.post_orden()'''
