class Solution {
public:
    int minCut(string s) {
        if(s.empty())
            return 0;
        int size = s.size();
        vector<vector<int>> palindrome(size, vector<int>(size, 0));
        this->palindrome = palindrome;
        this->str = s;
        vector<int> dp(size, INT32_MAX);
        this->dp = dp;
        for(int i = 0; i < size; ++i) {
            preProcess(i, i);
            preProcess(i, i + 1);
        }
        return this->dp[size - 1];
    }
private:
    vector<vector<int>> palindrome;
    string str;
    vector<int> dp;
    void preProcess(int left, int right) {
        while(left >= 0 && right < str.size() && str[left] == str[right]) {
            if(left - 1 >= 0)
                dp[right] = min(dp[left - 1] + 1, dp[right]);
            else 
                dp[right] = 0;
            --left;
            ++right;
        }
    }
};