import json 


class bloque:
    def __init__(self, numero, data, anterior, hashid):
        self.id = numero
        self.data = data
        self.anterior = anterior
        self.hash = hashid

    def get(self):
        return [self.id, self.data, self.anterior, self.hash]


class blockchain:
    def __init__(self):
        self.id_bloques = 1
        self.anterior = 0000000000
        self.bloques = []

    def insertar(self, tablas):
        id_hash = self.id_bloques
        nuevo = bloque(self.id_bloques, tablas, self.anterior, id_hash)
        self.id_bloques +=1
        self.bloques.append(nuevo)
        file = open("bloques.json", "w+")
        file.write(json.dumps([j.get() for j in self.bloques]))
        self.anterior = id_hash
    
    def update(self, tabla, registro):
        file = open("bloques.json", "r")
        lista = json.loads(file.read())
        file.close()
        for bloque in lista:
            if registro == bloque[0]:
                bloque[1] = tabla
                bloque[3] = -1
        
        file = open("bloques.json", "w+")
        file.write(json.dumps(lista))
        file.close()
  

tabla = {1:"Andree", 2:"Avalos"}
tabla1 = {1:"Andree1", 2:"Avalos1"}
tabla2 = {1:"Andree2", 2:"Avalos3"}

bc = blockchain()
bc.insertar(tabla)
bc.insertar(tabla1)
bc.insertar(tabla2)

bc.update({1:"aaaa", 2:"ttt"},2)

