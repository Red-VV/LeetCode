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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> res;
        if(!root)
            return res;
        
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int queSize = que.size();
            vector<int> temp;
            for(int i = 0; i < queSize; ++i) {
                TreeNode *pnode = que.front();
                que.pop();
                temp.push_back(pnode->val);
                if(pnode->left)
                    que.push(pnode->left);
                if(pnode->right)
                    que.push(pnode->right);
            }
            res.push_back(temp);
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};
