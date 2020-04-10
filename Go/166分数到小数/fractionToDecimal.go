package main

import (
	"fmt"
	"strconv"
)

func fractionToDecimal(numerator int, denominator int) string {
	var res string
	if numerator^denominator < 0 {
		res += "-"
	}

	if numerator < 0 {
		numerator = -numerator
	}

	if denominator < 0 {
		denominator = -denominator
	}

	intgral := numerator / denominator
	res += strconv.Itoa(intgral)
	num := numerator % denominator
	if num == 0 {
		if res == "-0" {
			return "0"
		}
		return res
	}
	fractionMap := make(map[int]int)
	fraction := make([]int, 0)
	var fractionStr string
	for i := 0; ; i++ {
		if num == 0 {
			for _, value := range fraction {
				fractionStr += strconv.Itoa(value)
			}
			break
		}
		num = num * 10
		if index, ok := fractionMap[num]; ok {
			for _, value := range fraction[0:index] {
				fractionStr += strconv.Itoa(value)
			}
			fractionStr += "("
			for _, value := range fraction[index:] {
				fractionStr += strconv.Itoa(value)
			}
			fractionStr += ")"
			break
		}
		fraction = append(fraction, num/denominator)
		fractionMap[num] = i
		num = num % denominator
	}

	return res + "." + fractionStr
}

func main() {
	val := fractionToDecimal(7, -12)
	fmt.Printf("%v", val)
}
