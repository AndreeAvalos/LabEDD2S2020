class Nodo:
    def __init__(self, valor, lst= None):
        self.valor = valor
        self.lst = lst

class ISAM:
    def __init__(self):
        self.root = []
    
    def insertar(self, valor):
        self.root = self.__add(valor, self.root, 0)
    
    def __add(self, valor, pivote, nivel):
        if nivel < 3:
            if len(pivote)<3:
                pivote.append(Nodo(valor,[]))
                return self.sort(pivote)
            else:
                if valor < pivote[0].valor:
                    pivote[0].lst = self.sort(self.__add(valor, pivote[0].lst, nivel + 1))
                elif pivote[0].valor <= valor < pivote[1].valor:
                    pivote[1].lst = self.sort(self.__add(valor, pivote[1].lst, nivel + 1))
                else:
                   pivote[2].lst = self.sort(self.__add(valor, pivote[2].lst,nivel + 1))
                return pivote
        else:
            pivote.append(Nodo(valor, None))
            return pivote
            

    def sort(self, array):
        arreglo = array
        for i in range(len(arreglo)-1,0,-1):
            for j in range(i):
                if arreglo[j].valor > arreglo[j+1].valor:
                    temp = arreglo[j]
                    arreglo[j] = arreglo[j+1]
                    arreglo[j+1] = temp
        return arreglo

    def print(self):
        self.__print(self.root, "raiz")
    
    def __print(self, lst, padre):
        if lst:
            print("Padre:", padre, "hijos", [i.valor for i in lst])
            for i in lst:
                self.__print(i.lst, i.valor)
            


isam = ISAM()
isam.insertar(40)
isam.insertar(10)
isam.insertar(32)
isam.insertar(51)
isam.insertar(52)
isam.insertar(53)
isam.insertar(64)
isam.insertar(74)
isam.insertar(84)
isam.insertar(94)
isam.insertar(994)
isam.insertar(914)
isam.insertar(924)
isam.insertar(934)
isam.insertar(11)
isam.insertar(1)
isam.insertar(12)
isam.insertar(13)
isam.insertar(14)
isam.insertar(15)
isam.insertar(16)
isam.insertar(17)
isam.insertar(18)
isam.insertar(19)
isam.insertar(21)
isam.insertar(22)
isam.insertar(23)

isam.print()
