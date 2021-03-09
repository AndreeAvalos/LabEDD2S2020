package abb

import "fmt"

type nodo struct {
	nivel    int
	indice   int
	izq, der *nodo
	dato     string
}

type Abb struct {
	raiz *nodo
}

func NewAbb() *Abb {
	return &Abb{raiz: nil}
}

func (abb *Abb) Insertar(indice int, dato string) {
	abb.raiz = insert(0, indice, dato, abb.raiz)
}

func (abb *Abb) Insertar2(indice int, dato string) {
	insert2(0, indice, dato, &abb.raiz)
}

func insert2(nivel int, indice int, dato string, padre **nodo) {
	if *padre == nil {
		*padre = &nodo{nivel, indice, nil, nil, dato}
	} else {
		if (*padre).indice > indice {
			insert2(nivel+1, indice, dato, &(*padre).izq)
		} else {
			insert2(nivel+1, indice, dato, &(*padre).der)
		}
	}
}

func insert(nivel int, indice int, dato string, padre *nodo) *nodo {
	if padre == nil {
		padre = &nodo{nivel, indice, nil, nil, dato}
	} else {
		if padre.indice > indice {
			padre.izq = insert(nivel+1, indice, dato, padre.izq)
		} else {
			padre.der = insert(nivel+1, indice, dato, padre.der)
		}
	}
	return padre
}

func (abb *Abb) Print() {
	fmt.Println("------ Recorrido In orden -------")
	print_in_orden(abb.raiz)
	fmt.Println("------ Recorrido Post orden -------")
	print_post_orden(abb.raiz)
	fmt.Println("------ Recorrido Pre orden -------")
	print_pre_orden(abb.raiz)
}

func print_in_orden(padre *nodo) {
	if padre != nil {
		print_in_orden(padre.izq)
		fmt.Println("Nivel:", padre.nivel, " Indice:", padre.indice, " Dato:", padre.dato)
		print_in_orden(padre.der)
	}
}

func print_post_orden(padre *nodo) {
	if padre != nil {
		fmt.Println("Nivel:", padre.nivel, " Indice:", padre.indice, " Dato:", padre.dato)
		print_post_orden(padre.izq)
		print_post_orden(padre.der)
	}
}

func print_pre_orden(padre *nodo) {
	if padre != nil {
		print_pre_orden(padre.izq)
		print_pre_orden(padre.der)
		fmt.Println("Nivel:", padre.nivel, " Indice:", padre.indice, " Dato:", padre.dato)
	}
}
