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
    void flatten(TreeNode* root) {
        if(!root)
            return;
        this->head = root;
        realFlatten();
    }
private:
    TreeNode* head;
    void realFlatten() {
        TreeNode *right = this->head->right;
        if(this->head->left != nullptr) {
            this->head->right = this->head->left;
            this->head->left = nullptr;
            this->head = this->head->right;
            realFlatten();
        }
        this->head->right = right;
        if(right != nullptr) {
            this->head = this->head->right;
            realFlatten();
        }
    }
};
