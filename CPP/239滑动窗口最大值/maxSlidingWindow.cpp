class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        res.reserve(nums.size() - k + 1);
        int max_index = 0;
        int max_num = nums[0];
        for(int i = 1; i < k; i++) {
            if(nums[i] >= max_num) {
                max_num = nums[i];
                max_index = i;
            }
        }
        res.push_back(max_num);
        for(int i = k; i < nums.size(); i++) {
            if(nums[i] >= max_num) {
                max_num = nums[i];
                max_index = i;
            }
            if(max_index + k == i) {
                max_index++;
                max_num = nums[max_index];
                for(int j = max_index + 1; j <= i; j++) {
                    if(nums[j] >= max_num) {
                        max_num = nums[j];
                        max_index = j;
                    }
                }
            }
            res.push_back(max_num);
        }

        return res;
    }
};