package main

import "fmt"

func minSubArrayLen(s int, nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	minLen := len(nums) + 1
	left := 0
	right := 0
	sum := 0
	for right != len(nums) || sum >= s {
		if sum < s {
			sum += nums[right]
			right++
		} else {
			if right-left < minLen {
				minLen = right - left
			}
			sum -= nums[left]
			left++
		}
	}
	if minLen == len(nums)+1 {
		return 0
	}
	return minLen
}

func main() {
	arr := []int{2, 3, 1, 2, 4, 3}
	res := minSubArrayLen(7, arr)
	fmt.Println(res)
}
