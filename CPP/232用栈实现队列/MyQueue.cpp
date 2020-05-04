class MyQueue {
public:
    stack<int> in;
    stack<int> out;
    int size;
    /** Initialize your data structure here. */
    MyQueue() {
        size = 0;
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        size++;
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if(out.empty())
        {
            while(!in.empty()) {
                int in_data = in.top();
                in.pop();
                out.push(in_data);
            }
        }
        int res = out.top();
        out.pop();
        size--;
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        if(out.empty())
        {
            while(!in.empty()) {
                int in_data = in.top();
                in.pop();
                out.push(in_data);
            }
        }
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return size == 0;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */