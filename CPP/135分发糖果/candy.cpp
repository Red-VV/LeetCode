class Solution {
public:
    int candy(vector<int>& ratings) {
        int minCandy = 0;
        if(ratings.empty())
            return minCandy;
        
        vector<int> temp(ratings.size(), 1);
        for(int i = 1; i < ratings.size(); ++i) {
            if(ratings[i] > ratings[i - 1]) {
                temp[i] = temp[i - 1] + 1;
            } 
        }
        
        for(int i = ratings.size() - 2; i >= 0; --i) {
            if(ratings[i] > ratings[i + 1]) {
                temp[i] = max(temp[i], temp[i + 1] + 1);
            }
        }
    }
};
