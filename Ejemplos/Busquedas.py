#tiene que ser un arreglo ordenado para la busqueda binaria
array = [1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16]

#para la busqueda secuencial no importa si esta ordenamiento o no 
array2 = [23,4,6,7,10,11,4545,20,80,90]


def busqueda_binaria(arreglo, busqueda, izquierda, derecha):
    if izquierda > derecha: return -1

    mitad = int((izquierda+ derecha)/2)
    valor_mitad = arreglo[mitad]

    if busqueda == valor_mitad:
        return mitad
    
    if busqueda< valor_mitad:
        derecha = mitad -1
    else:
        izquierda = mitad +1
    
    return busqueda_binaria(arreglo,busqueda,izquierda, derecha)

def busqueda_secuencial(arreglo, apuntador, busqueda):

    if apuntador< len(arreglo):

        if arreglo[apuntador] == busqueda:
            return apuntador

        return busqueda_secuencial(arreglo, apuntador + 1, busqueda)

    return -1


print("La posicion del numero 3 es: ", busqueda_binaria(array, 3, 0, len(array)))
print("La posicion del numero 11 es: ", busqueda_secuencial(array2, 0, 11))


