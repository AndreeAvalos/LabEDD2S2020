#include <iostream>
#include <string>
#include <fstream>

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
    void graficar(){
        ofstream file;
        file.open("./list_of_list.dot");
        file << "digraph{\n";
        //recorremos la lista global para crear nodos
        nodoL *vertical = raiz;
        int contador = 0;
        while(vertical!=nullptr){
            file << "\""<< vertical->nombre.c_str()<<"\"[shape=box,rankdir=UD, style =\"filled\"; label=\""<< vertical->nombre.c_str()<<"\";pos=\"0,-"<< to_string(contador)<<"!\"" << "]\n";
            //Recorremos la lista interna de la lista global para crear nodos
            nodo *horizontal = vertical->lst->raiz;
            int contador2 = 0;
            while(horizontal!=nullptr){
                 file << "\""<< horizontal->name.c_str()<<"\"[shape=box,rankdir=LR ,style =\"filled\"; label=\""<< horizontal->name.c_str()<<"\";pos=\""<< to_string(contador2)<<",-"<<to_string(contador)<<"!\""<<"]\n";
                 contador2++;
                 horizontal = horizontal->siguiente;
            }
            contador++;
            vertical = vertical->siguiente;
        }
        //Enlazar nodos verticales
        vertical = raiz;
        while(vertical!=nullptr){
            if(vertical==raiz){
                file << "\""<<vertical->nombre.c_str()<<"\"";
            }else{
                file << "->\""<<vertical->nombre.c_str()<<"\"";
            }
            vertical = vertical->siguiente;
        }
        file <<"\n";
        //enlazamos nodos horizontales
        vertical = raiz;
        while(vertical!=nullptr){
            nodo *horizontal = vertical->lst->raiz;
            if(horizontal!=nullptr){
                file << "\""<<vertical->nombre.c_str()<<"\"->\""<<horizontal->name.c_str()<<"\"\n";
                while(horizontal!=nullptr){
                    if(horizontal==vertical->lst->raiz){
                        file<<"\""<<horizontal->name.c_str()<<"\"";
                    }else{
                        file<<"->\""<<horizontal->name.c_str()<<"\"";
                    }
                    horizontal = horizontal->siguiente;
                }
            }
            file <<"\n";
            vertical = vertical->siguiente;
        }
        file << "}\n";
        file.close();
        system("dot -Tpng ./list_of_list.dot -o ./list_of_list.png");
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
    lst->add("Avion 3", "Everest");
    lst->add("Avion 3", "Sergio");
    lst->add("Avion 3", "Miguel");
    lst->add("Avion 3", "Sara");
    lst->add("Avion 3", "Maria");
    lst->print();
    lst->graficar();


    return 0;
}
