package main

import "fmt"

func combinationSum3(k int, n int) [][]int {
	res := make([][]int, 0)
	path := make([]int, 0)
	return backtrace(1, k, n, res, path)
}

func backtrace(index int, k int, n int, res [][]int, path []int) [][]int {
	if k == 0 && n == 0 {
		curPath := make([]int, len(path))
		copy(curPath, path)
		res = append(res, curPath)
		return res
	}
	if k == 0 || n == 0 || index > 9 {
		return res
	}
	for i := index; i <= 9; i++ {
		path = append(path, i)
		res = backtrace(i+1, k-1, n-i, res, path)
		path = path[0 : len(path)-1]
	}
	return res
}

func main() {
	res := combinationSum3(3, 7)
	fmt.Println(res)
}
