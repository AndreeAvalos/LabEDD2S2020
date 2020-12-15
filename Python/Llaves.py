class Tabla:
    def __init__(self, nombre):
        self.nombre = nombre #Nombre de tabla 
        self.pks = [] #Lista de llaves primarias
        self.fks = [] #Lista de llaves foraneas
        self.diccionario = {} #Estructura donde se guardan Ej:(AVL, B, B+, Hash, ISAM)
        self.auto = 0 #autoincremental cuando no existan llaves primarias

    def alterAddPK(self, lst):
        self.pks = lst

    def search(self, pks):
        indice = ""
        for i in pks:
            indice = i + "," + indice
        
        if indice in self.diccionario:
            return self.diccionario[indice]
        else:
            return None

    def insertar(self, tupla):
        #Ver si la lista de primarias esta vacia
        if len(self.pks) != 0:
            identificador = ""
            for key in self.pks:
                identificador = tupla[key] + "," + identificador
            
            if identificador in self.diccionario:
                return 1
            else:
                self.diccionario[identificador] = tupla


        else:
            self.diccionario[self.auto] = tupla
            self.auto += 1

        return 0

    def print(self):
        print("Nombre Tabla:",self.nombre)
        print("LLaves primarias------")
        for i in self.pks:
            print("Indices", i)

        print("Valores-----")
        for i in self.diccionario:
            print("ID:", i, [j for j in self.diccionario[i]])


t1 = Tabla("tabla 1")
t1.alterAddPK([0])
t1.insertar(["uno","Andree",2020])
t1.insertar(["dos","Carlos", 2021])
t1.print()
print("Resultados de busquedas")

print(t1.search(["dos"]))
print(t1.search(["tres"]))



    