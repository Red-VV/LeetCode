func rotate(nums []int, k int)  {
    k = k % len(nums)
    k = len(nums) - k
	reverse(nums[0:k])
	reverse(nums[k:len(nums)])
	reverse(nums)
}

func reverse(nums []int) {
	left := 0
	right := len(nums) - 1
	for ; left < right; {
		nums[left], nums[right] = nums[right], nums[left]
        right--
        left++
	}
}