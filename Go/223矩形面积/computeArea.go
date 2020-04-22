package main

import "fmt"

func computeArea(A int, B int, C int, D int, E int, F int, G int, H int) int {
	res := (D-B)*(C-A) + (H-F)*(G-E)
	length := getLength(A, C, E, G)
	width := getLength(B, D, F, H)
	return res - length*width
}

func getLength(x1, x2, y1, y2 int) int {
	if x1 > y1 {
		return getLength(y1, y2, x1, x2)
	}
	if x2 > y2 {
		return y2 - y1
	}
	res := min(x2, y2) - max(x1, y1)
	if res < 0 {
		return 0
	}
	return res
}

func min(a, b int) int {
	if a > b {
		return b
	}
	return a
}

func max(a, b int) int {
	if a < b {
		return b
	}
	return a
}

func main() {
	res := getLength(-3, 3, 0, 9)
	fmt.Println(res)
}
