package lista

import (
	"fmt"
)

type nodo struct {
	siguiente, anterior *nodo
	dato int
}

type Lst struct {
	raiz, ultimo *nodo
	size int
}

func NewLst() *Lst {
	return &Lst{nil,nil,0}
}

func (m *Lst)Insert(entrada int) int {
	nuevo := &nodo{nil,nil,entrada}
	if m.raiz==nil {
		m.raiz = nuevo
		m.ultimo = nuevo
	}else{
		m.ultimo.siguiente = nuevo
		nuevo.anterior = m.ultimo
		m.ultimo = nuevo
	}
	m.size++
	return 1
}

func (m *Lst)Print()  {
	aux := m.raiz
	contador := 0
	for(aux != nil){
		fmt.Println(aux.dato)
		aux = aux.siguiente
		contador++;
	}
	fmt.Println("Valores en lista:",m.size,"Nodos impresos:", contador)
}