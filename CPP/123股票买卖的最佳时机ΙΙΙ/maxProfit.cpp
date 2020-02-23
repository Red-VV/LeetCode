class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxP = 0;
        for(int i = 0; i < prices.size(); ++i) {
            maxP = max(maxP, maxSingle(prices, 0, i) + maxSingle(prices, i , prices.size()));
        }
        return maxP;
    }
private:
    int maxSingle(vector<int>& prices, int left, int right) {
        int maxP = 0;
        if(left == right)
            return maxP;
        int minL = prices[left];
        for(int i = left; i < right; ++i) {
            if(prices[i] - minL > maxP)
                maxP = prices[i] - minL;
            else if(minL > prices[i])
                minL = prices[i];
        }
        return maxP;
    }
};
