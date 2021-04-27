package tablahash

import "fmt"

type Tupla struct {
	clave string
	valor string
}

func NewTupla(clave string, valor string) *Tupla {
	return &Tupla{clave: clave, valor: valor}
}

type Nodo struct {
	indice int
	lista  []Tupla
}

func NewNodo(indice int) *Nodo {
	return &Nodo{indice: indice}
}

type HashTable struct {
	vector      []*Nodo
	elementos   int
	factorCarga float64
	size        int
}

func (ht *HashTable) GetAtributos() {
	fmt.Println("Tamaño:", ht.size, "Elementos:", ht.elementos, "Factor Carga:", ht.factorCarga)
}

func NewHashTable(size int) *HashTable {
	ht := &HashTable{elementos: 0, factorCarga: 0, size: size}

	for i := 0; i < size; i++ {
		ht.vector = append(ht.vector, nil)
	}
	return ht
}

func (ht *HashTable) funcionHash(id int) int {
	//Funcion hash por metodo de division
	posicion := id % (ht.size - 1)
	if posicion > ht.size {
		return posicion - ht.size
	}
	return posicion
}

func (ht *HashTable) rehashing() {
	siguente := ht.size //la variable siguiente no es nada mas que el siguiente valor que se acople al factor de carga libre
	factor := 0.0

	//Siguiente tama;o adecuado para cumplir con el factor de utilizacion minimo
	for factor < 0.3 {
		factor = float64(ht.elementos) / float64(siguente)
		siguente++
	}

	ht_temporal := NewHashTable(siguente) // creamos una tabla temporal para almacenar nuevamente los datos

	for _, nodo := range ht.vector { //recorremos el vector de nuestra tabla
		for _, tupla := range nodo.lista { //recorremos el clave valor
			ht_temporal.Insertar(int(stringtoascii(tupla.clave)), tupla.clave, tupla.valor) //los insertamos en la nueva tabla
		}
	}

	//igualamos los atributos de la tabla actual con la temporal
	ht.vector = ht_temporal.vector
	ht.elementos = ht_temporal.elementos
	ht.size = ht_temporal.size
	ht.factorCarga = ht_temporal.factorCarga
}

func (ht *HashTable) Insertar(id int, clave string, valor string) {
	posicion := ht.funcionHash(id)

	if ht.vector[posicion] != nil {
		nuevo := NewTupla(clave, valor)
		ht.vector[posicion].lista = append(ht.vector[posicion].lista, *nuevo)
	} else {
		nuevo := NewNodo(posicion)
		nuevo.lista = append(nuevo.lista, *NewTupla(clave, valor))
		ht.vector[posicion] = nuevo
		ht.elementos++
		ht.factorCarga = float64(ht.elementos) / float64(ht.size)
	}
	if ht.factorCarga > 0.6 {
		//hacer rehashing
		ht.rehashing()
	}
}

func (nodo *Nodo) print() {
	for i := 0; i < len(nodo.lista); i++ {
		fmt.Println("indice:", i, "Valor:", nodo.lista[i].valor)
	}
}

func (ht *HashTable) Print() {
	for i := 0; i < ht.size; i++ {
		if ht.vector[i] == nil {
			fmt.Println("Posicion:", i, "vacia")
		} else {
			fmt.Println("Posicion:", i)
			ht.vector[i].print()
		}
	}
}

func stringtoascii(entrada string) int32 {
	cod := []rune(entrada)
	var temp int32
	temp = 0
	for i := 0; i < len(cod); i++ {
		temp = cod[i] + temp
	}
	return temp
}
