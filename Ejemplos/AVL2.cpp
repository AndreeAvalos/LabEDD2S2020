#include <iostream>
#include <string>

using namespace std;
//Nodo simple
struct nodoSimple{
    string dato;
    string matriz;
    string abb;
    nodoSimple *siguiente;

    nodoSimple(string dato){
        this->dato = dato;
        this->siguiente = nullptr;
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


class nodo{
    public:
        nodo *izq, *der;
        int dato;
        ListaSimple *lst;
        int altura;

        nodo(int dato){
            this->dato = dato;
            lst = new ListaSimple();
            izq = der  = nullptr;
            altura = 0;
        }
};

class AVL{
    private:
        int MAX(int val1, int val2){
            if(val1 > val2)
                return val1;
            return val2;
        }
        nodo * RotacionIzquierda(nodo *pivote){
            nodo *aux = pivote->izq;
            pivote->izq = aux->der;
            aux->der = pivote;
            pivote->altura = MAX(getAltura(pivote->izq), getAltura(pivote->der))+1;
            aux->altura = MAX(getAltura(aux->izq),pivote->altura)+1;
            return aux;
        }
        nodo * RotacionDerecha(nodo *pivote){
            nodo *aux = pivote->der;
            pivote->der = aux->izq;
            aux->izq = pivote;
            pivote->altura = MAX(getAltura(pivote->der), getAltura(pivote->izq))+1;
            aux->altura = MAX(getAltura(aux->der),pivote->altura)+1;
            return aux;
        }

        nodo * RotacionDobleIzquierda(nodo *pivote){
            pivote->izq = RotacionDerecha(pivote->izq);
            return RotacionIzquierda(pivote);
        }
        nodo *RotacionDobleDerecha(nodo *pivote){
            pivote->der = RotacionIzquierda(pivote->der);
            return RotacionDerecha(pivote);
        }

        int getAltura(nodo *temp){
            if(temp!=nullptr){
                return temp->altura;
            }
            return -1;
        }

        nodo * insert(nodo *root, int dato, string valor){
            if(root==nullptr){
                root = new nodo(dato);
                root->lst->add(valor);
            }else if(dato<root->dato){
                root->izq = insert(root->izq,dato, valor);
                if(getAltura(root->der)-getAltura(root->izq)==-2){
                    if(dato<root->izq->dato){
                        root = RotacionIzquierda(root);
                    }else{
                        root = RotacionDobleIzquierda(root);
                    }
                }
            }else if(dato> root->dato){
                
                root->der = insert(root->der,dato, valor);
                if(getAltura(root->der)-getAltura(root->izq)==2){
                    if(dato>root->der->dato){
                        root = RotacionDerecha(root);
                    }else{       
                        root = RotacionDobleDerecha(root);
                    }
                }
            }
            root->altura = MAX(getAltura(root->izq),getAltura(root->der))+1;
            return root;

        }

        ListaSimple** buscar2(nodo *pivote, int indice){
            if(pivote!=nullptr){
                if(pivote->dato==indice){
                    return &pivote->lst;
                }
                if(pivote->izq!=nullptr){
                    return buscar2(pivote->izq, indice);
                }else{
                    return buscar2(pivote->der, indice);
                }
            }
            return nullptr;
        }

        bool buscar(nodo *pivote, int indice){
            if(pivote!=nullptr){
                if(pivote->dato==indice){
                    return true;
                }
                if(pivote->izq!=nullptr){
                    return buscar(pivote->izq, indice);
                }else{
                    return buscar(pivote->der, indice);
                }
            }
            return false;
        }

        void recorridoInOrden(nodo *pivote){
            if(pivote!=nullptr){
                recorridoInOrden(pivote->izq);
                cout<< pivote->dato<< " ";
                recorridoInOrden(pivote->der);
            }
            return;
        }

        void searchPrint(nodo *pivote, int indice){
            if(pivote!=nullptr){
                if(pivote->dato==indice){
                    cout<<"SE VA IMPRIMIR LISTA DE AVL"<< pivote->dato<<endl;
                    pivote->lst->print();
                }
                if(pivote->izq!=nullptr){
                    searchPrint(pivote->izq, indice);
                }else{
                    searchPrint(pivote->der, indice);
                }
            }
            return;
        }  

        void searchInsert(nodo *pivote, int indice, string valor){
            if(pivote!=nullptr){
                if(pivote->dato==indice){
                    pivote->lst->add(valor);
                }
                if(pivote->izq!=nullptr){
                    searchInsert(pivote->izq, indice, valor);
                }else{
                    searchInsert(pivote->der, indice, valor);
                }
            }
            return;
        }

    public: 
        nodo *root;
        AVL(){
            root = nullptr;
        }
        bool buscar(int indice){
            return buscar(root,indice);
        }
        void insertar(int dato, string valor){
            if(buscar(dato)){
                searchInsert(root, dato, valor);
                return;
            }
           root = insert(root, dato, valor);
        }
        void print(){
            recorridoInOrden(root);
        }
        void searchPrint(int indice){
            searchPrint(root, indice);
        }
        ListaSimple **buscar2(int indice){
            return buscar2(root, indice);
        }

};

int main(){

    string matriz = "1,2,3,4,4";
    string abb = "1,1,1,1,1";
    AVL *avl = new AVL();
    avl->insertar(1, "2");
    avl->insertar(1, "3");
    avl->insertar(1, "4");
    avl->insertar(1, "5");
    ListaSimple **aux = avl->buscar2(1);
    (*aux)->add("7");
    
    //cout<<"BUSCAR 1 "<< avl->buscar(2)<<endl;
    avl->insertar(2,"3");
    avl->insertar(3,"4");
    avl->insertar(4,"5");
    avl->insertar(5,"6");
    avl->insertar(6,"7");
    avl->searchPrint(1);
    return 0;
}