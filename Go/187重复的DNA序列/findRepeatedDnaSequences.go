func findRepeatedDnaSequences(s string) []string {
	dict := make(map[string]int, 0)
	res := make([]string, 0)
	for i := 0; i <= len(s) - 10; i++ {
		dict[s[i:i + 10]]++
		if dict[s[i:i + 10]] == 2 {
			res = append(res, s[i:i + 10])
		}
	}
	return res
}