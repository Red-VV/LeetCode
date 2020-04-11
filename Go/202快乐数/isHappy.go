package main

import (
	"sort"
)

func isHappy(n int) bool {
	set := make(map[int]bool, 0)
	for {
		if n == 0 {
			break
		}
		if n == 1 {
			return true
		}

		num := make([]int, 0)
		for n != 0 {
			num = append(num, n%10)
			n /= 10
		}
		sort.Ints(num)
		newNum := 0
		n = 0
		for _, val := range num {
			newNum = newNum*10 + val
			n += val * val
		}
		if _, ok := set[newNum]; ok {
			break
		}
		set[newNum] = true
	}
	return false
}

func main() {
	isHappy(2)
}
