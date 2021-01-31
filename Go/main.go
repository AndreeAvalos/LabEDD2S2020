package main

import (
	"./listadelistas"
)


func main() {
	ll := listadelistas.NewLL()
	ll.Insert(1,1)
	ll.Insert(1,11)
	ll.Insert(2,12)
	ll.Insert(2,13)
	ll.Insert(3,14)
	ll.Print()



}
