package main

import "fmt"

func containsNearbyAlmostDuplicate(nums []int, k int, t int) bool {
	if t < 0 {
		return false
	}
	dict := make(map[int64]int64)
	for index := range nums {
		val := int64(nums[index])
		id := getID(val, int64(t))
		if _, ok := dict[id]; ok {
			return true
		}
		if mapV, ok := dict[id-1]; ok {
			if val-mapV <= int64(t) {
				return true
			}
		}
		if mapV, ok := dict[id+1]; ok {
			if mapV-val <= int64(t) {
				return true
			}
		}
		dict[id] = val
		if index >= k {
			key := getID(int64(nums[index-k]), int64(t))
			delete(dict, key)
		}
	}
	return false
}

func getID(num int64, t int64) int64 {
	if num >= 0 {
		return num / (t + 1)
	}
	return (num+1)/(t+1) - 1
}

func main() {
	arr := []int{1, 5, 9, 1, 5, 9}
	k := 2
	t := 3
	res := containsNearbyAlmostDuplicate(arr, k, t)
	fmt.Println(res)
}
