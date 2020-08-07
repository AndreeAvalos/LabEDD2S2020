#include <iostream>
#include <string.h>
using namespace std;

/* Clase utilizando templates, esto nos sirve para guardar
 * valores de forma generica */
template <class T>
class Nodo{


public:
    T dato;//Dato generico
    Nodo *siguiente, *anterior;//apuntadores
    //metodo constructor para crear el nodo utilizando "plantillas"
    Nodo(T val){
        this->dato = val;
        this->siguiente = this->anterior = nullptr;
    }
};

/* Clase lista, estructura realizada para guardar valores de forma
 * lineal */
template <class T>
class Lista{

private:
    //nodos apuntadores para poder anodar de forma lineal
    Nodo<T> *primero, *ultimo;

public:
    //constructor de la clase lista
    Lista<T>(){
        this->primero = this->ultimo = nullptr;
    }

    //metodo que agrega un tipo generico a la lista
    void add(T dato){
        //creamos el nodo el cual vamos a agregar <T> indica que es generico
        Nodo<T> * nuevo = new Nodo<T>(dato);
        //comprobamos si el primer elemento de la lista esta vacia, si lo esta creamos el nodo
        if(this->primero==nullptr){
            //ambos apuntan al mismo nodo (espacio de memoria)
            this->primero = this->ultimo = nuevo;
        }else{
            //declaramos que el siguiente de ultimo es nuevo
            this->ultimo->siguiente = nuevo;
            //declaramos que el anterior de nuevo es el ultimo
            nuevo->anterior = this->ultimo;
            //por ultimo decimos que ahora nuestro ultimo nodo sera nuevo
            this->ultimo = nuevo;
        }
    }

    void print(){
        Nodo<T> *aux = this->primero;
        while(aux!=nullptr){
            cout<< aux->dato <<endl;
            aux = aux->siguiente;
        }
    }

    void print2(){
        Nodo<T> *aux = this->primero;
        while(aux!=nullptr){
            aux->dato->print();
            aux = aux->siguiente;
        }
    }
};

//definimos un tipo con typedef que hereda del tipo int
typedef int credito;

struct coordenadas{
    int x,y;
    coordenadas(int x, int y){
        this->x = x;
        this->y = y;
    }

    void print(){
        printf("x:%d, y:%d\n",x,y);
    }
};

int main()
{
    Lista<int> *lst = new Lista<int>();
    cout<<"-----Lista de enteros-----"<<endl;
    lst->add(1);
    lst->add(2);
    lst->add(3);
    lst->add(4);
    lst->add(5);
    lst->add(6);
    lst->print();
    cout<<"-----Lista de strings-----"<<endl;
    Lista<string> *lst2 = new Lista<string>();
    lst2->add("CARLOS");
    lst2->add("ANDREE");
    lst2->add("AVALOS");
    lst2->add("SOTO");
    lst2->print();
    cout<<"-----Lista de booleans-----"<<endl;
    Lista<bool> *lst3 = new Lista<bool>();
    lst3->add(true);
    lst3->add(true);
    lst3->add(false);
    lst3->add(true);
    lst3->add(true);
    lst3->print();
    cout<<"-----Lista de Creditos-----"<<endl;
    Lista<credito> *lst4 = new Lista<credito>();
    lst4->add(1000);
    lst4->add(5000);
    lst4->add(20000);
    lst4->add(200);
    lst4->print();
    cout<<"-----Lista de Coordenadas-----"<<endl;
    Lista<coordenadas*> *lst5 = new Lista<coordenadas*>();
    lst5->add(new coordenadas(1,2));
    lst5->add(new coordenadas(2,2));
    lst5->add(new coordenadas(3,7));
    lst5->add(new coordenadas(450,500));
    lst5->add(new coordenadas(80,-2));
    lst5->print2();
    return 0;
}
