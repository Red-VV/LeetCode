class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if(!wordBreak_139(s, wordDict))
            return vector<string>();
        int size = s.size();
        unordered_set dict(wordDict.begin(), wordDict.end());
        vector<vector<string>> dp(size + 1);
        vector<string> nullRes;
        for(int i = 0; i <= size; ++i) {
            for(int j = 0; j < i; ++j) {
                string subStr = s.substr(j, i - j);
                if(dict.find(subStr) == dict.end())
                    continue;
                if(j == 0) {
                    dp[i].push_back(subStr);
                } else if(!dp[j].empty()) {
                    for(string prefix : dp[j]) {
                        dp[i].push_back(prefix + " " + subStr);
                    }
                }
            }
        }

        return dp[size];
    }
private:
    bool wordBreak_139(string s, vector<string>& wordDict) {
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