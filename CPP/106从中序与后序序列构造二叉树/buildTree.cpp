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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->inorder = inorder;
        this->postorder = postorder;
        return buildTree(0, inorder.size(), 0, postorder.size());
    }
private:
    vector<int> inorder;
    vector<int> postorder;
    TreeNode* buildTree(int leftLow, int leftHigh, int rightLow, int rightHigh) {
        int totalSize = leftHigh - leftLow;
        if(totalSize == 0)
            return nullptr;
        int rootVal = postorder[rightHigh - 1];
        int leftSubSize = 0;
        for( ; leftSubSize + leftLow < leftHigh; ++leftSubSize) {
            if(inorder[leftSubSize + leftLow] == rootVal)
                break;
        }
        TreeNode *root = new TreeNode(rootVal);
        root->left = buildTree(leftLow, leftLow + leftSubSize, rightLow, rightLow + leftSubSize);
        root->right = buildTree(leftLow + leftSubSize + 1, leftHigh, rightLow + leftSubSize, rightHigh - 1);
        return root;
    }
};
