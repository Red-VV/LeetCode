package main

import "fmt"

func findKthLargest(nums []int, k int) int {
	if k == 1 && len(nums) == 1 {
		return nums[0]
	}

	left := 0
	right := len(nums) - 1
	pivot := nums[right]

	for left != right {
		for nums[left] <= pivot && right > left {
			left++
		}
		for nums[right] >= pivot && right > left {
			right--
		}
		if left != right {
			nums[left], nums[right] = nums[right], nums[left]
		}
	}
	nums[len(nums)-1] = nums[right]
	nums[right] = pivot
	if k == len(nums)-right {
		return pivot
	} else if k > len(nums)-right {
		return findKthLargest(nums[0:left], k-(len(nums)-right))
	} else {
		return findKthLargest(nums[left+1:], k)
	}
}

func main() {
	arr := []int{1, 2, 3, 4, 5}
	res := findKthLargest(arr, 3)
	fmt.Println(res)
}
