
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set hashSet(wordList.begin(), wordList.end());
        
        if(hashSet.find(endWord) == hashSet.end())
            return 0;
        
        int level = 0;
        queue<string> que;
        que.push(beginWord);
        hashSet.erase(beginWord);
        while(!que.empty()) {
            ++level;
            int queSize = que.size();
            for(int i = 0; i < queSize; ++i) {
                string str = que.front();
                que.pop();
                vector<string> nextNode = getNext(hashSet, str);
                for(string next : nextNode) {
                    if(next == endWord) {
                        return level + 1;
                    }
                    que.push(next);
                }
            }
        }
        return 0;
    }
private:
    vector<string> getNext(unordered_set<string>& hashSet, string word) {
        vector<string> res;
        for(int i = 0; i < word.size(); ++i) {
            for(char c = 'a'; c <= 'z'; ++c) {
                if(c == word[i])
                    continue;
                else {
                    swap(word[i], c);
                    if(hashSet.find(word) != hashSet.end()) {
                        res.push_back(word);
                        hashSet.erase(word);
                    }
                    swap(word[i], c);
                }
            }
        }
        return res;
    }
};