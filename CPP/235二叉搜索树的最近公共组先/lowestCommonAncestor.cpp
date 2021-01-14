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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root)
            return root;
        TreeNode *pmin = p;
        TreeNode *pmax = q;
        if(pmin->val > pmax->val)
            swap(pmin, pmax);
        if(pmin->val > root->val)
            return lowestCommonAncestor(root->right, pmin, pmax);
        else if(pmax->val < root->val)
            return lowestCommonAncestor(root->left, pmin, pmax);
        return root;
    }
};
