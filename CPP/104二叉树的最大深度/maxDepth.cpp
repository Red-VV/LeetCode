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
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int leftLevel = maxDepth(root->left);
        int rightLevel = maxDepth(root->right);
        return 1 + max(leftLevel, rightLevel);
    }
};
