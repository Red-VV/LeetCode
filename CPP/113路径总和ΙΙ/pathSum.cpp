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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pathGenerate(root, sum);
        return this->res;
    }
private:
    vector<int> path;
    vector<vector<int>> res;
    void pathGenerate(TreeNode* root, int sum) {
        if(!root)
            return;
        path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            if(sum == root->val) {
                res.push_back(path);
            }
        } else if(root->left == nullptr) {
            pathGenerate(root->right, sum - root->val);
        } else if(root->right == nullptr) {
            pathGenerate(root->left, sum - root->val);
        } else {
            pathGenerate(root->left, sum - root->val);
            pathGenerate(root->right, sum - root->val);
        }
        path.pop_back();
    }
};
