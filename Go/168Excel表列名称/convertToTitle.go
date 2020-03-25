package main

import "fmt"

func convertToTitle(n int) string {
	dict := make(map[int]byte)
	for i := 1; i <= 26; i++ {
		dict[i] = byte('A' + i - 1)
	}
	res := ""
	var cur int
	for n > 0 {
		cur = n % 26
		if cur == 0 {
			cur = 26
			n = n - 26
		}
		res = string(dict[cur]) + res
		n = n / 26
	}

	return res
}

func main() {
	str := convertToTitle(29)
	fmt.Printf(str)
}
