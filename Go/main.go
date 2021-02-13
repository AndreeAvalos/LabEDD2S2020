package main

import (
	"./listadelistas"
	"./matriz"
)


func main() {
	ll := listadelistas.NewLL()
	ll.Insert(1,1)
	ll.Insert(1,11)
	ll.Insert(2,12)
	ll.Insert(2,13)
	ll.Insert(3,14)
	ll.Print()

	m := matriz.NewMatriz()
	m.Insert(&matriz.Product{1,"Manzana roja"," Manzana criolla de color roja"},0,0)


}
