class Nodo:
    def __init__(self, indice, clave, valor):
        self.indice = indice
        self.clave = clave
        self.valor = valor

class Hash:
    def __init__(self, valor=7):
        self.vector = []
        self.elementos = 0
        self.factorCarga = 0
        self.tamano = valor

        for i in range(valor):
            self.vector.append(None)

    def insertar(self, id, clave, valor):
        posicion = self.funcion_hash(id)
        nuevo = Nodo(posicion, clave, valor)
        self.vector[posicion] = nuevo
        self.elementos+=1
        self.factorCarga = self.elementos/self.tamano

        if self.factorCarga > 0.6:
            self.rehashing()

    def rehashing(self):
        siguiente = self.tamano
        factor = 0
        while(factor < 0.3):
            factor = self.elementos/siguiente
            siguiente +=1
            
        temporal = []

        for i in range(siguiente):
            temporal.append(None)
        aux_vector = self.vector

        self.vector = temporal
        self.tamano = siguiente

        print("Nuevo tamano", siguiente, "Tamano:", len(temporal))
        for i in aux_vector:
            if i :
                posicion = self.funcion_hash(toASCII(i.clave))
                print("Nueva posicion:", posicion)
                i.indice = posicion
                temporal[posicion] = i

        self.vector = temporal
        

    def funcion_hash(self, id):
        
        posicion = id % (self.tamano -1) 
    
        while(self.vector[posicion]!=None):
           posicion += 1
           if posicion > self.tamano:
               posicion = posicion - self.tamano
        return posicion


    def print(self):
        contador = 0
        for i in self.vector:
            if i:
                print("indice:",contador, "valor:", i.valor )
            else:
                print("indice:", contador, "valor", i)

            contador+=1

def toASCII(cadena):
    result = 0
    for char in cadena:
        result += ord(char)
    return result




tabla = Hash(5)
tabla.insertar(toASCII("primero"),"primero","ocupado")
tabla.insertar(toASCII("casa"),"casa","colision")
tabla.insertar(toASCII("saca"),"saca","colision")
tabla.insertar(toASCII("saca1"),"saca1","colision")
tabla.insertar(toASCII("saca2"),"saca2","no hay colision")
tabla.insertar(toASCII("saca3"),"saca3","1")
tabla.print()
