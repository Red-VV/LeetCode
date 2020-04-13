/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil {
		return head
	}

	dummyNode := &ListNode{
		Val:0,
		Next:nil}
	dummyNode.Next = head
	ptr := head.Next
	head.Next = nil
	for ptr != nil {
		tmpNode := ptr
		ptr = ptr.Next
		tmpNode.Next = dummyNode.Next
		dummyNode.Next = tmpNode
	}
	return dummyNode.Next
}