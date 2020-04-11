package main

import "fmt"

func rangeBitwiseAnd(m int, n int) int {
	cnt := 0
	for m != n {
		m >>= 1
		n >>= 1
		cnt++
	}
	return m << cnt
}

func main() {
	res := rangeBitwiseAnd(4, 7)
	fmt.Println(res)
}
