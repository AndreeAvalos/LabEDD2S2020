/*
 * autor: Andree Avalos
 * curso: Estructuras de datos
 * semestre: segundo
 * año: 2020 
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

#pragma region producto
class producto{
public:
    string nombre = "";
    int codigo = 0;
    string descripcion = "";
    
    producto(int cod, string name, string descrip){
        nombre = name;
        codigo = cod;
        descripcion = descrip;
    }
};
#pragma endregion producto

#pragma region Nodo

class nodo{
private:
    int x,y;//coordenadas para un mejor manejo
    producto *obj;//datos que vamos a almacenar en cada nodo de la matriz, simulando a una estanteria 
public:
    
    nodo *derecha, *izquierda, *arriba, *abajo;//punteros que tendremos para entrar a los nodos interiores de la matriz
    int header;
    nodo *siguiente, *anterior;//enlaces para poder movernos entre cabeceras

    /* 
    * @header_x: cabecera en el eje x
    * @header_y: cabecera en el eje y
    * @valor_nodo: valor que se guardara en el nodo
    */
    nodo(int header_x, int header_y, producto *valor_nodo){
        derecha = izquierda = arriba = abajo = nullptr;
        x = header_x;
        y = header_y;
        obj = valor_nodo;
    }

    /*
    * @header: valor que obtendra la cabecera de la lista 
    */

    nodo(int cabecera){//metodo constructor para el nodo lista
        siguiente = anterior = nullptr;
        derecha = izquierda = arriba = abajo = nullptr;
        header = cabecera;
    }

    int headerX(){return x;}
    int headerY(){return y;}
    void print(){
        printf("[\nCodigo: %d\nNombre: %s\nDescripcion: %s\n]Fila: %d,Columna: %d\n",obj->codigo, obj->nombre.c_str(), obj->descripcion.c_str(),y,x);
    }

};
#pragma endregion Nodo

#pragma region Lista

class lista{
private:
nodo *first, *last;
public:
    
    lista(){
        first = last = nullptr;
    }
    bool mayor(int index1, int index2){
        if(index1>index2){
            return true;
        }
        return false;
    }
    void ordenar(nodo *nuevo){
        nodo *aux = first;

        while(aux != nullptr){
            if(mayor(nuevo->header, aux->header)){
                aux = aux->siguiente;
            }else{
                if(aux==first){
                    nuevo->siguiente = aux;
                    aux->anterior = nuevo;
                    first = nuevo;
                }else{
                    nuevo->anterior = aux->anterior;
                    aux->anterior->siguiente = nuevo;
                    nuevo->siguiente = aux;
                    aux->anterior = nuevo;
                }
                return;
            }
        }
        last->siguiente = nuevo;
        nuevo->anterior = last;
        last = nuevo;
    }

    void insert(int header){
        nodo *nuevo = new nodo(header);
        if(first==nullptr){
            first = last = nuevo;
        }else{
            ordenar(nuevo);
        }
    }

    nodo *search(int header){
        nodo *temp = first;
        while(temp!=nullptr){
            if(temp->header == header){
                return temp;
            }
            temp = temp->siguiente;
        }
        return nullptr;
    }

    void print(){
        nodo *temp = first;
        while(temp!=nullptr){
            printf("Header: %d\n", temp->header);
            temp = temp->siguiente;
        } 
    }
    bool empty(){
        if(first!=nullptr){return false;}
        return true;
    }
    nodo *getfirst(){
        return first;
    }
};
#pragma endregion Lista

#pragma region Matriz
class matriz{
    lista *horizontal_header, *vertical_header;// listas que nos serviran como cabeceras de la matriz
private:
    void NoExisten(producto *dato, int x, int y){
        //insertamos el primer valor en la lista horizontal
            horizontal_header->insert(x);
            //insertamos el primer valor en la lista vertical
            vertical_header->insert(y);
            //obtenemos los nodos de las cabeceras
            nodo *horizontal = horizontal_header->search(x);
            nodo *vertical = vertical_header->search(y);
            //creamos un nuevo valor de la nodo matriz
            nodo *nuevo = new nodo(x,y, dato);
            //enlazamos el nodo de la cabecera horizontal con el nodo disperso
            horizontal->abajo = nuevo;
            nuevo->arriba = horizontal;
            //enlazamos el nodo cabecera vertical con el nodo disperso
            vertical->derecha = nuevo;
            nuevo->izquierda = vertical;
            return;
    }
    void ExisteVertical(producto *dato, int x, int y){
        //insertamos nuestro valor en la cabecera horizontal
        horizontal_header->insert(x);
        //ahora buscamos nuestros nodos cabeceras
        nodo *horizontal = horizontal_header->search(x);
        nodo *vertical = vertical_header->search(y);
        //agregamos una bandera para saber si se inserto el valor
        bool agregado = false;
        //creamos un nodo disperso nuevo
        nodo *nuevo = new nodo(x,y,dato);
        //creamos un nodo auxiliar para poder recorrer los nodos dispersos
        nodo *aux = vertical->derecha;     
        int header_x;
        //vamos verificando su cabecera en x para saber donde agregarlo
        while (aux!=nullptr)
        {
            //obtenemos la cabecera en horizontal del nodo actual
            header_x = aux->headerX();
            //comparamos si la cabecera actual es mayor al indice que queremos agregar
            //si es mayor entonces solo seguimos pasando
            if( header_x < x){
                aux = aux->derecha;
            }else{
                //lo vamos a insertar si el dato esta entre nodos 
                nuevo->derecha = aux;
                nuevo->izquierda = aux->izquierda;
                aux->izquierda->derecha = nuevo;
                aux->izquierda = nuevo;
                agregado = true;
                break;
            }
        }
        // de lo contrario entonces lo enlazamos de ultimo
        if(agregado == false){
            aux = vertical->derecha;
            while(aux->derecha!=nullptr){
                aux = aux->derecha;
            }
            nuevo->izquierda=aux;
            aux->derecha = nuevo;
        }
        //enlazamos con la cabecera horizontal
        horizontal->abajo = nuevo;
        nuevo->arriba = horizontal;
        
    }
    void ExisteHorizontal(producto *dato, int x, int y){
        vertical_header->insert(y);
        nodo *horizontal = horizontal_header->search(x);
        nodo *vertical = vertical_header->search(y);
        bool agregado = false;
        nodo *nuevo = new nodo(x,y,dato);
        nodo *aux = horizontal->abajo;

        while (aux!=nullptr)
        {
            int header_y = aux->headerY();
            if( header_y < y){
                aux = aux->abajo;
            }
            else{
                nuevo->abajo = aux;
                nuevo->arriba = aux->arriba;
                aux->arriba->abajo = nuevo;
                aux->arriba = nuevo;
                agregado = true;
                break;
            }
        }

        if(agregado == false){
            aux = horizontal->abajo;
            while(aux->abajo!=nullptr){
                aux = aux->abajo;
            }
            nuevo->arriba=aux;
            aux->abajo = nuevo;
        }

        vertical->derecha = nuevo;
        nuevo->izquierda = vertical;
    }

