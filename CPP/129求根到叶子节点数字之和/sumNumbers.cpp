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
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        return sumNumbers(root, 0);
    }
private:
    int sumNumbers(TreeNode* root, int value) {
        value = value * 10 + root->val;
        
        if(root->left == nullptr && root->right == nullptr)
            return value;
        
        if(root->left == nullptr) {
            return sumNumbers(root->right, value);
        } else if(root->right == nullptr) {
            return sumNumbers(root->left, value);
        } else {
            return sumNumbers(root->left, value) + sumNumbers(root->right, value);
        }
    }
};