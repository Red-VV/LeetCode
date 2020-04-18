func containsDuplicate(nums []int) bool {
	dict := make(map[int]bool, 0)
	for _, val := range nums {
		if _, ok := dict[val]; ok {
			return true
		}
		dict[val] = true
	}
	return false
}
