package main

import (
	"fmt"	
)

type I interface {
	M()
}

type T struct {
	S string
}

func (t *T) M(){
	fmt.Println(t.S)
}

func describe(i I){
	fmt.Printf("(%v , %T)\n",i , i)
}
	
func main() {
	var i I = &T{"hello"}
	i.M()
	describe(i)
}