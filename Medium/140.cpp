class Solution {
public:
    unordered_map<int, int> mp;
    int size;
    
    bool isValid(int index) {
        if(index < 0 || index > size) return false;
        if(mp[index] == 0) return true;
        if(mp[index] == -1) return false;
        
        int k = mp[index];
        mp[index] = -1;
        
        return isValid(index + k) || isValid(index - k);
    }
    
    bool canReach(vector<int>& arr, int start) {
        int i=0;
        for(int it: arr) mp[i++] = it;
        
        size = i-1;
        return isValid(start);
    }
};