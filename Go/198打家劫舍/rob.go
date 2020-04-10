func rob(nums []int) int {
	if len(nums) == 0 {
		return 0
	} else if len(nums) == 1 {
		return nums[0]
	} else if len(nums) == 2 {
		return max(nums[0], nums[1])
	}
	money := make([]int, len(nums))
	money[0] = nums[0]
	money[1] = max(nums[0], nums[1])
	for i := 2; i < len(nums); i++ {
		money[i] = max(money[i-1], nums[i] + money[i-2])
	}
	return money[len(nums)-1]
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}