    void Existen(producto *dato, int x, int y){

        //buscamos y obtenemos los nodos de las cabeceras 
        nodo *horizontal = horizontal_header->search(x);
        nodo *vertical = vertical_header->search(y);
        //creamos el nod disperso
        nodo *nuevo = new nodo(x,y,dato);
        bool agregado = false;
        nodo *aux = horizontal->abajo;

        while (aux!=nullptr)
        {
            int header_y = aux->headerY();
            if( header_y < y){
                aux = aux->abajo;
            }
            else{
                nuevo->abajo = aux;
                nuevo->arriba = aux->arriba;
                aux->arriba->abajo = nuevo;
                aux->arriba = nuevo;
                agregado = true;
                break;
            }
        }

        if(agregado == false){
            aux = horizontal->abajo;
            while(aux->abajo!=nullptr){
                aux = aux->abajo;
            }
            nuevo->arriba=aux;
            aux->abajo = nuevo;
        }

        //proceso para enlazar nodos hacia la derecha
        aux = vertical->derecha;
        while (aux!=nullptr)
        {
            int header_y = aux->headerX();
            if( header_y < x){
                aux = aux->derecha;
            }else{
                nuevo->derecha = aux;
                nuevo->izquierda = aux->izquierda;
                aux->izquierda->derecha = nuevo;
                aux->izquierda = nuevo;
                agregado = true;
                break;
            }
        }
        if(agregado == false){
            aux = vertical->derecha;
            while(aux->derecha!=nullptr){
                aux = aux->derecha;
            }
            nuevo->izquierda=aux;
            aux->derecha = nuevo;
        }
    }

public:
    matriz(){//constructor para nuestra matriz dispersa
        horizontal_header = new lista();
        vertical_header = new lista();
    }

    void insert(producto *dato, int x, int y){

        nodo *horizontal = horizontal_header->search(x);
        nodo *vertical = vertical_header->search(y);
        if(horizontal==nullptr&&vertical==nullptr){NoExisten(dato,x,y);}
        else if(horizontal==nullptr&&vertical!=nullptr){ExisteVertical(dato,x,y);}
        else if(horizontal!=nullptr&&vertical==nullptr){ExisteHorizontal(dato,x,y);}
        else if(horizontal!=nullptr&&vertical!=nullptr){Existen(dato,x,y);}
    }
    void imprimir_vertical(){
        nodo *cabecera = vertical_header->getfirst();
        while(cabecera!= nullptr){
            nodo *aux = cabecera->derecha;
            while(aux!=nullptr){
                aux->print();
                aux = aux->derecha;
            }
            cabecera = cabecera->siguiente;
        }
        
    }
    void imprimir_horizontal(){
        nodo *cabecera = horizontal_header->getfirst();
        while(cabecera!= nullptr){
            nodo *aux = cabecera->abajo;
            while(aux!=nullptr){
                aux->print();
                aux = aux->abajo;
            }
            cabecera = cabecera->siguiente;
        }
        
    }

};
#pragma endregion


int main(){
    matriz * dispersa = new matriz();
    dispersa->insert(new producto(1,"Manzana roja"," Manzana criolla de color roja"),1,1);
    dispersa->insert(new producto(2,"Manzana verde"," Manzana criolla de color verde"),1,2);
    dispersa->insert(new producto(3,"Sandia","Deliciosa fruta fresca"),2,1);
    dispersa->insert(new producto(4,"Melon","Deliciosa fruta fresca"),2,2);
    dispersa->insert(new producto(5,"Cloro", "Cloro magia blanca 300 ml"),4,4);
    cout<<"-----------Imprimimos de manera vertical hacia derecha-----------"<<endl;
    dispersa->imprimir_vertical();
    cout<<"-----------Imprimimos de manera horizontal hacia abajo----------"<<endl;
    dispersa->imprimir_horizontal();
    return 0;
}
