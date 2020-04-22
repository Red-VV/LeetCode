func maximalSquare(matrix [][]byte) int {
	if len(matrix) == 0 {
		return 0
	}
	n := len(matrix)
	m := len(matrix[0])
	res := make([][]int, n)
	left := make([][]int, n)
	up := make([][]int, n)
	for i := 0; i < n; i++ {
		res[i] = make([]int, m)
		left[i] = make([]int, m)
		up[i] = make([]int, m)
	}

	maxL := 0
	for i := 0; i < n; i++ {
		for j := 0; j < m; j++ {
			if matrix[i][j] == byte('1') {
				last := getLastArea(res, i , j)
				lastLeft := getLeft(left, i, j)
				lastUp := getUp(up, i, j)
				res[i][j] = min(last, min(lastLeft, lastUp)) + 1
				if maxL < res[i][j] {
					maxL = res[i][j]
				}
				left[i][j] = lastLeft + 1
				up[i][j] = lastUp + 1
			}
		}
	}
	return maxL * maxL
}

func getLastArea(res [][]int, i, j int) int {
	if i - 1 < 0 || j - 1 < 0 {
		return 0
	}
	return res[i-1][j-1]
}

func getLeft(left [][]int, i, j int) int {
	if j - 1 < 0 {
		return 0
	}
	return left[i][j-1]
}

func getUp(up [][]int, i, j int) int {
	if i - 1 < 0 {
		return 0
	}
	return up[i-1][j]
}

func min(i, j int) int {
	if i > j {
		return j
	}
	return i
}