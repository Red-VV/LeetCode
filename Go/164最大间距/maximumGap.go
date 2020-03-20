func maximumGap(nums []int) int {
	length := len(nums)
	if length < 2 {
		return 0
	}

	newArr := make([]int, length)
	maxVal := maxElement(nums)
	exp := 1
	radix := 10

	for {
		if maxVal/exp == 0 {
			break
		}
		count := make([]int, radix)
		for _, val := range nums {
			count[(val/exp)%10]++
		}
		for i := 1; i < radix; i++ {
			count[i] += count[i-1]
		}
		for i := length - 1; i >= 0; i-- {
			index := (nums[i] / exp) % 10
			count[index]--
			newArr[count[index]] = nums[i]
		}
		for index, val := range newArr {
			nums[index] = val
		}
		exp *= radix
	}
	var maxGap int
	for i := 1; i < length; i++ {
		if maxGap < nums[i]-nums[i-1] {
			maxGap = nums[i] - nums[i-1]
		}
	}
	return maxGap
}

func maxElement(nums []int) int {
	maxVal := 0
	for _, val := range nums {
		if val > maxVal {
			maxVal = val
		}
	}
	return maxVal
}