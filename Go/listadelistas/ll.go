package listadelistas

import (
	"../lista"
	"fmt"
)



type nodo struct {
	lst *lista.Lst
	siguiente, anterior *nodo
	index int
}

func newNodo(index int) *nodo {
	return &nodo{lista.NewLst(), nil, nil, index}
}

type LL struct{
	raiz, ultimo *nodo
	size int
}

func NewLL() *LL {
	return &LL{raiz: nil, ultimo: nil, size: 0}
}


func (ll *LL) Insert(index int, dato int)  {
	nuevo := newNodo(index)
	if ll.raiz == nil{
		ll.raiz = nuevo
		ll.ultimo = nuevo
		nuevo.lst.Insert(dato)
	}else{
		aux := ll.raiz
		for(aux!=nil){
			if aux.index==index{
				aux.lst.Insert(dato)
				return
			}
			aux = aux.siguiente
		}
		nuevo.lst.Insert(dato)
		ll.ultimo.siguiente = nuevo
		nuevo.anterior= ll.ultimo
		ll.ultimo = nuevo
	}
	ll.size++
	return
}

func (ll *LL) Print(){
	aux := ll.raiz
	for aux!= nil {
		fmt.Println("--------Index:", aux.index, "---------")
		aux.lst.Print()
		aux = aux.siguiente
	}
}
