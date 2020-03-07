class LRUCache {
public:
    LRUCache(int capacity) {
        capacity_ = capacity;
    }
    
    int get(int key) {
        if(dict_.find(key) == dict_.end())
            return -1;
        pair<int, int> node = *dict_[key];
        cache_.erase(dict_[key]);
        cache_.push_front(node);
        dict_[key] = cache_.begin();
        return node.second;
    }
    
    void put(int key, int value) {
        if(dict_.find(key) == dict_.end()) {
            if(capacity_ == dict_.size()) {
                int old_key = cache_.back().first;
                cache_.pop_back();
                dict_.erase(old_key);
            }
        } else {
            cache_.erase(dict_[key]);
        }
        cache_.push_front(make_pair(key, value));
        dict_[key] = cache_.begin();
    }
private:
    int capacity_;
    list<pair<int, int>> cache_;
    unordered_map<int, list<pair<int, int>>::iterator> dict_;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */