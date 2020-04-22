func countNodes(root *TreeNode) int {
	if root == nil {
		return 0
	}
	deep := getDeep(root)
	maxIndex := pow(2, deep)
	left := 1
	right := maxIndex
	for left != right {
		mid := left + (right-left+1)/2
		if isExist(root, mid, maxIndex) {
			left = mid
		} else {
			right = mid - 1
		}
	}
	return maxIndex - 1 + left
}

func isExist(root *TreeNode, index int, maxIndex int) bool {
	left := 1
	right := maxIndex
	node := root
	for left != right {
		if node == nil {
			return false
		}
		mid := left + (right-left)/2
		if mid >= index {
			node = node.Left
			right = mid
		} else {
			node = node.Right
			left = mid + 1
		}
	}
    if node == nil {
        return false
    }
	return true
}

func getDeep(root *TreeNode) int {
	deep := 0
	node := root
	for node != nil {
		deep++
		node = node.Left
	}
	return deep - 1
}

func pow(x int, y int) int {
	res := 1
	for y != 0 {
		if y&1 == 1 {
			res *= x
			y = y - 1
		} else {
			x = x * x
			y = y >> 1
		}
	}
	return res
}
