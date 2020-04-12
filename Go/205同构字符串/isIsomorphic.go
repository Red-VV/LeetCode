func isIsomorphic(s string, t string) bool {
    return helper(s, t) && helper(t, s)
}

func helper(s string, t string) bool {
    dict := make(map[byte]byte, 0)
	for i := 0; i < len(s); i++ {
		if val, ok := dict[s[i]]; ok {
			if val != t[i] {
				return false
			}
		} else {
			dict[s[i]] = t[i]
		}
	}
	return true
}