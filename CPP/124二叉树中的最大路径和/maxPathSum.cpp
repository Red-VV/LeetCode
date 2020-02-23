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
    int maxPathSum(TreeNode* root) {
        int value = root->val;
        maxPathSum(root, value);
        return value;
    }
private:
    int maxPathSum(TreeNode* root, int &value) {
        if(!root) {
            return 0;
        }
        int maxL = maxPathSum(root->left, value);
        int maxR = maxPathSum(root->right, value);
        int totalMax = root->val + max(0, maxL) + max(0, maxR);
        value = max(value, totalMax);
        return root->val + max(0, max(maxL, maxR));
    }
};
