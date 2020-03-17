class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right) {
            int mid = (left + right) / 2;
            if(nums[right] < nums[left] && nums[left] <= nums[mid]) {
                left = mid + 1;
            } else if(nums[left] <= nums[mid] && nums[mid] < nums[right]) {
                return nums[left];
            } else {
                right = mid;
            }
        }
        return nums[left];
    }
};