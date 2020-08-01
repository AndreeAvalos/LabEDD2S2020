#include <iostream>
#include <string>


using namespace std;

//Nodo simple
struct nodoSimple{
    string dato;
    nodoSimple *siguiente;

    nodoSimple(string dato){
        this->dato = dato;
        this->siguiente = nullptr;
    }
};

struct nodoDoble{
    string dato;
    nodoDoble *siguiente, *anterior;

    nodoDoble(string dato){
        this->dato = dato;
        this->siguiente=this->anterior=nullptr;
    }
};

struct ListaSimple{
    nodoSimple *raiz, *ultimo;
    int size;
    ListaSimple(){
        this->raiz=this->ultimo = nullptr;
        size = 0;
    }

    void add(string dato){
        nodoSimple *nuevo = new nodoSimple(dato);
        if(this->raiz==nullptr){
            this->raiz=this->ultimo = nuevo;
        }else{
            this->ultimo->siguiente = nuevo;
            this->ultimo = nuevo;
        }
        size++;
        return;
    }

    void print(){
        nodoSimple *aux = this->raiz;
        while(aux!=nullptr){
            printf("Dato: %s\n",aux->dato.c_str());
            aux = aux->siguiente;
        }
    }
};

struct ListaDoble{
    nodoDoble *raiz, *ultimo;
    int size;
    ListaDoble(){
        this->raiz = this->ultimo = nullptr;
        size = 0;
    }

    void add(string dato){
        nodoDoble *nuevo = new nodoDoble(dato);
        if(this->raiz==nullptr){
            this->raiz=this->ultimo = nuevo;
        }else{
            this->ultimo->siguiente = nuevo;
            nuevo->anterior = this->ultimo;
            this->ultimo = nuevo;
        }
        size++;
        return;
    }


    void print(){
        nodoDoble *aux = this->raiz;
        printf("Recorrido primero-ultimo\n");
        while(aux!=nullptr){
            printf("Dato: %s\n",aux->dato.c_str());
            aux = aux->siguiente;
        }
        aux = this->ultimo;
        printf("Recorrido ultimo-primero\n");
        while(aux!=nullptr){
            printf("Dato: %s\n",aux->dato.c_str());
            aux = aux->anterior;
        }
    }
};

struct Stack{
    nodoDoble *top, *bottom;

    Stack(){
        this->top=this->bottom = nullptr;
    }

    void push(string dato){
        nodoDoble *nuevo = new nodoDoble(dato);
        if(this->top == nullptr){
            this->top=this->bottom = nuevo;
        }else{
            this->top->siguiente = nuevo;
            nuevo->anterior = this->top;
            this->top = nuevo;
        }
    }

    nodoDoble* pop(){
        if(this->top->anterior!=nullptr){
            nodoDoble *aux = this->top;
            nodoDoble *actual = this->top->anterior;
            actual->siguiente = nullptr;
            this->top = actual;
            return aux;
        }else if(this->bottom==this->top){
            nodoDoble *aux = this->top;
            this->top = nullptr;
            return aux;
        }
        else{
            printf("No existen elementos\n");
            return nullptr;
        }
    }
    nodoDoble* peek(){
        return this->top;
    }

    void print(){
        nodoDoble *aux = this->bottom;
        while(aux!=nullptr){
            printf("Dato: %s\n",aux->dato.c_str());
            aux = aux->siguiente;
        }
    }
};

struct Queue{
    nodoSimple *head, *tail;
    Queue(){
        head=tail=nullptr;
    }
    void enqueue(string dato){
        nodoSimple *nuevo = new nodoSimple(dato);
        if(this->head==nullptr){
            this->head = this->tail = nuevo;
        }else{
            this->tail->siguiente = nuevo;
            this->tail = nuevo;
        }
    }

    nodoSimple* dequeue(){
        if(this->head==nullptr){
            printf("No existe elementos a decolar\n");
            return nullptr;
        }else{
            nodoSimple *aux = this->head;
            this->head = this->head->siguiente;
            return aux;
        }
    }

    void print(){
        nodoSimple *aux = this->head;
        while(aux!=nullptr){
            printf("Dato: %s\n",aux->dato.c_str());
            aux = aux->siguiente;
        }
    }
};

int main()
{
    ListaSimple *lst_simple = new ListaSimple();
    lst_simple->add("1");
    lst_simple->add("2");
    lst_simple->add("3");
    lst_simple->add("4");
    lst_simple->add("5");
    lst_simple->add("6");
    printf("---------Lista Simple----------\n");
    lst_simple->print();

    ListaDoble *lst_doble = new ListaDoble();
    lst_doble->add("1");
    lst_doble->add("2");
    lst_doble->add("3");
    lst_doble->add("4");
    lst_doble->add("5");
    lst_doble->add("6");
    printf("---------Lista Doble----------\n");
    lst_doble->print();

    Stack *pila = new Stack();
    pila->push("0");
    pila->push("1");
    pila->push("2");
    pila->push("3");
    pila->push("4");
    printf("---------Pila----------\n");
    pila->print();
    printf("Se saco: %s\n",pila->pop()->dato.c_str());
    printf("Ultimo elemento en la pila : %s\n",pila->peek()->dato.c_str());
    printf("Se saco: %s\n",pila->pop()->dato.c_str());
    printf("Ultimo elemento en la pila : %s\n",pila->peek()->dato.c_str());
    printf("Se saco: %s\n",pila->pop()->dato.c_str());
    printf("Ultimo elemento en la pila : %s\n",pila->peek()->dato.c_str());
    pila->print();

    Queue *cola = new Queue();
    cola->enqueue("1");
    cola->enqueue("2");
    cola->enqueue("3");
    cola->enqueue("4");
    cola->enqueue("5");
    cola->enqueue("6");
    cola->enqueue("7");
    cola->enqueue("8");
    printf("---------Cola----------\n");
    cola->print();
    printf("Se saco: %s\n",cola->dequeue()->dato.c_str());
    printf("Se saco: %s\n",cola->dequeue()->dato.c_str());
    printf("Se saco: %s\n",cola->dequeue()->dato.c_str());
    printf("Se saco: %s\n",cola->dequeue()->dato.c_str());
    cola->print();
    return 0;
}
