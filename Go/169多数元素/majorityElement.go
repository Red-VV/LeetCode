package main

func majorityElement(nums []int) int {
	count := 0
	candidate := 0
	for _, value := range nums {
		if count == 0 {
			candidate = value
			count++
		} else {
			if candidate == value {
				count++
			} else {
				count--
			}
		}
	}
	return candidate
}

func main() {

}
