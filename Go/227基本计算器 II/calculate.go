package main

import (
	"fmt"
)

func calculate(s string) int {
	numStack := make([]int, 0, len(s))
	optionStack := make([]byte, 0, len(s))
	i := 0
	num := 0
	for i < len(s) {
		if isDigit(s[i]) {
			for i < len(s) && isDigit(s[i]) {
				num = num*10 + int(s[i]) - int('0')
				i++
			}
			numStack = append(numStack, num)
			num = 0
		} else if s[i] != byte(' ') {
			optionStack = append(optionStack, s[i])
			i++
		} else {
			i++
		}
	}
	return realCal(numStack, optionStack)
}

func doCal(option byte, num1, num2 int) int {
	var res int
	switch option {
	case '+':
		res = num1 + num2
	case '-':
		res = num1 - num2
	case '*':
		res = num1 * num2
	case '/':
		res = num1 / num2
	}
	return res
}

func isDigit(ch byte) bool {
	if ch <= byte('9') && ch >= byte('0') {
		return true
	}
	return false
}

func realCal(numStack []int, optionStack []byte) int {
	index := 0
	for {
		if index >= len(optionStack) {
			break
		}
		option := optionStack[index]
		if option == byte('*') || option == byte('/') {
			numStack[index+1] = doCal(option, numStack[index], numStack[index+1])
			numStack = append(numStack[:index], numStack[index+1:]...)
			optionStack = append(optionStack[:index], optionStack[index+1:]...)
		} else {
			index++
		}
	}
	res := numStack[0]
	for i := 1; i < len(numStack); i++ {
		res = doCal(optionStack[i-1], res, numStack[i])
	}
	return res
}

func main() {
	res := calculate("100000000/1/2/3/4/5/6/7/8/9/10")
	fmt.Println(res)
}
