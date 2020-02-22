/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        if(!root)
            return root;
        queue<Node*> que;
        que.push(root);
        while(!que.empty()) {
            int queSize = que.size();
            for(int i = 0; i < queSize; ++i) {
                Node* pnode = que.front();
                que.pop();
                if(pnode->left) 
                    que.push(pnode->left);
                if(pnode->right)
                    que.push(pnode->right);
                if(i != queSize - 1)    
                    pnode->next = que.front();
            }
        }
        return root;
    }
};
