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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder = preorder;
        this->inorder = inorder;
        return buildTree(0, preorder.size(), 0, inorder.size());
    }
private:
    vector<int> preorder;
    vector<int> inorder;
    TreeNode* buildTree(int leftLow, int leftHigh, int rightLow, int rightHigh) {
        int totalSize = leftHigh - leftLow;
        if(totalSize == 0)
            return nullptr;
        int rootVal = preorder[leftLow];
        int leftSubSize = 0;
        for( ; leftSubSize + rightLow < rightHigh; ++leftSubSize) {
            if(inorder[leftSubSize + rightLow] == rootVal)
                break;
        }
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTree(leftLow + 1, leftLow + 1 + leftSubSize, rightLow, rightLow + leftSubSize);
        root->right = buildTree(leftLow + 1 + leftSubSize, leftHigh, rightLow + 1 + leftSubSize, rightHigh);
        return root;
    }
};
