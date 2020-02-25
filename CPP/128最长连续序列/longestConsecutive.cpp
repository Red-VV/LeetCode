class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> dp;
        int maxV = 0;
        for(int num : nums) {
            if(dp[num] != 0)
                continue;
            dp[num] = dp[num + 1] + dp[num - 1] + 1;
            dp[num + dp[num + 1]] = dp[num];
            dp[num - dp[num - 1]] = dp[num];
            maxV = max(maxV, dp[num]);
        }
        return maxV;
    }
};