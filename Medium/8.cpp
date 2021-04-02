class Solution {
public:
    int findDuplicate(vector<int>& v) {
        unordered_map<int, int> mp;
        for(int i: v) mp[i]++;
        for(auto i: mp) if(i.second > 1) return i.first;
        return -1;
    }
};