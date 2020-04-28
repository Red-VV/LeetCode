type MyStack struct {
	stack []int
	size int
}


/** Initialize your data structure here. */
func Constructor() MyStack {
	return MyStack{
		stack: make([]int, 0),
		size: 0}
}


/** Push element x onto stack. */
func (this *MyStack) Push(x int)  {
	this.stack = append(this.stack, x)
	this.size++
}


/** Removes the element on top of the stack and returns that element. */
func (this *MyStack) Pop() int {
	res := this.stack[this.size-1]
	this.size--
	this.stack = this.stack[0:this.size]
	return res
}


/** Get the top element. */
func (this *MyStack) Top() int {
	return this.stack[this.size-1]
}


/** Returns whether the stack is empty. */
func (this *MyStack) Empty() bool {
	return this.size == 0
}


/**
 * Your MyStack object will be instantiated and called as such:
 * obj := Constructor();
 * obj.Push(x);
 * param_2 := obj.Pop();
 * param_3 := obj.Top();
 * param_4 := obj.Empty();
 */