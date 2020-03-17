class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxV = nums[0];
        int tempMax = nums[0];
        int tempMin = nums[0];
        for(int i = 1; i < nums.size(); ++i) {
            if(tempMax == 0 || nums[i] == 0) {
                tempMax = nums[i];
                tempMin = nums[i];
                maxV = max(maxV, tempMax);
                continue;
            } else {
                if(nums[i] < 0) {
                    swap(tempMax, tempMin);                    
                }
                tempMax = max(tempMax * nums[i], nums[i]);
                tempMin = min(tempMin * nums[i], nums[i]);
                maxV = max(maxV, tempMax);
            }
        }
        return maxV;
    }
};