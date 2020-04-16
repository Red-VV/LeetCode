package main

import "fmt"

func shortestPalindrome(s string) string {
	if len(s) == 0 {
		return s
	}
	arr := []byte(s)
	longestSub := longestSubPalindrome(arr)
	subArr := arr[longestSub+1 : len(arr)]
	return string(reverse(subArr)) + s
}

func longestSubPalindrome(arr []byte) int {
	res := 0
	length := len(arr)
	for i := 0; i < length; i++ {
		if isPlindrome(arr, 0, i) {
			res = i
		}
	}
	return res
}

func isPlindrome(arr []byte, i, j int) bool {
	for i <= j {
		if arr[i] != arr[j] {
			return false
		}
		i++
		j--
	}
	return true
}

func reverse(arr []byte) []byte {
	left := 0
	right := len(arr) - 1
	for left < right {
		arr[left], arr[right] = arr[right], arr[left]
		left++
		right--
	}
	return arr
}

func main() {
	res := shortestPalindrome("abcd")
	fmt.Println(res)
}
