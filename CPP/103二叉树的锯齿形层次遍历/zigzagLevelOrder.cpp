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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
            vector<vector<int>> res;
            if(!root)
                return res;
            
            deque<TreeNode*> que;
            que.push_back(root);
            bool reverse  = false;
            while(!que.empty()) {
                int queSize = que.size();
                vector<int> temp;
                for(int i = 0; i < queSize; ++i) {
                    if(reverse) {
                        TreeNode* pnode = que.back();
                        que.pop_back();
                        temp.push_back(pnode->val);
                        if(pnode->right)
                            que.push_front(pnode->right);
                        if(pnode->left)
                            que.push_front(pnode->left);
                    } else {
                        TreeNode* pnode = que.front();
                        que.pop_front();
                        temp.push_back(pnode->val);
                        if(pnode->left)
                            que.push_back(pnode->left);
                        if(pnode->right)
                            que.push_back(pnode->right);
                    }
                }
                reverse = !reverse;
                res.push_back(temp);
            }
            return res;
    }
};
