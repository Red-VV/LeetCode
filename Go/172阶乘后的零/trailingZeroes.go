func trailingZeroes(n int) int {
	count := 0
	for i := n; i > 0; {
		i /= 5
		count += i
	}
	return count
}