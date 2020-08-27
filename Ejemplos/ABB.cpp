#include <iostream>
#include <string>

using namespace std;

class nodo{
    public:
        int indice;
        nodo *izq, *der;

        nodo(int index){
            indice = index;
            izq = der = nullptr;
        }
};

class ABB{
    public:
        nodo *root;
        ABB(){
            root = nullptr;
        }
        void insert(int index){
            insert(&root, index);
        }
        void insert(nodo **p, int index){
            if(*p == nullptr){
                *p = new nodo(index);
                return; 
            }else{
                if((*p)->indice>index){
                    insert(&(*p)->izq,index);
                }else{
                    insert(&(*p)->der,index);
                }
                return;
            }
        }
        void print(){
            cout<<"SE RECORRERA DE MANERA PREORDEN"<<endl;
            pre(root); 
            cout<<"\nSE RECORRERA DE MANERA INORDEN"<<endl;
            in(root);
            cout<<"\nSE RECORRERA DE MANERA POSTORDEN"<<endl;
            post(root);
        }
        void pre(nodo *padre){
            if(padre!=nullptr){
                cout<< padre->indice<< " ";
                pre(padre->izq);
                pre(padre->der);
            }
            return;
        }
        void in(nodo *padre){
            if(padre!=nullptr){
                pre(padre->izq);
                cout<< padre->indice<< " ";
                pre(padre->der);
            }
            return;
        }
        void post(nodo *padre){
            if(padre!=nullptr){
                pre(padre->izq);
                pre(padre->der);
                cout<< padre->indice<< " ";
            }
            return;
        }
};

int main(){
    ABB *abb = new ABB();
    abb->insert(10);
    abb->insert(9);
    abb->insert(11);
    abb->insert(7);
    abb->insert(2);
    abb->insert(3);
    abb->insert(15);
    abb->insert(14);
    abb->print();
    return 0;
}