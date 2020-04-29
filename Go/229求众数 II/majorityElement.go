func majorityElement(nums []int) []int {
	var num1, num2 int
	var cnt1, cnt2 int
	for _, v := range nums {
		if cnt1 != 0 && num1 == v {
			cnt1++
		} else if cnt2 != 0 && num2 == v {
			cnt2++
		} else {
			if cnt1 != 0 && cnt2 != 0 {
				cnt1--
				cnt2--
			} else if cnt1 == 0 {
				num1 = v
				cnt1++
			} else {
				num2 = v
				cnt2++
			}
		}
	}
	res := make([]int, 0, 2)
	if cnt1 > 0 && isMajority(nums, num1) {
		res = append(res, num1)
	}
	if cnt2 > 0 && isMajority(nums, num2) {
		res = append(res, num2)
	}
	return res
}

func isMajority(nums []int, num int) bool {
	maxCnt := len(nums) / 3
	cnt := 0
	for _, v := range nums {
		if v == num {
			cnt++
			if cnt > maxCnt {
				return true
			}
		}
	}
	return false
}