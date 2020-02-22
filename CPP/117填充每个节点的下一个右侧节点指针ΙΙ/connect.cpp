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
        Node* mostLeft = root;
        Node* nextMostLeft = nullptr;
        Node* pre = nullptr;
        while(true) {
            Node* cur = getNext(mostLeft);
            if(cur == nullptr)
                break;
            if(cur->left) {
                nextMostLeft = cur->left;
            } else {
                nextMostLeft = cur->right;
            }
            pre = nextMostLeft;
            
            while(cur) {
                if(cur->left && cur->right) {
                    if(cur->left != pre) {
                        pre->next = cur->left;
                    }
                    cur->left->next = cur->right;
                    pre = cur->right;
                } else if(cur->left) {
                    if(cur->left != pre) {
                        pre->next = cur->left;
                        pre = pre->next;
                    }
                } else if(cur->right) {
                    if(cur->right != pre) {
                        pre->next = cur->right;
                        pre = pre->next;
                    }
                }
                cur = cur->next;
            }
            mostLeft = nextMostLeft;
            pre = nullptr;
            nextMostLeft = nullptr;
        }
        return root;
    }
private:
    Node* getNext(Node *pnode) {
        while(pnode) {
            if(pnode->left || pnode->right)
                return pnode;
            pnode = pnode->next;
        }
        return nullptr;
    }
    
};
