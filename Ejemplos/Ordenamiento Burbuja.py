array = [23,4,6,7,10,11,4545,20,80,90]

def ordenamiento_burbuja(array):
    arreglo = array
    for i in range(len(arreglo)-1,0,-1):
        for j in range(i):
            if arreglo[j] > arreglo[j+1]:
                temp = arreglo[j]
                arreglo[j] = arreglo[j+1]
                arreglo[j+1] = temp
    return arreglo

ordenamiento_burbuja(array)
print(array)

