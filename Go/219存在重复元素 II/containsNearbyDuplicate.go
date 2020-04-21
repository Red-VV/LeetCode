func containsNearbyDuplicate(nums []int, k int) bool {
	dict := make(map[int]int, 0)
	for index, val := range nums {
		if i, ok := dict[val]; ok {
			if index - i <= k {
				return true
			} else {
				dict[val] = index
			}
		} else {
			dict[val] = index
		}
	}
	return false
}