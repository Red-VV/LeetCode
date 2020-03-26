/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 type BSTIterator struct {
	stack []*TreeNode
}

func Constructor(root *TreeNode) BSTIterator {
	var it BSTIterator
	it.stack = make(([]*TreeNode), 0)
	if root == nil {
		return it
	} else {
		for ptr := root; ptr != nil; ptr = ptr.Left {
			it.stack = append(it.stack, ptr)
		}
	}
	return it
}


/** @return the next smallest number */
func (this *BSTIterator) Next() int {
	stackLen := len(this.stack)
	ptr := this.stack[stackLen - 1]
	res := ptr.Val
	this.stack = this.stack[0 : stackLen - 1]

	if ptr.Right != nil {
		ptr = ptr.Right
		for ; ptr != nil; ptr = ptr.Left {
			this.stack = append(this.stack, ptr)
		}
	}
	return res
}


/** @return whether we have a next smallest number */
func (this *BSTIterator) HasNext() bool {
	return len(this.stack) != 0
}


/**
 * Your BSTIterator object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Next();
 * param_2 := obj.HasNext();
 */