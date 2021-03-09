package fase1

import "fmt"

type Tienda struct {
	nombre string
}


type nodo struct {
	izq, der *nodo
	tienda *Tienda
}

type Lista struct {
	first, last *nodo
}

func NewLista() *Lista {
	return &Lista{nil, nil}
}

func (l *Lista) Insert(name string)  {
	nuevo := &nodo{nil, nil, &Tienda{name}}
	if l.first == nil {
		l.first = nuevo
		l.last = nuevo
	}else{
		l.last.der = nuevo
		nuevo.izq = l.last
		l.last = nuevo
	}
}

func (l *Lista) Search(name string) *Tienda{
	aux := l.first
	for aux != nil{
		if aux.tienda.nombre == name{
			return aux.tienda
		}
		aux = aux.der
	}
	return nil
}
func (l *Lista) Print(){
	aux := l.first
	for aux != nil{
		fmt.Println(aux.tienda.nombre)
		aux = aux.der
	}
}

var vector []*Lista
var bandera = false

func simulacion(){
	bandera = true
	for i := 0; i<26; i++{
		for  j := 0 ; j<13 ; j++{
			for k:=0 ; k<5 ; k++{
				vector= append(vector, NewLista())
			}
		}
	}
}


func Insertar(letra int, departamento int, calificacion int, nombre string)  {
	indice := letra+departamento+calificacion
	if bandera != true {
		simulacion()
	}
	vector[indice].Insert(nombre)
}

func Buscar(letra int, departamento int, calificacion int, nombre string) {
	indice := letra+departamento+calificacion
	resultado := vector[indice].Search(nombre)

	if resultado != nil{
		fmt.Println(resultado.nombre)
	}else{
		fmt.Println("No se encontro")
	}
}

func All(letra int, departamento int, calificacion int){
	indice := letra+departamento+calificacion
	vector[indice].Print()
}