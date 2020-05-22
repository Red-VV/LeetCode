class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        vector<int> right;
        left.reserve(nums.size());
        right.reserve(nums.size());
        left.push_back(1);
        right.push_back(1);
        for(int i = 0; i < nums.size() - 1; i++) {
            left.push_back(left.back() * nums[i]);
            right.push_back(right.back() * nums[nums.size() - 1 - i]);
        }
        vector<int> res(nums.size());
        for(int i = 0; i < res.size(); i++) {
            res[i] = left[i] * right[res.size() - 1 - i];
        }
        return res;
    }
};