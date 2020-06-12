class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = 0;
        for(int i = 0; i < nums.size(); i++) {
            n = n ^ nums[i];
            n = n ^ (i + 1);
        }
        return n;
    }
};