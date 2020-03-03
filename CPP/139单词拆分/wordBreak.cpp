class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int size = s.size();
        vector<bool> dp(size + 1, false);
        dp[0] = true;
        for(int i = 0; i < size + 1; ++i) {
            for(int j = 0; j < i; ++j) {
                if(dp[j] && dict.find(s.substr(j, i - j)) != dict.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[size];
    }
};
