package main

import (
	"fmt"
	"strconv"
)

func calculate(s string) int {
	s = "(" + s + ")"
	infix := stringTransf(s)
	postfix := in2post(infix)
	stack := make([]interface{}, 0, len(postfix))
	for _, v := range postfix {
		if isInt(v) {
			stack = append(stack, v)
		} else {
			num := stack[len(stack)-1].(int64)
			stack = stack[0 : len(stack)-1]
			if v == '+' {
				stack[len(stack)-1] = stack[len(stack)-1].(int64) + num
			} else {
				stack[len(stack)-1] = stack[len(stack)-1].(int64) - num
			}
		}
	}
	return int(stack[0].(int64))
}

func stringTransf(s string) []interface{} {
	res := make([]interface{}, 0, len(s))
	var num string
	for _, v := range s {
		if isNum(v) {
			if num == "" {
				num = string(v)
				intNum, _ := strconv.Atoi(num)
				res = append(res, int64(intNum))
			} else {
				num = num + string(v)
				intNum, _ := strconv.Atoi(num)
				res[len(res)-1] = int64(intNum)
			}
		} else if v == ' ' {
			continue
		} else {
			num = ""
			res = append(res, v)
		}
	}
	return res
}

func isNum(c rune) bool {
	if c <= '9' && c >= '0' {
		return true
	}
	return false
}

func isInt(c interface{}) bool {
	if _, ok := c.(int64); ok {
		return true
	}
	return false
}

func in2post(infix []interface{}) []interface{} {
	postfix := make([]interface{}, 0, len(infix))
	stack := make([]interface{}, 0, len(infix))
	for _, v := range infix {
		if isInt(v) {
			postfix = append(postfix, v)
		} else {
			if v == '(' {
				stack = append(stack, v)
			} else {
				for i := len(stack) - 1; i >= 0; i-- {
					if stack[i] == '(' {
						if v == ')' {
							stack = stack[0:i]
						} else {
							stack = stack[0 : i+1]
							stack = append(stack, v)
						}
						break
					} else {
						postfix = append(postfix, stack[i])
					}
				}
			}
		}
	}
	return postfix
}

func main() {
	ret := calculate("1+2")
	fmt.Println(ret)
}
