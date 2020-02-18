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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        if(root->left == nullptr && root->right == nullptr)
            return 1;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if(root->left == nullptr || root->right == nullptr)
            return left + right + 1;
        else 
            return min(left, right) + 1;
    }
};
