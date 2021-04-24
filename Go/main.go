package main

import (
	"./tablahash"
	"fmt"
	"math/rand"
	"sync"
	"time"
)

var wg sync.WaitGroup

func escribir(numero int) {
	defer wg.Done()
	time.Sleep(time.Duration(rand.Intn(100)))
	fmt.Println("Su peticion es la numero:", numero)
}

func main() {
	//ll := listadelistas.NewLL()
	//ll.Insert(1,1)
	//ll.Insert(1,11)
	//ll.Insert(2,12)
	//ll.Insert(2,13)
	//ll.Insert(3,14)
	//ll.Print()

	//m := matriz.NewMatriz()
	//m.Insert(&matriz.Product{1,"Manzana roja"," Manzana criolla de color roja"},0,0)
	//m.Insert(&matriz.Product{1,"Manzana roja"," Manzana criolla de color roja"},1,0)
	//m.Insert(&matriz.Product{1,"Manzana roja"," Manzana criolla de color roja"},0,1)
	//m.Insert(&matriz.Product{1,"Manzana roja"," Manzana criolla de color roja"},1,1)
	//fmt.Println("Print por Horizontal")
	//m.Print_horizontal()
	//fmt.Println("Print por Vertical")
	//m.Print_vertical()

	//arbol := abb.NewAbb()
	//arbol.Insertar(10, "Esta es la raiz")
	//arbol.Insertar(11, "Valor 1")
	//arbol.Insertar(9, "Valor 2")
	//arbol.Insertar(1, "Valor 3")
	//arbol.Insertar(4, "Valor 4")
	//arbol.Insertar(60, "Valor 5")
	//arbol.Insertar(7, "Valor 6")
	//arbol.Insertar(1000, "Valor 7")
	//
	//arbol.Print()
	//
	//fmt.Println(" Arbol con puntero doble ")
	//
	//arbol2 := abb.NewAbb()
	//arbol2.Insertar2(10, "Esta es la raiz")
	//arbol2.Insertar2(11, "Valor 1")
	//arbol2.Insertar2(9, "Valor 2")
	//arbol2.Insertar2(1, "Valor 3")
	//arbol2.Insertar2(4, "Valor 4")
	//arbol2.Insertar2(60, "Valor 5")
	//arbol2.Insertar2(7, "Valor 6")
	//arbol2.Insertar2(1000, "Valor 7")
	//arbol2.Print()

	//fase1.Insertar(0,0,0,"Tienda 1")
	//fase1.Insertar(0,2,2,"Tienda 12")
	//fase1.Insertar(1,0,3,"Tienda 13")
	//fase1.Insertar(0,10,0,"Tienda 14")
	//fase1.Insertar(6,0,0,"Tienda 15")
	//fase1.Insertar(9,11,7,"Tienda 16")
	//fase1.Insertar(10,0,0,"Tienda 17")
	//fase1.Insertar(1,1,1,"Tienda 18")
	//fase1.Insertar(0,0,0,"Tienda 2")
	//fase1.Insertar(0,0,0,"Tienda 3")
	//
	//fase1.Buscar(0,0,0,"Tienda 1")
	//fase1.Buscar(0,0,0,"Tienda 12")
	//
	//fase1.All(4,0,0)

	//miavl := avl.NewAVL()
	//miavl.Insertar(1)
	//miavl.Insertar(11)
	//miavl.Insertar(12)
	//miavl.Insertar(13)
	//miavl.Insertar(14)
	//miavl.Insertar(15)
	//miavl.Insertar(16)
	//miavl.Insertar(17)
	//fmt.Println("Valores de AVL")
	//miavl.Print()
	//var dec1, asig1 interfaces.Instruccion
	//
	//dec1 = interfaces.NewDeclaracion("a","10")
	//asig1 = interfaces.NewAsignacion("b", "20")
	//
	//lst_instrucciones := []interfaces.Instruccion{dec1, asig1}
	//
	//for _, inst := range lst_instrucciones {
	//	inst.Ejecutar()
	//}
	//for i := 0; i < 100; i++ {
	//	wg.Add(1)
	//	go escribir(i)
	//}
	//wg.Wait()
	//fmt.Println("TERMINO")
	ht := tablahash.NewHashTable(17)
	valor := stringtoascii("prueba")
	valor2 := stringtoascii("abeurp")
	ht.Insertar(int(valor), "prueba","Primera inserccion")
	ht.Insertar(int(valor2), "abeurp","COLISION")
	ht.Insertar(int(stringtoascii("Carlos")),"Carlos","No debera de haber colision")
	ht.Insertar(int(stringtoascii("Andree1")),"Andree1","No debera de haber colision 1")
	ht.Insertar(int(stringtoascii("Andree2")),"Andree2","No debera de haber colision 2")
	ht.Insertar(int(stringtoascii("4")),"4","No debera de haber colision 6")
	ht.GetAtributos()
	ht.Print()
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
