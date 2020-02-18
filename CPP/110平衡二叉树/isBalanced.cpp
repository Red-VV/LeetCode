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
    bool isBalanced(TreeNode* root) {
        int level = 0;
        return isBalanced(root, level);
    }
private:
    bool isBalanced(TreeNode* root, int& level) {
        if(!root) {
            level = 0;
            return true;
        }
        
        int leftLevel = 0;
        int rightLevel = 0;
        bool leftBalanced = isBalanced(root->left, leftLevel);
        bool rightBalanced = isBalanced(root->right, rightLevel);
        level = max(leftLevel, rightLevel) + 1;
        return leftBalanced && rightBalanced && level - min(leftLevel, rightLevel) <= 2;
    }
};
