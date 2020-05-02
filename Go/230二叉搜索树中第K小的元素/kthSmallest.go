/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthSmallest(root *TreeNode, k int) int {
	res := new(int)
	isVisited := new(int)
	inorderTraversal(root, res, k, isVisited);
	return *res
}

func inorderTraversal(root *TreeNode, res *int, k int, isVisited *int) {
	if root == nil {
		return
	}
	inorderTraversal(root.Left, res, k, isVisited)
	if *isVisited + 1 == k {
		(*isVisited)++
		*res = root.Val
	} else if *isVisited + 1 < k {
		(*isVisited)++
		inorderTraversal(root.Right, res, k, isVisited)
	}
}