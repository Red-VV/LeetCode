func isPowerOfTwo(n int) bool {
	if n <= 0 {
		return false
	}
	res := 1
	for res <= n && res > 0 {
		if res == n {
			return true
		}
		res = res << 1
	}
	return false
}