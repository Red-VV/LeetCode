package main

import "fmt"

func countPrimes(n int) int {
	if n <= 2 {
		return 0
	}
	primers := make([]int, n, n)
	primers[0] = 2
	cnt := 1
	for i := 3; i < n; i++ {
		isPrimer := true
		for j := 0; j < cnt; j++ {
			if primers[j]*primers[j] > i {
				break
			}
			if i%primers[j] == 0 {
				isPrimer = false
				break
			}
		}
		if isPrimer {
			primers[cnt] = i
			cnt++
		}
	}
	return cnt
}

func main() {
	res := countPrimes(499979)
	fmt.Println(res)
}
