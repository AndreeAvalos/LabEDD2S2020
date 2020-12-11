class Automovil:
    def __init__(self, color, neumaticos, marca):
        self.color = color
        self.neumaticos = neumaticos
        self.marca = marca
    
    def Reporte(self):
        print("Color:", self.color, "Neumaticos:",self.neumaticos, "Marca:", self.marca)

class BMW(Automovil):
    def __init__(self, color, neumaticos, año):
        Automovil.__init__(self, color,neumaticos, "BMW")
        self.año = año
    
    def Año(self):
        print("Año:", self.año)
    
    #def Reporte(self):
    #    print("Color:", self.color, "Neumaticos:",self.neumaticos, "Marca:", self.marca, "Año:", self.año)
    
carro1 =BMW("Rojo", 4, 2020)
carro1.Reporte()
carro1.Año()