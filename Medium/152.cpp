class LRUCache {
public:    
    list<pair<int, int>> dll;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    int size;
    
    LRUCache(int capacity) {
        size = capacity;
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()) 
            return -1;
        dll.splice(dll.begin(), dll, mp[key]);
        return mp[key]->second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()) {
            dll.splice(dll.begin(), dll, mp[key]);
            mp[key]->second = value;
            return;
        }
        if(dll.size() == size) {
            auto d_key = dll.back().first;
            dll.pop_back();
            mp.erase(d_key);
        }
        dll.push_front({key, value});
        mp[key] = dll.begin();
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */