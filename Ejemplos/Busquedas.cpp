#include <iostream>
#define length(x) (sizeof(x)/sizeof(x[0]))

using namespace std;
int arreglo [] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16};
int arreglo2[] = {23,4,6,7,10,11,4545,20,80,90};

int busqueda_binaria(int arreglo[],int busqueda, int izquierda, int derecha){
    if(izquierda> derecha){ return -1;}
    int mitad = int((izquierda + derecha)/1);
    int valor = arreglo[mitad];
    if (busqueda==valor){
        return mitad;
    }
    if(busqueda < valor){
        derecha = mitad -1;
    }else{
        izquierda = mitad +1;
    }
    return busqueda_binaria(arreglo, busqueda, izquierda, derecha);
}

int busqueda_secuencial(int arreglo2[], int apuntador, int busqueda, int tamano){
    if(apuntador < tamano ){
        if (arreglo2[apuntador] == busqueda){
            return apuntador;
        }
        return busqueda_secuencial(arreglo2, apuntador+1, busqueda, tamano);
    }
    return -1;
}

int main()
{
    cout << busqueda_binaria(arreglo, 12, 0, length(arreglo)) << endl;
    cout << busqueda_secuencial(arreglo2, 0,4545, length(arreglo2)) << endl;
    return 0;
}
