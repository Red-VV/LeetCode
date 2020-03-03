/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head)
            return head;
        
        vector<Node*> newNode;
        map<Node*, Node*> dict;
        Node* ptr = head;
        for(int i = 0; ; ++i) {
            if(ptr == nullptr)
                break;
            Node* newNodePtr = new Node(ptr->val);
            newNodePtr->random = ptr->random;
            newNode.push_back(newNodePtr);
            dict[ptr] = newNodePtr;
            ptr = ptr->next;
        }
        for(int i = 0; i < newNode.size(); ++i) {
            if(i != newNode.size() - 1)
                newNode[i]->next = newNode[i + 1];
            if(newNode[i]->random != nullptr)
                newNode[i]->random = dict[newNode[i]->random];
        }
        return newNode[0];
    }
};
