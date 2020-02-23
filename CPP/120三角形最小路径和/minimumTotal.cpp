class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int length = triangle.size();
        vector<int> dp(triangle[length - 1].size(), 0);
        dp[0] = triangle[0][0];
        for(int i = 1; i < length; ++i) {
            for(int j = triangle[i].size() - 1; j > 0; --j) {
                if(j == triangle[i - 1].size()) {
                    dp[j] = dp[j - 1] + triangle[i][j];
                } else {
                    dp[j] = min(dp[j - 1], dp[j]) + triangle[i][j];
                }
            }
            dp[0] += triangle[i][0]; 
        }
        return *(min_element(dp.begin(), dp.end()));
    }
};
