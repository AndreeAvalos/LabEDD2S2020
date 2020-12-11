class Tipo:
    def __init__(self, tipo):
        self.tipo = tipo
class Tipo2:
    def __init__(self, tipo):
        self.tipo2 = tipo
class Animal:
    def __init__(self, nombre, sonido, color, habitat):
        self.nombre = nombre
        self.sonido = sonido
        self.color = color
        self.habitat = habitat
        self.atributo1 = True
    
    def Reporte(self):
        print("Nombre:", self.nombre, "Sonido:", self.sonido, "Color:",self.color, "Habitad:", self.habitat)
    
    def generarSonido(self):
        print(self.sonido)

class Perro(Animal, Tipo, Tipo2):
    def __init__(self, color, habitat):
        Animal.__init__(self, "Perro", "Sonido1", color,habitat)
        Tipo.__init__(self, "Canino")
        Tipo2.__init__(self, "Mamifero")
    
    def mover(self):
        print("Agito la cola")
    
    def generarSonido(self):
        print("GUAU")

class Gato(Animal):
    def __init__(self, color, habitat):
        Animal.__init__(self, "Gato", "Sonido2", color, habitat)

    def acariciar(self):
        print("Le gusto al gato")


perro1 = Perro("Azul","Domestico")
gato1 = Gato("Gris","Rural")

perro1.Reporte()
perro1.generarSonido()
print(perro1.tipo, perro1.tipo2 )
print(perro1.atributo1)

gato1.Reporte()
gato1.generarSonido()
