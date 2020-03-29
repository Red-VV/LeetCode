package main

import "fmt"

func calculateMinimumHP(dungeon [][]int) int {
	M := len(dungeon)
	N := len(dungeon[0])

	leastHP := make([]int, N)
	leastHP[N-1] = 1 - dungeon[M-1][N-1]
	if leastHP[N-1] < 1 {
		leastHP[N-1] = 1
	}
	for i := N - 2; i >= 0; i-- {
		leastHP[i] = getNext(leastHP[i+1], leastHP[i+1], dungeon[M-1][i])
	}

	for i := M - 2; i >= 0; i-- {
		for j := N - 1; j >= 0; j-- {
			if j == N-1 {
				leastHP[j] = getNext(leastHP[j], leastHP[j], dungeon[i][j])
			} else {
				leastHP[j] = getNext(leastHP[j+1], leastHP[j], dungeon[i][j])
			}
		}
	}
	return leastHP[0]
}

func getNext(leastHPRight int, leastHPDown int, dungeon int) (leastHP int) {
	var minLeast int
	if leastHPDown < leastHPRight {
		minLeast = leastHPDown
	} else {
		minLeast = leastHPRight
	}
	leastHP = minLeast - dungeon
	if leastHP <= 0 {
		leastHP = 1
	}
	return
}

func myPrint(value []int) {
	for _, val := range value {
		fmt.Printf("%d ", val)
	}
	fmt.Println()
}

func main() {
	dungeon := [][]int{{1, -3, 3}, {0, -2, 0}, {-3, -3, -3}}
	res := calculateMinimumHP(dungeon)
	fmt.Printf("%d", res)
}
