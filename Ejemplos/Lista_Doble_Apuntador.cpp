#include <iostream>
#include <string>
using namespace std;

struct nodo{
    string dato;
    nodo *siguiente, *anterior;

    nodo(string dato){
        this->dato = dato;
        this->siguiente= this->anterior = nullptr;
    }
};

//Nodos para la lista con punteros dobles
nodo * primero, *ultimo;

nodo * buscar(nodo *p, string dato){
    nodo * temp = p;
    while(temp!=nullptr){
        if(temp->dato.compare(dato)==0){
            return temp;
        }
        temp = temp->siguiente;
    }
    return nullptr;
}

nodo * insertar(nodo ** p, string dato){
    nodo *aux = buscar(*p,dato);
    if(aux!=nullptr){
        return aux;
    }else{
        nodo * nuevo = new nodo(dato);
        if(*p != nullptr){
            nuevo->siguiente= *p;
            (*p)->anterior = nuevo;
        }
        *p = nuevo;
        return *p;
    }
}
void imprimir(nodo *p){
    nodo *aux = p;
    while(aux!=nullptr){
        printf(" Nodo: %s\n",aux->dato.c_str());
        aux = aux->siguiente;
    }
}

int main()
{
    nodo *lista_dp = nullptr;
    lista_dp = insertar(&lista_dp, "1");
    lista_dp = insertar(&lista_dp, "2");
    lista_dp = insertar(&lista_dp, "3");
    lista_dp = insertar(&lista_dp, "4");

    imprimir(lista_dp);
    return 0;
}
