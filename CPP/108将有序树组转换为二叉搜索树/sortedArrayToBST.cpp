/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size() == 0)
            return nullptr;
        this->nums = nums;
        return sortedArrayToBST(0, nums.size() - 1);
    }
private:
    vector<int> nums;
    TreeNode* sortedArrayToBST(int low, int high) {
        if(low > high)
            return nullptr;
            
        int mid = (low + high) / 2;
        int rootVal = nums[mid];
        TreeNode *root = new TreeNode(rootVal);
        root->left = sortedArrayToBST(low, mid - 1);
        root->right = sortedArrayToBST(mid + 1, high);
        return root;
    }
};
