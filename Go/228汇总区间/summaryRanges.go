package main

import (
	"fmt"
	"strconv"
)

func summaryRanges(nums []int) []string {
	res := make([]string, 0, len(nums))
	left := 0
	right := 0
	for left < len(nums) {
		for right+1 < len(nums) && nums[right]+1 == nums[right+1] {
			right++
		}
		res = append(res, pair2Str(nums[left], nums[right]))
		right++
		left = right
	}
	return res
}

func pair2Str(num1, num2 int) string {
	if num1 == num2 {
		return strconv.Itoa(num1)
	}
	return strconv.Itoa(num1) + "->" + strconv.Itoa(num2)
}

func main() {
	arr := []int{1, 2, 3, 4, 6, 7, 8, 10}
	res := summaryRanges(arr)
	fmt.Println(res)
}
