class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        int pos = 0;
        while(true) {
            pos = s.find_first_not_of(" ", pos);
            if(pos == string::npos)
                break;
            int next = s.find(" ", pos);
            st.push(s.substr(pos, next - pos));
            pos = next;
        }
        string res;
        while(!st.empty()) {
            res += st.top() + " ";
            st.pop();
        }
        res.erase(res.find_last_not_of(" ") + 1);
        return res;
    }
};