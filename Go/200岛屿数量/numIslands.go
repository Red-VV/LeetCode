func numIslands(grid [][]byte) int {
	if len(grid) == 0 {
		return 0
	}

	row := len(grid)
	column := len(grid[0])
	res := 0

	newGrid := make([][]byte, row)
	for i := range newGrid {
		newGrid[i] = make([]byte, column)
	}
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			newGrid[i][j] = grid[i][j]
		}
	}
	for i := 0; i < row; i++ {
		for j := 0; j < column; j++ {
			if newGrid[i][j] == byte('1') {
				dfs(newGrid, i, j)
				res++
			}
		}
	}
	return res
}

func dfs(grid [][]byte, i, j int) {
	row := len(grid)
	column := len(grid[0])
	if i == row || j == column || i == -1 || j == -1{
		return
	}
	if grid[i][j] == byte('0') {
		return
	}
	grid[i][j] = byte('0')
	dfs(grid, i-1, j)
	dfs(grid, i, j-1)
	dfs(grid, i+1, j)
	dfs(grid, i, j+1)
}