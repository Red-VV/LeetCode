/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        backtrace(root);
        return this->res;
    }
private:
    vector<int> path;
    vector<string> res;
    void backtrace(TreeNode* root) {
        if(root == nullptr)
            return;
        this->path.push_back(root->val);
        if(root->left == nullptr && root->right == nullptr) {
            this->res.push_back(vect2string(this->path));
        }
        backtrace(root->left);
        backtrace(root->right);
        this->path.pop_back();
    }
    string vect2string(vector<int> path) {
        stringstream str;
        for(const auto &node : path) {
            str << node << "->";
        }
        string res;
        str >> res;
        if(!res.empty()) {
            res = res.substr(0, res.size() - 2);
        }
        return res;
    }
};