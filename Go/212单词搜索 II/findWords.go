func findWords(board [][]byte, words []string) []string {
	res := make([]string, 0)
	for _, word := range words {
		if isExisted(word, board) {
			res = append(res, word)
		}
	}
	return res
}

func isExisted(word string, board [][]byte) bool {
	for row, val := range board {
		for column := range val {
			isVisited := make([][]bool, len(board))
			for index := range isVisited {
				isVisited[index] = make([]bool, len(board[0]))
			}
			if backtrace(word, isVisited, board, row, column) {
				return true
			}
		}
	}
	return false
}

func backtrace(word string, isVisited [][]bool, board [][]byte, row, column int) bool {
	if len(word) == 0 {
		return true
	}
	lenRow := len(isVisited)
	lenColumn := len(isVisited[0])
	if row < 0 || row >= lenRow || column < 0 || column >= lenColumn {
		return false
	}
	if isVisited[row][column] || word[0] != board[row][column] {
		return false
	}
	isVisited[row][column] = true
	word = word[1:]
	res := backtrace(word, isVisited, board, row - 1, column) ||
	 backtrace(word, isVisited, board, row, column - 1) ||
	 backtrace(word, isVisited, board, row + 1, column) ||
	 backtrace(word, isVisited, board, row, column + 1)
	isVisited[row][column] = false
	return res
}