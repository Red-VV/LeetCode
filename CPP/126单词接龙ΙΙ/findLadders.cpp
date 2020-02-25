class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        queue<vector<string>> que;
        
        initHashSet(wordList);
        if(hashSet.find(endWord) == hashSet.end())
            return res;
        hashSet.erase(beginWord);
        vector<string> beginPath{beginWord};
        que.push(beginPath);

        bool findTarget = false;
        while(!que.empty()) {
            int pathSize = que.size();
            unordered_set<string> deleteNode;
            for(int i = 0; i < pathSize; ++i) {
                vector<string> path = que.front();
                que.pop();
                string node = path[path.size() - 1];
                vector<string> nextNode = getNext(node);
                deleteNode.insert(nextNode.begin(), nextNode.end());
                for(string str : nextNode) {
                    path.push_back(str);
                    que.push(path);
                    if(str == endWord) {
                        findTarget = true;
                        res.push_back(path);
                    }
                    path.pop_back();
                }
            }
            for(string str : deleteNode) {
                hashSet.erase(str);
            }
            if(findTarget) {
                return res;
            }
        }
        return res;
    }
private:
    unordered_set<string> hashSet;

    void initHashSet(vector<string>& wordList) {
        for(string str : wordList) 
            hashSet.insert(str);
    }
    
    vector<string> getNext(string word) {
        vector<string> res;
        for(int i = 0; i < word.size(); ++i) {
            for(char c = 'a'; c <= 'z'; ++c) {
                if(c == word[i])
                    continue;
                else {
                    char temp = word[i];
                    word[i] = c;
                    if(hashSet.find(word) != hashSet.end()) {
                        res.push_back(word);
                    }
                    word[i] = temp;
                }
            }
        }
        return res;
    }
};