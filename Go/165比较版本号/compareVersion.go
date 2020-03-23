package main

import (
	"fmt"
	"strconv"
	"strings"
)

func compareVersion(version1 string, version2 string) int {
	sep := "."
	strArr1 := strings.Split(version1, sep)
	strArr2 := strings.Split(version2, sep)

	maxLen := len(strArr1)
	if maxLen < len(strArr2) {
		maxLen = len(strArr2)
	}

	intArr1 := make([]int, maxLen)
	intArr2 := make([]int, maxLen)

	for index, val := range strArr1 {
		intArr1[index], _ = strconv.Atoi(val)
	}

	for index, val := range strArr2 {
		intArr2[index], _ = strconv.Atoi(val)
	}

	for i := 0; i < maxLen; i++ {
		if intArr1[i] > intArr2[i] {
			return 1
		} else if intArr1[i] < intArr2[i] {
			return -1
		}
	}
	return 0
}

func main() {
	val := compareVersion("1.01", "1.01.01")
	fmt.Printf("%v", val)
}
