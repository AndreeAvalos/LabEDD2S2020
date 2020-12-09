class nodo:
    def __init__(self, valor, x =None, y = None):
        self.x = x
        self.y = y
        self.valor = valor
        self.derecho = self.izquierdo = self.arriba = self.abajo = None
        self.siguiente = self.anterior = None

class lista:
    def __init__(self):
        self.raiz = self.ultimo = None

    def insertar(self, valor):
        nuevo = nodo(valor)
        if self.raiz == None:
            self.raiz = self.ultimo = nuevo
        else:
            self.ordenar(nuevo)
    
    def ordenar(self, nodo):
        aux = self.raiz

        while(aux!=None):
            if aux.valor < nodo.valor:
                aux = aux.siguiente
            else:
                if aux == self.raiz:
                    nodo.siguiente = aux
                    aux.anterior = nodo
                    self.raiz = nodo
                    return
                else:
                    nodo.anterior = aux.anterior
                    aux.anterior.siguiente = nodo
                    nodo.siguiente = aux
                    aux.anterior = nodo
                    return
            self.ultimo.siguiente = nodo
            nodo.anterior = self.ultimo
            self.ultimo = nodo
    
    def search(self, valor):
        temp = self.raiz
        while(temp != None):
            if temp.valor == valor:
                return temp
            temp = temp.siguiente
        return None

    def print(self):
        temp = self.raiz
        while(temp!=None):
            print("Cabecera:", temp.valor)
            temp = temp.siguiente
    
class matriz:
    def __init__(self):
        self.lista_horizontal = lista()
        self.lista_vertical = lista()
    
    def insertar(self, valor, x, y):
        horizontal = self.lista_horizontal.search(x)
        vertical = self.lista_vertical.search(y)

        if horizontal == None and vertical == None:
            self.Caso1(valor, x, y)
        elif horizontal == None and vertical != None:
            self.Caso2(valor, x, y)
        elif horizontal != None and vertical == None:
            self.Caso3(valor, x, y)
        else:
            self.Caso4(valor, x, y)

    def Caso1(self, valor, x, y):
        self.lista_horizontal.insertar(x)
        self.lista_vertical.insertar(y)

        horizontal = self.lista_horizontal.search(x)
        vertical = self.lista_vertical.search(y)
        
        nuevo = nodo(valor, x, y)
        horizontal.abajo = nuevo
        nuevo.arriba = horizontal

        vertical.derecho = nuevo
        nuevo.izquierdo = vertical

    def Caso2(self, valor, x, y):
        self.lista_horizontal.insertar(x)

        horizontal = self.lista_horizontal.search(x)
        vertical = self.lista_vertical.search(y)

        agregado = False

        nuevo = nodo(valor, x, y)
        aux = vertical.derecho
        cabecera = 0

        while(aux!= None):
            cabecera = aux.x
            if cabecera < x:
                aux = aux.derecho
            else:
                nuevo.derecho = aux
                nuevo.izquierdo = aux.izquierdo
                aux.izquierdo.derecho = nuevo
                aux.izquierdo = nuevo
                agregado = True
                break
        if agregado == False:
            aux = vertical.derecho
            while(aux.derecho!=None):
                aux = aux.derecho
            nuevo.izquierdo = aux
            aux.derecho = nuevo
        
        horizontal.abajo = nuevo
        nuevo.arriba = horizontal

    def Caso3(self, valor, x, y):
        self.lista_vertical.insertar(y)

        horizontal = self.lista_horizontal.search(x)
        vertical = self.lista_vertical.search(y)

        agregado = False

        nuevo = nodo(valor, x, y)
        aux = horizontal.abajo
        cabecera = 0

        while(aux!= None):
            cabecera = aux.y
            if cabecera < y:
                aux = aux.abajo
            else:
                nuevo.abajo = aux
                nuevo.arriba = aux.arriba
                aux.arriba.abajo = nuevo
                aux.arriba = nuevo
                agregado = True
                break
        if agregado == False:
            aux = horizontal.abajo
            while(aux.abajo!=None):
                aux = aux.abajo
            nuevo.arriba = aux
            aux.abajo = nuevo
        
        vertical.derecho = nuevo
        nuevo.izquierdo = vertical

    def Caso4(self, valor, x, y):
        horizontal = self.lista_horizontal.search(x)
        vertical = self.lista_vertical.search(y)

        nuevo = nodo(valor, x, y)
        
        agregado = False
        aux = horizontal.abajo

        while(aux!= None):
            cabecera = aux.y
            if cabecera < y:
                aux = aux.abajo
            else:
                nuevo.abajo = aux
                nuevo.arriba = aux.arriba
                aux.arriba.abajo = nuevo
                aux.arriba = nuevo
                agregado = True
                break
        if agregado == False:
            aux = horizontal.abajo
            while(aux.abajo!=None):
                aux = aux.abajo
            nuevo.arriba = aux
            aux.abajo = nuevo
        agregado = False
        aux = vertical.derecho
        cabecera = 0

        while(aux!= None):
            cabecera = aux.x
            if cabecera < x:
                aux = aux.derecho
            else:
                nuevo.derecho = aux
                nuevo.izquierdo = aux.izquierdo
                aux.izquierdo.derecho = nuevo
                aux.izquierdo = nuevo
                agregado = True
                break
        if agregado == False:
            aux = vertical.derecho
            while(aux.derecho!=None):
                aux = aux.derecho
            nuevo.izquierdo = aux
            aux.derecho = nuevo
        

    def imprimir_horizontal(self):
        cabecera = self.lista_horizontal.raiz
        while(cabecera != None):
            aux = cabecera.abajo
            while(aux != None):
                print(aux.valor, aux.x, aux.y)
                aux= aux.abajo
            cabecera = cabecera.siguiente

    def imprimir_vertical(self):
        cabecera = self.lista_vertical.raiz
        while(cabecera!=None):
            aux = cabecera.derecho
            while(aux!= None):
                print(aux.valor, aux.x, aux.y)
                aux = aux.derecho
            cabecera = cabecera.siguiente


matriz = matriz()



matriz.insertar(1, 0,0)
matriz.insertar(2, 0,1)
matriz.insertar(3, 1,0)
matriz.insertar(4, 1,1)
print("Cabeceras")
matriz.lista_horizontal.print()
matriz.lista_vertical.print()

print("Se imprime de forma horizontal")
matriz.imprimir_horizontal()
print("Se imprime de forma vertical")
matriz.imprimir_vertical()
