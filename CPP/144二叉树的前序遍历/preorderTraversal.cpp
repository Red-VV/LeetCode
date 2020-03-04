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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        TreeNode* ptr = root;
        while(ptr || !st.empty()) {
            while(ptr) {
                res.push_back(ptr->val);
                st.push(ptr);
                ptr = ptr->left;
            }
            if(!ptr) {
                ptr = st.top()->right;
                st.pop();
            }
        }
        return res;
    }
};