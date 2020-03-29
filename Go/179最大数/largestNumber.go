package main

import (
	"fmt"
	"sort"
	"strconv"
	"strings"
)

func largestNumber(nums []int) string {
	strs := make([]string, len(nums))
	for index, val := range nums {
		strs[index] = strconv.Itoa(val)
	}
	sort.Slice(strs, func(i, j int) bool {
		return strs[i]+strs[j] >= strs[j]+strs[i]
	})
	res := strings.Join(strs, "")
	if res[0] == '0' {
		return "0"
	}
	return res
}

func main() {
	nums := []int{10, 12}
	res := largestNumber(nums)
	fmt.Printf("%s ", res)
}
