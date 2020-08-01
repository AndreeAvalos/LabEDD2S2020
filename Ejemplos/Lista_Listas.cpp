#include <iostream>
#include <string>

using namespace std;

struct nodo{
    int asiento;//asiento asignado a cada pasajero
    string name;//
    nodo *siguiente, *anterior;
    nodo(int asiento, string nombre){
        this->asiento = asiento;
        this->name = nombre;
        this->siguiente = this->anterior = nullptr;
    }
};

struct lista{
    nodo *raiz, *ultimo;//apuntadores de la lista
    int correlativo;//numero de asiento

    //constructor de struct
    lista(){
        this->raiz=this->ultimo = nullptr;
        this->correlativo = 1;
    }

    void add(string nombre){
        nodo *nuevo = new nodo(correlativo, nombre);// creamos un nuevo nodo con los datos que ingresan
        correlativo++;//aumentamos el correlativo que representa el numero de asiento
        if(this->raiz == nullptr){
            this->raiz = this->ultimo = nuevo;
            return;
        }else{
            this->ultimo->siguiente = nuevo;
            nuevo->anterior = this->ultimo;
            ultimo = nuevo;
            return;
        }
    }
    void print(){
        nodo *aux = this->raiz;
        while(aux!=nullptr){
            printf("Numero de asiento: %d, Pasajero: %s\n",aux->asiento, aux->name.c_str());
            aux = aux->siguiente;
        }
    }
    void inverse_print(){
        nodo *aux = this->ultimo;
        while(aux!=nullptr){
            printf("Numero de asiento: %d, Pasajero: %s\n",aux->asiento, aux->name.c_str());
            aux = aux->anterior;
        }
    }
};

struct nodoL{
    string nombre;//nombre de aeronave
    lista *lst;//lista de pasajeros
    nodoL *siguiente, *anterior;//siguiente y anterior aeronave

    nodoL(string nombre){
        this->nombre = nombre;
        this->lst = new lista();
        this->siguiente = this->anterior = nullptr;
    }
};

struct lista_listas{
    nodoL *raiz, *ultimo;
    lista_listas(){
        this->raiz = this->ultimo = nullptr;
    }

    bool search(string name){
        nodoL * aux = this->raiz;
        while(aux!=nullptr){
            if (aux->nombre.compare(name)==0){
                return true;
            }
            aux = aux->siguiente;
        }
        return false;
    }

    void add(string aeronave, string pasajero ){
        if (this->raiz == nullptr){
            this->raiz = this->ultimo = new nodoL(aeronave);
            this->raiz->lst->add(pasajero);
            return ;
        }else{
            //comparamos el valor para saber si existe la aeronave en la lista
            if(this->search(aeronave)==false){
                nodoL *nuevo = new nodoL(aeronave);// creamos un nuevo nodo para la lista de aeronaves
                nuevo->lst->add(pasajero);//ingresamos el primer pasajero de la lista
                this->ultimo->siguiente = nuevo;
                nuevo->anterior = this->ultimo;
                this->ultimo = nuevo;
                return;
            }else{
                nodoL *temp = this->get(aeronave);
                temp->lst->add(pasajero);
                return;
            }
        }
    }

    //metodo que retorna el nodo que hace match con el nombre que ingresa
    nodoL * get(string name){
        nodoL * aux = this->raiz;
        while(aux!=nullptr){
            if (aux->nombre.compare(name)==0){
                return aux;
            }
            aux = aux->siguiente;
        }
        return nullptr;
    }
    void print(){
        nodoL *aux = this->raiz;
        while(aux!=nullptr){
            printf("----------------Aeronave:%s------------\n",aux->nombre.c_str());
            aux->lst->print();
            aux = aux->siguiente;
        }
    }
};

int main()
{
    /*
    lista *lst = new lista();
    lst->add("Luis");
    lst->add("Andree");
    lst->add("Marvin");
    lst->add("Juan");
    printf("Se debe imprimir de primero-ultimo\n");
    lst->print();
    printf("Se debe imprimir de ultimo-primero\n");
    lst->inverse_print();
    */

    lista_listas *lst = new lista_listas();
    lst->add("Avion 1", "Carlos");
    lst->add("Avion 1", "Andree");
    lst->add("Avion 1", "Marvin");
    lst->add("Avion 1", "Juan");
    lst->add("Avion 2", "Marlon");
    lst->add("Avion 2", "Antonio");
    lst->print();


    return 0;
}
