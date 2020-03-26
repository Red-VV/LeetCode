func titleToNumber(s string) int {
	dict := make(map[byte]int, 0)
	for i := 1; i <= 26; i++ {
		dict[byte('A' + i - 1)] = i
	}
	var res int
	var factor = 1;
	for i := len(s) - 1; i >= 0; i-- {
		res += factor * dict[s[i]]
		factor = factor * 26
	}
	return res
}