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
    TreeNode* res;
    TreeNode* p;
    TreeNode* q;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        this->res = nullptr;
        hasPOrQ(root);
        return this->res;
    }
private:
    bool hasPOrQ(TreeNode *root) {
        if(root == nullptr)
            return false;
        bool left = hasPOrQ(root->left);
        bool right = hasPOrQ(root->right);
        if((left && right) || ((root == p || root == q) && (left || right))) {
            res = root;
        }
        return (left || right || root == p || root == q);
    }
};
