class LRUCache {
private:
    int capacity_;
    int used_capacity_;
    std::unordered_map<int, int> cache_;
    std::unordered_map<int, int> references_;
    std::queue<int> operations_;
public:
    LRUCache(int capacity) {
        this->capacity_ = capacity;
        this->used_capacity_ = 0;
    }
    
    int get(int key) {
        if (!this->cache_.contains(key)) {
            return -1;
        }
        this->operations_.push(key);
        this->references_[key]++;
        return this->cache_[key];
    }
    
    void put(int key, int value) {
        if (!this->cache_.contains(key)) {
            this->used_capacity_++;
            this->references_[key] = 0;
        }
        this->operations_.push(key);
        this->references_[key]++;
        this->cache_[key] = value;
        while (this->used_capacity_ > this->capacity_) {
            int front_key{this->operations_.front()};
            this->operations_.pop();
            this->references_[front_key]--;
            if (this->references_[front_key] == 0) {
                this->used_capacity_--;
                this->references_.erase(front_key);
                this->cache_.erase(front_key);
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
