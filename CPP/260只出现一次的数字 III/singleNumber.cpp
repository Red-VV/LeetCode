class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int bitmask = 0;
        for(const auto & num : nums) {
            bitmask ^= num;
        }
        int flag = bitmask & (-bitmask);
        int x = 0;
        for(const auto & num : nums) {
            if(flag & num) {
                x ^= num;
            }
        }
        int y = x ^ bitmask;
        return vector<int> {x, y};
    }
};