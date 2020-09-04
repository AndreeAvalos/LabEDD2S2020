#include <iostream>
#include <string>

using namespace std;

class nodo{
    public:
        nodo *izq, *der;
        int dato;
        int altura;

        nodo(int dat){
            this->dato = dat;
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

        nodo * insert(nodo *root, int dato){
            if(root==nullptr){
                root = new nodo(dato);
            }else if(dato<root->dato){
                root->izq = insert(root->izq,dato);
                if(getAltura(root->der)-getAltura(root->izq)==-2){
                    if(dato<root->izq->dato){
                        root = RotacionIzquierda(root);
                    }else{
                        root = RotacionDobleIzquierda(root);
                    }
                }
            }else if(dato> root->dato){
                
                root->der = insert(root->der,dato);
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
        void recorridoInOrden(nodo *pivote){
            if(pivote!=nullptr){
                recorridoInOrden(pivote->izq);
                cout<< pivote->dato<< " ";
                recorridoInOrden(pivote->der);
            }
            return;
        }

    public: 
        nodo *root;
        AVL(){
            root = nullptr;
        }
        void insertar(int dato){
           root = insert(root, dato);
        }
        void print(){
            recorridoInOrden(root);
        }

};

int main(){
    AVL *avl = new AVL();
    avl->insertar(1);
    avl->insertar(2);
    avl->insertar(3);
    avl->insertar(4);
    avl->insertar(5);
    avl->insertar(6);
    avl->print();
    return 0;
}