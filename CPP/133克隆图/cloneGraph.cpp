/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    Node* cloneGraph(Node* node) {
        genNew(node);
        return genGraph(node);
    }
private:
    map<Node*, Node*> relaDict;
    map<Node*, int> isVisited;
    /*
     * @brief: 给每个节点生成一个副本，并用map保存新旧节点之间的对应关系
     * @param: node 图节点
     */
    void genNew(Node* node) {
        if(node == nullptr)
            return;
        if(relaDict.find(node) != relaDict.end())
            return;
        Node* newNode = new Node(node->val);
        relaDict[node] = newNode;
        for(int i = 0; i < node->neighbors.size(); ++i) {
            genNew(node->neighbors[i]);
        }
    }
    
    /*
     * @brief: 连接新节点之间的关系，根据原来的图生成一张新的图
     * @param: node 节点
     */
    Node* genGraph(Node* node) {
        if(node == nullptr)
            return nullptr;
        if(isVisited.find(node) != isVisited.end())
            return relaDict[node];
        isVisited[node] = 1;
        for(int i = 0; i < node->neighbors.size(); ++i) {
            relaDict[node]->neighbors.push_back(relaDict[node->neighbors[i]]);
            genGraph(node->neighbors[i]);
        }
        return relaDict[node];
     }
};
