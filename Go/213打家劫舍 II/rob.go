func rob(nums []int) int {
	switch len(nums) {
	case 0:
		return 0
	case 1:
		return nums[0]
	case 2:
		return max(nums[0], nums[1])
	default:
		return max(helper(nums[1:]), helper(nums[0:len(nums)-1]))
	}
}

func helper(nums []int) int {
	dp := make([]int, len(nums))
	dp[0] = nums[0]
	dp[1] = max(nums[0], nums[1])
	for i := 2; i < len(nums); i++ {
		dp[i] = max(dp[i-1], dp[i-2] + nums[i])
	}
	return dp[len(dp)-1]
}

func max(a, b int) {
	if a > b {
		return a
	}
	return b
}