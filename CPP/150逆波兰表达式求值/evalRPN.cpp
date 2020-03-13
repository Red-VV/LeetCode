class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(string &str : tokens) {
            if(str == "+" || str =="-" || str == "*" || str == "/") {
                operation(st, str);
            } else {
                st.push(atoi(str.c_str()));
            }
        }
        return st.top();
    }
private:
    int value_;
    void operation(stack<int> &st, string &str) {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        int value = 0;
        if(str == "+") {
            value = a + b;
        } else if(str == "-") {
            value = b - a;
        } else if(str == "*") {
            value = a * b;
        } else if(str == "/") {
            value = b / a;
        }
        st.push(value);
    }
};