class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> nums(n, INT_MAX);
        nums[0] = 1;
        int i2 = 0, i3 = 0, i5 = 0;
        for(int i = 1; i < n; i++) {
            nums[i] = min(nums[i2] * 2, min(nums[i3] * 3, nums[i5] * 5));
            if(nums[i] == nums[i2] * 2)
                i2++;
            if(nums[i] == nums[i3] * 3)
                i3++;
            if(nums[i] == nums[i5] * 5)
                i5++;
        }
        return nums.back();
    }
};