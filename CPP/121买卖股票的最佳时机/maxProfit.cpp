class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> minL(prices.size());
        vector<int> maxR(prices.size());
        for(int i = 0; i < prices.size(); ++i) {
            if(i == 0)
                minL[i] = prices[i];
            else 
                minL[i] = min(minL[i - 1], prices[i]);
        }
        
        for(int i = prices.size() - 1; i >= 0; --i) {
            if(i == prices.size() - 1)
                maxR[i]= prices[i];
            else 
                maxR[i] = max(maxR[i + 1], prices[i]);
        }
        
        int maxP = 0;
        for(int i = 0; i < prices.size(); ++i) {
            if(maxP < maxR[i] - minL[i])
                maxP = maxR[i] - minL[i];
        }
        return maxP;
    }
};
